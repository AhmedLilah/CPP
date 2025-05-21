#include <print>

struct Math {
	static auto printHello() {
		std::println("Hello, World!");
	}
};


auto main() -> int {
	Math math;
	math.printHello();
	return 0;
}
