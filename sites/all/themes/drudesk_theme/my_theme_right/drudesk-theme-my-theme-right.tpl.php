<div class="panel-display panel-3col-33 clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="panel-panel panel-col-first">
		<div class="inside"><?php print $content['left']; ?></div>
	</div>

	<div class="panel-panel panel-col">
		<div class="inside"><?php print $content['middle']; ?></div>
	</div>

	<div class="panel-panel panel-col-last">
		<div class="inside"><?php print $content['right']; ?></div>
	</div>
</div>
