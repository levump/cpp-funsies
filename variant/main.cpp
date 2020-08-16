#include <iostream>
#include <utility>
#include <variant>
#include <list>
#include <string>
#include <algorithm>


class cat{
	std::string name;
public:
	explicit cat(std::string n)
		: name{std::move(n)}
	{}

	void say() const
	{
		std::cout << name << " says Meow!" << std::endl;
	}
};

class snek
{
	std::string name;
public:
	explicit snek(std::string n )
		: name{std::move(n)}
	{}

	void say() const
	{
		std::cout << name << " says sssssss!" << std::endl; 
	}


};

class dog
{
	std::string name;

public:
	explicit dog(std::string n)
		: name {std::move(n)}
	{}
	void say() const
	{
		std::cout << name << " says Woof!" << std::endl;
	}

};

class chicken
{
	std::string name;

	public:
		explicit chicken(std::string n)
			: name{std::move(n)}
		{}

		void say() const
		{
			std::cout << name << " says chip-chip-chip!" << std::endl;
		}


};

class fox
{
	std::string name;
public:
	explicit fox(std::string n)
		: name {std::move(n)}
	{}

	void say() const
	{
		std::cout << name << " says hatey hatey!" << std::endl;
	}

};

// similar to haskells data Type = Smth1 | Smth2 | Smth3
// our animal can be a dog, a cat, a chicken, a fox or a snek
using animal = std::variant<dog, cat, snek, chicken, fox>;

struct animal_voice{

	//turning our call operator to a generic state, to avoid tedious writting
	template <typename ValType>
	void operator() (ValType &&d) const
	{
		std::forward<ValType>(d).say();
	}
	
};

int main(){
	//using variant we can simply creata a visitor design pattern, since it has a visit function
	std::list<animal> l {snek{"Salazar"}, cat{"Garfield"}, dog{"Shirou"}, dog{"Benjamin"}, fox{"Mark"}, chicken{"Tommy"}}; 
	for(const animal &a : l){
		visit(animal_voice{}, a);
	}


	return 0;
}
