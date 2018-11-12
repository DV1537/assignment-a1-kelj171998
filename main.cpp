#include <iostream>
#include <fstream>

// Test Test2
// Test 3

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
    
    int a = 0;
    int sum = 0;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);

    if (myReadFile.fail()) {
        std::cout << "Error: COuldn't open file!";
    }
    
    int currentSize = 3;
    int* numbers = new int[currentSize];
    int numCounter = 0;

    while (myReadFile >> a)
    {
        if (numCounter < currentSize) {
            numbers[numCounter] = a;
        }
        else {
            int* tempCopy = new int[currentSize + numCounter];

            // Copy array elements
            for (int i = 0; i < currentSize; i++) 
                tempCopy[i] = numbers[i];
            delete[] numbers;
            numbers = nullptr;

            numbers = tempCopy;
            currentSize += numCounter;

            numbers[numCounter] = a;
        }
        sum += a;
        numCounter++;
    }
    myReadFile.close();

    double average = static_cast<double>(sum) / numCounter;
    for (int i = 0; i < numCounter; i++) {
        if (numbers[i] > average) {
            std::cout << numbers[i] << " ";
        }
    }

    std::cout << sum << "\n";
    
    return 0;
}

