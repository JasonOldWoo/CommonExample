#include "use.h"
#include <stdio.h>

int main()
{
	std::pair<IVSAppMapIt, IVSAppMapIt> ret;
	ret = g_ivsAppMapArray[cbegin].equal_range(1);
	for (IVSAppMapIt it = ret.first; it != ret.second; it++) {
		printf("type: %d\n", it->second);
	}
	return 0;
}
