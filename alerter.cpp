#include <iostream>
#include <assert.h>

int alertFailureCount = 0;


typedef int (*NetworkAlertFunc)(float);


int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if (celcius > 200.0) {
        return 500; // Simulate not-ok response
    }
    return 200; // Ok response
}

void alertInCelcius(float farenheit, NetworkAlertFunc alertFunc) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = alertFunc(celcius);
    if (returnCode != 200) {
        alertFailureCount++;
    }
}

void testAlertInCelcius() {
    alertFailureCount = 0;

    // Test cases
    alertInCelcius(400.5, networkAlertStub);
    assert(alertFailureCount == 1); // Should fail due to simulated error

    alertInCelcius(303.6, networkAlertStub);
    assert(alertFailureCount == 1); // Should not increment, still 1

    alertInCelcius(202.2, networkAlertStub);
    assert(alertFailureCount == 2); // Should increment to 2
}

int main() {
    // Run tests
    testAlertInCelcius();

    // Output failure count
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
