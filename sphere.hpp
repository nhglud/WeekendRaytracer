#pragma once

#include "hittable.hpp"
#include "vec3.hpp"

class Sphere : public Hittable
{
private:
	Point3 center;
	double radius;

public:
	Sphere(const Point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

	bool hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec)
	{
        Vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = dot(oc, oc) - radius * radius;
        auto discriminant = h * h - a * c;

        if (discriminant < 0)
        {
            return false;
        }

        auto sqrd = std::sqrt(discriminant);

        auto root = (h - sqrd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
        {
            root = (h + sqrd) / a;
            if (root <= ray_tmin || ray_tmax <= root)
            {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        rec.normal = (rec.p - center) / radius;

        return true;
	}
};