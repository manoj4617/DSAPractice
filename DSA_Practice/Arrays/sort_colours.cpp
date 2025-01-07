#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> colors (0);

/**
 * Sorts the given vector of colors by using the Dutch National Flag algorithm.
 * The algorithm works by maintaining 3 pointers: red, white and blue. The
 * red pointer points to the first element of the vector, the white pointer points
 * to the element just after the red pointer and the blue pointer points to the
 * last element of the vector. The algorithm then iterates over the vector and
 * swaps the elements at the white and blue pointers if the element at the white
 * pointer is equal to 2. If the element at the white pointer is equal to 0, the
 * algorithm swaps the elements at the red and white pointers and increments both
 * the red and white pointers. If the element at the white pointer is equal to 1,
 * the algorithm just increments the white pointer. The algorithm continues until
 * the white pointer is greater than the blue pointer.
 *
 * @param colors The vector of colors to be sorted.
 */
void SortColors(std::vector<int> &colors){
    int red = 0;
    int white = 0;
    int blue = colors.size() - 1;

    while(white <= blue){

        if(colors[white] == 0){
            // Swap the elements at the white and red pointers
            std::swap(colors[white], colors[red]);

            // Increment both the red and white pointers
            white++;
            red++;
        }
        else if(colors[white] == 1){
            // Increment the white pointer
            white++;
        }
        else if(colors[white] == 2){
            // Swap the elements at the white and blue pointers
            std::swap(colors[white], colors[blue]);

            // Decrement the blue pointer
            blue--;
        }
        
    }
}

void print(){
    for(auto& ele : colors){
        std::cout << ele << " "; 
    }
    std::cout << std::endl;
}

int main(){

    int size;
    std::cin >> size;

    for(int i=0;i<size;++i){
        int tmp;
        std::cin >> tmp;
        colors.emplace_back(tmp);
    }

    print();
    SortColors(colors);
    print();

    return 0;
}