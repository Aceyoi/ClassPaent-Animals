// Код создан Сапожниковым Ю.С.
// Создание классов наследования
// Используемые библиотеки

#include <iostream>
#include <string>
#include <cassert>
#include "Classchild.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

    Cat cattest{ "1", 5, "1", "Белый" };
    Dog dogtest{ "2", 12, "2", "Мячик" };

    assert(cattest.getAge() == 5);
    assert(cattest.getName() == "1");
    assert(cattest.getBreed() == "1");

    assert(dogtest.getAge() == 12);
    assert(dogtest.getName() == "2");
    assert(dogtest.getBreed() == "2");


    Animal* mira = new Cat("Мира", 1, "Сиамская", "Белый");
    Animal* psina = new Dog("Псина", 12, "Овчарка", "Мячик");

    //  Полиморфизм для вывода информации о животных
    printanimal(mira);   // Вызовет print() для кошки
    cout << endl;
    printanimal(psina);  // Вызовет print() для собаки


    // Освобождаем память, выделенную для объектов
    delete mira;   
    delete psina;  

    return 0;
}

