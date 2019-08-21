#include <iostream>

struct A
{
	A()
	{
		b = new char[10]();
	}
	int a;
	char* b;
};
class T
{
public:
	T()
	{
		memset(this, 0, sizeof(T));
	}
	~T() = default;
	int geti() const { return i; }
	const A& getA() const { return a; }
private:
	int i;
	A a;
};

int main()
{
	T t;
	std::cout << t.geti() << std::endl;
	std::cout << t.getA().a << std::endl;
	std::cout << t.getA().b << std::endl;
	return 0;
}