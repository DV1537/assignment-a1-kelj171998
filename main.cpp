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
        std::cout << "Error: COuldn't open file!";
    }
    
    int currentSize = 3;
    int* listOfNumbers = new int[currentSize];
    int numCounter = 0;

    while (myReadFile >> readInNum)
    {
        if (numCounter < currentSize) {
            listOfNumbers[numCounter] = readInNum;
        }
        else {
            int* tempCopy = new int[currentSize + numCounter];

            // Copy array elements
            for (int i = 0; i < currentSize; i++) 
                tempCopy[i] = listOfNumbers[i];
            delete[] listOfNumbers;
            listOfNumbers = nullptr;

            listOfNumbers = tempCopy;
            currentSize += numCounter;

            listOfNumbers[numCounter] = readInNum;
        }
        sum += readInNum;
        numCounter++;
    }
    myReadFile.close();

    double average = static_cast<double>(sum) / numCounter;
    for (int i = 0; i < numCounter; i++) {
        if (listOfNumbers[i] > average) {
            std::cout << listOfNumbers[i] << " ";
        }
    }

    std::cout << sum << "\n";
    
    return 0;
}