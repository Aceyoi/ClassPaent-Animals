// Код создан Сапожниковым Ю.С.
// Создание классов наследования
// Используемые библиотеки

#include <iostream>
#include <string>


using namespace std;

// Абстрактный класс Animal
class Animal {
protected:
	string name,    // Кличка животного
	       breed;   // Порода животного
	size_t age;     // Возраст животного

public:

	// Конструктор без параметров
	Animal() : name(" "), age(0), breed(" ") {}

	// Конструктор с параметрами
	Animal(string n, size_t a, string b) : name(n), age(a), breed(b) {
		if (a < 0 || a > 20) { throw runtime_error("Ошибка: недопустимый возраст"); }
	}

	// Виртуальный метод делает класс абстрактным
	virtual void print() const = 0;

	// Виртуальный деструктор
	virtual ~Animal() {}

	// Конструктор копирования
	Animal(const Animal& other)
		: name(other.name), breed(other.breed), age(other.age) {}

	// Конструктор перемещения
	Animal(Animal&& other) noexcept
		: name(other.name), breed(other.breed), age(other.age) {
		other.name = " ";
		other.breed = " ";
		other.age = 0;
	}

	// Методы вывода
	string getName() const { return name; }
	size_t getAge() const { return age; }
	string getBreed() const { return breed; }

	// Методы ввода
	void setName (string n){
		name = n;
	}

	void setAge (size_t a) {
		if (a < 0 || a > 20) {
			age = a;
		}
		else {
			cout << "Высота должна быть неотрицательной." << endl;
		}
	}

	void setBreed (string b) {
		breed = b;
	}
}; 

// Класс Cat наследуемый от Animal
class Cat: public Animal {
private:
	string furColor;

public:
	// Конструктор
	Cat(string name, size_t age, string breed, string furColor)
		: Animal{ name, age, breed }, furColor(furColor)
	{}

	string getfurColor() const { return furColor; }

	void setfurColor(string c) {
		furColor = c;
	}

	//Методы
	void print() const override {
		cout << "Это кошка!" << endl;
		cout << "Кличка: " << name << endl
			<< "Возраст: " << age << endl
			<< "Порода: " << breed << endl
			<< "Цвет шерсти: " << furColor << endl;
	}
};

// Класс Dog наследуемый от Animal
class Dog: public Animal {
private:
	string favoriteToy;

public:
	// Конструктор
	Dog(string name, size_t age, string breed, string favoriteToy)
		: Animal{ name, age, breed }, favoriteToy(favoriteToy)
	{}

	string getfavoriteToy() const { return favoriteToy; }

	void setfavoriteToy(string t) {
		favoriteToy = t;
	}

	//Методы
	void print() const override{
		cout << "Это собака!" << endl;
		cout << "Кличка: " << name << endl
			<< "Возраст: " << age << endl
			<< "Порода: " << breed << endl
			<< "Любимая игрушка: " << favoriteToy << endl;
	}
};

void printanimal(const Animal* animal) {
	animal->print();  // Здесь происходит полиморфный вызов метода print()
}