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
		// oper�tor -> proto�e hodnota listu je * 
		//		a na metody objektu p�ed�van�ho * se odkazujeme ->
		// (*iterator) z�sk�me hodnotu na kterou ukazuje iterator
		// stejn� v�znam by m�lo (*(*iterator)). == (*iterator) ->
		(*iterator)->execute();
	}
}