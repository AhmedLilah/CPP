#include <ctime>
#include <cstdlib>

template <typename T>
struct Vec3 {
	T x, y, z;
};

template <typename T>
using RGB = Vec3<T>;


template <typename T>
constexpr auto vec3(T x, T y, T z) -> Vec3<T> {
	Vec3 vec = {.x = x, .y = y, .z = z};
	return vec;
}

template <typename T>
constexpr auto rgb = vec3<T>;

auto main() -> int {
	Vec3 red = rgb<float>(1.0f, 0.0f, 0.0f);

	srand(time(nullptr));

	red.x = static_cast<float>(rand()) / 1000;

	return rgb<float> == vec3<float>;
}
