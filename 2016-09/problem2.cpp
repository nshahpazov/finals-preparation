#include <map>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <utility>

using namespace std;

struct tree_node {
    int value;
    vector<tree_node> children;
};

void insert_at_one(tree_node* root, int k, vector<int> numbers)
{
    for (int i = 0; i < k && !numbers.empty(); i++) {
        tree_node n;
        n.value = numbers.back();
        numbers.pop_back();
        root->children.push_back(n);
    }
}

void insert_rec(tree_node* root, int k, vector<int> numbers)
{
    for (auto child : root->children) {
        insert_at_one(&child, k, numbers);
    }
    
    for (auto child : root->children) {
        insert_rec(&child, k, numbers);
    }
}

tree_node build_tree(int k, int* arr) {
    tree_node root;
    root.value = *arr;
    set<int> set_of_numbers(arr + 1, arr + sizeof(arr));
    vector<int> vector_of_numbers;
    
    // cout << "size: " < sizeof(arr) / k << endl;

    for (auto it : set_of_numbers) {
        vector_of_numbers.push_back(it);
    }

    insert_at_one(&root, k, vector_of_numbers);
    insert_rec(&root, k, vector_of_numbers);

    return root;
}

void print(tree_node* root) {
    cout << root->value << " ";
    for (auto it : root->children) {
        cout << it.value << " ";
    }
    for (auto it : root->children) {
        print(&it);
    }
    
}

int main(int argc, const char * argv[]) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    tree_node root = build_tree(3, arr);
    
    // cout << root.value << endl;
    
    //for (auto it: root.children) {
    //    cout << it.value << " ";
   // }
    // cout << endl;
    
     print(&root);

    return 0;
}
