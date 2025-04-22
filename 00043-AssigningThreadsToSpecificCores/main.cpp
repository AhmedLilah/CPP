#include <windows.h> 
#include <thread> 
#include <vector> 
#include <print>
#include <random>
#include <ctime>

auto setThreadAffinity(std::thread& th, DWORD_PTR mask) -> void { 
	HANDLE handle = th.native_handle(); 
	SetThreadAffinityMask(handle, mask); 
} 

auto workFunction() -> void { 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	volatile size_t result = dist(gen);

	for (size_t i=0; i<0xFFFFFFFFF; i++) {
		result = 0.1 * i;
	}

	size_t printable = result;
	std::println("Result: {}", printable);
}

auto main() -> int { 

	std::vector<std::thread> threadPool; 
	threadPool.reserve(30);

	for (int i = 0; i < 30; i++) {
		threadPool.emplace_back(workFunction);
		setThreadAffinity(threadPool[i], 1 << (i+2)); 
	}

	for (auto & thread : threadPool) {
		thread.join();
	}

	return 0; 
} 
