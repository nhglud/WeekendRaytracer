#pragma once

#include "hittable.hpp"
class Material
{
public:
	virtual ~Material() = default;

	virtual bool Scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const
	{
		return false;
	}
};
