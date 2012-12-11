#include <iostream>
#include "Client.h"

using namespace std;

int main(int argc, char **argv)
{
	Client client;

	string input="";
	cout << "enter server ip"<<endl;
	cin >> input;
	sf::IPAddress ip(input);
	client.connect(ip,1337);
	while(input!="exit"&&client.isConnected())
	{
		getline(cin,input);
		client.tellServer(input);
	}
	client.disconnect();

}
