#include <map>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <utility>
#include <string.h>

using namespace std;

template <typename T = int>
struct node {
    T inf;
    node *left, *right;
};

template <typename T = int>
class tree
{
public:
    tree();
    ~tree();
    tree(const tree<T>&);
    tree& operator=(const tree<T>&);
    bool empty() const;
    void print() const;
    void create();
    
    node<T>* getRoot() const;
    T rootTree() const;
    
    tree leftTree() const;
    tree rightTree() const;
    
    void createTree(const T&, const tree<T>&, const tree<T>&);
private:
    node<T>* root;
    void copyTree(const tree<T>&);
    void copy(node<T>*&, node<T>* const &) const;
    
    void deleteTree(node<T>*&) const;
    void pr(const node<T>*) const;
    
    void createTree(node<T>*&) const;
};

template <typename T>
tree<T>::tree()
{
    root = NULL;
}

template <typename T>
tree<T>::~tree()
{
    deleteTree(root);
}

template <typename T>
tree<T>::tree(const tree<T>& tr)
{
    copyTree(tr);
}

template <typename T>
tree<T>& tree<T>::operator=(const tree<T>& tr)
{
    if (this != &tr) {
        deleteTree(root);
        copyTree(tr);
    }
    return *this;
}


template <typename T>
void tree<T>::copyTree(const tree<T>& tr)
{
    copy(root, tr.root);
}

template <typename T>
void tree<T>::copy(node<T>*& pos, node<T>* const& r) const
{
    pos = NULL;
    if (r) {
        pos = new node<T>();
        pos->inf = r->inf;
        copy(pos->left, r->left);
        copy(pos->right, r->right);
    }
}

template <typename T>
void tree<T>::deleteTree(node<T>*& p) const
{
    if (p) {
        deleteTree(p->left);
        deleteTree(p->right);
        delete p;
        p = NULL;
    }
}

template <typename T>
bool tree<T>::empty() const
{
    return root == NULL;
}

template <typename T>
node<T>* tree<T>::getRoot() const
{
    return root;
}

template <typename T>
T tree<T>::rootTree() const
{
    return root->inf;
}

template <typename T>
tree<T> tree<T>::leftTree() const
{
    tree<T> t;
    copy(t.root, root->left);
    return t;
}

template <typename T>
tree<T> tree<T>::rightTree() const
{
    tree<T> t;
    copy(t.root, root->right);
    return t;
}

template <typename T>
void tree<T>::pr(const node<T> * p) const
{
    if (p) {
        pr(p->left);
        cout << p->inf << " ";
        pr(p->right);
    }
}

template <typename T>
void tree<T>::print() const
{
    pr(root);
    cout << endl;
}

template <typename T>
void tree<T>::createTree(node<T>*& pos) const
{
    T x;
    char c;
    cout << "root: ";
    cin >> x;
    pos = new node<T>;
    pos->inf = x;
    pos->left = NULL;
    pos->right = NULL;
    cout << "Left: ";
    cin >> c;
    if (c == 'y') {
        createTree(pos->left);
    }

    cout << "right: ";
    cin >> c;
    if (c == 'y') {
        createTree(pos->right);
    }
}

template <typename T>
void tree<T>::create()
{
    createTree(root);
}

int main()
{
    tree<int> *t = new tree<int>();
    t->create();
    t->print();
    return 0;
}
