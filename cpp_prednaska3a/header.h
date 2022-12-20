#pragma once
#include <list>
#include <string>
#include <iostream>

class Command {
public:
	// kdo chce vytv��et command, mus� n�co implementovat
	virtual void execute() const = 0;

	virtual ~Command();
};


// potomek Command
class SimpleCommand : public Command {
private:
	std::string message;

public:
	// explicit zakazuje implicitn� konverze
	explicit SimpleCommand(std::string _message);
	// p�epsan� metoda p�edka
	void execute() const override;
};

// reciever obsahuje logiku pro proveden� r�zn�ch druh� operac�
class Reciever {
public:
	void DoSomething(const std::string& a);
	void DoSomethingElse(const std::string& b);
};

// dal�� potomek Command
class ComplexCommand : public Command {
private:
	// pot�ebuje reciever 
	Reciever* reciever_;
	// data pro pr�ci s recieverem 
	std::string a_;
	std::string b_;
	// slo�it�j�� p��kazy mohou p�ij�mat v�ce objekt� typu reciever 
	//	spolu s dal��mi daty krze konstruktor 
public:
	ComplexCommand(Reciever* reciever, std::string a, std::string b);
	// command m��e volat kteroukoli metodu recieveru
	void execute() const override;
};

// invoker je spojen s jedn�m a v�ce Command 
// invoker vol� Command
class Invoker {
	// nepot�ebujeme instanci Command kop�rovat -  jedn� se o list *
	std::list<Command*> commands;
public:
	// const na konci nebude z d�vodu, �e metoda m�n� atributy t��dy
	//		- zde modifiuje list
	// nechceme zde d�lat kopii parametru - p�ed�v�me *
	void addCommand(Command* c);

	// medoda nem�n� atributy t��dy -> const na konci
	void doCommands();

	~Invoker();
};