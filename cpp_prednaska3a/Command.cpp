#pragma once
#include "header.h"

Command::~Command() {}

SimpleCommand::SimpleCommand(std::string _message) : message(_message) {}

void SimpleCommand::execute() const {
	std::cout << "SimpleCommand: {" << this->message << "}\n";
}

void Reciever::DoSomething(const std::string& a) {
	std::cout << "Receiver: Working on {" << a << ".}\n";
}
void Reciever::DoSomethingElse(const std::string& b) {
	std::cout << "Receiver: Also working on {" << b << ".}\n";
}

ComplexCommand::ComplexCommand(Reciever* reciever, std::string a, std::string b) : reciever_(reciever), a_(a), b_(b) {}

void ComplexCommand::execute() const {
	std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
	this->reciever_->DoSomething(this->a_);
	this->reciever_->DoSomethingElse(this->b_);
}

Invoker::~Invoker() {
	std::cout << "Bye Bye Commands. \n";
	std::list<Command*>::iterator iterator = commands.begin();
	while (iterator != commands.end()) {
		delete* iterator;
		++iterator;
	}
}

void Invoker::addCommand(Command* _command) {
	commands.push_back(_command);
}

void Invoker::doCommands() {
	std::cout << "Lets do the jobs ...\n";
	std::list<Command*>::iterator iterator = commands.begin();
	while (iterator != commands.end()) {
		(*iterator)->execute();
		++iterator;
	}
}