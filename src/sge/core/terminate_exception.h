#pragma once

#include <exception>
#include <string>

class TerminateException : public std::exception
{
private:
	std::string message;

public:
	TerminateException(const std::string& message) : message(message) {}

	const char* what() const
	{
		return message.c_str();
	}
};