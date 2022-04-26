<<<<<<< HEAD
#ifndef _LIST_
#define _LIST_
#include <cassert>
#include <iostream>

template <typename T>
class node {
public: // ≈сть ли возможность сделать эту область private
    //friend class List;
    //friend class polinom;

    T data;
    node* next;
public:
    node();                                      
    node(const T& m_data);                               
    node(const node& a);                          //  опирует только data, указатель на следующий - nullptr
    bool operator==(const node<T>& m_node);
    bool operator<(const node& m_node);
    bool operator>(const node& m_node);
    bool operator>=(const node& m_node);
};


template <typename T>
class List {
protected:
    node<T>* first;
    int Size;
public:
    class iterator;

    List();
    List(const T& data_m);
    List(node<T>* Node_m);                              //Copy-constructor
    List(const List& List_m);
    List(List&& m_list);
    ~List();

    List<T>& operator=(const List& List_m);
    List<T>& operator=(List&& List_m);

    T read_first() { return first->data; }
    int size() { return Size; }
    bool empty() { return ((first) ? 0 : 1); }


    void delElem(T data_m);
    void clear();

    void push_front(const T& m_data);

    void push_back(const T& m_data);
    void push_back(node<T>* Node_m);
    void pop_front();
    void pop_back();

    void reverse();

    iterator begin() { return iterator(first); }
    iterator begin() const { return iterator(first); }
    iterator end() { return iterator(nullptr); }
    iterator end() const { return iterator(nullptr); }
    void sort();
    node<T>* merge_sort(node<T>* a);
    node<T>* get_middle(node<T>* a);
    node<T>* merge(node<T>* first_node, node<T>* second_node);

    void show();

    class iterator
    {
    private:
        friend class Monom;
        node<T>* currentNode;
    public:

        iterator()
            : currentNode(nullptr) {}

        iterator(node<T>* Node_m)
            : currentNode(Node_m) {}

        iterator& operator=(node<T>* Node_m)
        {
            currentNode = Node_m;
            return *this;
        }

        iterator& operator++()
        {
            if (currentNode)
            {
                currentNode = currentNode->next;
            }
            return *this;
        }


        iterator& operator++(int)
        {
            iterator it = *this;
            ++* this;
            return it;
        }

        bool operator!=(const iterator& it)
        {
            return (currentNode != it.currentNode);
        }

        bool operator==(const iterator& it) {
            return (currentNode == it.currentNode);
        }

        T& operator*()
        {
            return currentNode->data;
        }
    };
};



template <typename T>
node<T>::node()
    : data(0)
    , next(nullptr) {}

template <typename T>
node<T>::node(const T& m_data)
    : data(m_data)
    , next(nullptr) {}

template <typename T>
node<T>::node(const node& a)
    : data(a.data)
    , next(nullptr) {}

template <typename T>
bool node<T>::operator==(const node<T>& m_node) {
    return(data == m_node.data);
}

template <typename T>
bool node<T>::operator>(const node<T>& m_node) {
    return(data > m_node.data);
}

template <typename T>
bool node<T>::operator<(const node<T>& m_node) {
    return(data < m_node.data);
}

template <typename T>
bool node<T>::operator>=(const node<T>& m_node) {
    return(data >= m_node.data);
}

template<typename T>
List<T>::List()
    : Size(0)
    , first(nullptr) {}

template<typename T>
List<T>::List(const T& data_m)
    : first(new node<T>(data_m))
    , Size(1)
{}

template<typename T>
List<T>::List(node<T>* Node_m)
    : first(new node<T>(Node_m->data))
    , Size((Node_m == nullptr) ? 0 : 1) {}

template<typename T>
List<T>::List(const List& List_m)
    : Size(0)
    , first(nullptr)
{
    List<T>::iterator it = List_m.begin();

    for (it; it != List_m.end(); it++)
    {
        this->push_back(*it);
    }
}

