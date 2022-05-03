#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void error()
{
   throw runtime_error("error()");
}


struct Person
{
	Person() {}
	Person(string fn, string ln, int aa);
	string f() const {return first;}
	string l() const {return last;}
	int a() const {return age;}
	
private:
	string first;
	string last;
	int age;
};

Person::Person(string f, string l, int a)
	:first{f}, last{l}, age{a}
{
	if (a < 0)
		error();
	string full_name = f + l;
	for(char c : full_name)
	{
		switch(c)
		{
			case ';': case ':': case '"': case '[': case ']': case '*':
            		case '&': case '^': case '%': case '$': case '#': case '@':
            		case '!':
            		
            		error();
			break;
			default: break;
		}
	}

}

ostream& operator<<(ostream& os, const Person& p)
{
	return os << p.f() << ' ' << p.l() << '\t' << p.a() << endl;
}

istream& operator>>(istream& is, Person& p)
{
	string first;
	string last;
	int age;
	
	is >> first >> last >> age;
	
	if(!is) error ();
	
	p = Person(first, last, age);
	return is;
}

int main()
{
	vector<Person> p_vec;
	cout << "Enter 5 names and ages" << endl;
	Person p;
	for(int i = 0; i< 5; i++)
	{
		cin >> p;
		p_vec.push_back(p);
	}
	
	for(Person p : p_vec)
		cout << p << endl;
}
