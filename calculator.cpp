#include <iostream>
#include <limits>
using namespace std;

// Reads a number safely (keeps asking until the input is valid)
double readNumber(const string &prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void showMenu() {
    cout << "\n===== SIMPLE CALCULATOR =====\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Remainder (whole numbers)\n";
    cout << "0. Exit\n";
    cout << "=============================\n";
}

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice! Please enter a number from the menu.\n";
            cin.clear();
            cin.ignoreignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0) {
            cout << "Thank you for using the calculator. Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please select 0-5.\n";
            continue;
        }

        double a = readNumber("Enter first number: ");
        double b = readNumber("Enter second number: ");

        switch (choice) {
            case 1:
                cout << "Result: " << a << " + " << b << " = " << a + b << endl;
                break;
            case 2:
                cout << "Result: " << a << " - " << b << " = " << a - b << endl;
                break;
            case 3:
                cout << "Result: " << a << " * " << b << " = " << a * b << endl;
                break;
            case 4:
                if (b == 0) {
                    cout << "Error: Division by zero is not allowed!\n";
                } else {
                    cout << "Result: " << a << " / " << b << " = " << a / b << endl;
                }
                break;
            case 5:
                if (static_cast<int>(b) == 0) {
                    cout << "Error: Remainder by zero is not allowed!\n";
                } else {
                    cout << "Result: " << static_cast<int>(a) << " % "
                         << static_cast<int>(b) << " = "
                         << static_cast<int>(a) % static_cast<int>(b) << endl;
                }
                break;
        }
    } while (true);

    return 0;
}

