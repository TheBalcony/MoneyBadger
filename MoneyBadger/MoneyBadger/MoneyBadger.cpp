// MoneyBadger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/SocketAcceptor.h"
#include "quickfix/Session.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/Application.h"

//http://www.quickfixengine.org/quickfix/doc/html/application.html

int main(int argc, char** argv)
{
	try
	{
		if (argc < 2) return 1;
		std::string fileName = argv[1];

		FIX::SessionSettings settings(fileName);

		//MyApplication application;
		FIX::FileStoreFactory storeFactory(settings);
		FIX::FileLogFactory logFactory(settings);
		//FIX::SocketAcceptor acceptor(application, storeFactory, settings, logFactory /*optional*/);
		//acceptor.start();
		// while( condition == true ) { do something; }
		//acceptor.stop();
		return 0;
	}
	catch (FIX::ConfigError& e)
	{
		std::cout << e.what();
		return 1;
	}
}
