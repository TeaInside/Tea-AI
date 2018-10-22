#include <phpcpp.h>

#include "headers/TeaAI.h"

extern "C" {
    PHPCPP_EXPORT void *get_module() {
        static Php::Extension extension("teaai", "1.0");
        extension.add<rd>("rd");
        return extension;
    }
}
