#ifndef MYFORWORDLIST_H_INCLUDED
#define MYFORWORDLIST_H_INCLUDED
#include <cstddef> // FOR NULL

template<typename T> //T is the type of data
class myForwardList{
private:
    struct Node{
        T data;
        struct Node *next;
    };
    Node *head, *tail;
public:
    //head����ֵ��tail����ֵ��
        myForwardList(){
        head =NULL; tail = NULL;
        head->next= tail;
    }

    class Iterator{
    private:
        Node *it;
    public:
        Iterator(Node *node){
            it= node;
        }
        T &operator*(){//û�в�����*��������أ�������ָ�����Ϊ��
            return it->data;
        }
        Iterator &operator++(){//ǰ��++,���������㣬��������
            it = it->next;
            return *this;
        }
        Iterator &operator++(int){//����++����Ȼ�������ݸı䣬���Ƿ���֮ǰ��ֵ���൱���ӳ١�
            Iterator tmp= *this;
            ++(*this);
            return tmp;
        }
    };
    Iterator Begin()const{
        return Iterator(head);
    }
    Iterator End()const{
        return Iterator(tail);
    }
    void pushFront(const T& value){
        Node *p = new Node();
        p->data = value;
        p->next = head->next;
        head->next =p;
    }
    void popFront(){//��Ϊ�ղſ�pop
        if(!isEmpty()){
            Node *p =head->next;
            head->next = p->next;
            delete p;
        }
    }
    void insertAfter(Iterator pos, const T& value){
         Node *p =new Node();
         p->data = value;
         p->next = pos->next;
         pos->next =p;
    }
    void eraseAfter(Iterator pos){//������һ����㣬��ɾ
        if(pos->next != tail){
            Node *p =pos->next;
            pos->next = p->next;
            delete p;
        }
    }
    int Size(){
        Node *tmp = head;
        int sz=0;
        while(tmp->next != tail){
            sz++;
            tmp= tmp->next;
        }
        return sz;
    }
    bool isEmpty(){
        if(head->next == tail) return true;
        else return false;
    }
    void Clear(){
        while(!isEmpty()) popFront();
    }

    void Remove(const T& value){
        for(Iterator i = Begin(); i!= End(); i++){
            if(++i.it->data == value) eraseAfter(i);
        }
    }

    template<typename unaryPredicate>
    void removeIf (unaryPredicate pred){
         for(Iterator i = Begin(); i!= End(); i++){
            if(pred(++i.it->data)) eraseAfter(i);
        }
    }

//    template<typename binaryPredicate>
//    void sort(binaryPredicate pred = less<T>){
//
//
//    }
    myForwardList merge (myForwardList &other){
        myForwardList mergeList;
        Iterator *itr1 = this.Begin()++, *itr2 =other.Begin()++;
        if(isEmpty()) return this;
        if(other.isEmpty()) return other;

        while(itr1 !=this.End() && itr2!=other.End()){
            if(itr1.it->data <  itr2.it->data) {
                mergeList.pushFront(itr1.it->data);
                itr1++;
            }
            else {
                mergeList.pushFront(itr2.it->data);
                itr2++;
            }
        }
       // if(itr1 !=this.End())

    }
};

#endif // MYFORWORDLIST_H_INCLUDED
