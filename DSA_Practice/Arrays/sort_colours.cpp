#include <iostream>
#include <vector>

std::vector<int> colors (0);

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void SortColors(std::vector<int> &colors){
    int red = 0;
    int white = 0;
    int blue = colors.size() - 1;

    while(white <= blue){

        if(colors[white] == 0){
            swap(&colors[white], &colors[red]);
            white++;
            red++;
        }
        else if(colors[white] == 1){
            white++;
        }
        else if(colors[white] == 2){
            swap(&colors[white], &colors[blue]);
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