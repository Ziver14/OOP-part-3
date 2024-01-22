#include<iostream>


//Инкапсуляуция,агрегация, композиция

//Формирование класса

class NameOfClass;// - объявление класса

class NameOfCclass {
	//внутренности фигурных скобок - тело класса.
	//тут хранятся свойства и поведения объектов

//хранящиеся здесь элементы доступны всем клиентам класса.
//Наслендникам класса, и клиентам наследника.
public:
	//обычно в этой зоне оставляют только методы класса

	//Конструктор класса
	NameOfCclass() {
		SetEven(2);
		even_ = 2;
	}
	void SomeWork() {
		std::cout << "I'm alive!!\n";
	}

	int  GetEven() {
		return even_;
	}

	//Конструктор применил делегацию работы
	//для передачи прав на создание и заполнение своего поля
	//конструктору поля
	NameOfCclass(int newNum) :even_(newNum)
	{
		if (even_ % 2 == 1) {
			throw 1;
		}
	}
	
	//делегация на поля применяеться для возможной работы с универсальной
	//инициализацией через {} и является единственным способом заполнить 
	//поля которые являются ссылками и неинициализированными константами


	void SetEven(int newNum) {
		if (newNum % 2 == 0) {
			even_ = newNum;
		}
		else {
			throw 1;
		}

	}
// хранящиеся здесь элементы доступны только членам класса
//дружественным классам и функциям
private:
	int even_;

// хранящиеся здесь элементы доступны только членам класса
// дружественным классам и функциям и членам классов наследников
protected:
};//определение класса




int main() {
	setlocale(LC_ALL, "ru");

	NameOfCclass obj;// создали экземпляр класса с именем obj
	obj.SomeWork();
	obj.SetEven(8);
	std::cout << obj.GetEven() << "\n";
	NameOfCclass obj2{10};
	std::cout << obj2.GetEven() << '\n';
	obj2.SetEven(4);
	std::cout << obj2.GetEven() << '\n';

	return 0;
}

class Day {
public:
	Day():units_(0){}
	Day(int days) :units_(days) {
		if (units_ < 0) {
			throw 1;
		}
	}

	int Days() {
		return units_;
	}

	void Days(const Day& obj) {
		this->units_ = obj.units_;
	}

	void AddDays(const Day& obj) {
		this->units_ += obj.units_;
	}



private:
	int units_;
};

class Month {
public:
	Month() :units_(0) {};
	Month(int monts) :units_(monts) {
		if (units_ < 0) {
			throw 1;
		}
	}

	Month(Day days) {
		units_ = days.Days() / 30;
	}


	int Months() {
		return units_;
	}

	void Months(const Month& obj) {
		units_ =  obj.units_;
	}

	void AddMonths(const Month& obj) {
		units_ += obj.units_;
	}

private:
	int units_;
};

class Year {
public:
	Year() :units_(0) {};
	Year(int year) :units_(year) {
		if (units_ < 0) {
			throw 1;
		}
	}

	Year(Day days) {
		units_ = days.Days() / 365;
	}

	Year(Month months) {
		units_ = months.Months() / 12;
	}


	int Years() {
		return units_;
	}

	void Years(const Year& obj) {
		units_ = obj.units_;
	}

	void AddYears(const Year& obj) {
		units_ += obj.units_;
	}

private:
	int units_;
};

class Date {
public:
	//Тут будут правила класса - даты

private:
		Day day_;
		Month month_;
		Year year_;
};// данный класс собирает внутри себя объекты других классов на правах
//композиции

 /*
 Композиция - способ связи полей класса с его объектом,
 при котором поле является неотемлемой частью объекта без которого 
 не возможна работа. При композиции объект в который сложены композиционные
 поля несетответственность за время жизни этих полей

 Агрегацция - способ связи полей класса с его объектом,
 при котором поле является легко заменяемой частью класса. Отсутсвие
 агрегационного компонента не ведет к проблемам в жизненном цикле хранящего
 данное поле объекта
 При агрегации хранящий объект не несет ответственности за время жизни
 хранимого на правах агрегации поля
 */