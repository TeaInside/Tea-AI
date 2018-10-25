
#include "../headers/TeaAI.h"

void TeaAI::setPattern(const char* pat, int maxLen = -1) {
	this->patterns[this->patternOffset] = (char*)malloc(strlen(pat) * sizeof(char*));
	strcpy(this->patterns[this->patternOffset++], pat);
}

void TeaAI::setResponse(int offset, const char *res) {
	if (this->responseOffsetD2[offset] == 0) {
		this->responses[offset] = (char**)malloc(5 * sizeof(char*));
	}
	this->responses[offset][this->responseOffsetD2[offset]] = (char*)malloc(strlen(res) * sizeof(char*));
	strcpy(this->responses[offset][this->responseOffsetD2[offset]++], res);
}

void TeaAI::zeroFill() {
	for (int i = 0; i < R_SIZE; ++i) {
		this->responseOffsetD2[i] = 0;
	}
}

bool TeaAI::iRange(int start, int end) {
	return this->h >= start && this->h <= end;
}

void TeaAI::buildResponses() {
	int unixtime = (int)Php::call("time");
	this->h = atoi(Php::call("date", "H"));
	this->patterns = (char**)malloc(R_SIZE * sizeof(char*));
	this->responses = (char***)malloc(R_SIZE * sizeof(char*));
	this->responseOffsetD2 = (int*)malloc(R_SIZE * sizeof(int*));
	this->zeroFill();


	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n]{1,})(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(pa?gi?)([\\!]*)?(?:[\\t\\s\\n]{1,}.{0,7}|$)/Usi"
	);
	if (this->iRange(0, 11)) {
		this->setResponse(0, "Selamat pagi!");
		this->setResponse(0, "Selamat pagi {name}, apa kabar?");
		this->setResponse(0, "Selamat pagi juga {cname}");
	} else if (this->iRange(12, 14)) {
		this->setResponse(0, "Ini sudah siang {cname}");
		this->setResponse(0, "Selamat siang, selamat beraktifitas!");
		this->setResponse(0, "Selamat siang!");
	} else if (this->iRange(15, 18)) {
		this->setResponse(0, "Ini sudah sore {cname}");
		this->setResponse(0, "Selamat sore!");
		this->setResponse(0, "Sore {cname}");
	} else {
		this->setResponse(0, "Ini sudah malam {cname}");
		this->setResponse(0, "Selamat malam, selamat beristirahat");
		this->setResponse(0, "Malam {cname}");
	}

	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n]{1,})(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(siang)([\\!]*)?(?:[\\t\\s\\n]{1,}.{0,7}|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(1, "Ini masih pagi {cname}");
		this->setResponse(1, "Selamat pagi!");
		this->setResponse(1, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(1, "Selamat siang!");
		this->setResponse(1, "Selamat siang {name}, apa kabar?");
		this->setResponse(1, "Selamat siang juga {cname}");
	} else if (this->iRange(15, 18)){
		this->setResponse(1, "Ini sudah sore {cname}");
		this->setResponse(1, "Selamat sore!");
		this->setResponse(1, "Sore {cname}");
	} else {
		this->setResponse(1, "Ini sudah malam {cname}");
		this->setResponse(1, "Selamat malam!");
		this->setResponse(1, "Malam {cname}");
	}

	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n]{1,})(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(sore)([\\!]*)?(?:[\\t\\s\\n]{1,}.{0,7}|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(2, "Ini masih pagi {cname}");
		this->setResponse(2, "Selamat pagi!");
		this->setResponse(2, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(2, "Ini masih siang {cname}");
		this->setResponse(2, "Selamat siang, selamat beraktifitas!");
		this->setResponse(2, "Selamat siang!");
	} else if (this->iRange(15, 18)){
		this->setResponse(2, "Selamat sore!");
		this->setResponse(2, "Selamat sore {name}, apa kabar?");
		this->setResponse(2, "Selamat sore juga {cname}");
	} else {
		this->setResponse(2, "Ini sudah malam {cname}");
		this->setResponse(2, "Selamat malam!");
		this->setResponse(2, "Malam {cname}");
	}

	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n])(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(ma?l(a|e)?m)([\\!]*)?(?:[\\t\\s\\n].{0,7}|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(3, "Ini sudah pagi {cname}");
		this->setResponse(3, "Selamat pagi!");
		this->setResponse(3, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(3, "Ini masih siang {cname}");
		this->setResponse(3, "Selamat siang, selamat beraktifitas!");
		this->setResponse(3, "Selamat siang!");
	} else if (this->iRange(15, 18)){
		this->setResponse(3, "Ini masih sore {cname}");
		this->setResponse(3, "Selamat sore!");
		this->setResponse(3, "Sore {cname}");
	} else {
		this->setResponse(3, "Selamat malam!");
		this->setResponse(3, "Selamat malam {cname}, apa kabar?");
		this->setResponse(3, "Selamat malam juga {cname}");	
	}


	this->setPattern(
<<<<<<< HEAD
		"/((?:^|[\\t\\s\\n])(b(e|3)?s(o|0)?k?)(?:[\\t\\s\\n]*)(itu?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(b(e|3)?s(o|0)?k?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
=======
		"/((?:^|[\\t\\s\n])(b?e?so?k?)(?:[\\t\\s\\n]*)(itu?)?(?:[\\t\\s\\n]*)(ha?ri?(nya?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\?\\.]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(b?e?so?k?)([\\?\\.]*)?(?:[\\t\\s\\n]|$))/Usi"
>>>>>>> master
	);
	this->setResponse(4, std::string("Besok adalah hari "+this->getDay(unixtime+(3600*24))).c_str());


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(k(e|3)?m(a|4)?r(i|1)?n?)(?:[\\t\\s\\n]*)(itu?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(k(e|3)?m(a|4)?r(i|1)?n?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(5, std::string("Kemarin adalah hari "+this->getDay(unixtime-(3600*24))).c_str());


	this->setPattern(
		"/((?:^|[\\t\\s\\n])((s(e|3)?k(a|4)?r(a|4)?ng|(i|1)n(i|1))?(?:[\\t\\s\\n]*)(itu?)?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\?]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?ng|(i|1)n(i|1))?([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(6, std::string("Sekarang hari "+this->getDay(unixtime)).c_str());


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(s(e|3)?k(a|4)?r(a|4)?n?g?)(?:[\\t\\s\\n]*)(j(a|4)?m)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(j(a|4)?m)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?n?g?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(7, std::string("Sekarang jam "+this->phpDate("h:i:s A T", unixtime)).c_str());


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?n?(g|6)?|(i|1)n(i|1))(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(s(e|3)?k(a|4)?r(a|4)?n?(g|6)?|(i|1)n(i|1))(?:[\\t\\s\\n]*)(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(8, std::string("Sekarang tanggal "+this->phpDate("d F Y", unixtime)).c_str());


	this->setPattern(
		"/(?:^|.{0,4}[\\t\\s\\n]{1,})(h{1,2}(a|e){1,4}l{1,4}o{1,4})(?:[\\t\\s\\n]{1,}.{0,20}|$)/Usi"
	);
	this->setResponse(9, "Halo {name}");
	this->setResponse(9, "Halo juga {name}");
	this->setResponse(9, "Halo juga {name}, apa kabar?");


	this->setPattern(
		"/(?:^|.{0,4}[\\t\\s\\n]{1,})(h{1,4}a{1,4}(i|e){1,4})(?:[\\t\\s\\n]{1,}.{0,20}|$)/Usi"
	);
	this->setResponse(10, "Hai {name}");
	this->setResponse(10, "Hai juga {name}");
	this->setResponse(10, "Hai juga {name}, apa kabar?");
}

std::string TeaAI::phpDate(const char *format, int unixtime) {
	return Php::call("date", format, unixtime);
}

std::string TeaAI::getDay(int unixtime) {
	switch (atoi(Php::call("date", "N", unixtime))) {
		case 1:
			return "Senin";
		case 2:
			return "Selasa";
		case 3:
			return "Rabu";
		case 4:
			return "Kamis";
		case 5:
			return "Jumat";
		case 6:
			return "Sabtu";
		case 7:
			return "Minggu";
		default:
			return "(null)";
	}
}