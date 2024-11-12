#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isConverged(const vector<double>& x_old, const vector<double>& x_new, double epsilon) {
    for (size_t i = 0; i < x_old.size(); ++i) {
        if (fabs(x_new[i] - x_old[i]) > epsilon) {
            return false;
        }
    }
    return true;
}

int main() {
    // Coefficient matrix
    vector<vector<double>> A = {
        {5, 1, 1, 0},
        {1, 2, 0, 0},
        {1, 0, 4, 2},
        {0, 0, 2, 3}
    };

    // Right-hand side vector
    vector<double> b = { 10, 5, 21, 18 };

    // Initial approximations
    vector<double> x = { 0, 0, 0, 0 };
    vector<double> x_old(x.size());

    // Input accuracy
    double epsilon;
    cout << "Enter accuracy: ";
    cin >> epsilon;

    int iterations = 0;
    const int max_iterations = 1000;  // Maximum number of iterations to avoid infinite loop

    do {
        x_old = x;
        cout << "Iteration " << iterations + 1 << ":" << endl;
        for (size_t i = 0; i < A.size(); ++i) {
            double sum = 0;
            for (size_t j = 0; j < A[i].size(); ++j) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }
        ++iterations;
    } while (!isConverged(x_old, x, epsilon) && iterations < max_iterations);

    // Check for convergence
    if (iterations >= max_iterations) {
        cout << "The method did not converge within the given number of iterations." << endl;
    }
    else {
        cout << "Solution of the system: " << endl;
        for (size_t i = 0; i < x.size(); ++i) {
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }
        cout << "Number of iterations: " << iterations << endl;
    }

    return 0;
}
