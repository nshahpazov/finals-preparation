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
    elem<T>* link;
};

template <typename T>
class linked_list
{public:
    linked_list();
    ~linked_list();
    linked_list(const linked_list&);
    linked_list& operator=(const linked_list&);
    void insertBefore(elem<T>*, const T&);
    void insertAfter(elem<T>*, const T&);
    void deleteBefore(elem<T>*, T&);
    void deleteAfter(elem<T>*, T&);
    void deleteElem(elem<T>*, T&);
    
    void iterStart(elem<T>* = NULL);
    elem<T>* iter();
    void toEnd(const T&);
    
    int length() const;
    bool empty() const;
    void concat(const linked_list&);
    void print() const;
    
private:
    elem<T> *start, *end, *current;
    int size;
    
    void copyList(const linked_list&);
    void delList();
};

template <typename T>
linked_list<T>::linked_list()
{
    start = end = NULL;
    size = 0;
}

template <typename T>
linked_list<T>::~linked_list()
{
    delList();
}

template <typename T>
linked_list<T>::linked_list(const linked_list& another)
{
    copyList(another);
}

template <typename T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& another)
{
    if (this != &another) {
        delList();
        copyList(another);
    }
    return *this;
}

template <typename T>
void linked_list<T>::copyList(const linked_list<T>& another)
{
    start = end = current = NULL;
    elem<T> *p = another.start;
    
    while (p) {
        toEnd(p->inf);
        p = p->link;
    }
    size = another.size;
}

template <typename T>
void linked_list<T>::delList()
{
    elem<T> *p;
    while (start) {
        p = start;
        start = start->link;
        delete p;
    }
    end = NULL;
    size = 0;
}

template <typename T>
void linked_list<T>::iterStart(elem<T>* p)
{
    if (p) {
        current = p;
    }
    current = start;
}

template <typename T>
elem<T>* linked_list<T>::iter()
{
    elem<T> *result = current;
    if (current) {
        current = current->link;
    }
    return result;
}

template <typename T>
void linked_list<T>::toEnd(const T& val)
{
    elem<T> *p = end;
    end = new elem<T>;
    end->inf = val;
    end->link = NULL;
    if (p) {
        p->link = end;
    } else {
        start = end;
    }
    size++;
}

template <typename T>
void linked_list<T>::insertAfter(elem<T> *el, const T& val)
{
    elem<T> *p = new elem<T>;
    p->inf = val;
    p->link = el->link;
    
    el->link = p;
    if (el == end) {
        end = p;
    }
    size++;
}

template <typename T>
void linked_list<T>::insertBefore(elem<T> *p, const T& val)
{
    elem<T> *q = new elem<T>;
    *q = *p;
    p->inf = val;
    p->link = q;
    size++;
}

template <typename T>
void linked_list<T>::deleteAfter(elem<T> *p, T& val)
{
    if (p->link) {
        elem<T> *q = p->link;
        val = q->inf;
        p->link = q->link;
        if (q == end) {
            end = p;
        }
        delete q;
        size--;
    }
}


template <typename T>
void linked_list<T>::deleteElem(elem<T> *p, T& val)
{
    val = p->inf;
    if (p == start) {
        val = p->inf;
        if (start == end) {
            start = end = NULL;
            size = 0;
        } else {
            start = start->link;
            delete p;
            size--;
        }
    } else {
        elem<T> *q = start;
        while (q->link != p) {
            q = q->link;
        }
        deleteAfter(q, val);
    }
}

template <typename T>
void linked_list<T>::deleteBefore(elem<T> *p, T& val)
{
    if (p != start) {
        elem<T> *q = start;
        while (q->link != p) {
            q = q->link;
        }
        deleteElem(q);
    } else {
        cout << "there's no element before p";
        exit(1);
    }
}


template <typename T>
bool linked_list<T>::empty() const
{
    return start == NULL;
}

template <typename T>
void linked_list<T>::concat(const linked_list& another) {
    elem<T> *p = another.start;
    while (p) {
        toEnd(p->inf);
        p = p->link;
    }
}

template <typename T>
int linked_list<T>::length() const {
    return size;
}

