#include <map>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <string.h>

using namespace std;
template <typename T>
struct elem {
    T inf;
    elem* link;
};

template <typename T>
class stack
{public:
    stack();
    ~stack();
    stack(const stack&);
    stack& operator=(const stack&);
    bool empty() const;
    void push(const T&);
    T& top() const;
    T& pop();
    int size() const;
    void print();
private:
    elem<T> *start;
    int _size;
    void copyStack(const stack&);
    void deleteStack();
};

template <typename T>
stack<T>::stack()
{
    start = NULL;
    _size = 0;
}

template <typename T>
stack<T>::~stack()
{
    deleteStack();
}

template <typename T>
stack<T>::stack(const stack<T>& anotherStack)
{
    copyStack(anotherStack);
    _size = anotherStack.size();
}

template <typename T>
stack<T>& stack<T>::operator=(const stack<T>& anotherStack)
{
    if (this != &anotherStack) {
        deleteStack();
        copyStack(anotherStack);
    }
    return *this;
}

template <typename T>
void stack<T>::copyStack(const stack<T>& anotherStack)
{
    elem<T> *current = anotherStack.start;
    elem<T> *ours = NULL;
    elem<T> *tmp = NULL;
    
    if (!anotherStack.start) {
        start = NULL;
        return;
    }
    
    start = new elem<T>;
    start->inf = current->inf;
    ours = start;
    current = current->link;
    while (current) {
        tmp = new elem<T>;
        tmp->inf = current->inf;

        ours->link = tmp;
        ours = tmp;

        current = current->link;
    }
    _size = anotherStack.size();
}

template <typename T>
void stack<T>::deleteStack()
{
    elem<T> *current;
    while (start) {
        current = start;
        start = start->link;
        delete current;
    }
}

template <typename T>
bool stack<T>::empty() const
{
    return _size == 0;
}

template <typename T>
void stack<T>::push(const T& value)
{
    elem<T> *p = start;
    start = new elem<T>;
    start->inf = value;
    start->link = p;
    _size++;
}

template <typename T>
T& stack<T>::pop()
{
    if (!start) {
        throw runtime_error("The stack is empty");
    }
    elem<T> *p = start;
    T result = start->inf;
    start = start->link;
    delete p;
    _size--;

    return result;
}

template <typename T>
T& stack<T>::top() const
{
    if (empty()) {
        throw runtime_error("The stack is empty");
    }
    return start->inf;
}


template <typename T>
void stack<T>::print()
{
    if (!start) {
        cout << "The stack is empty";
        return;
    }
    
    elem<T> *p = start;
    while (p) {
        cout << p->inf << " ";
        p = p->link;
    }
    cout << endl;
}

int main()
{
    cout << "testing stack" << endl;
    stack<int> *st = new stack<int>();
    st->push(3);
    st->push(2);
    st->push(1);
    cout << st->top();
    st->pop();
    cout << st->top();
    st->pop();
    cout << st->top();
    st->pop();
    cout << st->top();
    st->pop();
    return 0;
}
