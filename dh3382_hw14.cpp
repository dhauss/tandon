#include <iostream>
#include <vector>
using namespace std;

template <class T>
vector<T> recursiveMinMax(vector<T>& v);
template <class T>
vector<T> recursiveMinMax(vector<T>& v, size_t start, size_t end);
int main() {
    vector<int> v {5, 6, 0, 10, 45, 3, 4, 7, 0, 45, 8};
    vector<int> minMax;

    minMax = recursiveMinMax(v);
    cout<<"Min: "<<minMax[0]<<endl<<"Max: "<<minMax[1]<<endl;

    return 0;
}
template <class T>
vector<T> recursiveMinMax(vector<T>& v){
    vector<T> minMax;
    minMax = recursiveMinMax(v, 0, v.size() - 1);
    return minMax;
}
template <class T>
vector<T> recursiveMinMax(vector<T>& v, size_t start, size_t end) {
    vector<T> minMax (2, v[start]);
    if (start == end) {
        return minMax;
    }
    else {
        vector<T> minMax2(2, v[start]);

        size_t mid = (start + end) / 2;
        minMax = recursiveMinMax(v, start, mid);
        minMax2 = recursiveMinMax(v, mid + 1, end);

        if(minMax2[1] > minMax[1])
            minMax[1] = minMax2[1];
        if(minMax2[0] < minMax[0])
            minMax[0] = minMax2[0];
    }
    return minMax;
}
