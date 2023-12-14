//Part-A

#include <iostream>
using namespace std;
int main() {

    //Q1.How many total combinations are possible? Show the math along with the code!
    int faces_A = 6;
    int faces_B = 6;
    int total_combinations = faces_A * faces_B;

    std::cout << "Total Combinations: " << total_combinations << std::endl; //prints total combinations
     cout<<"\n";
    //Q2.display the distribution of all possible combinations
     int distribution[6][6];

    for (int i = 0; i < faces_A; i++) {
        for (int j = 0; j < faces_B; j++) {
            distribution[i][j] = (i + 1) + (j + 1);
        }
    }

    std::cout << "Distribution of Combinations:" << std::endl;
    for (int i = 0; i < faces_A; i++) {
        for (int j = 0; j < faces_B; j++) {
            std::cout << distribution[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout<<"\n";

    //Q3.e Probability of all Possible Sums

     for (int sum = 2; sum <= 12; ++sum) {
        double count = 0.0;
        for (int i = 0; i < faces_A; ++i) {
            for (int j = 0; j < faces_B; ++j) {
                if (distribution[i][j] == sum) {
                    count++;
                }
            }
        }
        double probability = count / total_combinations;
        std::cout << "P(Sum = " << sum << ") = "<< probability << std::endl;
    }

    return 0;
}