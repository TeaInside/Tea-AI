#include "headers/TeaAI.h"
#include "TeaLib/TeaPCRE.h"

TeaAI::TeaAI() {
	this->buildPattern();
	this->buildResponses();
}

TeaAI::~TeaAI() {

}

int match(Php::Value pat, Php::Value txt) {
	return Php::call("preg_match", pat, txt);
}

bool TeaAI::check(Php::Value txt) {
	for (int i = 0; i < this->patternOffset; ++i) {
		printf("%s\n", this->patterns[i]);
		std::string pat(this->patterns[i], strlen(this->patterns[i]));
		if (match(pat, txt)) {
			printf("Match!\nGot response: %s", this->responses[i][0]);
		}
	}
}


Php::Value tea_ai_chat(Php::Parameters &p) {
	
	TeaAI *t = new TeaAI;
	t->check(p[0]);
}
