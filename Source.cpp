#include <iostream>
#include <string>
#include <cctype> // For std::tolower

using namespace std;

// Function to double a digit and sum its individual digits
int doubleAndSum(int digit) {
    int doubled = digit * 2;
    return doubled % 10 + doubled / 10;
}

// Function to verify the credit card number
bool isCardValid(const string& cardNumber) {
    int sum1 = 0;
    int sum2 = 0;

    // Iterate through the card number digits from right to left
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if ((cardNumber.length() - i) % 2 == 0) {
            // Step 1: Double each of the digits and sum their individual digits
            sum2 += doubleAndSum(digit);
        }
        else {
            // Step 2: Form the sum of every other digit
            sum1 += digit;
        }
    }

    // Step 3: Add the sums
    int totalSum = sum1 + sum2;

    // Step 4: Check if the last digit of the result is 0
    return (totalSum % 10 == 0);
}

// Function to check if a string contains only numeric characters
bool isNumeric(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Function to check if a string is of the correct length (16 characters)
bool isCorrectLength(const string& s) {
    return s.length() == 16;
}

int main() {
    string cardNumber;
    while (true) {
        cout << "Enter 16-digit credit card # or Q to quit: ";
        cin >> cardNumber;

        // Convert input to lowercase
        char firstChar = tolower(cardNumber[0]);

        if (firstChar == 'q') {
            // Quit the program if user inputs 'Q' or 'q'                           // test 1 of code
            break;
        }

        if (!isCorrectLength(cardNumber)) {
            cout << "Error - card number must contain 16 digits." << endl;
            continue;
        }

    }

    return 0;
}
