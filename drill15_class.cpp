#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Person
{
public:
	Person() {};
	Person(string Fn, string Ln, int Age)
	{
		if(Age <1 || Age>150)
			throw runtime_error("Invalid Age");
		else
			age = Age;

		string Name = Fn + Ln;
		for (int i = 0; i < Name.length(); ++i)
		{
			if (Name[i]==';' || Name[i]==':' || Name[i]=='[' || Name[i]==']' || Name[i]=='"' || Name[i]=='*' || Name[i]=='\'' || Name[i]=='&' || Name[i]=='^' || Name[i]=='%' || Name[i]=='$' || Name[i]=='#' || Name[i]=='@' || Name[i]=='!')
				throw runtime_error("Invalid Name");
			{
				fn = Fn;
				ln = Ln;
			}
		}
	}

	//string GetName() const{return name;}
	//void SetName(string a) {name = a;}

	string GetLn() const{return ln;}
	void SetLn(string a) {ln = a;}

	string GetFn() const{return fn;}
	void SetFn(string a) {fn = a;}

	int GetAge() const{return age;}
	void Setage(int a) {age = a;}

private:
	//string name;
	string fn;
	string ln;
	int age;
};

ostream& operator<< (ostream& os, Person& p){
	return os << p.GetFn() << " " << p.GetLn() << " " << p.GetAge() << endl;
}

istream& operator>> (istream& is, Person & p){
	string fn;
	string ln;
	int a;
	is >> fn >> ln >> a;
	p = Person(fn, ln, a);
	return is;
}

int main(){
	Person p;
	p.SetFn("Goodfy");
	p.SetLn("lastGod");
	p.Setage(63);
	cout << p.GetFn() << " " << p.GetLn() << " " << p.GetAge() << endl;

	Person p2 = Person("Goodfy2", "Lastgood" ,64);
	cout << p2.GetFn() << " " << p2.GetLn() << " " << p2.GetAge() << endl;

	Person p3;
	cout << "p3 person fn (space) ls (space) Age: ";
	cin >> p3;
	cout << p3 << endl;

	vector<Person> vec;
	cout << "Person for vec: fn (space) ls (space) Age: ( for end: end (space) a (space) 1)\n";
	for(Person per; cin >> per;){
		if(per.GetFn()!="end")
			vec.push_back(per);
		else{
			cout << "ok." << endl;
			break;
		}
	}

	cout << "\nPerson from vec:\n";
	for(Person p : vec){
		cout << p;
	}

}