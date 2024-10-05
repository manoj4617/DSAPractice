#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * isValid is a helper function that checks if it is possible to distribute the books fairly
 * with the given maximum number of pages.
 *
 * The function takes a vector of integers, the number of books, the number of students, and
 * the maximum number of pages as input.
 *
 * The function first initializes the number of students to 1, and the sum of the pages to 0.
 *
 * Then the function loops over the vector of books, and for each book, it adds the number of
 * pages to the sum. If the sum exceeds the maximum number of pages, the number of students is
 * incremented by 1 and the sum is reset to the number of pages in the current book.
 *
 * If the number of students exceeds the number of students given as input, the function returns
 * false to indicate that it is impossible to distribute the books fairly with the given
 * maximum number of pages.
 *
 * Otherwise, the function returns true to indicate that it is possible to distribute the books
 * fairly with the given maximum number of pages.
 */
bool isValid(const vector<int>& books, int n , int students, int max_pages){
    int st = 1;
    int sum = 0;

    for(int i=0;i<n;++i){
        sum += books[i];
        if(sum > max_pages){
            st++;
            sum = books[i];
        }
        if(st > students){
            return false;
        }
    }
    return true;
}


/**
 * AllocatePages is a function that takes a vector of integers and an integer as input
 * and returns the minimum number of pages that each student needs to have in order
 * to distribute the books fairly.
 *
 * The function first checks if the number of books is less than the number of students.
 * If it is, the function returns -1 to indicate that it is impossible to distribute the
 * books fairly.
 *
 * Then the function sets the lower and upper bounds of the search window to the
 * minimum and maximum number of pages of the books respectively.
 *
 * The function then performs a binary search in the search window to find the minimum
 * number of pages that each student needs to have in order to distribute the books fairly.
 * The search function isValid is used to check if it is possible to distribute the books
 * fairly with the given number of pages.
 *
 * If it is possible to distribute the books fairly with the given number of pages,
 * the function sets the result to the current number of pages and narrows the search
 * window to the lower half. Otherwise, the function sets the result to -1 and narrows
 * the search window to the upper half.
 *
 * The function continues to search until the search window is empty, and then returns
 * the result.
 */
int AllocatePages(const vector<int>& books, int students){
    int n = books.size();
    if(n < students){
        return -1;
    }

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    int res = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(isValid(books, n ,students, mid)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> books(n);
    for(int i=0;i<n;++i){
        cin >> books[i];
    }
    int m;
    cin >> m;
    cout << AllocatePages(books, m);
    return 0;
}