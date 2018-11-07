
#include "../headers/TeaAI.h"

void TeaAI::setPattern(const char* pat) {
	this->patterns[this->patternOffset] = (char*)malloc(strlen(pat) * sizeof(char*));
	strcpy(this->patterns[this->patternOffset++], pat);	
}

void TeaAI::setResponse(int offset, const char *res, int rep = 1) {
	if (this->responseOffsetD2[offset] == 0) {
		this->responses[offset] = (char**)malloc(5 * sizeof(char*));
	}
	for (int i = 0; i < rep; ++i)
	{
		this->responses[offset][this->responseOffsetD2[offset]] = (char*)malloc(strlen(res) * sizeof(char*));
		strcpy(this->responses[offset][this->responseOffsetD2[offset]++], res);	
	}
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
		"/(?:^|.{0,7}[\\t\\s\\n]{1,})(se?la?ma?t|met|mat)(?:[\\t\\s\\n]*)(pa?gi?)([\\W]*)(?:[\\t\\s\\n]{1,}.{0,7}|$)/Usi"
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
		"/((?:^|[\\t\\s\\n])(b(e|3)?s(o|0)?k?)(?:[\\t\\s\\n]*)(itu?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(b(e|3)?s(o|0)?k?)([\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Besok adalah hari "+this->getDay(unixtime+(3600*24))).c_str());
	i++;

	this->setPattern(
		"/((?:^|[\\t\\s\\n])(k(e|3)?m(a|4)?r(i|1)?n?)(?:[\\t\\s\\n]*)(itu?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)([\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?)(?:[\\t\\s\\n]*)(k(e|3)?m(a|4)?r(i|1)?n?)([\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Kemarin adalah hari "+this->getDay(unixtime-(3600*24))).c_str());
	i++;

	this->setPattern(
		"/((?:^|^.{0,20}[\\t\\s\\n]+)(ha?ri?)(?:[\\t\\s\\n]*)(a?pa?(an)?)(?:[\\t\\s\\n]*)(i?ni?)(?:\\?*[\\t\\s\\n]+.{0,20}$|$))|((?:^|^.{0,20}[\\t\\s\\n]+)(i?ni?)(?:[\\t\\s\\n]*)(ha?ri?)(?:[\\t\\s\\n]*)(a?pa?(an)?)(?:\\?*[\\t\\s\\n]+.{0,20}$|$))|((?:^|[\\t\\s\\n])((s(e|3)?k(a|4)?r(a|4)?ng|(i|1)n(i|1))?(?:[\\t\\s\\n]*)(itu?)?)?(?:[\\t\\s\\n]*)(h(a|4)?r(i|1)?(ny(a|4)?)?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?(an)?)([\\?]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(ha?ri?)(?:[\\t\\s\\n]*)((o|a|i)p(o|a|i)?(ap)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?ng|(i|1)n(i|1))?([\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Sekarang hari "+this->getDay(unixtime)).c_str());
	i++;

	this->setPattern(
		"/((?:^|[\\t\\s\\n])(s(e|3)?k(a|4)?r(a|4)?n?g?)(?:[\\t\\s\\n]*)(j(a|4)?m)(?:[\\t\\s\\n]*)(b?(e|3)?r(a|4)?p?(a|4)?)([\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(j(a|4)?m)(?:[\\t\\s\\n]*)(b?(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?n?g?)([\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Sekarang jam "+this->phpDate("h:i:s A T", unixtime)).c_str());
	i++;


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(b?(e|3)?s(o|0)?k)(?:[\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(b?(e|3)?s(o|0)?k)(?:[\\t\\s\\n]*)(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Besok adalah tanggal "+this->phpDate("d F Y", unixtime+(3600*24))).c_str());
	i++;


	this->setPattern(
		"/((?:^|[\\t\\s\\n])(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(k(e|3)?m(a|4)?r(i|1)?n)(?:[\\W]*)?(?:[\\t\\s\\n]|$))|((?:^|[\\t\\s\\n])(k(e|3)?m(a|4)?r(i|1)?n)(?:[\\t\\s\\n]*)(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\W]*)?(?:[\\t\\s\\n]|$))/Usi"
	);
	this->setResponse(i, std::string("Kemarin adalah tanggal "+this->phpDate("d F Y", unixtime-(3600*24))).c_str());
	i++;


	this->setPattern(
		"/((?:^|^.{1,15}[\\t\\s\\n])(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\t\\s\\n]*)(s(e|3)?k(a|4)?r(a|4)?n?(g|6)?|(i|1)n(i|1))(?:[\\W]*)?(?:[\\t\\s\\n].{1,10}$|$))|((?:^|^.{1,15}[\\t\\s\\n])(s(e|3)?k(a|4)?r(a|4)?n?(g|6)?|(i|1)n(i|1))(?:[\\t\\s\\n]*)(t(a|4)?n?(g|6)?(g|6)(a|4)?l)(?:[\\t\\s\\n]*)(b(e|3)?r(a|4)?p?(a|4)?)(?:[\\W]*)?(?:[\\t\\s\\n].{1,10}$|$))/Usi"
	);
	this->setResponse(i, std::string("Sekarang tanggal "+this->phpDate("d F Y", unixtime)).c_str());
	i++;


	this->setPattern(
		"/((?:^|.{0,20}[\\t\\s\\n]+)(se?ka?ra?ng?)(?:[\\t\\s\\n]*)(bu?la?n?)(?:[\\t\\s\\n]*)(a?pa?(an)?)(?:\\?*[\\t\\s\\n]+.{0,20}$|$))|((?:^|.{0,20}[\\t\\s\\n]+)(bu?la?n?)(?:[\\t\\s\\n]*)(a?pa?(an)?)(?:[\\t\\s\\n]*)(se?ka?ra?ng?)(?:\\?*[\\t\\s\\n]+.{0,20}$|$))|((?:^|^.{0,20}[\\t\\s\\n]+)(bu?la?n?)(?:[\\t\\s\\n]*)(a?pa?(an)?)(?:[\\t\\s\\n]*)(i?ni?)(?:\\?*[\\t\\s\\n]+.{0,20}$|$))|((?:^|^.{0,20}[\\t\\s\\n]+)(i?ni?)(?:[\\t\\s\\n]*)(bu?la?n?)(?:[\\t\\s\\n]*)(a?pa?(an)?)(?:\\?*[\\t\\s\\n]+.{0,20}$|$))/Usi"
	);
	this->setResponse(i, std::string("Sekarang bulan "+this->phpDate("F", unixtime)).c_str());
	i++;


	this->setPattern(
		"/(?:^|^.{0,20}[\\t\\s\\n]*)(se?la?ma?t)(?:[\\t\\s\\n]+)(ma?ka?n)(?:[\\t\\s\\n]*.{0,20}$|$)/Usi"
	);
	this->setResponse(i, "Jangan lupa kerja sebelum makan");
	i++;


	this->setPattern(
		"/(^.{0,15})((awk|awko|wk){2,}|(ha){2,}|(hi){2,}|(xi){2,})(.{0,15}$)/Usi"
	);
	this->setResponse(i, "Dilarang ketawa!");
	this->setResponse(i, "ZGVZ10get_moduleE9extension_ZZ10get_moduleE9extension_GLOBAL__sub_I_main.cpp_ZStL8__ioinit_GLOBAL__sub_I_Responses.cpp_GLOBAL__sub_I_TeaAI.cppcrtstuff.cderegister_tm_clones__do_global_dtors_auxcompleted.7696__do_global_dtors_aux_fini_array_entryframe_dummy__frame_dummy_init_array_entry__FRAME_END__DW.ref._ZTIN3Php9ExceptionE__GNU_EH_FRAME_HDR__dso_handleDW.ref.__gxx_personality_v0_DYNAMIC__TMC_END___GLOBAL_OFFSET_TABLE__ZN5TeaAI11setResponseEiPKc_ZN3Php5ValueD1Ev_ZNK3Php5Value12numericValueEvget_module_ZN3Php12ZendCallable10parametersEP18_zend_execute_data_edata_ZN5TeaAI6getDayB5cxx11Ei_ZN3Php5ValueC1EDn_ZNR3Php5Value7setTypeENS_4TypeE_ZN3Php12ZendCallable5yieldEP12_zval_structRKNS_5ValueE__cxa_begin_catch@@CXXABI_1.3_ZN3Php5ValueC1Ev__cxa_finalize@@GLIBC_2.2.5strlen@@GLIBC_2.2.5_ZNK3Php5Value11stringValueB5cxx11Ev_ZN5TeaAI5checkEN3Php5ValueE_ZN3Php5ValueC1ERKS0__ZN3Php4callIJiiEEENS_5ValueEPKcDpOT__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_@@GLIBCXX_3.4.21_ZN5TeaAID1Ev_ZN3Php9Namespace3addEPKcPFvP18_zend_execute_dataP12_zval_structERKSt16initializer_listINS_8ArgumentEE_ZN3Php5ValueC1Ei__cxa_guard_abort@@CXXABI_1.3__cxa_guard_release@@CXXABI_1.3_ZTSN3Php9ExceptionE_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3_ZSt19__throw_logic_errorPKc@@GLIBCXX_3.4_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev_finimemcpy@@GLIBC_2.14_Z11tea_ai_chatRN3Php10ParametersE_ZTVN3Php8ArgumentE__cxa_atexit@@GLIBC_2.2.5_ZN3Php9ExtensionD1Ev_ZN3Php9Extension6moduleEvstrcpy@@GLIBC_2.2.5_ZdlPv@@GLIBCXX_3.4_ZNK3Php5Value8rawValueEv_ZN3Php12ZendCallable6invokeIXadL_Z11tea_ai_chatRNS_10ParametersEEEEEvP18_zend_execute_dataP12_zval_struct_Znwm@@GLIBCXX_3.4_ZN3Php8ArgumentD1Ev__stack_chk_fail@@GLIBC_2.4_init_ZN5TeaAI10setPatternEPKc_ZN3Php8ArgumentD0Evfree@@GLIBC_2.2.5_ZN3Php5Value6setRawEiRKS0__ZN5TeaAI14buildResponsesEv_ZNK3Php5Value4execEiPS0__ZTVN10__cxxabiv120__si_class_type_infoE@@CXXABI_1.3_ZN3Php12ZendCallable6handleERNS_9ExceptionE_ZN5TeaAI8zeroFillEv_ZN5TeaAI7phpDateB5cxx11EPKcimalloc@@GLIBC_2.2.5_ZN5TeaAI17getResponseResultB5cxx11Ev_end_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED1Ev_ZN5TeaAI6iRangeEiistrtol@@GLIBC_2.2.5_ZTIN3Php8ArgumentE_ZN3Php5ValueC1EPKci_ZTSN3Php8ArgumentE_ZN3Php8ArgumentD2Ev_ZN3Php5ValueC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE_ZN3Php9ExtensionC1EPKcS2_i__bss_start_ZN5TeaAIC2Ev_ZN3Php12ZendCallable5validEP18_zend_execute_dataP12_zval_struct_ZNSt8ios_base4InitC1Ev@@GLIBCXX_3.4_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_replaceEmmPKcm@@GLIBCXX_3.4.21__cxa_end_catch@@CXXABI_1.3__gxx_personality_v0@@CXXABI_1.3_ZNK3Php5ValueclEv_ZNK3Php5Value9boolValueEv_ITM_deregisterTMCloneTable_Unwind_Resume@@GCC_3.0_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@@GLIBCXX_3.4.21__cxa_guard_acquire@@CXXABI_1.3_ZN5TeaAIC1Ev_ZN5TeaAI7setNameENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES5__ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE12emplace_backIJS5_EEEvDpOT__ZN5TeaAID2Ev_ZTISt9exception@@GLIBCXX_3.4__gmon_start___ITM_registerTMCloneTable_ZNSt8ios_base4InitD1Ev@@GLIBCXX_3.4.symtab.strtab.shstrtab.note.gnu.build-id.gnu.hash.dynsym.dynstr.gnu.version.gnu.version_r.rela.dyn.rela.plt.init.plt.got.text.fini.rodata.eh_frame_hdr.eh_frame.gcc_except_table.init_array.fini_array.data.rel.ro.dynamic.got.plt.data.bss.comment");
	i++;

	this->setPattern(
		"/(?:^|^.{0,20}[\\t\\s\\n])(laravel.{0,5})(?:[\\t\\s\\n].{0,20}|$)/Usi"
	);
	this->setResponse(i, "Hmm... Laravel, mirip nama framework yak", 2);
	this->setResponse(i, "The Laravel Framework for Web Artisans");
	this->setResponse(i, "Love beautiful code? We do to, the PHP Framework for Web Artisan");
	i++;


	this->setPattern(
		"/((?:^|.{0,20}[\\t\\s\\n])(te?ri?ma?)[\\t\\s\\n]*(ka?si?h)(?:[\\t\\s\\n]*.{0,20}|$))|((?:^|.{0,20}[\\t\\s\\n])(ma?ka?si?h)(?:[\\t\\s\\n]*.{0,20}|$))/Usi"
	);
	this->setResponse(i, "Sama-sama");
	this->setResponse(i, "Terima kasih kembali");
	i++;

	this->setPattern(
		"/(?:^|.{0.10}[\\t\\s\\n]{1,})(a?pa?(an)?)(?:[\\t\\s\\n]*)(ka?ba?r)(?:[\\W]*)?(?:[\\t\\s\\n]|$)/Usi"
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