template<typename T>
List<T>::List(List&& m_list)
    : first(m_list.first)
    , Size(m_list.size)
{
    m_list.first = nullptr;
    m_list.Size = 0;
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T>& List<T>::operator=(const List& List_m) {
    if (first == List_m.first)
        return *this;
    if (this->empty())
    {
        List<T>::iterator it = List_m.begin();

        for (it; it != List_m.end(); it++)
        {
            this->push_back(*it);
        }
    }
    else
    {
        this->clear();
        List<T>::iterator it = List_m.begin();

        for (it; it != List_m.end(); it++)
        {
            this->push_back(*it);
        }
    }
}

template <typename T>
List<T>& List<T>::operator=(List&& List_m) {
    if (first != nullptr) {
        clear();
    }
    first = List_m.first;
    Size = List_m.Size();

    List_m.first = nullptr;
    List_m.Size = 0;

    return *this;
}

template<typename T>
void List<T>::push_front(const T& data_m) {
    if (!first)
        first = new node<T>(data_m);
    else {
        node<T>* new_node = new node<T>(data_m);

        new_node->next = first;
        first = new_node;
    }
}

template <typename T>
void List<T>::push_back(const T& m_data) {
    if (empty())
    {
        first = new node<T>(m_data);
        first->data = m_data;
    }
    else
    {
        node<T>* current = first;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new node<T>(m_data);
    }

    Size++;
}

template <typename T>
void List<T>::push_back(node<T>* Node_m) {
    if (empty()) {
        first = new node<T>(*Node_m);
    }
    else {
        node<T>* current = first;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new node<T>(*Node_m);
    }

    Size++;
}

template<typename T>
void List<T>::delElem(T data_m)
{
    while (first->data == data_m)
    {
        pop_front();
    }
    if (!empty())
    {
        node<T>* prev = first;
        node<T>* curr = first->next;

        while (curr != nullptr)
        {
            if (curr->data == data_m)
            {
                node<T>* temp = curr;
                curr = curr->next;
                prev->next = curr;

                delete temp;
                Size--;
            }
            else if (curr != nullptr) {        
                prev = prev->next;
                curr = curr->next;
            }
        }
    }

}


template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}


template <typename T>
void List<T>::pop_front()
{
    if (!empty()) {
        node<T>* curr = first;

        first = first->next;

        Size--;
    }
}

template <typename T>
void List<T>::pop_back() {
    if (!empty()) {
        node<T>* curr = first;
        if (curr->next != nullptr) {
            while (curr->next->next != nullptr) {
                curr = curr->next;
            }
            node<T>* curr1 = curr->next;
            curr->next = curr->next->next;
            delete curr1;
        }
        else {
            node<T>* curr = first;
            first = nullptr;
            delete curr;
        }

        Size--;
    }
}


template<typename T>
void List<T>::reverse()
{
    node<T>* prev = nullptr;
    node<T>* curr = first;
    node<T>* Next;

    while (curr != nullptr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }

    first = prev;
}

template <typename T>
void List<T>::sort() {
    node<T>* a = first;
    first = merge_sort(a);

    iterator it = begin();
    Size = 0;
    while (it != end()) {
        it++;
        Size++;
    }
}

template<typename T>
node<T>* List<T>::merge_sort(node<T>* a) {
    if (a == nullptr || a->next == nullptr) {
        return a;
    }

    node<T>* middle = get_middle(a);

    node<T>* _second = middle->next;
    middle->next = nullptr;
    node<T>* _first = a;

    return merge(merge_sort(_first), merge_sort(_second));
}


template<typename T>
node<T>* List<T>::get_middle(node<T>* a) {
    node<T>* prev = a;
    node<T>* curr = a->next;

    while (curr != nullptr) {
        curr = curr->next;
        if (curr != nullptr) {
            curr = curr->next;
            prev = prev->next;
        }
    }

    return prev;
}

template <typename T>
node<T>* List<T>::merge(node<T>* first_node, node<T>* second_node) {
    List<T> result;

    node<T>* curr_1 = first_node;
    node<T>* curr_2 = second_node;

    while (curr_1 != nullptr && curr_2 != nullptr) {
        if (curr_1->data > curr_2->data) {
            result.push_back(curr_1->data);
            curr_1 = curr_1->next;
        }
        else if (curr_1->data < curr_2->data) {
            result.push_back(curr_2->data);
            curr_2 = curr_2->next;
        }
        else {
            result.push_back(curr_1->data + curr_2->data);
            curr_1 = curr_1->next;
            curr_2 = curr_2->next;
        }
    }

    if (curr_1 != nullptr) {
        while (curr_1 != nullptr) {
            result.push_back(curr_1);
            curr_1 = curr_1->next;
        }
    }
    else if (curr_2 != nullptr) {
        while (curr_2 != nullptr) {
            result.push_back(curr_2);
            curr_2 = curr_2->next;
        }
    }

    delete first_node;
    delete second_node;

    return result.first;
}

template <typename T>
void List<T>::show()
{
    node<T>* curr = first;
    while (curr != nullptr)
    {
        std::cout << curr << " " << curr->data << std::endl;
        curr = curr->next;
    }
}


