/*
    By default std::accumulate sums the items in a collection, but that behavior can
    be changed by passing it another function as an argument. To calculate the
    product of the elements in the collection, pass std::multiplies as the last
    argument of std::accumulate.
*/

#include <iostream>
#include <vector>
#include <numeric>    // std::accumulate
#include <functional> // std::multiplies

using std::cout;
using std::vector;

double average_scores(const std::vector<double>& scores);
double sum_scores(const std::vector<double>& scores);
double product_scores(const std::vector<double>& scores);

int main()
{
    vector<double> scores = {9.520, 4.981, 7.880, 7.763, 5.978, 8.654};

    double avg = average_scores(scores);
    cout << "average score: " << avg << '\n';

    double prod = product_scores(scores);
    cout << "product of scores: " << prod << '\n';
}


double average_scores(const std::vector<double>& scores) {
    return std::accumulate(scores.cbegin(), scores.cend(), 0) / (double)scores.size();
}


double sum_scores(const std::vector<double>& scores) {
    return std::accumulate(scores.cbegin(), scores.cend(), 0);
}


double product_scores(const std::vector<double>& scores) {
    return std::accumulate( scores.cbegin(), scores.cend(), 1, std::multiplies<double>() );
}
