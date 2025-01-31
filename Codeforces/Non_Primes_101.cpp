#include <iostream>
#include <vector>
using namespace std;

void precomputePrimes(vector<bool>& is_prime) {
    int max_val = 200;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= max_val; ++i) {
        is_prime[i] = true;
    }
    
    for (int i = 2; i * i <= max_val; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_val; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    vector<bool> is_prime(201, false);
    precomputePrimes(is_prime);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<int> freq(101, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            freq[A[i]]++;
        }

        bool found = false;
        for (int i = 1; i <= 100 && !found; ++i) {
            if (freq[i] == 0) continue;
            for (int j = i; j <= 100; ++j) {
                if (freq[j] == 0) continue; 
                int sum = i + j;
            
                if (!is_prime[sum]) {
                    if (i == j && freq[i] < 2) continue; 
                
                    int first_index = -1, second_index = -1;
                    for (int k = 0; k < N; ++k) {
                        if (A[k] == i && first_index == -1) {
                            first_index = k + 1;
                        } else if (A[k] == j && second_index == -1) {
                            second_index = k + 1;
                        }
                        if (first_index != -1 && second_index != -1) break;
                    }
                    cout << first_index << " " << second_index << endl;
                    found = true;
                    break;
                }
            }
        }


        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
