#include <iostream>
#include <cmath>

using namespace std;

// 1.0e-5 == 0.000010
int CompareDoubleAbsoulte(double x, double y, double absTolerance = (1.0e-2)) {
    double diff = x - y;
    if (fabs(diff) <= absTolerance)
        return 0;

    return (diff > 0) ? 1 : -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//cout.setf(ios::fixed);
	//cout.precision(6);
 
	double inch = 0;
	double ratio_h = 0, ratio_w = 0;

	cin >> inch >> ratio_h >> ratio_w;

	for(double h=99.0; h>=1; h-=0.001) {
		for(double w=100.0; w>h; w-=0.001) {
			//cout << h << ' ' << w << "        " << w/h << "        " << h*h + w*w << '\n';
			if(CompareDoubleAbsoulte(inch*inch, h*h + w*w) == 0 && CompareDoubleAbsoulte(ratio_w/ratio_h, w/h) == 0) {
				//cout << h << ' ' << w << "        " << w/h << '\n';
				//cout << h << ' ' << w << "        " << w/h << '\n';
				cout << (int)h << ' ' << (int)w << '\n';
				//cout << (int)h << ' ' << (int)w << '\n';
				return 0;
			}
			else if(CompareDoubleAbsoulte(inch*inch, h*h + w*w) == 1 || CompareDoubleAbsoulte(ratio_w/ratio_h, w/h) == 1) {
				break;
			}
		}
	}

	return 0;
}