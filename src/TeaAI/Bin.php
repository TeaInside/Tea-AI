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
		$this->argv = array_shift($_SERVER["argv"]);
	}

	/**
	 * @return void
	 */
	public function run(): void
	{

	}
}
