#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;

   // constructors for struct
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

// Abstract Class
class Cache{
   protected:
       unordered_map<int,Node*> mp; //map the key to the node in the linked list
       int cp;  //capacity
       Node* tail; // double linked list tail pointer
       Node* head; // double linked list head pointer
       virtual void set(int, int) = 0; //set function
       virtual int get(int) = 0; //get function
};

// Inheritance
class LRUCache: public Cache{
    public:
        LRUCache(int cap){
            this->cp = cap;
        }

        void set(int k,int v){
        	// if cache is empty then add node
            if(mp.empty()){
                Node* new_node = new Node(k, v);
                this->head = this->tail = new_node;
                mp[k] = new_node;
                return;
            }

            // map iterator (Pointer) -- <key , value> -- <first, second>
            auto it = mp.find(k); // iterator pointing to pair where key = k

            // if key not in Cache
            if(it == mp.end()){
                Node* new_node = new Node(NULL, head, k, v);
                head->prev = new_node;
                head = new_node;
                mp[k] = new_node;

                // if capacity exceeded, then delete tail element
                if(mp.size() > cp){
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    delete tail->next;
                    tail->next = NULL;
                }
            }

            // else key is in Cache
            else{
                it->second->value = v; // Update value

                // If key is already at head, then return
                if(it->second == head){
                    return;
                }

                // if key is not at head then update the list
                if(it->second == tail){
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else{
                    it->second->prev->next = it->second->next;
                    it->second->next->prev = it->second->prev;
                }

                it->second->next = head;
                it->second->prev = NULL;
                head->prev = it->second;
                head = it->second;
            }
        }

        int get(int k){
            auto it = mp.find(k);
            if(it != mp.end()){
                return it->second->value;
            }
            return -1;
        }
};



int main() {
    // n is the nmber of queries and capacity is the cache size
    int n, capacity;
    cin >> n >> capacity;
    LRUCache cache(capacity);
    for(int i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        }
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            cache.set(key,value);
        }
   }
   return 0;
}
