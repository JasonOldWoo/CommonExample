#include <assert.h>
class B
{
public:
	int m_iNum;
	virtual void foo();
};

class D : public B
{
public:
	char m_szName[100];
};

void func(B* pb)
{
	D* pd1 = static_cast<D*> (pb);
	D* pd2 = dynamic_cast<D*> (pb);

#if 0
	if (pd1) {
		pd1->m_szName[0] = 'H';
	}
	if (pd2) {
		pd2->m_szName[0] = 'L';
	}
#else
	assert(pd1);
	assert(pd2);
#endif
}
