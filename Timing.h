#pragma once

#include <vector>
#include <list>
#include "ListAndVector.h"
#include <chrono>

using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::vector;
using std::list;


template <typename Func>
class Timing {
public:
	long long TimeFunc(Func f);
};

template<typename Func>
inline long long Timing<Func>::TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}