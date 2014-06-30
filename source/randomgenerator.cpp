#include "include\randomgenerator.hpp"

#include <chrono>

namespace jb
{
    RandomGenerator::RandomGenerator() : generator(std::chrono::system_clock::now().time_since_epoch().count()) {}

    int RandomGenerator::generateInt(int lower, int upper)
    {
        std::uniform_int_distribution<> dist(lower, upper);
        return dist(generator);
    }
}
