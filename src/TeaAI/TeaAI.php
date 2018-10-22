<?php

namespace TeaAI;

/**
 * TeaAI class file.
 *
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license MIT
 * @package \TeaAI
 * @version 0.0.1
 */
final class TeaAI
{
	/**
	 * @param string $cmd
	 */
	private $cmd = null;

	/**
	 * Constructor.
	 */
	public function __construct(string $cmd)
	{
		$this->cmd = $cmd;
	}

	/**
	 * @return void
	 */
	public function run(): void
	{
		switch ($this->cmd) {
			case "calc":
				$this->calc();
				return;
				break;
			case "chat":
				tea_ai_chat("selamat pagi");
				break;
			default:
				break;
		}
	}
}
