#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void Bucket_Sort(vector <int> &vec1, int Bucket_Size){
    int length = vec1.size();
    if (length < 2){
        return;
    }
    int min_v = vec1[0],max_v = vec1[0];
    for (int i = 0; i < length; i++){
        min_v = min(min_v,vec1[i]);
        max_v = max(max_v,vec1[i]);
    }
    int bk_count = (max_v - min_v) / Bucket_Size + 1;
    vector<int> bk_arr[bk_count];
    for (int i = 0; i < length; i++){
        bk_arr[(vec1[i]-min_v)/Bucket_Size].push_back(vec1[i]);
    }
    vec1.clear();
    for (int j = 0; j < bk_count; j++){
        int each_bk_size = bk_arr[j].size();
        sort(bk_arr[j].begin(),bk_arr[j].end());
        for (int i = 0; i < each_bk_size; i++){
            vec1.push_back(bk_arr[j][i]);
        }
    }

}

int main(){
    vector<int> vec1{3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    // Just setted 5 as the bucket size
    int Bucket_Size = 5;
    Bucket_Sort(vec1,Bucket_Size);
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ' ';
    }
    cout << endl;
    return 0;
}