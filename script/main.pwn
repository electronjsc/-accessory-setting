#define FILTERSCRIPT

#include "a_samp.inc"
#include "sscanf2.inc"
#include "dc_cmd.inc"
#include "mdialog.inc"
#include "mxINI.inc"

#define FILTERSCRIPT

public OnFilterScriptInit() {
	printf("---------------------------------");
	printf("| Accessory Setting script loaded |");
	printf("| Author: James                   |");
	printf("--------------------------------");
	return true;
}

#include "module\main.inc"


#undef FILTERSCRIPT