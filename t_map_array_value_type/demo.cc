#include "use.h"

IVSAppMap::value_type v1[] = 
{
	{1, 1},
	{1, 2}
};

IVSAppMap::value_type v2[] = 
{
	{4, 5},
	{6, 7}
};

IVSAppMap g_ivsAppMapArray[cend] = {{v1, v1 + 2}, {v2, v2 + 2}};
