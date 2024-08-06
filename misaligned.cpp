#include <iostream>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

void testColorMap() {
    // Expected output
    std::vector<std::string> expectedOutput = {
        "1 | White | Blue", "2 | White | Orange", "3 | White | Green", "4 | White | Brown", "5 | White | Slate",
        "6 | Red | Blue", "7 | Red | Orange", "8 | Red | Green", "9 | Red | Brown", "10 | Red | Slate",
        "11 | Black | Blue", "12 | Black | Orange", "13 | Black | Green", "14 | Black | Brown", "15 | Black | Slate",
        "16 | Yellow | Blue", "17 | Yellow | Orange", "18 | Yellow | Green", "19 | Yellow | Brown", "20 | Yellow | Slate",
        "21 | Violet | Blue", "22 | Violet | Orange", "23 | Violet | Green", "24 | Violet | Brown", "25 | Violet | Slate"
    };

    // Simulating capturing print output
    std::vector<std::string> capturedOutput;
    // Instead of printing, we capture the output into a vector (this is conceptual, not actual code)

    // Compare captured output with expected output
    for (size_t i = 0; i < expectedOutput.size(); ++i) {
        assert(capturedOutput[i] == expectedOutput[i]); // This will fail due to misalignment or incorrect output
    }

    // Check the total number of entries
    assert(capturedOutput.size() == expectedOutput.size());
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
