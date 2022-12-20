#pragma once
#include <list>
#include <string>
#include <iostream>

class Command {
public:
	// kdo chce vytváøet command, musí nìco implementovat
	virtual void execute() const = 0;

	virtual ~Command();
};


// potomek Command
class SimpleCommand : public Command {
private:
	std::string message;

public:
	// explicit zakazuje implicitní konverze
	explicit SimpleCommand(std::string _message);
	// pøepsaná metoda pøedka
	void execute() const override;
};

// reciever obsahuje logiku pro provedení rùzných druhù operací
class Reciever {
public:
	void DoSomething(const std::string& a);
	void DoSomethingElse(const std::string& b);
};

// další potomek Command
class ComplexCommand : public Command {
private:
	// potøebuje reciever 
	Reciever* reciever_;
	// data pro práci s recieverem 
	std::string a_;
	std::string b_;
	// složitìjší pøíkazy mohou pøijímat více objektù typu reciever 
	//	spolu s dalšími daty krze konstruktor 
public:
	ComplexCommand(Reciever* reciever, std::string a, std::string b);
	// command mùže volat kteroukoli metodu recieveru
	void execute() const override;
};

// invoker je spojen s jedním a více Command 
// invoker volá Command
class Invoker {
	// nepotøebujeme instanci Command kopírovat -  jedná se o list *
	std::list<Command*> commands;
public:
	// const na konci nebude z dùvodu, že metoda mìní atributy tøídy
	//		- zde modifiuje list
	// nechceme zde dìlat kopii parametru - pøedáváme *
	void addCommand(Command* c);

	// medoda nemìní atributy tøídy -> const na konci
	void doCommands();

	~Invoker();
};