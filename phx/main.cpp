
#include <phpcpp.h>
#include <iostream>
#include "headers/teacrypt_php_function.h"

extern "C" {
	PHPCPP_EXPORT void *get_module() {
		
		static Php::Extension extension("teaai", "1.0");
		
		// extension.add<teaEncrypt>("teaEncrypt", {
		// 	Php::ByVal("data", Php::Type::String),
		// 	Php::ByVal("key", Php::Type::String)
		// });

		// extension.add<teaDecrypt>("teaDecrypt", {
		// 	Php::ByVal("data", Php::Type::String),
		// 	Php::ByVal("key", Php::Type::String)			
		// });

		return extension;
	}
}
