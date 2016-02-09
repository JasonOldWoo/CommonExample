class A
{
public:
#if 1
	A(int x):data_(x) {;}
#else
	A() {;}
#endif

public:
	int data_;
};

int main()
{
#if 0
	A a = 10;
#else
	A a = static_cast<A> (10);
#endif

	int i = a.data_;
	// double d = i;
	double d = static_cast<double> (i);

	// char ch = d;
	char ch = static_cast<char> (d);

	return ch;
}
