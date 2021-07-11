#include <iostream>
#include <vector>

namespace algorithm::greedy
{
    int Solve(int n, int r, const std::vector<int>& x)
    {
        int res = 0;

        int i = 0;
        while (i < n)
        {
            int s = x[i++];
            while (i < n && x[i] - s <= r) {++i;}
            
            int p = x[i - 1];
            while (i < n && x[i] - p <= r) {++i;}

            ++res;
        }
        
        return res;
    }
}

int main()
{
    int n, r;
    std::cin >> n >> r;

    std::vector<int> x;
    x.resize(n);
    for(int i = 0;i < n; ++i)
    {
        std::cin >> x.at(i);
    }

    std::cout << algorithm::greedy::Solve(n, r, x) << std::endl;
    return 0;
}