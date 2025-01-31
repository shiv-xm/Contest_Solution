#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> passExam(int t, vector<tuple<int, int, int, vector<int>, vector<int>>> test_cases) {
    vector<string> results;

    for (const auto& test_case : test_cases) {
        int n = get<0>(test_case);
        int m = get<1>(test_case);
        int k = get<2>(test_case);
        const vector<int>& a = get<3>(test_case); // List indices of missing questions
        const vector<int>& q = get<4>(test_case); // Questions Monocarp knows

        // Store known questions in a set for quick lookup
        unordered_set<int> known_questions(q.begin(), q.end());

        // Generate the result string for the current test case
        string result = "";
        for (int missing : a) {
            if (known_questions.size() == n - 1 && known_questions.count(missing) == 0) {
                result += "1";
            } else {
                result += "0";
            }
        }

        results.push_back(result);
    }

    return results;
}

int main() {
    int t;
    cin >> t;

    vector<tuple<int, int, int, vector<int>, vector<int>>> test_cases(t);
    for (int i = 0; i < t; ++i) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[j];
        }

        vector<int> q(k);
        for (int j = 0; j < k; ++j) {
            cin >> q[j];
        }

        test_cases[i] = {n, m, k, a, q};
    }

    vector<string> results = passExam(t, test_cases);

    for (const string& result : results) {
        cout << result << "\n";
    }

    return 0;
}
