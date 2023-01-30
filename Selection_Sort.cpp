#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &v1){
    int length = v1.size();
    if (length != 0 || length > 1){
        for(int i = 0; i < length - 1; i++){
            int min_index = i;
            for (int j = i + 1; j < length; j++){
                if(v1[j] < v1[min_index]){
                    min_index = j;
                }
            }
            swap(v1[i],v1[min_index]);
        }
    }
    else{
        cout << "This vector elements are not valid." <<endl;
    }

}



int main(){
    vector<int> vec1{3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    SelectionSort(vec1);
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ' ';
    }
    cout << endl;
    return 0;
}