<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>
<div id="bg">
  <ul>
    <li class="slide slide01"></li>
    <li class="slide slide02"></li>
    <li class="slide slide03"></li>
    <li class="slide slide04"></li>
    <li class="slide slide05"></li>
    <li class="slide slide06"></li>
    <li class="slide slide07"></li>
    <li class="slide slide08"></li>
    <li class="slide slide09"></li>
    <li class="slide slide10"></li>
    <li class="slide slide11"></li>
    <li class="slide slide12"></li>
    <li class="slide slide13"></li>
    <li class="slide slide14"></li>
    <li class="slide slide15"></li>
    <li class="slide slide16"></li>
    <li class="slide slide17"></li>
    <li class="slide slide19"></li>
    <li class="slide slide20"></li>
    <li class="slide slide21"></li>
  </ul>
</div>
<div class="supercontainer">
  <!-- navbar -->
  <div id="navbar" class="outerbox">
    <div id="navbar-inner" class="inner clearfix">
      <?php if ($page['navbar']): ?><?php print render($page['navbar']); ?><?php endif; ?>
    </div>
  </div>
  <div class="maincontainer">
    <!-- intro -->
    <div id="intro" class="outerbox">
      <div id="intro-inner" class="inner clearfix">
        <?php if ($page['intro']): ?><?php print render($page['intro']); ?><?php endif; ?>
      </div>
    </div>
    <!-- menubar -->
    <div id="menubar" class="outerbox">
      <div id="menubar-inner" class="clearfix">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
            <img src="/sites/all/themes/gent2014/logo.svg" alt="<?php print t('Home'); ?>" />
          </a>
        <?php endif; ?>
        <?php if ($site_name || $site_slogan): ?>
          <div id="name-and-slogan">
            <?php if ($site_name): ?>
              <?php if ($title): ?>
                <h2 id="site-name">
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
                </h2>
              <?php else: /* Use h1 when the content title is empty */ ?>
                <h2 id="site-name">
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
                </h2>
              <?php endif; ?>
            <?php endif; ?>

            <?php if ($site_slogan): ?>
              <div id="site-slogan"><?php print $site_slogan; ?></div>
            <?php endif; ?>
          </div> <!-- /#name-and-slogan -->
        <?php endif; ?>
        <?php if ($page['menubar']): ?><?php print render($page['menubar']); ?><?php endif; ?>
      </div>
    </div>
    <!-- content -->
    <div id="content" class="outerbox">
      <div id="content-inner" class="inner clearfix">
        <?php print $messages; ?>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?><h1 class="title" id="page-title"><span><?php print $title; ?></span></h1><?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if ($page['sidebar']): ?><div id="content-sidebar"><?php print render($page['sidebar']); ?></div><?php endif; ?>
        <div id="content-content">
          <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
        </div>
      </div>
    </div>
    <!-- postscript -->
    <div id="postscript" class="outerbox">
      <div id="postscript-inner" class="inner clearfix">
        <?php if ($page['postscript']): ?><?php print render($page['postscript']); ?><?php endif; ?>
      </div>
    </div>
    <!-- footer -->
    <div id="footer" class="outerbox">
      <div id="footer-inner" class="inner clearfix">
        <?php if ($page['footer']): ?><?php print render($page['footer']); ?><?php endif; ?>
      </div>
    </div>
  </div>
</div>