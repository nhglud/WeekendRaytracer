#pragma once
#include "vec3.hpp"

class ray
{
private:
	point3 orig;
	vec3 dir;

public:
	ray() {}

	ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

	const point3& origin() { return orig; }
	const vec3& direction() { return dir; }

	point3 at(double t)
	{
		return orig + t * dir;
	}
};