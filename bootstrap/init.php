<?php

/**
 * Tea AI init file.
 *
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license MIT
 */

if (defined("__TEA_AI_INIT")):
	
	define("__TEA_AI_INIT", 1);

	require __DIR__."/../config/init.php";


	// Debug only
	require __DIR__."/debug/debugger.php";


	date_default_timezone_set(DEFAULT_TIMEZONE);

	if (file_exists($f = BASEPATH."/vendor/autoload.php")) {
		require $f;
	}

	/**
	 * @param string $class
	 * @return void
	 */
	function teaAIClassAutoloader(string $class): void
	{
		$class = str_replace("\\", "/", $class);

		if (file_exists($f = BASEPATH."/src/{$class}.php")) {
			require $f;
		}
	}

	spl_autoload_register("teaAIClassAutoloader");

	require BASEPATH."/src/helpers.php";

endif;
