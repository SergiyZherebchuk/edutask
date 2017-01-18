<?php

$plugin = array(
  'title' => t('Custom pane'),
  'single' => TRUE,
  'category' => t('Custom Panes'),
  'render callback' => 'drudesk_panels_custom_pane_render',
);

/**
 * Render the pane
 */
function drudesk_panels_custom_pane_render($subtype, $conf, $panel_args, $contexts) {
  $items = array();

  $nodes = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->where('n.nid % 3 = 0')
    ->extend('PagerDefault')
    ->limit(50)
    ->execute()
    ->fetchAll();

  foreach ($nodes as $result) {
    $items[] = l($result->title, 'node/' . $result->nid);
  }

  $block = new stdClass();

  $block->title = t('All nodes as 3 number');
  $block->content = theme('item_list', array('items' => $items));
  $block->content .= theme('pager');

  return $block;
}
