<?php
declare(ticks=1);
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
	 * @var string
	 */
	private $cmd = NULL;

	/**
	 * @var string
	 */
	private $name = "";

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
		
		$argv = $_SERVER["argv"];

		// Strip the app name.
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
					
					$opt = substr($v, 2);

					if (preg_match("/(^[^\=]*)(?:=?)([^=]*$)/Usi", $opt, $m)) {

						if ($m[1] === "") {
							$m[1] = $m[2];
							$m[2] = null;
						}

						switch ($m[1]) {
							case "name":
								$this->name = is_null($m[2]) ? "" : $m[2];
								break;
							case "stdout-output":
								$this->outputRes[] = "php://stdout";
								break;
							case "stdin-input":
								if (isset($this->inputRes)) {
									$oldInputRes = $this->inputRes;
									$inputResError = 1;
								}
								$this->inputRes = "php://stdin";
								if (isset($inputResError)) {
									$this->err(
										"You can only provide one input resource!\n".
										"Parsed input resources: ".json_encode(
											[$oldInputRes, $this->inputRes], 
											64
										)
									);
								}
								break;

							case "timeout":
								if ($this->timeout !== -1) {
									$oldTimeout = $this->timeout;
									$timeoutResError = 1;
								}

								if (isset($m[2])) {
									$this->timeout = $m[2] = trim($m[2]);
									if (empty($m[2])) {
										$this->err(
											"Detected an empty string on timeout value"
										);
									}
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
										"Parsed timeout values: ".json_encode(
											[$oldInputRes, $this->inputRes],
											64
										)
									);
								}

								if (
									!is_numeric($this->timeout) ||
									preg_match("/[^0-9]/Usi", $this->timeout)
								) {
									$this->err(
										"The timeout value must be an integer and more than -1!\n".
										"Parsed timeout values: \"{$this->timeout}\""
									);
								}

								$this->timeout = (int)$this->timeout;
								break;

							case "output":
								if (isset($m[2])) {
									$this->outputRes[] = $m[2] = trim($m[2]);
									if (empty($m[2])) {
										$this->err(
											"Detected an empty string on output value"
										);
									}
								} else {
									if (
										isset($this->argv[$k + 1]) && 
										$this->argv[$k + 1][0] !== "-"
									) {
										$this->outputRes[] = $this->argv[$k + 1];
									} else {
										$this->err("--output option needs a value");
									}
									$tSkip = true;
								}
								break;
							case "input":
								if (isset($this->inputRes)) {
									$oldInputRes = $this->inputRes;
									$inputResError = 1;
								}

								if (isset($m[2])) {
									$this->inputRes = $m[2] = trim($m[2]);
									if (empty($m[2])) {
										$this->err(
											"Detected an empty string on input value"
										);
									}
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
										"Parsed input resources: ".json_encode(
											[$oldInputRes, $this->inputRes],
											64
										)
									);
								}
								break;
							default:
								$this->err("Invalid option --{$m[0]}");
								break;
						}
					} else {
						$this->err("Invalid argv {$v}");
					}
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
					} else if ($v[1] === "i") {
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
								"Parsed input resources: ".json_encode(
									[$oldInputRes, $this->inputRes],
									64
								)
							);
						}
					} else if ($v[1] === "t") {
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
								"Parsed timeout values: ".json_encode(
									[$oldInputRes, $this->inputRes],
									64
								)
							);
						}

						if (
							!is_numeric($this->timeout) ||
							preg_match("/[^0-9]/Usi", $this->timeout)
						) {
							$this->err(
								"The timeout value must be an integer and more than -1!\n".
								"Parsed timeout values: \"{$this->timeout}\""
							);
						}

						$this->timeout = (int)$this->timeout;
					} else {
						$this->err("Invalid option -{$v[1]}");
					}
				}
			} else {
				if (isset($this->cmd)) {
					$this->err(
						"You can only provide one command!\n".
						"Parsed commands: ".json_encode([$this->cmd, $v], 64)
					);
				}
				$this->cmd = $v;
			}
		}

		if (count($this->outputRes) === 0) {
			$this->err("You need to provide at least one output resource!");
		}

		if (!isset($this->inputRes)) {
			$this->err("You need to provide an input resource!");
		}

		if (!is_string($this->cmd)) {
			$this->err("Command not is defined");
		}

		if ($this->timeout === -1) {
			$res = new TeaAI($this->cmd);
			$res->setFullname($this->name);
			$res->setNickname($this->name);
			$handle = fopen($this->inputRes, "r");
			$res->setInput(fread($handle, 4096));
			fclose($handle);
			print $res->run();
		}

		//	else {
		// 	pcntl_signal(SIGCHLD, SIG_IGN);
		// 	$pid = pcntl_fork();
		// 	$key = ftok(__FILE__, 'd');
		// 	if ($pid === 0) {
		// 		print("The child is started its execution\n");
		// 		sleep(3);
		// 		// $res = new TeaAI($this->cmd);
		// 		// $handle = fopen($this->inputRes, "r");
		// 		// $res->setInput(fread($handle, 4096));
		// 		// fclose($handle);
		// 		// $shm = shmop_open($key, "c", 0644, 4096);
		// 		// shmop_write($shm, $res->run(), 0);
		// 		// shmop_close($shm);
		// 		print("The child has finished its execution\n");
		// 		exit(2);
		// 	}
		// 	$status = null;
		// 	$i = 0;
		// 	while (true) {
		// 		sleep(1);
		// 		$i++;
		// 		pcntl_waitpid($pid, $status, WNOHANG);
		// 		var_dump($status);
		// 		if ($i == $this->timeout) {
		// 			// Send SIGKILL to child process.
		// 			shell_exec("kill -9 {$pid}");
		// 			print("Timeout\n");
		// 			exit(0);
		// 		} else if ($status === 0) {
		// 			//break;
		// 		}
		// 	}
		// 	$shm = shmop_open($key, "c", 0644, 4096);
		// 	$res = shmop_read($shm, 0, 4096);
		// 	shmop_delete($shm);
		// 	shmop_close($shm);
		// 	print($res);
		// }
	}

	/**
	 * @param string $str
	 * @return void
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
		fprintf(STDERR, "\t--name\t\t\tSet name\n");

		// Coming soon
		// fprintf(STDERR, "\t--argv-input <string>\tRead the input from <string>.\n");

		fprintf(STDERR, "\t-t <int>\t\tLimit the AI execution time in seconds.\n");
		fprintf(STDERR, "\t--timeout <int>\t\tLimit the AI execution time in seconds.\n");
		exit(1);
	}
}
