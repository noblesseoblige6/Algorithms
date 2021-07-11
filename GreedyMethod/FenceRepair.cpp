#include <iostream>
#include <vector>

namespace algorithm::greedy
{
    int Solve(int n, std::vector<int> &val)
    {
        int res = 0;
        while (n > 1)
        {
            int min_index1 = 0, min_index2 = 1;
            if (val[min_index1] > val[min_index2])
                std::swap(min_index1, min_index2);

            for (int i = 2; i < n; ++i)
            {
                if (val[i] < val[min_index1])
                {
                    min_index2 = min_index1;
                    min_index1 = i;
                }
                else if (val[i] < val[min_index2])
                {
                    min_index2 = i;
                }
            }

            int tmp = val[min_index1] + val[min_index2];
            res += tmp;

            if (min_index1 == n - 1)
                std::swap(min_index1, min_index2);
            val[min_index1] = tmp;
            val[min_index2] = val[n - 1]; //Note: last element won't be referenced, so move to at min_index2

            --n;
        }

        return res;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> values(n);
    for (int i = 0; i < n; ++i)
        std::cin >> values.at(i);

    std::cout << algorithm::greedy::Solve(n, values) << std::endl;

    return 0;
}