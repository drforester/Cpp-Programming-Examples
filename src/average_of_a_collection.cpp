#include <iostream>
#include <vector>
#include <numeric> // std::accumulate

using std::cout;
using std::vector;

double average_score(const std::vector<double>& scores);

int main()
{
    vector<double> scores = {9.520, 4.981, 7.880, 7.763, 5.978, 8.654};
    double avg = average_score(scores);
    cout << "average score: " << avg << '\n';
}


double average_score(const std::vector<double>& scores) {
    return std::accumulate(scores.cbegin(), scores.cend(), 0) / (double)scores.size();
}
