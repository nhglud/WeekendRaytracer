#pragma once
//
//#include "rtweekend.hpp"

class Interval
{
public:
	double min;
	double max;

	Interval() : min(-infinity), max(infinity) {}
	Interval(double min, double max) : min(min), max(max) {}

	double size()
	{
		return max - min;
	}


	bool contains(double x) const
	{
		return min <= x && max >= x;
	}

	bool surrounds(double x) const 
	{
		return min < x && max > x;
	}

	double clamp(double x) const
	{
		if (x < min) return min;
		if (x > max) return max;

		return x;
	}

	static const Interval empty;
	static const Interval universe;
};

const Interval Interval::empty = Interval(infinity, -infinity);
const Interval Interval::universe = Interval();