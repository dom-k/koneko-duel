#include "randomgenerator.h"
#include <ctime>

RandomGenerator *RandomGenerator::m_randomGeneratorInstance = NULL;

RandomGenerator *RandomGenerator::GetInstance()
{
    if (!m_randomGeneratorInstance)
        m_randomGeneratorInstance = new RandomGenerator();

    return m_randomGeneratorInstance;
}

RandomGenerator::RandomGenerator()
{
    m_randomGenerator.seed(std::time(0));
}

int RandomGenerator::getRandomNumber(int from, int to)
{
    std::uniform_int_distribution<uint32_t> dice(from, to);
    int randomNumber{dice(m_randomGenerator)};
    return randomNumber;
}

std::string RandomGenerator::getRandomName(int size)
{
    std::string randomName = "";
    int firstASCIILetter{65};
    int numOfLetters{26};
    const int numberOfVowels{5};
    char vowelLetters[numberOfVowels]{'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < size; i++)
    {
        int randomNum{getRandomNumber(firstASCIILetter,
                                      firstASCIILetter + numOfLetters - 1)};

        if (useVowelLetter())
            randomName += vowelLetters[getRandomNumber(0, numberOfVowels - 1)];
        else
            randomName += (char)randomNum;
    }

    return randomName;
}

bool RandomGenerator::useVowelLetter()
{
    return getRandomNumber(0, 1) == 1;
}
