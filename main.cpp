#include <iostream>
#include <fstream>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
    int readInNum = 0;
    int sum = 0;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);
    if (myReadFile.fail()) {
        std::cout << "Error: Couldn't open file!";
        std::cin.get();
        exit(EXIT_FAILURE);
    }
    
    int currentSize = 3;
    int* arrOfNumbers = new int[currentSize];
    int numCounter = 0;

    while (myReadFile >> readInNum)
    {
        if (numCounter < currentSize) {
            arrOfNumbers[numCounter] = readInNum;
        }
        else {
            int* tempCopy = new int[currentSize + numCounter];

            // Copy array elements
            for (int i = 0; i < currentSize; i++) 
                tempCopy[i] = arrOfNumbers[i];
            delete[] arrOfNumbers;
            arrOfNumbers = nullptr;

            arrOfNumbers = tempCopy;
            currentSize += numCounter;

            arrOfNumbers[numCounter] = readInNum;
        }
        sum += readInNum;
        numCounter++;
    }
    myReadFile.close();

    double average = static_cast<double>(sum) / numCounter;
    for (int i = 0; i < numCounter; i++) {
        if (arrOfNumbers[i] > average) {
            std::cout << arrOfNumbers[i] << " ";
        }
    }
    delete[] arrOfNumbers;

    getchar();
    return 0;
}