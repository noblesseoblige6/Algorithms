#include "acLib_PCH.h"

using namespace std;
using namespace acLib::cgl;
using namespace acLib::psl;
using namespace acLib::mat;

int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());

    vector<double> func;
    for (int i = 0; i < 5000; ++i)
    {
        double x = (i / 5000.0);
        func.push_back(exp(-x));
    }

    ProbabilityDensity1D pd(func);

    std::uniform_real_distribution<double> rnd(0.0, 1.0);

    vector<pair<double, int>> count;

    for (int i = 0; i < 5000; ++i)
    {
        double u = rnd(mt);

        double res = pd.SampleContinuous(u);

        int j;
        for (j = 0; j < count.size(); ++j)
        {
            // �����������_��2�ʈȉ��̏ꍇ�����l�Ƃ݂Ȃ�
            if (abs(res - count[j].first) < 1e-2)
            {
                count[j].second++;
                break;
            }
        }

        // ���o�̒l�łȂ���Βǉ�
        if (j == count.size())
        {
            count.push_back(pair<double, int>(res, 1));
        }
    }

    // �ݐϕ��z�֐��̒l���\�[�g
    sort(count.begin(), count.end());

    for (int j = 0; j < count.size(); ++j)
    {
        cout << count[j].first << " " << count[j].second << endl;
    }

    return 0;
}