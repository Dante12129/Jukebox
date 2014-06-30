#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <random>

namespace jb
{
    class RandomGenerator
    {
        public:
            RandomGenerator();

            int generateInt(int lower, int upper);

        private:
            std::mt19937 generator;
    };
}

#endif // RANDOMGENERATOR_HPP
