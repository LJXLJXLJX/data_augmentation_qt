#include "utils.h"

#include <random>
#include <ctime>

std::string randomStr()
{
	std::string res = "";
	const std::string CCH = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static std::default_random_engine e(time(0));
	static std::uniform_int_distribution<unsigned> u(0, CCH.size() - 1);
	for (int i = 0; i < 10; ++i)
	{
		int x = u(e);
		res.push_back(CCH[x]);
	}
	return res;
}
