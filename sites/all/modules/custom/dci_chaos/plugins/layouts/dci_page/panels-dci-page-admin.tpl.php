<?php
/**
 * Template for dci-header panel layout.
 *
 * This is the Drupal Camp Indonesia header layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['header']: Content in the left column.
 *   - $content['banner']: Content in the right column.
 *   - $content['main']: Content in the right column.
 *   - $content['sidebar-last']: Content in the second sidebar.
 *   - $content['footer-1st']: Content in the right column.
 *   - $content['footer-2nd']: Content in the right column.
 *   - $content['footer-3rd']: Content in the right column.
 *   - $content['footer-4th']: Content in the right column.
 *   - $content['footer-last']: Content in the right column.
 */
/*
<div class="page<?php if (!empty($css_class)): ?> <?php print $css_class;?><?php endif; ?>"<?php if (!empty($css_id)): ?> id="<?php print $css_id; ?>"<?php endif; ?>>
*/
?>
<div class="page">

<?php if ($content['header'] || $content['banner']): ?>
<header role="banner">
  <?php if ($content['header']): ?>
    <div class="centerwrap-header">
      <div class="header-wrap">
        <div class="header-content"><?php print $content['header']; ?></div>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($content['banner']): ?>
  <div class="backwrap-banner">
    <div class="centerwrap-banner">
      <div class="banner-wrap">
        <div class="banner-content">
        <?php print $content['banner']; ?>
        </div>
      </div>
    </div>
  </div>
  <?php endif; ?>
</header>
<?php endif; ?>

<?php if ($content['main'] || $content['sidebar-last']): ?>
<div class="backwrap-main">
<div class="centerwrap-main <?php if ($content['sidebar-last']): ?>has-sidebar<?php endif; ?>">
  <div class="main-wrap">
    <?php if ($content['main-before']): ?>
    <div class="main-before"><?php print $content['main-before']; ?></div>
    <?php endif; ?>

    <?php if ($content['main']): ?>
    <div id="main" role="main"><?php print $content['main']; ?></div>
    <?php endif; ?>

    <?php if ($content['main-after']): ?>
    <div class="main-after"><?php print $content['main-after']; ?></div>
    <?php endif; ?>
  </div>

  <?php if ($content['sidebar-last']): ?>
  <?php print $content['sidebar-last']; ?>
  <?php endif; ?>
</div>
</div>
<?php endif; ?>

<?php
  $footer_count = 0;
  if ($content['footer-1st']) {
    $footer_count += 1;
  }
  if ($content['footer-2nd']) {
    $footer_count += 1;
  }
  if ($content['footer-3rd']) {
    $footer_count += 1;
  }
  if ($content['footer-4th']) {
    $footer_count += 1;
  }

  $footer_extra_count = 0;
  if ($content['footer-extra-1st']) {
    $footer_extra_count += 1;
  }
  if ($content['footer-extra-2nd']) {
    $footer_extra_count += 1;
  }

  if ($footer_count !== 0 || $footer_extra_count !== 0):
?>
<footer>
  <?php if ($footer_count !== 0): ?>
  <div class="centerwrap-footer">
    <?php if ($content['footer-1st']): ?>
    <div class="footer-<?php print $footer_count; ?>col"><?php print $content['footer-1st']; ?></div>
    <?php endif; ?>

    <?php if ($content['footer-2nd']): ?>
    <div class="footer-<?php print $footer_count; ?>col"><?php print $content['footer-2nd']; ?></div>
    <?php endif; ?>

    <?php if ($content['footer-3rd']): ?>
    <div class="footer-<?php print $footer_count; ?>col"><?php print $content['footer-3rd']; ?></div>
    <?php endif; ?>

    <?php if ($content['footer-4th']): ?>
    <div class="footer-<?php print $footer_count; ?>col"><?php print $content['footer-4th']; ?></div>
    <?php endif; ?>
  </div>
  <?php endif; ?>

  <?php if ($footer_extra_count !== 0): ?>
  <div class="footer-extra"><div class="centerwrap-footer-extra">
    <?php if ($content['footer-extra-1st']): ?>
    <div class="footer-<?php print $footer_extra_count; ?>col"><?php print $content['footer-extra-1st']; ?></div>
    <?php endif; ?>

    <?php if ($content['footer-extra-2nd']): ?>
    <div class="footer-<?php print $footer_extra_count; ?>col"><?php print $content['footer-extra-2nd']; ?></div>
    <?php endif; ?>
  </div></div>
  <?php endif; ?>
</footer>
<?php endif; ?>

</div>
