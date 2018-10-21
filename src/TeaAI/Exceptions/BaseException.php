<?php

namespace TeaAI\Exceptions;

use Exception;

/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license MIT
 * @package \TeaAI\Exceptions
 * @version 0.0.1
 */
class BaseException extends Exception
{
	/**
	 * @param string $format
	 * @param mixed  $args
	 *
	 * Constructor.
	 */
	public function __construct(string $format, ...$args)
	{
		parent::__construct(sprintf($format, ...$args));
	}
}
