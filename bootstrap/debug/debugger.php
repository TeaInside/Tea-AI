<?php

/**
 * Tea AI debugger file.
 *
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license MIT
 */

define("__DV", defined("DEBUG_VERBOSE") && DEBUG_VERBOSE);

if (__DV) {
	defined("STDOUT") or define("STDOUT", fopen("php://stdout", "w"));

	/**
	 * @param string $format
	 * @param mixed  ...$args
	 * @return void
	 */
	function debugMsg(string $format, ...$args): void
	{
		fprintf(
			STDOUT,
			"Debug: [%s] %s\n",
			date("Y-m-d H:i:s"),
			sprintf(
				$format, 
				...$args
			)
		);
	}
}

class DebuggerError extends \Exception
{
	/**
	 * @param string $format
	 * @param mixed ...$args
	 *
	 * Constructor.
	 */
	public function __construct(string $format, ...$args)
	{
		parent::__construct(sprintf($format, ...$args));
	}
}

// Constant checker.

$constants = [
	"BASEPATH",
	"STORAGE_PATH",
	"TMP_PATH",
	"CACHE_PATH",
	"DEFAULT_TIMEZONE"
];

foreach ($constants as $v) {
	if (defined($v)) {
		__DV and debugMsg("`%s` constant is defined", $v);
	} else {
		throw new DebuggerError("%s is not defined", $v);
	}
}
