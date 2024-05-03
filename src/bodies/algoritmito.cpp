#include <iostream> 

using namespace std; 

Container cont1(50,100, 100); 
Container cont2(25, 50, 50); 
Container cont3(15, 25, 25); 

vector<Box> boxes; 
vector<Container> containers_used; 

class Box {
    private: 
        const int length, width, height, volume; 
    public: 
        box(l, w, h){
            length = l; 
            width = w; 
            height = h; 
            volume = height * width * height; 
        }
        int get_length(){
            return length; 
        }
        int get_width(){
            return width; 
        }
        int get_height(){
            return height; 
        }
        int get_volume(){
            return volume; 
        }
}; 

class Container {
    private: 
        const int height, width, length, volume; 
        int matrix[length][width][volume]; 
    public: 
        box(h, w, l){
            height = h; 
            width = w; 
            length = l;  
            volume = height * width * height; 
        }
        int get_length(){
            return length; 
        }
        int get_width(){
            return width; 
        }
        int get_height(){
            return height; 
        }
        int get_volume(){
            return volume; 
        }
        void print_matrix(){
            for(int i = 0; i < length; i++){
                cout << "Length " << i << endl; 
                for(int j = 0; j < width; j++){
                    for(int k = 0; k < height; k++){
                        cout << matrix[i][j][k] << " "; 
                    }
                    cout << endl; 
                }
            }
        }
}; 

void algorithm(vector<Box> boxes){
    for(int i = 0; i < boxes.size(); i++){

    }
}


int main(){
    algorithm(boxes); 


}