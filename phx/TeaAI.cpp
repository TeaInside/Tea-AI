

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
			this->patterns = nullptr;
			this->responses = nullptr;

			return true;
		} else {
			free(this->patterns[i]);
			free(this->responses[i]);
			this->patterns[i] = nullptr;
			this->responses[i] = nullptr;
		}
	}
	return false;
}

void TeaAI::setName(std::string fullname, std::string nickname) {
	this->fullname = fullname;
	this->nickname = nickname;
}

std::string TeaAI::getResponseResult() {

	std::vector<std::string> r1;
	std::vector<std::string> r2;	

	r1.push_back(std::string("{name}"));
	r2.push_back(std::string(this->fullname));

	r1.push_back(std::string("{cname}"));
	r2.push_back(std::string(this->nickname));

	return Php::call(
		"str_replace",
		r1,
		r2,
		this->responseResult
	);
}

Php::Value tea_ai_chat(Php::Parameters &p) {

	TeaAI *t = new TeaAI;
	t->setName(p[1], p[2]);

	if (t->check(p[0])) {
		return t->getResponseResult();
	} else {
		return nullptr;
	}
}
