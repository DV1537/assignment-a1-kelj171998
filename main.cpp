#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// A1: Pointers and memory management
void ExpandAndStoreNumbers(double readNum, double numbers[], int* currentSize, int* numOfElements);
double AverageValue(double numbers[], const int size);
void PrintFileValues(double numbers[], const int size);
void PrintOutputValues(double numbers[], const int size);

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[]) {

    bool isReadable = true;
    int currentSize = 3;
    double* numbers = new double[currentSize];
    int countNumbers = 0;
    double readNum = 0;

    std::ifstream inputFile;
    inputFile.open(argv[1]);
    
    if (inputFile.fail()) {
        std::cout << "Error: Couldn't open file!\n";
        isReadable = false;
    } 
    
    while (inputFile >> readNum) {
        ExpandAndStoreNumbers(readNum, numbers, &currentSize, &countNumbers);
        countNumbers++;
    }
    inputFile.close();

    // Check for end of file
    if (inputFile.eof()) {
        PrintFileValues(numbers, countNumbers);
        PrintOutputValues(numbers, countNumbers);
    }
    else {
        std::cout << "Error: Input file is corrupt!";
        isReadable = false;
    }

    if (!isReadable) {
        std::cin.get();
        exit(EXIT_FAILURE);
    }

    std::cin.get();
    return 0;
}

void ExpandAndStoreNumbers(double readNum, double numbers[], int* currentSize, int* numOfElements) {
    if (numOfElements < currentSize) {
        numbers[*numOfElements] = readNum;
    }
    else {
        double* tempCopy = new double[*currentSize + *numOfElements];
    
        // Copy array
        for (int i = 0; i < *currentSize; i++) {
            tempCopy[i] = numbers[i];
        }
        delete[] numbers;
        numbers = nullptr;

        numbers = tempCopy;
        currentSize += *numOfElements;

        numbers[*numOfElements] = readNum;
    }
}

double AverageValue(double numbers[], const int size) {

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    double average = static_cast<double>(sum) / size;
    return average;
}

void PrintFileValues(double numbers[], const int size) {
    const double MAX_DECIMALS = 1000.0; 

    std::cout << "Input: ";
    for (int i = 0; i < size; i++) {
        std::cout << round(numbers[i] * MAX_DECIMALS) / MAX_DECIMALS << " ";
    }
}

void PrintOutputValues(double numbers[], const int size) {
    const double MAX_DECIMALS = 1000.0; 

    std::cout << "\tOutput: ";
    double average = AverageValue(numbers, size);
    for (int i = 0; i < size; i++) {
        if (numbers[i] > average)
            std::cout << round(numbers[i] * MAX_DECIMALS) / MAX_DECIMALS << " ";
    }
}