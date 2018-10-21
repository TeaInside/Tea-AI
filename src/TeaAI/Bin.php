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
	 * @var array
	 */
	private $outputRes = [];

	/**
	 * @var string
	 */
	private $inputRes = NULL;

	/**
	 * @var int
	 */
	private $timeout = -1;

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

		$tSkip = false;
		foreach ($this->argv as $k => $v) {

			if ($tSkip) {
				$tSkip = false;
				continue;
			}

			if ($v[0] === "-" && isset($v[1])) {
				if ($v[1] === "-") {
					
				} else {

					if ($v[1] === "o") {
						if (isset($v[2])) {
							$this->outputRes[] = substr($v, 2);
						} else {
							if (
								isset($this->argv[$k + 1]) && 
								$this->argv[$k + 1][0] !== "-"
							) {
								$this->outputRes[] = $this->argv[$k + 1];
							} else {
								$this->err("-o option needs a value");
							}
							$tSkip = true;
						}
					}

					if ($v[1] === "i") {
						if (isset($this->inputRes)) {
							$oldInputRes = $this->inputRes;
							$inputResError = 1;
						}

						if (isset($v[2])) {
							$this->inputRes = substr($v, 2);
						} else {
							if (
								isset($this->argv[$k + 1]) && 
								$this->argv[$k + 1][0] !== "-"
							) {
								$this->inputRes = $this->argv[$k + 1];
							} else {
								$this->err("-i option needs a value");
							}
							$tSkip = true;
						}

						if (isset($inputResError)) {
							$this->err(
								"You can only provide one input resource!\n".
								"Parsed input resources: ".json_encode([$oldInputRes, $this->inputRes])
							);
						}
					}

					if ($v[1] === "t") {
						if ($this->timeout !== -1) {
							$oldTimeout = $this->timeout;
							$timeoutResError = 1;
						}

						if (isset($v[2])) {
							$this->timeout = substr($v, 2);
						} else {
							if (
								isset($this->argv[$k + 1]) && 
								$this->argv[$k + 1][0] !== "-"
							) {
								$this->timeout = $this->argv[$k + 1];
							} else {
								$this->err("-t option needs a value");
							}
							$tSkip = true;
						}

						if (isset($timeoutResError)) {
							$this->err(
								"You can only provide one timeout value!\n".
								"Parsed timeout values: ".json_encode([$oldInputRes, $this->inputRes])
							);
						}

						if (
							!is_numeric($this->timeout) ||
							preg_match("/[^0-9]/Usi", $this->timeout)
						) {
							$this->err(
								"The timeout value must be an integer!\n".
								"Parsed timeout values: \"{$this->timeout}\""
							);
						}

						$this->timeout = (int)$this->timeout;
					}
				}
			}
		}
	}

	/**
	 *
	 */
	private function err(string $str): void
	{
		fprintf(STDERR, "Error: %s\n", $str);
		exit(1);
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
		exit(1);
	}
}
