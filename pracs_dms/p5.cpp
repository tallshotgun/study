#include <iostream>
#include <vector>
using namespace std;

double evaluatePolynomial(const vector<double>& coeffs, double n) {
    double result = 0;

    for (double c : coeffs) {
        result = result * n + c;
    }

    return result;
}

int main() {
    int degree;
    double n;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coeffs(degree + 1);

    cout << "Enter " << degree + 1 << " coefficients starting from n^" << degree << " down to the constant term:" << endl;
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient for n^" << (degree - i) << ": ";
        cin >> coeffs[i];
    }

    cout << "\nEnter the value of n to evaluate: ";
    cin >> n;

    double finalValue = evaluatePolynomial(coeffs, n);

    cout << "\n-----------------------------------" << endl;
    cout << "Result: f(" << n << ") = " << finalValue << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}

/*
[tsglmao@arch pracs_dms]$ ./p5
Enter the degree of the polynomial: 2
Enter 3 coefficients starting from n^2 down to the constant term:
Coefficient for n^2: 4
Coefficient for n^1: 2
Coefficient for n^0: 9

Enter the value of n to evaluate: 5

-----------------------------------
Result: f(5) = 119
-----------------------------------
[tsglmao@arch pracs_dms]$ 
*/