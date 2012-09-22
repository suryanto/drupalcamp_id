<?php

function custom_home() {
  //module_load_include('inc','forum','forum.pages');
  global $user;  
  return custom_forum_page();
}

function custom_forum_page($forum_term = NULL) {
  if (!isset($forum_term)) {
    // On the main page, display all the top-level forums.
    $forum_term = forum_forum_load(0);
  }  

  $forum_per_page = variable_get('forum_per_page', 25);
  $sortby = variable_get('forum_order', 1);  
  
  if (empty($forum_term->container)) {    
    $topics = custom_forum_get_topics($forum_term->tid, $sortby, $forum_per_page);
  }
  else {
    $topics = custom_forum_get_topics(0, $sortby, $forum_per_page);
  }    
     

  return theme('custom_forums', array('forums' => $forum_term->forums, 'topics' => $topics, 'parents' => $forum_term->parents, 'tid' => $forum_term->tid, 'sortby' => $sortby, 'forums_per_page' => $forum_per_page));
}

function custom_forum_get_topics($tid, $sortby, $forum_per_page) {  
  global $user, $forum_topic_list_header;

  $forum_topic_list_header = array(
    NULL,
    array('data' => t('Topic'), 'field' => 'f.title'),
    array('data' => t('Replies'), 'field' => 'f.comment_count'),
    array('data' => t('Last reply'), 'field' => 'f.last_comment_timestamp'),
  );

  $order = _forum_get_topic_order($sortby);  
  for ($i = 0; $i < count($forum_topic_list_header); $i++) {
    if ($forum_topic_list_header[$i]['field'] == $order['field']) {
      $forum_topic_list_header[$i]['sort'] = $order['sort'];
    }
  }  

  $query = db_select('forum_index', 'f')->extend('PagerDefault')->extend('TableSort');
  $query->fields('f');  
  $query
    //->condition('f.tid', $tid)
    ->addTag('node_access')
    ->orderBy('f.sticky', 'DESC')
    ->orderByHeader($forum_topic_list_header)
    ->orderBy('f.last_comment_timestamp', 'DESC')
    ->limit($forum_per_page);      

  $count_query = db_select('forum_index', 'f');
  //$count_query->condition('f.tid', $tid);
  $count_query->addExpression('COUNT(*)');
  $count_query->addTag('node_access');

  $query->setCountQuery($count_query);
  $result = $query->execute();
  /*$nids = array();
  foreach ($result as $record) {
    $nids[] = $record->nid;    
  }    
  
  if ($nids) {  
    //$result = db_query("SELECT n.title, n.nid, n.type, n.sticky, n.created, n.uid, n.comment AS comment_mode, ncs.*, f.tid AS forum_tid, u.name, CASE ncs.last_comment_uid WHEN 0 THEN ncs.last_comment_name ELSE u2.name END AS last_comment_name FROM {node} n INNER JOIN {node_comment_statistics} ncs ON n.nid = ncs.nid INNER JOIN {forum} f ON n.vid = f.vid INNER JOIN {users} u ON n.uid = u.uid INNER JOIN {users} u2 ON ncs.last_comment_uid = u2.uid WHERE n.nid IN (:nids)", array(':nids' => $nids));
    $result = db_query("SELECT n.title, n.nid, n.type, n.sticky, n.created, n.uid, n.comment AS comment_mode, ncs.*, f.tid AS forum_tid, u.name, CASE ncs.last_comment_uid WHEN 0 THEN ncs.last_comment_name ELSE u2.name END AS last_comment_name FROM {node} n INNER JOIN {node_comment_statistics} ncs ON n.nid = ncs.nid INNER JOIN {forum} f ON n.vid = f.vid INNER JOIN {users} u ON n.uid = u.uid INNER JOIN {users} u2 ON ncs.last_comment_uid = u2.uid");
  }
  else {
    $result = array();
  } */

  $topics = array();
  $first_new_found = FALSE;
  foreach ($result as $topic) {
    $temp = db_query("SELECT n.title, n.nid, n.type, n.sticky, n.created, n.uid, n.comment AS comment_mode, ncs.*, f.tid AS forum_tid, u.name, CASE ncs.last_comment_uid WHEN 0 THEN ncs.last_comment_name ELSE u2.name END AS last_comment_name, c.subject AS last_comment_subject FROM {node} n INNER JOIN {node_comment_statistics} ncs ON n.nid = ncs.nid LEFT JOIN {comment} AS c ON c.cid = ncs.cid INNER JOIN {forum} f ON n.vid = f.vid INNER JOIN {users} u ON n.uid = u.uid INNER JOIN {users} u2 ON ncs.last_comment_uid = u2.uid WHERE n.nid = (:nid)", array(':nid' => $topic->nid));
    $topic = $temp->fetchObject();
    
    $term = taxonomy_term_load($topic->forum_tid);
    $topic->postedin = l($term->name, 'forum/' . $term->tid);
              
    if ($user->uid) {
      // folder is new if topic is new or there are new comments since last visit
      $topic->new = 0;
      /*if ($topic->forum_tid != $tid) {
        $topic->new = 0;
      }
      else {
        $history = _forum_user_last_visit($topic->nid);
        $topic->new_replies = comment_num_new($topic->nid, $history);
        $topic->new = $topic->new_replies || ($topic->last_comment_timestamp > $history);
      } */
    }
    else {
      // Do not track "new replies" status for topics if the user is anonymous.
      $topic->new_replies = 0;
      $topic->new = 0;
    }

    // Make sure only one topic is indicated as the first new topic.
    $topic->first_new = FALSE;
    if ($topic->new != 0 && !$first_new_found) {
      $topic->first_new = TRUE;
      $first_new_found = TRUE;
    }

    if ($topic->comment_count > 0) {
      $last_reply = new stdClass();
      $last_reply->created = $topic->last_comment_timestamp;
      $last_reply->name = $topic->last_comment_name;
      $last_reply->uid = $topic->last_comment_uid;
      $last_reply->subject = l($topic->last_comment_subject, 'node/'. $topic->nid, array('fragment' => 'comment-'. $topic->cid));
      $last_reply->comment = TRUE;
      //print_r($last_reply);
      //$topic->comment_subject = $topic->last_comment_subject;
      //print_r($temp);
      $topic->last_reply = $last_reply;
    }
    $topics[] = $topic;
  }    
    

  return $topics;
}
