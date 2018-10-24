#include <phpcpp.h>

#include "headers/TeaAI.h"

extern "C" {
    PHPCPP_EXPORT void *get_module() {
        static Php::Extension extension("teaai", "1.0");
        extension.add<tea_ai_chat>("tea_ai_chat", {
        	Php::ByVal("text", Php::Type::String),
        	Php::ByVal("full_name", Php::Type::String),
        	Php::ByVal("nick_name", Php::Type::String)
        });
        return extension;
    }
}
