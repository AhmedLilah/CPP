#include <print>
#include <chrono>
#include <vector>
#include <random>

struct SoA {
        std::vector<float> x;
        std::vector<double> y;
        std::vector<float> z;

        std::vector<double> g1;
        std::vector<int> g2;
        std::vector<long> g3;
        std::vector<float> g4;
        std::vector<short> g5;
        std::vector<float> g6;
        std::vector<double> g7;
        std::vector<float> g8;
        std::vector<float> g9;
};

struct Pos {
        float x;
        double y;
        float z;

        double g1;
        int g2;
        long g3;
        float g4;
        short g5;
        float g6;
        double g7;
        float g8;
        float g9;
};

using AoS = std::vector<Pos>;

auto main() -> int {
        int returnInt;
        size_t sizeLimit {static_cast<size_t>(191'739'612)};
        for (size_t NUMBER_OF_ELEMENTS {100'000}; NUMBER_OF_ELEMENTS < sizeLimit; NUMBER_OF_ELEMENTS*=2) {
                auto start = std::chrono::high_resolution_clock::now();
                std::println("Number Of Elements: {}", NUMBER_OF_ELEMENTS);
                SoA soa;
                soa.x.reserve(NUMBER_OF_ELEMENTS);
                soa.y.reserve(NUMBER_OF_ELEMENTS);
                soa.z.reserve(NUMBER_OF_ELEMENTS);
                soa.g1.reserve(NUMBER_OF_ELEMENTS);
                soa.g2.reserve(NUMBER_OF_ELEMENTS);
                soa.g3.reserve(NUMBER_OF_ELEMENTS);
                soa.g4.reserve(NUMBER_OF_ELEMENTS);
                soa.g5.reserve(NUMBER_OF_ELEMENTS);
                soa.g6.reserve(NUMBER_OF_ELEMENTS);
                soa.g7.reserve(NUMBER_OF_ELEMENTS);
                soa.g8.reserve(NUMBER_OF_ELEMENTS);
                soa.g9.reserve(NUMBER_OF_ELEMENTS);

                for (size_t i=0; i< NUMBER_OF_ELEMENTS; ++i) {
                        soa.x[i] = static_cast<float>(rand());
                        soa.y[i] = static_cast<float>(rand());
                        soa.z[i] = static_cast<float>(rand());
                        soa.g1[i] = {};
                        soa.g2[i] = {};
                        soa.g3[i] = {};
                        soa.g4[i] = {};
                        soa.g5[i] = {};
                        soa.g6[i] = {};
                        soa.g7[i] = {};
                        soa.g8[i] = {};
                        soa.g9[i] = {};
                }

                AoS aos;
                aos.reserve(NUMBER_OF_ELEMENTS);

                for (size_t i=0; i< NUMBER_OF_ELEMENTS; ++i) {
                        aos[i] = {static_cast<float>(rand()), static_cast<float>(rand()), static_cast<float>(rand()), {}, {} ,{}, {}, {}, {}, {}, {}, {}};
                }
                auto end   = std::chrono::high_resolution_clock::now();
                auto timeInit = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                std::println("\tInitialization Time : {:<}ns", timeInit);


                // SoA Part
                start = std::chrono::high_resolution_clock::now();
                for (size_t i=0; i< NUMBER_OF_ELEMENTS; ++i) {
                        float temp1, temp2, temp3;
                        soa.x[i] = soa.y[i] * soa.z[i];
                }
                end   = std::chrono::high_resolution_clock::now();
                auto timeSoA = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                returnInt += static_cast<int>(soa.x[NUMBER_OF_ELEMENTS -1]);
                std::println("\tSoA Time            : {:<}ns", timeSoA);


                // AoS Part
                start = std::chrono::high_resolution_clock::now();
                for (size_t i=0; i< NUMBER_OF_ELEMENTS; ++i) {
                        float temp1, temp2, temp3;
                        aos[i].x = aos[i].y * aos[i].z;
                }
                end   = std::chrono::high_resolution_clock::now();
                auto timeAoS = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                returnInt += static_cast<int>(aos[NUMBER_OF_ELEMENTS -1].x);
                std::println("\tAoS Time            : {:<}ns", timeAoS);
                std::println("\tSpeedup             : {:<}", static_cast<double>(timeAoS)/static_cast<double>(timeSoA));
        }
        return returnInt;
}