#endif
=======
#ifndef _LIST_
#define _LIST_
#include <cassert>
#include <iostream>

template <typename T>
class node {
public: // ≈сть ли возможность сделать эту область private
    //friend class List;
    //friend class polinom;

    T data;
    node* next;
public:
    node();                                      
    node(const T& m_data);                               
    node(const node& a);                          //  опирует только data, указатель на следующий - nullptr
    bool operator==(const node<T>& m_node);
    bool operator<(const node& m_node);
    bool operator>(const node& m_node);
    bool operator>=(const node& m_node);
};


template <typename T>
class List {
protected:
    node<T>* first;
    int Size;
public:
    class iterator;

    List();
    List(const T& data_m);
    List(node<T>* Node_m);                              //Copy-constructor
    List(const List& List_m);
    List(List&& m_list);
    ~List();

    List<T>& operator=(const List& List_m);
    List<T>& operator=(List&& List_m);

    T read_first() { return first->data; }
    int size() { return Size; }
    bool empty() { return ((first) ? 0 : 1); }


    void delElem(T data_m);
    void clear();

    void push_front(const T& m_data);

    void push_back(const T& m_data);
    void push_back(node<T>* Node_m);
    void pop_front();
    void pop_back();

    void reverse();

    iterator begin() { return iterator(first); }
    iterator begin() const { return iterator(first); }
    iterator end() { return iterator(nullptr); }
    iterator end() const { return iterator(nullptr); }
    void sort();
    node<T>* merge_sort(node<T>* a);
    node<T>* get_middle(node<T>* a);
    node<T>* merge(node<T>* first_node, node<T>* second_node);

    void show();

    class iterator
    {
    private:
        friend class Monom;
        node<T>* currentNode;
    public:

        iterator()
            : currentNode(nullptr) {}

        iterator(node<T>* Node_m)
            : currentNode(Node_m) {}

        iterator& operator=(node<T>* Node_m)
        {
            currentNode = Node_m;
            return *this;
        }

        iterator& operator++()
        {
            if (currentNode)
            {
                currentNode = currentNode->next;
            }
            return *this;
        }


        iterator& operator++(int)
        {
            iterator it = *this;
            ++* this;
            return it;
        }

        bool operator!=(const iterator& it)
        {
            return (currentNode != it.currentNode);
        }

        bool operator==(const iterator& it) {
            return (currentNode == it.currentNode);
        }

        T& operator*()
        {
            return currentNode->data;
        }
    };
};



template <typename T>
node<T>::node()
    : data(0)
    , next(nullptr) {}

template <typename T>
node<T>::node(const T& m_data)
    : data(m_data)
    , next(nullptr) {}

template <typename T>
node<T>::node(const node& a)
    : data(a.data)
    , next(nullptr) {}

template <typename T>
bool node<T>::operator==(const node<T>& m_node) {
    return(data == m_node.data);
}

template <typename T>
bool node<T>::operator>(const node<T>& m_node) {
    return(data > m_node.data);
}

template <typename T>
bool node<T>::operator<(const node<T>& m_node) {
    return(data < m_node.data);
}

template <typename T>
bool node<T>::operator>=(const node<T>& m_node) {
    return(data >= m_node.data);
}

template<typename T>
List<T>::List()
    : Size(0)
    , first(nullptr) {}

template<typename T>
List<T>::List(const T& data_m)
    : first(new node<T>(data_m))
    , Size(1)
{}

template<typename T>
List<T>::List(node<T>* Node_m)
    : first(new node<T>(Node_m->data))
    , Size((Node_m == nullptr) ? 0 : 1) {}

template<typename T>
List<T>::List(const List& List_m)
    : Size(0)
    , first(nullptr)
{
    List<T>::iterator it = List_m.begin();

    for (it; it != List_m.end(); it++)
    {
        this->push_back(*it);
    }
}

