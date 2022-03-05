#include "DrawJava.h"
#include "Connection.h"

constexpr char ADRESS[] = "127.0.0.1";
constexpr int PORT = 1337;

void DrawJava::visite(const FormGroup* formGroup) const
{
	string data = "{";
	for (Form* form : formGroup->getFromList())
	{
		data += string(*form) + "/";
	}
	data += formGroup->getColor() + ",";
	data += formGroup->getName() + "}";

	drawOnServer(data);
}

void DrawJava::visite(const Circle* form) const
{
	string data = "{" + string(*form) + "}";
	drawOnServer(data);
}

void DrawJava::visite(const Cross* form) const
{
	string data = "{" + string(*form) + "}";
	drawOnServer(data);
}

void DrawJava::visite(const Segment* form) const
{
	string data = "{" + string(*form) + "}";
	drawOnServer(data);
}

void DrawJava::drawOnServer(string data) const
{
	Connection* instanceConnection = Connection::getInstance(ADRESS, PORT);
	SOCKET* socket = instanceConnection->createSocket();
	instanceConnection->sendMsg(data, socket);
	instanceConnection->closeSocket(socket);
}