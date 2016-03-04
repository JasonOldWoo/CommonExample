#ifndef __USE_H__
#define __USE_H__

#include <map>

typedef enum type_t
{
	cbegin = 0,
	cmiddle = 1,
	cend = 2,
} ctype;

typedef const std::multimap<unsigned int, int> IVSAppMap;
typedef IVSAppMap::const_iterator IVSAppMapIt;
extern IVSAppMap g_ivsAppMapArray[cend];

#endif
