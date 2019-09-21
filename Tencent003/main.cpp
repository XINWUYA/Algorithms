#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, x1, y1, x2, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;

	vector<pair<int, int>> PlaneStartPosSet;
	vector<float> PlaneKSet;
	vector<pair<int, int>> ModelPosSet;
	for (int i = 0; i < n; ++i)
	{
		int Ui, Li;
		cin >> Ui >> Li;
		
		if (Ui == Li)
		{
			PlaneStartPosSet.push_back(make_pair(Ui, y1));
			PlaneKSet.push_back(FLT_MAX);
		}
		else
		{
			PlaneStartPosSet.push_back(make_pair(Ui, y1));
			PlaneKSet.push_back(float(y1-y2) / float(Ui - Li));
		}
	}
	PlaneStartPosSet.push_back(make_pair(x2, y1));
	PlaneKSet.push_back(FLT_MAX);

	for (int j = 0; j < m; ++j)
	{
		int Xj, Yj;
		cin >> Xj >> Yj;
		ModelPosSet.push_back(make_pair(Xj, Yj));
	}

	vector<int> ModelsCntSet(PlaneKSet.size(), 0);
	for (auto& ModelPos : ModelPosSet)
	{
		for (int i = 0; i < PlaneKSet.size(); ++i)
		{
			if (ModelPos.second >= y2 && ModelPos.second <= y1 && ModelPos.first >= x1 && ModelPos.first <= ((ModelPos.second - PlaneStartPosSet[i].second) / PlaneKSet[i] + PlaneStartPosSet[i].first))
			{
				ModelsCntSet[i]++;
				break;
			}
		}
	}


	for (int i = 0; i < ModelsCntSet.size(); ++i)
		cout << i << ": " << ModelsCntSet[i];

	return 0;
}