#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> arr){
    if (arr.size() <= 1) {
        return arr;
    }

    int pivot = arr[0];
    vector<int> left, equal, right;

    for (auto &num : arr){
        if (num < pivot) {
            left.push_back(num);
        } else if (num > pivot) {
            right.push_back(num);
        } else {
            equal.push_back(num);
        }        
    }

    left = quickSort(left);
    right = quickSort(right);

    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = quickSort(arr);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
