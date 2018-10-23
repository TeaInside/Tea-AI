

#include "headers/TeaAI.h"
#include "TeaLib/TeaPCRE.h"

TeaAI::TeaAI() {
	this->buildResponses();
}

TeaAI::~TeaAI() {

}

bool TeaAI::check(Php::Value txt) {
	for (int i = 0; i < this->patternOffset; ++i) {
		if (Php::call("preg_match", this->patterns[i], txt)) {
			int offsetResult = Php::call("rand", 0, this->responseOffsetD2[i] - 1);

			this->responseResult = (char*)malloc(
				strlen(this->responses[i][offsetResult]) * sizeof(char*)
			);
			strcpy(this->responseResult, this->responses[i][offsetResult]);
			
			free(this->patterns);
			free(this->responses);

			return true;
		} else {
			free(this->patterns[i]);
			free(this->responses[i]);
		}
	}
	return false;
}

std::string TeaAI::getResponseResult() {

	std::vector<std::string> r1;
	std::vector<std::string> r2;
	
	std::string _r1[] = {
		"{cname}"
	};

	std::string _r2[] = {
		"mar"
	};

	r1.insert(r1.begin(), _r1, _r1+1);
	r2.insert(r2.begin(), _r2, _r2+1);

	return Php::call(
		"str_replace",
		r1,
		r2,
		this->responseResult
	);
}

Php::Value tea_ai_chat(Php::Parameters &p) {
	TeaAI *t = new TeaAI;
	if (t->check(p[0])) {
		return t->getResponseResult();
	} else {
		return nullptr;
	}
}
