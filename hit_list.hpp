#pragma once
#include "rtweekend.hpp"
#include "hittable.hpp"

#include <vector>

class HitList : public Hittable
{
public:
	std::vector<shared_ptr<Hittable>> objects;

	HitList() {}
	HitList(shared_ptr<Hittable> object) { add(object); }

	void clear()
	{
		objects.clear();
	}

	void add(shared_ptr<Hittable> object)
	{
		objects.push_back(object);
	}

	bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override
	{
		HitRecord tmp_rec;
		bool hit_anything = false;

		auto closest_so_far = ray_t.max;

		for (const auto& o : objects)
		{
			if (o->hit(r, Interval(ray_t.min, closest_so_far), tmp_rec))
			{
				hit_anything = true;
				closest_so_far = tmp_rec.t;
				rec = tmp_rec;
			}
		}

		return hit_anything;

	}
};