#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());

	// std::uniform_real_distribution<double> rnd(0.0, 1.0);
	std::uniform_real_distribution<double> rnd(0.0, 1.0-exp(-1.0)); // PDFの範囲を0~1にする

	vector<pair<double, int>> count;

	for (int i = 0; i < 5000; ++i)
	{
		double u = rnd(mt);

		// 指数分布(平均を1として)の累積分布関数
		double res = -log(1.0 - u);

		int j;
		for (j = 0; j < count.size(); ++j)
		{
			// 差分が小数点第2位以下の場合同じ値とみなす
			if (abs(res - count[j].first) < 1e-2)
			{
				count[j].second++;
				break;
			}
		}

		// 既出の値でなければ追加
		if (j == count.size())
		{
			count.push_back(pair<double, int>(res, 1));
		}
	}

	// 累積分布関数の値をソート
	sort(count.begin(), count.end());

	for (int j = 0; j < count.size(); ++j)
	{
		cout << count[j].first << " " << count[j].second << endl;
	}
	return 0;
}
