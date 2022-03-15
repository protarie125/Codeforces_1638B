#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		int n;
		cin >> n;

		auto ais = vi(n);
		for (int i = 0; i < n; ++i) {
			cin >> ais[i];
		}

		auto mxeven = vi(n, -1);
		auto mxodd = vi(n, -1);
		for (int i = 1; i < n; ++i) {
			if (0 == ais[i - 1] % 2) {
				if (mxeven[i - 1] < 0) {
					mxeven[i] = ais[i - 1];
				}
				else {
					mxeven[i] = ais[i - 1] < mxeven[i - 1] ? mxeven[i - 1] : ais[i - 1];
				}

				mxodd[i] = mxodd[i - 1];
			}
			else {
				if (mxodd[i - 1] < 0) {
					mxodd[i] = ais[i - 1];
				}
				else {
					mxodd[i] = ais[i - 1] < mxodd[i - 1] ? mxodd[i - 1] : ais[i - 1];
				}

				mxeven[i] = mxeven[i - 1];
			}
		}

		auto mneven = vi(n, -1);
		auto mnodd = vi(n, -1);
		for (int i = n - 2; 0 <= i; --i) {
			if (0 == ais[i + 1] % 2) {
				if (mneven[i + 1] < 0) {
					mneven[i] = ais[i + 1];
				}
				else {
					mneven[i] = mneven[i + 1] < ais[i + 1] ? mneven[i + 1] : ais[i + 1];
				}

				mnodd[i] = mnodd[i + 1];
			}
			else {
				if (mnodd[i + 1] < 0) {
					mnodd[i] = ais[i + 1];
				}
				else {
					mnodd[i] = mnodd[i + 1] < ais[i + 1] ? mnodd[i + 1] : ais[i + 1];
				}

				mneven[i] = mneven[i + 1];
			}
		}

		auto isOk = bool{ true };
		for (int i = 0; i < n; ++i) {
			if (0 == ais[i] % 2) {
				if ((-1 != mxeven[i] && ais[i] < mxeven[i]) ||
					(-1 != mneven[i] && mneven[i] < ais[i])) {
					isOk = false;
					break;
				}
			}
			else {
				if ((-1 != mxodd[i] && ais[i] < mxodd[i]) ||
					(-1 != mnodd[i] && mnodd[i] < ais[i])) {
					isOk = false;
					break;
				}
			}
		}

		cout << (isOk ? "Yes" : "No") << '\n';
	}

	return 0;
}