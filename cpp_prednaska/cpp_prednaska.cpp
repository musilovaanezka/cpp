// cpp_prednaska.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include "Header.h";
// pokus s int k
//int k;

int main()
{
    int k;

    //::k; // k na řádku 7
    //k; // k na řádku 11
    //std::cout << "Hello World!\n";

    // definice nového objektu typu Pumpkun 
    // Pumpkin p;
    // nebo 
    // Pumpkin p1();

    // volání 
    // p.display();

    // po zavolání new - nutnost volání delete 
    Pumpkin* p_p2 = new Pumpkin(10);
    //přístup přes šipku

    // dynamické volání metody display_total - nesprávné 
    // nemělo by se volat pro jednu instanci třídy, když se jedná o statickou metodu
    p_p2->display_total();
    p_p2->display();

    Pumpkin* p_p3 = new Pumpkin(30);

   // korektní volání statické metody 
   Pumpkin::display_total();

   //nelze z důvodu private metody 
   //Pumpkin::display; 
   
   // testování přetíženého operátoru ()
   // nutnost tvorby nového Pumpkin, které nebude pointerem 
   Pumpkin p(50);
   // vytiskne váhu p
   p();
   // nelze
   // p_p2();

    // p_p2->~Pumpkin();
    // stejné 
   delete p_p2;


   return 0;
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
