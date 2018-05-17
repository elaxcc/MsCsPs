#pragma once

namespace GDS
{

struct Point
{
	unsigned x;
	unsigned y;

	Point(unsigned x_val, unsigned y_val)
		: x(x_val)
		, y(y_val)
	{
	}
};

} // namespace GDS
