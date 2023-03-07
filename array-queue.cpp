#include <iostream>

class Queue{
    public:

        void enqueue(int value){
            if(isFull()) std::cout<<"Queue is full, try removing the first element first."<<std::endl;
            else {
                if(isEmpty()) {
                    *head = value;
                    tail++;
                    if(isFull()) std::cout<<"You reached the maximum size of queue."<<std::endl;
                } else {
                    *tail = value;
                    tail++;
                }
            }
        };

        int dequeue(){
            *head = NULL;
            head++;
        }

        void display(){
            for(int i = 0; i < size; i++){
                std::cout<<queueArr[i]<<' ';
            }
            std::cout<<std::endl;
        }

        int isEmpty(){
            if(head == tail) return 1;
            else return 0;
        }
        int isFull(){
            if(queueArr[size-1]) return 1;
            else return 0;
        }
    private:
        int size = 4;
        int *queueArr = (int*) malloc(size * sizeof(int));
        int *head = queueArr;
        int *tail = queueArr;
};

int main(void){
    Queue queue1;
    queue1.enqueue(4);
    queue1.enqueue(2);
    queue1.enqueue(6);
    queue1.enqueue(9);
    queue1.enqueue(9);
    queue1.display();
};