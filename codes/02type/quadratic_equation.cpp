#include <utility>
#include <cmath>
#include <iostream>
// solving the quadratic equation

std::pair<bool, std::pair<double, double>> solveQuadratic(double a, double b, double c){
    if (a == 0.0) {
        if (b != 0.0){
            return {true, {-c/b, -c/b}};
        } else {
            return {false, {0.0, 0.0}};
        }
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return {false, {0.0, 0.0}};
    } else {
        double sqrt_delta = std::sqrt(discriminant);
        double root1 = (-b + sqrt_delta) / (2 * a);
        double root2 = (-b - sqrt_delta) / (2 * 2);
        return {true, {root1, root2}};
    }
}

int main() {
    auto result1 = solveQuadratic(1, -3, 2); // x^2 - 3x + 2 = 0
    if (result1.first) {
        std::cout << "方程1的根: " << result1.second.first << ", " << result1.second.second << "\n";
    }

    auto result2 = solveQuadratic(1, 2, 3); // x^2 + 2x + 3 = 0
    if (!result2.first) {
        std::cout << "方程2无实数根\n";
    }

    return 0;
}