template<typename T>
List<T>::List(List&& m_list)
    : first(m_list.first)
    , Size(m_list.size)
{
    m_list.first = nullptr;
    m_list.Size = 0;
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T>& List<T>::operator=(const List& List_m) {
    if (first == List_m.first)
        return *this;
    if (this->empty())
    {
        List<T>::iterator it = List_m.begin();

        for (it; it != List_m.end(); it++)
        {
            this->push_back(*it);
        }
    }
    else
    {
        this->clear();
        List<T>::iterator it = List_m.begin();

        for (it; it != List_m.end(); it++)
        {
            this->push_back(*it);
        }
    }
}

template <typename T>
List<T>& List<T>::operator=(List&& List_m) {
    if (first != nullptr) {
        clear();
    }
    first = List_m.first;
    Size = List_m.Size();

    List_m.first = nullptr;
    List_m.Size = 0;

    return *this;
}

template<typename T>
void List<T>::push_front(const T& data_m) {
    if (!first)
        first = new node<T>(data_m);
    else {
        node<T>* new_node = new node<T>(data_m);

        new_node->next = first;
        first = new_node;
    }
}

template <typename T>
void List<T>::push_back(const T& m_data) {
    if (empty())
    {
        first = new node<T>(m_data);
        first->data = m_data;
    }
    else
    {
        node<T>* current = first;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new node<T>(m_data);
    }

    Size++;
}

template <typename T>
void List<T>::push_back(node<T>* Node_m) {
    if (empty()) {
        first = new node<T>(*Node_m);
    }
    else {
        node<T>* current = first;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new node<T>(*Node_m);
    }

    Size++;
}

template<typename T>
void List<T>::delElem(T data_m)
{
    while (first->data == data_m)
    {
        pop_front();
    }
    if (!empty())
    {
        node<T>* prev = first;
        node<T>* curr = first->next;

        while (curr != nullptr)
        {
            if (curr->data == data_m)
            {
                node<T>* temp = curr;
                curr = curr->next;
                prev->next = curr;

                delete temp;
                Size--;
            }
            else if (curr != nullptr) {        
                prev = prev->next;
                curr = curr->next;
            }
        }
    }

}


template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}


template <typename T>
void List<T>::pop_front()
{
    if (!empty()) {
        node<T>* curr = first;

        first = first->next;

        Size--;
    }
}

template <typename T>
void List<T>::pop_back() {
    if (!empty()) {
        node<T>* curr = first;
        if (curr->next != nullptr) {
            while (curr->next->next != nullptr) {
                curr = curr->next;
            }
            node<T>* curr1 = curr->next;
            curr->next = curr->next->next;
            delete curr1;
        }
        else {
            node<T>* curr = first;
            first = nullptr;
            delete curr;
        }

        Size--;
    }
}


template<typename T>
void List<T>::reverse()
{
    node<T>* prev = nullptr;
    node<T>* curr = first;
    node<T>* Next;

    while (curr != nullptr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }

    first = prev;
}

template <typename T>
void List<T>::sort() {
    node<T>* a = first;
    first = merge_sort(a);

    iterator it = begin();
    Size = 0;
    while (it != end()) {
        it++;
        Size++;
    }
}

template<typename T>
node<T>* List<T>::merge_sort(node<T>* a) {
    if (a == nullptr || a->next == nullptr) {
        return a;
    }

    node<T>* middle = get_middle(a);

    node<T>* _second = middle->next;
    middle->next = nullptr;
    node<T>* _first = a;

    return merge(merge_sort(_first), merge_sort(_second));
}


template<typename T>
node<T>* List<T>::get_middle(node<T>* a) {
    node<T>* prev = a;
    node<T>* curr = a->next;

    while (curr != nullptr) {
        curr = curr->next;
        if (curr != nullptr) {
            curr = curr->next;
            prev = prev->next;
        }
    }

    return prev;
}

template <typename T>
node<T>* List<T>::merge(node<T>* first_node, node<T>* second_node) {
    List<T> result;

    node<T>* curr_1 = first_node;
    node<T>* curr_2 = second_node;

    while (curr_1 != nullptr && curr_2 != nullptr) {
        if (curr_1->data > curr_2->data) {
            result.push_back(curr_1->data);
            curr_1 = curr_1->next;
        }
        else if (curr_1->data < curr_2->data) {
            result.push_back(curr_2->data);
            curr_2 = curr_2->next;
        }
        else {
            result.push_back(curr_1->data + curr_2->data);
            curr_1 = curr_1->next;
            curr_2 = curr_2->next;
        }
    }

    if (curr_1 != nullptr) {
        while (curr_1 != nullptr) {
            result.push_back(curr_1);
            curr_1 = curr_1->next;
        }
    }
    else if (curr_2 != nullptr) {
        while (curr_2 != nullptr) {
            result.push_back(curr_2);
            curr_2 = curr_2->next;
        }
    }

    delete first_node;
    delete second_node;

    return result.first;
}

template <typename T>
void List<T>::show()
{
    node<T>* curr = first;
    while (curr != nullptr)
    {
        std::cout << curr << " " << curr->data << std::endl;
        curr = curr->next;
    }
}


#endif
>>>>>>> 0313d6a0bcb831d82a3e6eade187621deaf054e0
