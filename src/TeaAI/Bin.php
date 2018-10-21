<?php

namespace TeaAI;

use TeaAI\Exceptions\BinException;

/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license MIT
 * @package \TeaAI
 * @version 0.0.1
 */
final class Bin
{
	/**
	 * @var array
	 */
	private $argv = [];

	/**
	 * @throws \TeaAI\Exceptions\BinException
	 *
	 * Constructor.
	 */
	public function __construct()
	{
		if (! isset($_SERVER["argv"])) {
			throw new BinException("\$_SERVER[\"argv\"] variable is not set");
		}

		if (PHP_SAPI !== "cli") {
			throw new BinException("You can only run this script in CLI environment");
		}

		// Strip app name.
		$argv = $_SERVER["argv"];
		array_shift($argv);
		$this->argv = $argv;
	}

	/**
	 * @return void
	 */
	public function run(): void
	{
		$c = count($this->argv);

		if ($c === 0) {
			$this->usage();
			return;
		}

		foreach ($this->argv as $k => $v) {
			
		}
	}

	/**
	 * @return void
	 */
	private function usage(): void
	{
		fprintf(STDERR, "Usage: php {$_SERVER['argv'][0]} [options] [command]\n");
		fprintf(STDERR, " Commands:\n");
		fprintf(STDERR, "\tcalc\t\t\tCalculate mathematical expression.\n");
		fprintf(STDERR, "\tchat\t\t\tPerforming an AI chat.\n");
		fprintf(STDERR, "\tupdate\t\t\tUpdate application core.\n\n");
		fprintf(STDERR, " Options:\n");
		fprintf(STDERR, "\t-o <file>\t\tPlace the output into <file>.\n");
		fprintf(STDERR, "\t--output <file>\t\tPlace the output into <file>.\n");
		fprintf(STDERR, "\t-i <file>\t\tRead the input from <file>.\n");
		fprintf(STDERR, "\t--input <file>\t\tRead the input from <file>.\n");
		fprintf(STDERR, "\t--stdout-output\t\tShow the output to stdout.\n");
		fprintf(STDERR, "\t--stdin-input\t\tRead the input from stdin.\n");
		fprintf(STDERR, "\t--argv-input <string>\tRead the input from <string>.\n");
		fprintf(STDERR, "\t-t <int>\t\tLimit the AI execution time in seconds.\n");
		fprintf(STDERR, "\t--timeout <int>\t\tLimit the AI execution time in seconds.\n");
	}
}
