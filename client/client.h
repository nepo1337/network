#ifndef CLIENT_H
#define CLIENT_H

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Client :private sf::Thread
{
private:
	//data for the host
	sf::IPAddress hostIp;
	sf::SocketTCP hostSocket;
	int hostPort;

	//a threaded function that will recive messages from the server
	virtual void Run();
	
public:
	Client();
	~Client();
	bool connect(sf::IPAddress, int port);
	bool isConnected();
	void disconnect();
	void tellServer(string msg);

};

#endif // CLIENT_H
