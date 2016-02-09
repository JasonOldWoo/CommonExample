#include <typeinfo>
#include <assert.h>

enum _dog_beh_
{
	_dog_run_ = 1,
	_dog_look_ = 10,
};

enum _cat_beh_
{
	_cat_run_ = 2,
	_cat_catch_ = 11,
};

class Animal
{
public:
	virtual ~Animal() = default;
	virtual int run() = 0;
};

class Dog : public Animal
{
public:
	virtual int run() override
	{
		return _dog_run_;
	}

	int lookafter_house()
	{
		return _dog_look_;
	}
};

class Cat : public Animal
{
public:
	virtual int run() override
	{
		return _cat_run_;
	}

	int catch_mouse()
	{
		return _cat_catch_;
	}
};

int main()
{
	Dog dog;
	Cat cat;

	Animal* pAnimal = static_cast<Animal*> (&dog);
	Dog* pDog = dynamic_cast<Dog*> (pAnimal);

	int beh = pAnimal->run();
	if (_dog_run_ == beh) {
		beh = pDog->lookafter_house();
		assert(_dog_look_ == beh);
	} else {
		beh = -1;
		return beh;
	}

	pAnimal = static_cast<Animal*> (&cat);
	pDog = dynamic_cast<Dog*> (pAnimal);

	beh = pAnimal->run();
	assert(_cat_run_ == beh);
	if (pDog) {
		beh = pDog->lookafter_house();
	} else {
		beh = -1;
	}
	assert(-1 == beh);

	try {
		Cat& rCat = dynamic_cast<Cat&> (*pAnimal);
		beh = rCat.catch_mouse();
	} catch (std::bad_cast const& e) {
		beh = -1;
	}

	try {
		Dog& rDog = dynamic_cast<Dog&> (*pAnimal);
		beh = rDog.lookafter_house();
	} catch (std::bad_cast const& e) {
		beh = -2;
	}

	return beh;
}
