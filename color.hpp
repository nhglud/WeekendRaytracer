#pragma once
//
//#include "rtweekend.hpp"
//#include "vec3.hpp"
using Color = Vec3;


inline double linear_to_gamma(double linear_component)
{
    return linear_component > 0 ? sqrt(linear_component) : 0;
}

inline void write_color(std::ostream& out, const Color& pixel_color)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    static const Interval intensity(0.000, 0.999);

    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
