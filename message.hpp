#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

enum MessageType : unsigned int {
	POSITION_GET = 0
};

class Message {
	private:
		MessageType type_;
	public:
		Message(const MessageType type): type_{type} {}
};

#endif

