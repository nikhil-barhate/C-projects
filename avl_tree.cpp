#include <iostream>

using namespace std;

struct Node{
    int val;
    int height;
    Node* left;
    Node* right;
};

class AVL{
    public:
        struct Node* root = NULL;

        int getHeight(struct Node* node){
            if(node == NULL){
                return 0;
            }
            return node->height;
        }

        int insert(int val){
            struct Node* new_node = new Node();

            new_node->val = val;
            new_node->height = 1;
            new_node->left = NULL;
            new_node->right = NULL;

            if(root == NULL){
                root = new_node;
            }
            else{
                root = insert_helper(new_node, root);
            }

            return 0;
        }

        struct Node* insert_helper(struct Node* new_node, struct Node* node){
            // Insert Element
            if(new_node->val > node->val){
                if(node->right == NULL){
                    node->right = new_node;
                }
                else{
                    node->right = insert_helper(new_node, node->right);
                }
            }
            else if(new_node->val < node->val){
                if(node->left == NULL){
                    node->left = new_node;
                }
                else{
                    node->left = insert_helper(new_node, node->left);
                }
            }
            // Update Heights
            node->height = max(getHeight(node->right), getHeight(node->left)) + 1;

            // Balance
            struct Node* new_root = node;
            int balance_factor = getHeight(node->right) - getHeight(node->left);

            if(balance_factor > 1){ // RightRight or RightLeft
                // RightRight
                if(new_node->val > node->right->val){
                    new_root = leftRotate(node);
                }
                // RightLeft
                else{
                    node->right = rightRotate(node->right);
                    new_root = leftRotate(node);
                }
            }
            else if(balance_factor < -1){ // LeftLeft or LeftRight
                // LeftLeft
                if(new_node->val < node->left->val){
                    new_root = rightRotate(node);
                }
                // LeftRight
                else{
                    node->left = leftRotate(node->left);
                    new_root = rightRotate(node);
                }
            }

            return new_root;
        }

        struct Node* rightRotate(struct Node* x){
            /*
                          x                     y
                        /  \                  /  \
                      y    t1      >>>      z     x
                    /  \                        /  \
                  z     t2                    t2    t1

            */
            struct Node* y = x->left;
            struct Node* t2 = y->right;

            y->right = x;
            x->left = t2;

            x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
            y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

            return y;
        }

        struct Node* leftRotate(struct Node* x){
            /*
                        x                       y
                      /  \                    /  \
                    t1    y       >>>       x     z
                        /  \              /  \
                      t2    z           t1    t2

            */
            struct Node* y = x->right;
            struct Node* t2 = y->left;

            y->left = x;
            x->right = t2;

            x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
            y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

            return y;
        }


        void inOrder(){
            inOrder_helper(root);
        }

        void inOrder_helper(struct Node* node){
            if(node == NULL){
                return;
            }
            else{
                inOrder_helper(node->left);
                cout << node->val << " ";
                inOrder_helper(node->right);
            }
        }


        void inOrder_height(){
            inOrder_height_helper(root);
        }

        void inOrder_height_helper(struct Node* node){
            if(node == NULL){
                return;
            }
            else{
                inOrder_height_helper(node->left);
                cout << node->height << " ";
                inOrder_height_helper(node->right);
            }
        }


        void preOrder(){
            preOrder_helper(root);
        }

        void preOrder_helper(struct Node* node){
            if(node == NULL){
                return;
            }
            else{
                cout << node->val << " ";
                preOrder_helper(node->left);
                preOrder_helper(node->right);
            }
        }


        void postOrder(){
            postOrder_helper(root);
        }

        void postOrder_helper(struct Node* node){
            if(node == NULL){
                return;
            }
            else{
                postOrder_helper(node->left);
                postOrder_helper(node->right);
                cout << node->val << " ";
            }
        }

};


int main(){
    int cmd = -1;

    AVL tr;

    cout << "----------------------------" << endl;
    cout << "Commands : " << endl;
    cout << " 0 - Insert" << endl;
    cout << " 1 - In Order Traversal" << endl;
    cout << " 2 - Pre Order Traversal" << endl;
    cout << " 3 - Post Order Traversal" << endl;
    cout << "-1 - To exit" << endl;

    while(true){
        cout << "----------------------------" << endl;
        cout << "Enter Command : ";
        cin >> cmd;

        if(cmd == 0){
            int val;
            cout << "Enter value : " ;
            cin >> val;

            tr.insert(val);

            tr.inOrder();
            cout << endl;
            tr.inOrder_height();
            cout << endl;
        }

        if(cmd == 1){
            tr.inOrder();
            cout << endl;
            tr.inOrder_height();
            cout << endl;
        }

        if(cmd == 2){
            tr.preOrder();
            cout << endl;
        }

        if(cmd == 3){
            tr.postOrder();
            cout << endl;
        }

        if(cmd < 0){
            cout << "----------------------------" << endl;
            break;
        }

    }

    return 0;
}
