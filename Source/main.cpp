#include <unistd.h>
#include <switch.h>
#include <iostream>
#include <string>
#include <errno.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include "applet.hpp"

AccountUid uid;

std::string urlc = "https://myrincon.duckdns.org";
//MAIN INT
int main(int argc, char **argv)
{
	romfsInit();
	socketInitializeDefault();
	Result rc = 0;
	rc =  accountInitialize(AccountServiceType_Application);
	if (R_SUCCEEDED(rc)) {
		//accountGetServiceSession ();
		accountGetPreselectedUser(&uid);
		printf("Goted user\n");
		accountExit();
	} else printf("failed tu get user \n");
	GetAppletMode();
	
	while(appletMainLoop()){
		WebBrowserCall(urlc,true);
		if (urlc == ""){break;}
	}
	accountExit();
	hidsysExit();
	socketExit();
	romfsExit();


	return 0;
}