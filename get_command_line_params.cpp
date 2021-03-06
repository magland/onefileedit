#include "get_command_line_params.h"

QVariant clp_string_to_variant(const QString &str);

CLParams get_command_line_params(int argc,char *argv[]) {
	CLParams ret;
	ret.success=true; //let's be optimistic!

	//find the named and unnamed parameters checking for errors along the way
	for (int i=1; i<argc; i++) {
		QString str=QString(argv[i]);
		if (str.startsWith("--")) {
			int ind2=str.indexOf("=");
			QString name=str.mid(2,ind2-2);
			QString val="";
			if (ind2>=0) val=str.mid(ind2+1);
			if (name.isEmpty()) {
				ret.success=false;
				ret.error_message="Problem with parameter: "+str;
				return ret;
			}
			ret.named_parameters[name]=clp_string_to_variant(val);
		}
		else {
			ret.unnamed_parameters << str;
		}
	}

	//we did it!
	return ret;
}

bool clp_is_int(const QString &str) {
	bool ok;
	str.toInt(&ok);
	return ok;
}

bool clp_is_float(const QString &str) {
	bool ok;
	str.toFloat(&ok);
	return ok;
}

QVariant clp_string_to_variant(const QString &str) {
	if (clp_is_int(str)) return str.toInt();
	if (clp_is_float(str)) return str.toFloat();
	return str;
}
