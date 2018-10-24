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
	 * @var string
	 */
	private $cmd = null;

	/**
	 * @var string 
	 */
	private $input;

	/**
	 * @var string
	 */
	private $fullname;

	/**
	 * @var string
	 */
	private $nickname;

	/**
	 * @param string $cmd
	 *
	 * Constructor.
	 */
	public function __construct(string $cmd)
	{
		$this->cmd = $cmd;
	}

	/**
	 * @param string $input
	 * @return void
	 */
	public function setInput(string $input): void
	{
		$this->input = $input;
	}

	/**
	 * @param string $fullname
	 * @return void
	 */
	public function setFullname(string $fullname): void
	{
		$this->fullname = $fullname;
	}

	/**
	 * @param string $nickname
	 * @return void
	 */
	public function setNickname(string $nickname): void
	{
		$this->nickname = $nickname;
	}

	/**
	 * @return mixed
	 */
	public function run()
	{
		$n1 = is_null($this->nickname);
		$n2 = is_null($this->fullname);

		if ($n1 && $n2) {
			$this->fullname = $this->nickname = "User";
		} else if ($n2) {
			$this->fullname = $this->nickname;
		} else if ($n1) {
			$this->nickname = $this->fullname;
		}

		switch ($this->cmd) {
			case "calc":
				$this->calc();
				return;
				break;
			case "chat":
				return tea_ai_chat(
					$this->input,
					$this->fullname,
					$this->nickname
				);
				break;
			default:
				break;
		}
	}
}