template <typename T>
void linked_list<T>::print() const {
    elem<T> *p = start;
    while (p) {
        cout << p->inf << " ";
        p = p->link;
    }
    cout << endl;
}

template <typename T = int>
class stack : private linked_list<T> {
public:
    stack();
    ~stack();
    stack(const stack<T>&);
    stack<T>& operator=(const stack<T>&);
    
    void push(const T&);
    
    T& top() const;
    void pop(T&);

    int size() const;
    void print() const;
    bool empty() const;
};

template<typename T>
stack<T>::stack() : linked_list<T>()
{}

template<typename T>
stack<T>::~stack() {}

template<typename T>
stack<T>::stack(const stack& st) : linked_list<T>(st)
{}

template<typename T>
stack<T>& stack<T>::operator=(const stack& st)
{
    if (this != &st) {
        linked_list<T>::operator=(st);
    }
    return *this;
}

template<typename T>
bool stack<T>::empty() const
{
    return linked_list<T>::empty();
}

template<typename T>
int stack<T>::size() const
{
    return linked_list<T>::length();
}

template<typename T>
void stack<T>::print() const
{
    linked_list<T>::print();
}

template<typename T>
T& stack<T>::top() const
{
    linked_list<T>::iterStart();
    elem<T> *p = linked_list<T>::iter();
    return p->inf;
}

template<typename T>
void stack<T>::pop(T& val) {
    if (!empty()) {
        linked_list<T>::iterStart();
        elem<T> *p = linked_list<T>::iter();
        return linked_list<T>::deleteElem(p, val);
    } else {
        throw runtime_error("the stack is empty");
    }
}

template<typename T>
void stack<T>::push(const T& val) {
    if (!empty()) {
        linked_list<T>::iterStart();
        elem<T> *p = linked_list<T>::iter();
        linked_list<T>::insertBefore(p, val);
    } else {
        linked_list<T>::toEnd(val);
    }
}


template <typename T = int>
class queue : private linked_list<T> {
public:
    queue();
    ~queue();
    queue(const queue<T>&);
    queue<T>& operator=(const queue<T>&);
    
    void insert(const T&);
    
    T& front() const;
    void dequeue(T&);
    
    int length() const;
    void print() const;
    bool empty() const;
};


template<typename T>
queue<T>::queue() : linked_list<T>()
{}

template<typename T>
queue<T>::~queue() {}

template<typename T>
queue<T>::queue(const queue& q) : linked_list<T>(q)
{}

template<typename T>
queue<T>& queue<T>::operator=(const queue& q)
{
    if (this != &q) {
        linked_list<T>::operator=(q);
    }
    return *this;
}

template<typename T>
bool queue<T>::empty() const
{
    return linked_list<T>::empty();
}

template<typename T>
int queue<T>::length() const
{
    return linked_list<T>::length();
}

template<typename T>
void queue<T>::print() const
{
    linked_list<T>::print();
}

template<typename T>
T& queue<T>::front() const
{
    linked_list<T>::iterStart();
    elem<T> *p = linked_list<T>::iter();
    return p->inf;
}

template<typename T>
void queue<T>::dequeue(T& val) {
    if (!empty()) {
        linked_list<T>::iterStart();
        elem<T> *p = linked_list<T>::iter();
        return linked_list<T>::deleteElem(p, val);
    } else {
        throw runtime_error("the queue is empty");
    }
}

template<typename T>
void queue<T>::insert(const T& val) {
    linked_list<T>::toEnd(val);
}


int main()
{
    int tmp;
    linked_list<int> *l = new linked_list<int>();
    stack<int> *st = new stack<int>();
    queue<int> *q = new queue<int>();
    
    q->insert(66);
    q->insert(55);
    q->insert(7);
    q->insert(5);
    q->insert(8);
    q->dequeue(tmp);
    q->print();
    cout << q->length() << endl;
    
    cout << "after that" << endl;
    
    st->push(12);
    st->push(12);
    st->push(12);
    st->push(12);
    
    st->print();
    
    l->toEnd(12);
    l->toEnd(5);
    l->toEnd(123);
    l->toEnd(555);
    l->print();
    cout << l->length() << endl;
    return 0;
}
