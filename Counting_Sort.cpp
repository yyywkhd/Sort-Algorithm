#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Counting_Sort(vector<int> &vec1){
    int length = vec1.size();
    if (length <= 0){
        return;
    }
    int min_value = vec1[0], max_value = vec1[0];
    for (int i = 0; i < length; i++){
        min_value = min(min_value,vec1[i]);
        max_value = max(max_value,vec1[i]);
    }
    vector<int> temp_array(max_value-min_value + 1,0);
    int bias_index = 0 - min_value;
    for (int i = 0; i < length; i++){
        temp_array[vec1[i]+bias_index]++;
    }
    int index = 0; int value = 0;
    while(index < length){
        if(temp_array[value]){
            vec1[index] = value - bias_index;
            temp_array[value]--;
            index++;
        }else{
            value++;
        }
    }

}


int main(){
    vector<int> vec1{3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    Counting_Sort(vec1);
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ' ';
    }
    cout << endl;
    return 0;
}