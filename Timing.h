#pragma once

#include <vector>
#include <list>
#include "ListAndVector.h"
using std::vector;
using std::list;


template <typename Func>
class Timing {
public:
	long long TimeFunc(Func f);
};
