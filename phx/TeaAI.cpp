

#include "headers/TeaAI.h"
#include "TeaLib/TeaPCRE.h"

TeaAI::TeaAI() {
	this->buildResponses();
}

TeaAI::~TeaAI() {

}

int match(Php::Value pat, Php::Value txt) {
	return Php::call("preg_match", pat, txt);
}

int rand(int low, int high) {
	return Php::call("rand", low, high);
}

bool TeaAI::check(Php::Value txt) {
	for (int i = 0; i < this->patternOffset; ++i) {
		if (match(this->patterns[i], txt)) {
			int offsetResult = rand(0, this->responseOffsetD2[i] - 1);
			this->responseResult = (char*)malloc(strlen(this->responses[i][offsetResult]) * sizeof(char*));
			strcpy(this->responseResult, this->responses[i][offsetResult]);
			return true;
		}
	}
	return false;
}

std::string TeaAI::getResponseResult() {
	return (std::string)this->responseResult;
}

Php::Value tea_ai_chat(Php::Parameters &p) {
	TeaAI *t = new TeaAI;
	t->check(p[0]);
	return t->getResponseResult();
}
