#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Heap{

private:
    int cap, size;
    int* items;

    bool has_left_child(int index){
        return 2*index + 1 < size;
    }
    bool has_right_child(int index){
        return 2*index + 2 < size;
    }
    bool has_parent(int index){
        return (index-1)/2 >= 0;
    }

    int left_child_index(int index){
        return 2*index + 1;
    }
    int right_child_index(int index){
        return 2*index + 2;
    }
    int parent_index(int index){
        return (index-1)/2;
    }

    void swap(int i, int j){
        int temp = items[i];
        items[i] = items[j];
        items[j] = temp;
    }

    void heapify_up(){
        int current = size - 1;
        while(has_parent(current) && items[parent_index(current)] > items[current]){
            swap(current, parent_index(current));
            current = parent_index(current);
        }
    }

    void heapify_down(){
        int current = 0;
        while(has_left_child(current)){
            int min_child = left_child_index(current);
            if(has_right_child(current) && items[right_child_index(current)] < items[min_child]){
                min_child = right_child_index(current);
            }

            if(items[current] > items[min_child]){
                swap(current, min_child);
            }
            else{
                break;
            }

            current = min_child;
        }

    }

public:

    Heap(){
        size = 0;
        cap = 1000000;
        items = new int[cap];
    }
    ~Heap(){
        delete [] items;
    }

    void insert_in_heap(int val){
        items[size] = val;
        size++;
        heapify_up();
    }

    void delete_in_heap(){
        items[0] = items[size - 1];
        size--;
        heapify_down();
    }

    int min_element(){
        return items[0];
    }

};

int main() {
    int n;
    cin >> n;

    Heap hp;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        hp.insert_in_heap(val);
    }

    cout << "---------------------------" << endl;

    for(int i=0; i<n; i++){
        cout << hp.min_element() << " ";
        hp.delete_in_heap();
    }
    cout << endl;

    return 0;
}
