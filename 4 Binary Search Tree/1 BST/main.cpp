#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

template <typename Key, typename Value>
class BST{

private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int count;

public:
    BST(){
        root = NULL;
        count = 0;
    }

    // Use post-order traversal to destroy the tree
    ~BST(){
        destroy(root);
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    // 1. insert
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    // 2. search

    bool contain(Key key){
        return contain(root, key);
    }

    // If the return type is Value, it can only return if the key exists in the tree
    // Use Value* allow us to return NULL if it does not exist in the tree
    Value* search(Key key){
        return search(root, key);
    }


    // 3. three ways of DFS O(N)

    void preOrder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    // 4. BFS O(N)
    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            cout << node->key << endl;

            if(node->left != NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }
    }

    // 5. find the minimum and maximum key in the BST
    Key minimum(){

        assert( count != 0 );
        Node* minNode = minimum(root);
        return minNode->key;
    }

    Key maximum(){

        assert( count != 0 );
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    // 6. remove Min node and remove Max node in the BST
    void removeMin(){
        if( root )
            root = removeMin(root);
    }

    void removeMax(){
        if(root)
            root = removeMax(root);
    }

    // 7. delete certain node in the BST : O(logN)
    // Hibbard Deletion
    void remove(Key key){
        root = remove(root, key);
    }

    // TODO: floor() and ceil() in binary search tree;
    // TODO: rank; select (Use an extra field in each node to store the # of nodes in the subtree rooted by itself)
    // TODO: use trie to calculate word frequencies


private:
    // insert a node of (key,value) into the BST rooted by node
    // return the root(node)
    // TODO: non-recursive version
    Node* insert(Node *node, Key key, Value value){

        if(node == NULL){
            count ++;
            return new Node(key,value);
        }

        if( node->key == key )
            node->value = value;
        else if( key < node->key )
            node->left = insert(node->left,key,value);
        else
            node->right = insert(node->right,key,value);

        return node;
    }

    // search if any node of key exist in the BST rooted by node
    bool contain(Node *node, Key key){

        if(node == NULL)
            return false;

        if(node->key == key)
            return true;
        else if(key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }

    Value* search(Node *node, Key key){

        if(node == NULL)
            return NULL;

        if(node->key == key)
            return &(node->value);
        else if( key < node->key )
            return search(node->left,key);
        else
            return search(node->right,key);
    }

    void preOrder(Node *node){

        if(node != NULL){
            cout<< node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node){

        if(node != NULL){
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node *node){

        if(node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
        }
    }

    void destroy(Node *node){

        if(node != NULL){
            destroy(node->left);
            destroy(node->right);

            delete node;
            count --;
        }
    }

    // find the node with minimum key in the BST rooted by node
    Node* minimum(Node *node){

        if (node->left == NULL)
            return node;

        return minimum(node->left);
    }

    // find the node with the maximum key in the BST rooted by node
    Node* maximum(Node *node){
         if(node->right == NULL)
             return node;

         return maximum(node->right);
    }

    // remove the minimum node in the BST rooted by node
    // return the root of the new BST
    Node* removeMin(Node* node){

        if(node->left == NULL){

            Node* rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

    // remove the maximum node in the BST rooted by node
    // return the root of the new BST
    Node* removeMax(Node* node){

        if(node->right == NULL){
            Node* leftNode = node->left;
            delete node;
            count -- ;
            return leftNode;
        }

        node->right = removeMax(node->right);
        return node;
    }

    // remove the node whose Key is "key" in the BST
    // return the root of the new tree
    Node* remove(Node* node, Key key){

        if(node == NULL)
            return NULL;

        if(node->key == key){
            if(node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if(node->right == NULL){
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            // node->left != NULL && node->right != NULL
            // use successor to replace node, successor s = min(node->right)
            // TODO: use predecessor p = max(node->left) can do the same thing
            Node* successor = new Node(minimum(node->right));
            count ++;
            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete node;
            count--;
            return successor;

        }
        else if(key < node->key){
            node->left = remove(node->left,key);
            return node;
        }
        else{ // key > node->key
            node->right = remove(node->right,key);
            return node;
        }

    }

};

int main() {

    return 0;
}