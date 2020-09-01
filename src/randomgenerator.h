#pragma once
#include <random>

class RandomGenerator
{
private:
    static RandomGenerator *m_randomGeneratorInstance;
    std::mt19937 m_randomGenerator;
    RandomGenerator();
    RandomGenerator(RandomGenerator const &);            // copy constructor
    RandomGenerator &operator=(RandomGenerator const &); // assignment operator

public:
    static RandomGenerator *GetInstance();
    int getRandomNumber(int from, int to);
    std::string getRandomName(int size = 6);
    bool useVowelLetter();
};
