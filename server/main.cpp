#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "Server.h"

using namespace std;

int main(int argc, char **argv)
{
	Server server;
	cout << server.start(1337)<<endl;
	
	string inp="";
	while(server.isRunning())
	{
		getline(cin,inp);
		server.broadcast(inp);
		if(inp=="exit")
			server.shutDown();
	}
	server.shutDown();
}
