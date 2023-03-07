#include <iostream>
#include <list>

class Queue{
    public:
        void enqueue(int value){
            ListNode *newNode = (struct ListNode*) malloc(sizeof(ListNode));
            newNode->value = value;
            newNode->next = NULL;
            if(isEmpty()) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            };
        };

        int dequeue(){
            ListNode *temp = head;
            int returnValue = temp->value;
            head = head->next;
            free(temp);
            return returnValue;
        }

        bool isEmpty(){
            if(head == NULL) return 1;
            else return 0;
        };
        void display(){
            ListNode *temp = head;
            std::cout<<"head: "<<head<<std::endl;
            while(temp){
                std::cout<<temp->value<<" - "<<temp->next<<std::endl;
                temp = temp->next;
            };
        };
    private:
        struct ListNode{
            int value;
            struct ListNode *next;
        };

        ListNode *head = NULL;
        ListNode *tail = NULL;

};

int main(void){
    Queue queue1;
    std::cout<<queue1.isEmpty()<<std::endl;
    queue1.enqueue(5);
    queue1.enqueue(1);
    queue1.enqueue(8);
    queue1.enqueue(6);
    queue1.display();
    std::cout<<queue1.isEmpty()<<std::endl;
    
    std::cout<<"Dequeued: "<<queue1.dequeue()<<std::endl;
    queue1.display();
};