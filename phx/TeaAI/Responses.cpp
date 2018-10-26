
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
	int i = 0;
	int unixtime = (int)Php::call("time");
	this->h = atoi(Php::call("date", "H"));
	this->patterns = (char**)malloc(R_SIZE * sizeof(char*));
	this->responses = (char***)malloc(R_SIZE * sizeof(char*));
	this->responseOffsetD2 = (int*)malloc(R_SIZE * sizeof(int*));
	this->zeroFill();

	this->setPattern(
		"/(?:^|.{0.10}[\\t\\s\\n]{1,})(a?pa?)(?:[\\t\\s\\n]*)(ka?ba?r)(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$)/Usi"
	);
	this->setResponse(i, "Kabar baik");
	this->setResponse(i, "Baik {cname}");
	i++;


	this->setPattern(
		"/(?:^|.{0,4}[\\t\\s\\n]{1,})(h{1,2}(a|e){1,4}l{1,4}o{1,4})(?:[\\t\\s\\n]{1,}.{0,20}|$)/Usi"
	);
	this->setResponse(i, "Halo {name}");
	this->setResponse(i, "Halo juga {name}");
	this->setResponse(i, "Halo juga {name}, apa kabar?");
	i++;


	this->setPattern(
		"/(?:^|.{0,4}[\\t\\s\\n]{1,})(h{1,4}a{1,4}(i|e){1,4})(?:[\\t\\s\\n]{1,}.{0,20}|$)/Usi"
	);
	this->setResponse(i, "Hai {name}");
	this->setResponse(i, "Hai juga {name}");
	this->setResponse(i, "Hai juga {name}, apa kabar?");
	i++;


	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n]{1,})(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(pa?gi?)([\\!]*)?(?:[\\t\\s\\n]{1,}.{0,7}|$)/Usi"
	);
	if (this->iRange(0, 11)) {
		this->setResponse(i, "Selamat pagi!");
		this->setResponse(i, "Selamat pagi {name}, apa kabar?");
		this->setResponse(i, "Selamat pagi juga {cname}");
	} else if (this->iRange(12, 14)) {
		this->setResponse(i, "Ini sudah siang {cname}");
		this->setResponse(i, "Selamat siang, selamat beraktifitas!");
		this->setResponse(i, "Selamat siang!");
	} else if (this->iRange(15, 18)) {
		this->setResponse(i, "Ini sudah sore {cname}");
		this->setResponse(i, "Selamat sore!");
		this->setResponse(i, "Sore {cname}");
	} else {
		this->setResponse(i, "Ini sudah malam {cname}");
		this->setResponse(i, "Selamat malam, selamat beristirahat");
		this->setResponse(i, "Malam {cname}");
	}
	i++;

	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n]{1,})(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(siang)([\\!]*)?(?:[\\t\\s\\n]{1,}.{0,7}|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(i, "Ini masih pagi {cname}");
		this->setResponse(i, "Selamat pagi!");
		this->setResponse(i, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(i, "Selamat siang!");
		this->setResponse(i, "Selamat siang {name}, apa kabar?");
		this->setResponse(i, "Selamat siang juga {cname}");
	} else if (this->iRange(15, 18)){
		this->setResponse(i, "Ini sudah sore {cname}");
		this->setResponse(i, "Selamat sore!");
		this->setResponse(i, "Sore {cname}");
	} else {
		this->setResponse(i, "Ini sudah malam {cname}");
		this->setResponse(i, "Selamat malam!");
		this->setResponse(i, "Malam {cname}");
	}
	i++;

	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n]{1,})(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(sore)([\\!]*)?(?:[\\t\\s\\n]{1,}.{0,7}|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(i, "Ini masih pagi {cname}");
		this->setResponse(i, "Selamat pagi!");
		this->setResponse(i, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(i, "Ini masih siang {cname}");
		this->setResponse(i, "Selamat siang, selamat beraktifitas!");
		this->setResponse(i, "Selamat siang!");
	} else if (this->iRange(15, 18)){
		this->setResponse(i, "Selamat sore!");
		this->setResponse(i, "Selamat sore {name}, apa kabar?");
		this->setResponse(i, "Selamat sore juga {cname}");
	} else {
		this->setResponse(i, "Ini sudah malam {cname}");
		this->setResponse(i, "Selamat malam!");
		this->setResponse(i, "Malam {cname}");
	}
	i++;

	this->setPattern(
		"/(?:^|.{0,7}[\\t\\s\\n])(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(ma?l(a|e)?m)([\\!]*)?(?:[\\t\\s\\n].{0,7}|$)/Usi"
	);
	if (this->iRange(0, 10)) {
		this->setResponse(i, "Ini sudah pagi {cname}");
		this->setResponse(i, "Selamat pagi!");
		this->setResponse(i, "Pagi {cname}");
	} else if (this->iRange(11, 14)) {
		this->setResponse(i, "Ini masih siang {cname}");
		this->setResponse(i, "Selamat siang, selamat beraktifitas!");
		this->setResponse(i, "Selamat siang!");
	} else if (this->iRange(15, 18)){
		this->setResponse(i, "Ini masih sore {cname}");
		this->setResponse(i, "Selamat sore!");
		this->setResponse(i, "Sore {cname}");
	} else {
		this->setResponse(i, "Selamat malam!");
		this->setResponse(i, "Selamat malam {cname}, apa kabar?");
		this->setResponse(i, "Selamat malam juga {cname}");	
	}
	i++;


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(b(e|3)?s(o|0)?k?)(?:[\\t\\s\\n]*)(itu?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(b(e|3)?s(o|0)?k?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Besok adalah hari "+this->getDay(unixtime+(3600*24))).c_str());
	i++;

	this->setPattern(
		"/((?:^|[\\t\\s\\n])(k(e|3)?m(a|4)?r(i|1)?n?)(?:[\\t\\s\\n]*)(itu?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(k(e|3)?m(a|4)?r(i|1)?n?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Kemarin adalah hari "+this->getDay(unixtime-(3600*24))).c_str());
	i++;

	this->setPattern(
		"/((?:^|[\\t\\s\\n])((s(e|3)?k(a|4)?r(a|4)?ng|(i|1)n(i|1))?(?:[\\t\\s\\n]*)(itu?)?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\?]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?ng|(i|1)n(i|1))?([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Sekarang hari "+this->getDay(unixtime)).c_str());
	i++;

	this->setPattern(
		"/((?:^|[\\t\\s\\n])(s(e|3)?k(a|4)?r(a|4)?n?g?)(?:[\\t\\s\\n]*)(j(a|4)?m)(?:[\\t\\s\\n]*)(b?(e|3)?r(a|4)?p?(a|4)?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(j(a|4)?m)(?:[\\t\\s\\n]*)(b?(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?n?g?)([\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Sekarang jam "+this->phpDate("h:i:s A T", unixtime)).c_str());
	i++;


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(b?(e|3)?s(o|0)?k)(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(b?(e|3)?s(o|0)?k)(?:[\\t\\s\\n]*)(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Besok adalah tanggal "+this->phpDate("d F Y", unixtime+(3600*24))).c_str());
	i++;


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(k(e|3)?m(a|4)?r(i|1)?n)(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(k(e|3)?m(a|4)?r(i|1)?n)(?:[\\t\\s\\n]*)(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Kemarin adalah tanggal "+this->phpDate("d F Y", unixtime-(3600*24))).c_str());
	i++;


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?n?(g|6)?|(i|1)n(i|1))(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(s(e|3)?k(a|4)?r(a|4)?n?(g|6)?|(i|1)n(i|1))(?:[\\t\\s\\n]*)(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\w\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Sekarang tanggal "+this->phpDate("d F Y", unixtime)).c_str());
	i++;

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
