#include <iostream>
#include <vector>
using namespace std;

void Bubble_Sort(vector<int> &v1){
    int length = v1.size();
    for (int i = 0; i < length -1; i++){
        for (int j = 0; j <length - 1 - i; j++){
            if(v1[j]>v1[j+1]){
                swap(v1[j],v1[j+1]);
            }
        }
    }

}



int main(){
    vector<int> vec1{3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    Bubble_Sort(vec1);
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ' ';
    }
    cout << endl;
    return 0;
}