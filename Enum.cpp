
using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
bool contains(vector<T> v, T a)
{
	return !v.empty() && find(v.begin(), v.end(), a) != v.end();
}

template <typename T>
class EnumElem {
	public:
	T val;
	size_t num;
	EnumElem(T a, size_t n) {
		val = a;
		num = n;
	}
};

template <typename T>
class Enum {
	vector<EnumElem<T> > data;
	public:
	Enum(vector<T> v) {
		for (size_t i = 0; i < v.size(); ++i) {
			data.push_back(EnumElem<T>(v[i], i));
		}
	}
	size_t size() { return data.size(); }
	EnumElem<T> operator[](size_t i) { return data[i]; }
};

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	Enum<int> e = Enum<int>(v);
	for (size_t i = 0; i < e.size(); ++i) {
		cout << e[i].num << " " << e[i].val << endl;
	}
	return 0;
}
