#pragma once

#include "SIOPacket.h"
#include <Poco/Notification.h>

using Poco::Notification;

class SIOClient;

class SIOEvent : public Notification
{
public:
	SIOEvent(SIOClient *client, SocketIOPacket *data) : client(client), data(data) {}

	SIOClient *client;
	SocketIOPacket *data;

protected:
	~SIOEvent() { delete data; };
};
