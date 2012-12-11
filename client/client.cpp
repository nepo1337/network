#include "Client.h"

Client::Client()
{
}

Client::~Client()
{
}

bool Client::connect(sf::IPAddress ip, int port)
{
	//connects to the server
	if(this->hostSocket.Connect(port,ip)!=sf::Socket::Done)
	{
		cout << "error connecting"<<endl;
	}
	
	this->hostSocket.SetBlocking(false);
	//launches the thread that listen to messages from the server
	this->Launch();
	
	this->hostPort=port;
	this->hostIp=ip;
	
	return this->hostSocket.IsValid();
}

void Client::disconnect()
{
	if(this->hostSocket.IsValid())
		this->hostSocket.Close();
}

void Client::tellServer(string msg)
{
	sf::Packet packet;
	packet << msg;
	if(this->hostSocket.IsValid())
		this->hostSocket.Send(packet);
}

void Client::Run()
{
	while(this->hostSocket.IsValid())
	{
		sf::Packet packet;
		if (this->hostSocket.Receive(packet) == sf::Socket::Done)
		{
			string message;
			packet >>message;
			cout << message<<endl;
			if(message=="disconnect")
			{
				this->disconnect();
			}
		}
	}
}

bool Client::isConnected()
{
	return this->hostSocket.IsValid();
}