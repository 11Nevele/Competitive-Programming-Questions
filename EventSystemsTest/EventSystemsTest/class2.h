#pragma once
#include "class1.h"
class c2
{
private:
	friend c1;
	c2() = default;
};