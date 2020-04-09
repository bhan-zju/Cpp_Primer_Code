#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
	// 友元声明
	friend std::istream& read(std::istream&, Person&);
	friend std::ostream& print(std::ostream&, const Person&);

private:
	std::string name;
	std::string address;

public:
	Person(): name("LinDaiyu"), address("XiaoxiangGuan") { }
	Person(const std::string& ming, std::string di): name(ming), address(di) { }
	Person(std::istream& is);

	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
};

std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);

// 构造函数
Person::Person(std::istream& is) 
{
	read(is, *this);
}

std::istream& read(std::istream& is, Person& item)
{
	is >> item.name >> item.address;
	return is;
}
std::ostream& print(std::ostream& os, const Person& item)
{
	os << item.name << " " << item.address;
	return os;
}

#endif // !PERSON_H

