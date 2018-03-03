#include<iostream>
//#include"myForwordList.h"
#include <cstddef> // FOR NULL
using namespace std;

template<typename T> //T is the type of data
class myForwardList{
private:
    class Node{
    public:
        T data;
        Node *next;
    };
    Node  *head,*tail;
public:
    //head不存值，tail不存值。
    myForwardList(){
        head = new Node();tail = new Node();
        head->data =NULL; tail->data = NULL;
        head->next= tail;
    }
    ~myForwardList(){
        Clear();
        delete head;
        delete tail;
    }
    class Iterator{
    private:
        Node *it;
    public:
        Iterator(Node *node){
            it= node;
        }
        T &operator*(){//没有参数的*运算符重载，类似于指针的行为；
            return it->data;
        }
        Iterator &operator++(){//前置++,对自身运算，返回自身
            it = it->next;
            return *this;
        }
        Iterator &operator++(int){//后置++，虽然里面内容改变，但是返回之前的值。相当于延迟。
            Iterator tmp= *this;
            ++(*this);
            return tmp;
        }
        bool operator!=(const Iterator &other){
            return it != other.it;
        }
        Node *getNode(){
            return it;
        }
    };
    Iterator Head()const{
        return Iterator(head->next);
    }
    Iterator Begin()const{
        return Iterator(head->next);
    }
    Iterator End()const{
        return Iterator(tail);
    }
    void pushFront(const T& value){
        Node *p= new Node();
        p->data = value;
        p->next = head->next;
        head->next =p;
    }
    void popFront(){//不为空才可pop
        if(!isEmpty()){
            Node *p =head->next;
            head->next = p->next;
            delete p;
        }
    }
    void insertAfter(Iterator pos, const T& value){
         Node *p =new Node();
         p->data = value;
         p->next = pos.getNode()->next;
         pos.getNode()->next =p;
    }
    void eraseAfter( Iterator pos){//如果最后一个结点，不删
        Node *tmp=pos.getNode();
        if(pos++ != End()){
            Node *p =tmp->next;
            tmp->next = p->next;
            delete p;
        }
    }
    int Size(){
        int sz=0;
        for(Iterator i = Begin(); i!= End(); i++){
            sz++;
        }
        return sz;
    }
    bool isEmpty(){
        return !(Begin()!= End());
    }
    void Clear(){
        while(!isEmpty()) popFront();
    }
    void Remove(const T& value){
        for(Iterator i = Head(); i!= End(); i++){
            if(i.getNode()->next->data == value) {
                eraseAfter(i);
            }
        }
    }

    template<typename unaryPredicate>
    void removeIf (unaryPredicate pred){
         for(Iterator i = Head(); i!= End(); i++){
            if(pred(i.getNode()->next->data)) eraseAfter(i);
        }
    }

    void Display(){
    cout<<"\n   The current forward list is ";
    for(auto k =Begin();k !=End();k++){
        cout<<*k<<" ";
    }
    cout<<endl;
}
//    template<typename binaryPredicate>
//    void sort(binaryPredicate pred = less<T>){
//
//
//    }
    myForwardList *Merge (myForwardList &other){
        Node *node1 = head,*node2 = other.Head();
        if(isEmpty()) return this;
        if(other.isEmpty()) return other;
        while(node1->next !=tail && node2->next !=other.tail){
            if(node1->data <  node1->data) {
                this.pushFront(node1);
                node1=node1->next;
            }
            else{
                this.pushFront(node2);
                node1=node1->next;
            }
        }
        if(itr2 !=this.End()){
            node1->next = itr2.getNode()->next;
            tail = itr2.tail;
        }

    }
};

void const displayForwardList(const myForwardList<int> &fl){
    cout<<"\n   The current forward list is ";
    for(auto k =fl.Begin();k !=fl.End();k++){
        cout<<*k<<" ";
    }
    cout<<endl;
}

bool predicate(int a){
    return(a<9 && a>5);
}

int main(){
    myForwardList<int> fl;
    fl.pushFront(3);
    fl.pushFront(5);
    fl.pushFront(7);
    fl.pushFront(9);

    myForwardList<int> fl2;
    fl2.pushFront(2);
    fl2.pushFront(4);
    fl2.pushFront(6);
    fl2.pushFront(8);

    fl.Merge(fl2);
    cout<<"test Merge : ";
    fl.Display();


    cout<<"test *, Begin, End : ";
    fl.Display();

    auto i = ++fl.Begin();
    cout<<"test prev ++ :(i=++fl.begin()) *i = "<<*i<<endl;
    auto j = fl.Begin()++;
    cout<<"test post ++ :(j=fl.begin()++) *j = "<<*j<<endl;

    fl.pushFront(11);
    cout<<"test pushFront: (push 11)";
    fl.Display();

    fl.popFront();
    cout<<"test popFront: ";
    fl.Display();

    fl.insertAfter(i,11);
    cout<<"test insertAfter: (After i, insert 11)";
    fl.Display();

    fl.eraseAfter(i);
    cout<<"test eraseAfter: (After i)";
    fl.Display();

    fl.Remove(5);
    cout<<"test Remove: (After i)";
    fl.Display();

    fl.removeIf(predicate);
    cout<<"test removeIf: (5<removeIf<9)";
    fl.Display();

    int n = fl.Size();
    cout<<"test size  =  "<<n<<endl;

    if(!fl.isEmpty()) fl.Clear();
    cout<<"test isEmpty, Clear : ";
    fl.Display();





    cout<<endl;
}
