#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

void undoom_dice(int Die_A[6], int Die_B[6]) {
    // Probabilities of original dice
    int total_combinations = 6 * 6;
    double original_probabilities[13] = {0.0};

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            original_probabilities[Die_A[i] + Die_B[j]] += 1.0 / total_combinations;
        }
    }

    // Brute force to find new faces for Die A and Die B
    double min_deviation = std::numeric_limits<double>::max();
    int new_Die_A[6], new_Die_B[6];

    for (int a1 = 1; a1 <= 4; ++a1) {
        for (int a2 = 1; a2 <= 4; ++a2) {
            for (int a3 = 1; a3 <= 4; ++a3) {
                for (int a4 = 1; a4 <= 4; ++a4) {
                    for (int a5 = 1; a5 <= 4; ++a5) {
                        for (int a6 = 1; a6 <= 4; ++a6) {
                           
                            new_Die_A[0] = a1;
                            new_Die_A[1] = a2;
                            new_Die_A[2] = a3;
                            new_Die_A[3] = a4;
                            new_Die_A[4] = a5;
                            new_Die_A[5] = a6;

                           
                            for (int b1 = 1; b1 <= 8; ++b1) {
                                for (int b2 = 1; b2 <= 8; ++b2) {
                                    for (int b3 = 1; b3 <= 8; ++b3) {
                                        for (int b4 = 1; b4 <= 8; ++b4) {
                                            for (int b5 = 1; b5 <= 8; ++b5) {
                                                for (int b6 = 1; b6 <= 8; ++b6) {
                                                   
                                                    new_Die_B[0] = b1;
                                                    new_Die_B[1] = b2;
                                                    new_Die_B[2] = b3;
                                                    new_Die_B[3] = b4;
                                                    new_Die_B[4] = b5;
                                                    new_Die_B[5] = b6;

                                                    // Recalculate probabilities with the new dice
                                                    double new_probabilities[13] = {0.0};
                                                    for (int i = 0; i < 6; ++i) {
                                                        for (int j = 0; j < 6; ++j) {
                                                            new_probabilities[new_Die_A[i] + new_Die_B[j]] += 1.0 / total_combinations;
                                                        }
                                                    }

                                                    // Calculate deviation
                                                    double deviation = 0.0;
                                                    for (int k = 2; k <= 12; ++k) {
                                                        deviation += std::abs(original_probabilities[k] - new_probabilities[k]);
                                                    }

                                                    // Update minimum deviation and store the best combination
                                                    if (deviation < min_deviation) {
                                                        min_deviation = deviation;
                                                        std::copy(new_Die_A, new_Die_A + 6, Die_A);
                                                        std::copy(new_Die_B, new_Die_B + 6, Die_B);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

   
    cout << "New_Die_A: [";
    for (int i = 0; i < 6; ++i) {
        cout << Die_A[i];
        if (i < 5) {
            cout << ", ";
        }
    }
    cout << "]" << std::endl;

    cout << "New_Die_B: [";
    for (int i = 0; i < 6; ++i) {
        std::cout << Die_B[i];
        if (i < 5) {
            std::cout << ", ";
        }
    }
    cout << "]" << std::endl;
}

int main() {
    int DieA[6] = {1, 2, 3, 4, 5, 6};
    int DieB[6] = {1, 2, 3, 4, 5, 6};

    undoom_dice(DieA, DieB);

    return 0;
}
