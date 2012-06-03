# include "../headers++/unixserverstream.hpp"
# include "../headers++/unixclientstream.hpp"
# include "../headers++/exception.hpp"
# include <string>
# include <iostream>
# include <string.h>

int main(void)
{
	using std::string;
	using libsocket::unix_stream_server;
	using libsocket::unix_stream_client;

	string bindpath = "/tmp/unixsocket";
	char* answer = new char[128];

	memset(answer,0,128);

	try {
		unix_stream_server srv(bindpath);

		unix_stream_client* client;
		client = srv.accept();

		client->rcv(answer,127);

		std::cout << answer;

		*client << "Hello back from server!\n";

		delete client;
		
		srv.destroy();

	} catch (libsocket::socket_exception exc)
	{
		std::cerr << exc.mesg;
	}

	return 0;
}