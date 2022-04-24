#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T> struct S{
private:
  T val;
public:
  S(T v) {val=v;}
  T& get(); //{return val;}
  const T& get() const;
  void operator=(const T&);
  void set(T v) {val=v;}
};

template<typename T>
T& S<T>::get() {return val;}

template<typename T>
void S<T>::operator=(const T& v){
  val = v;
}

template<typename T>
const T& S<T>::get() const{return val;}

template<typename T>
void read_val(T& v){
  cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
  os << "{";
  for(int i=0; i<v.size(); ++i){
    os << v[i] << (i<v.size()-1 ? ", " : "");
  }
  os << "}\n";
  return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
  char ch = 0;
  is >> ch;
  if(ch!='{'){
    is.unget();
    return is;
  }
  for(T val; is >> val;){
    v.push_back(val);
    is >> ch;
    if(ch!=',')
      break;
  }
  return is;
}

int main(){
  S<int> si{37};
  S<char> sc{'a'};
  S<double> sd{3.2};
  S<string> ss{"alma"};
  S<vector<int>> svi{vector<int>{10, 2, 5}};

  cout <<"S<int>: "<< si.get() << endl;
  cout <<"S<cahr>: "<< sc.get() << endl;
  cout <<"S<double>: "<< sd.get() << endl;
  cout <<"S<string>: "<< ss.get() << endl;
  cout <<"S<vector<int>>: ";
  for(auto& a : svi.get()){ 
    cout << a << ' ';
  }
  cout << endl;

  si.set(10);
  sc.set('b');
  sd.set(5.5);
  ss.set("korte");
  cout << "int, double, char, string, vector({val, val, val}: " << endl;
  int si2;
  read_val(si2);
  S<int> sii{si2};

  double sd2;
  read_val(sd2);
  S<double> sdd{sd2};

  char sc2;
  read_val(sc2);
  S<char> scc{sc2};

  string ss2;
  read_val(ss2);
  S<string> sss{ss2};

  vector<int> vec;
  read_val(vec);
  S<vector<int>> svec{vec};

  cout << "S<int>: " << sii.get() << endl;
  cout << "S<double>: " << sdd.get() << endl;
  cout << "S<char>: " << scc.get() << endl;
  cout << "S<string>: " << sss.get() << endl;
  cout << "S<vector<int>>: "<< svec.get() << endl;

}
