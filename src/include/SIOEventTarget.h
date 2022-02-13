#pragma once

#include <Poco/JSON/Array.h>

using Poco::JSON::Array;

class SIOEventTarget
{
private:
public:
	virtual ~SIOEventTarget() = default;
};
