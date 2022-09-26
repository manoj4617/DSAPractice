#include<iostream>
#include<vector>

using namespace std;

/******************** approach-1 copy paste ******************/
// void rotate_array(int arr[], int n, int d){
//     int temp[n],i;
//     int d_1 = d;

//     for(i=0;i<n,d_1<n;++i){
//         temp[i] = arr[d_1];
//         d_1++;
//     }

//     for(int j = 0;j<d;++j){
//         temp[i] = arr[j];
//         i++;
//     }
//     for (int i = 0; i < n; i++) {
//         arr[i] = temp[i];
//     }
// }


/******************* approach-2 rotation*******************/
// void rotate_array(vector<int> arr,int d){
//     int temp, i = 1;
//     while(i <= d){
//         temp = arr[0];
//         for(int j=0;j<arr.size()-1;++j){
//             arr[j] = arr[j+1];
//         }
//         arr[arr.size()-1] = temp;
//         i++;
//     }
// }

/****************** approach-3 GCD****************************/
// int gcd(int a , int b){
//     if(b == 0) return a;
//     else return gcd(b,a%b);
// }
// void rotate_array(vector<int> arr,int d){
//     int g = gcd(d,arr.size());
//     d = d%arr.size();

//     for(int i=0;i<g;++i){
//         int temp = arr[i];
//         int j = i;
//         while(1){
//             int k = j + d;
//             if(k >= arr.size())  k-=arr.size();
//             if(k == i) break;
//             arr[j] = arr[k];
//             j = k;
//         }
//         arr[j] = temp;
//     }
// }

/****************** approach-4 reversing ****************************/
void reverse_array(vector<int> arr, int start, int end){
    int temp;
    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate_array(vector<int> arr,int d){
    if(d == 0)
        return;

    d = d%arr.size();

    reverse_array(arr,0,d-1);
    reverse_array(arr,d,arr.size()-1);
    reverse_array(arr,0,arr.size()-1);
}

void PrintTheArray(vector<int> arr)
{
    for (auto i : arr) {
        cout << i << " ";
    }
}


int main(){

    int n,d,t;
    cin >> n >> d;
    vector<int> A;
    for(int i=0;i<n;++i){
        cin >> t;
        A.push_back(t);
    }

    rotate_array(A,d);
    PrintTheArray(A);
    return 0;
}