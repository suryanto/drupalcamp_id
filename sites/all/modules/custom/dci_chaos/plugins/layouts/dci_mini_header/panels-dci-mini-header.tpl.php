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
 *   - $content['logo']: Content in the left column.
 *   - $content['menu']: Content in the right column.
 */
?>
<?php /*<header tes <?php if (!empty($css_id)) {
  print ' id="' . $css_id . '"';
} ?><?php if (!empty($css_class)) {
  print ' class="' . $css_class . '"';
} ?>>
*/ ?>
  <?php if ($content['logo']): ?>
    <div class="logo-wrap">
      <div class="logo"><?php print $content['logo']; ?></div>
    </div>
  <?php endif; ?>

  <?php if ($content['menu']): ?>
    <nav><?php print $content['menu']; ?></nav>
  <?php endif; ?>
<?php /*</header>*/ ?>
