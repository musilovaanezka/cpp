// cpp_prednaska3a.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
#include "header.h"
#include <iostream>

int main()
{
    Invoker* invoker = new Invoker;
    std::string s("Say Hi!");
    invoker->addCommand(new SimpleCommand("Starting DB ..."));
    invoker->addCommand(new SimpleCommand("Starting jetty ..."));
    Reciever* receiver = new Reciever;
    invoker->addCommand(new ComplexCommand(receiver, "Send email", "Save report"));

    invoker->doCommands();

    delete invoker;
    delete receiver;

    std::cin.get();
    return 0;
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
