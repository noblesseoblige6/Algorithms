#include <iostream>
#include <string>

namespace algorithm::greedy
{
    std::string Solve(const std::string &in)
    {
        std::string res;
        int a = 0, b = in.size()-1;

        while (a <= b)
        {
            bool left = false;
            for(int i = 0; a+i <= b; ++i)
            {
                if(in[a+i] < in[b-i])
                {
                    left = true;
                    break;
                }
                else if (in[a + i] > in[b - i])
                {
                    left = false;
                    break;
                }
            }

            res += (left) ? in[a++] : in[b--];
        }

        return res;
    }
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << algorithm::greedy::Solve(str) << std::endl;
    return 0;
}