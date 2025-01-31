#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        int result = 0;
        
     for(int L=0; L<N; L++){
            set<int> initial_elements;
             set<int> final_elements;
            
        for(int i=0; i<N; i++){
            initial_elements.insert(A[i]);
            
        }
        for(int R=L; R<N; R++){
           final_elements.clear();
    
        for(int i=0; i<L; i++){
            final_elements.insert(A[i]);
        }
        for(int i=L; i<=R; i++){
            final_elements.insert((A[i]%3)+1);
        }
        for(int i =R+1; i<N; i++){
            final_elements.insert(A[i]);
        }
        if(final_elements.size()==3){
            result++;
        }
     }
   }
    cout<<result<<endl;
  }
  return 0;
    
}
