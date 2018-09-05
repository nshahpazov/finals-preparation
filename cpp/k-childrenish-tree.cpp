#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int inf;
    vector<node*> children;
};

node* build_tree(int k, int arr[], int n)
{
    node *root = new node();;
    int i = 1;
    queue<node*> q;
    if (n > 0) {
        root->inf = arr[0];
        q.push(root);
    }

    while (!q.empty() && i < n) {
        node *current = q.front();
        q.pop();

        for (int j = 0; j < k && i < n; j++, i++) {
            node *el = new node();
            el->inf = arr[i];
            
            current->children.push_back(el);
            q.push(el);
        }
    }
    return root;
}

int main()
{
    // int arr[3] = {1,2,3};
//    cout << sizeof(arr) / sizeof(int);
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    node* root = build_tree(3, arr, 10);
    
    // print the tree in a dummy way (non-recursive)
    cout << root->inf << endl;
    for (auto it : root->children) {
        cout << it->inf << " ";
        
    }
    cout << endl;
    
    for (auto it : root->children) {
        for (auto it2: it->children) {
            cout << it2->inf << " ";
        }
    }
    cout << endl;

    vector<int> list;
    list.push_back(12);
    cout << list.front() << endl;
    
    return 0;
}

