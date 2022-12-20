#include "header.h"

Command::~Command() {}

SimpleCommand::SimpleCommand(std::string _message) : message(_message) {}

void SimpleCommand::execute() const {
	std::cout << "SimpleCommand {" << this->message << "}\n"
}



void Invoker::addCommand(Command* c) {
	commands.push_back(c);
}
void Invoker::doCommands() const {
	std::list<Command *>::iterator = commands.begin();
	while (iterator != commands.end()) {
		// operátor -> protože hodnota listu je * 
		//		a na metody objektu pøedávaného * se odkazujeme ->
		// (*iterator) získáme hodnotu na kterou ukazuje iterator
		// stejný význam by mìlo (*(*iterator)). == (*iterator) ->
		(*iterator)->execute();
	}
}