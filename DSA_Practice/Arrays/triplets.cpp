#include<iostream>
#include<algorithm>

using namespace std;

	int countTriplet(int arr[], int n)
	{
	    int count = 0;
	    sort(arr,arr+n);
	    for(int i=0;i<n;++i){
	        for(int j=i+1;j<n;++j){
	            if(arr[i] + arr[j] == arr[j+1]){
	                count++;
	                break;
	            }
	            if(j == n-1){
	                break;
	            }
	        }
	    }
	    return count;
	}

int main(){
    int a[1000],n;
    cin >> n;
    for(int i=0;i< n;++i){
        cin >> a[i];
    }
    cout << countTriplet(a,n);

}