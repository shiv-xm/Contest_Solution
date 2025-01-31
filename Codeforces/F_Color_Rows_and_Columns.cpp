#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle {
    int width;
    int height;
    int maxPoints;
    long long operations;
};

bool compare(Rectangle &a, Rectangle &b) {
    return a.maxPoints > b.maxPoints;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<Rectangle> rectangles(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> rectangles[i].width >> rectangles[i].height;
            rectangles[i].maxPoints = max(rectangles[i].width, rectangles[i].height);
            rectangles[i].operations = (long long)rectangles[i].width * rectangles[i].height;
        }
        
        // Sort rectangles by the maximum points they can provide in descending order
        sort(rectangles.begin(), rectangles.end(), compare);
        
        long long totalPoints = 0;
        long long totalOperations = 0;
        
        for (const auto& rect : rectangles) {
            if (totalPoints >= k) break;
            totalPoints += rect.maxPoints;
            totalOperations += rect.operations;
        }
        
        if (totalPoints >= k) {
            cout << totalOperations << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
