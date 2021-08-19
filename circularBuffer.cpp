#include<iostream>
#include<memory>

template <class T>

class circularBuffer
{
    uint size;
    uint head;
    uint tail;
    std::unique_ptr<T[]> buf;
    public:
    explicit circularBuffer(uint sz):size(sz),buf(std::make_unique<T[]>(sz+1)){
        head=tail=0;
    }
    void enque(T val);
    T  deque();
    T front() const;
    bool isEmpty() const;
    bool isFull() const;
};

template<class T>
void circularBuffer<T>::enque(T val){
        if(isFull()){
            std::cout<<"buffer is full"<<std::endl;
        }
        else{
            buf[tail]=val;
            tail=(++tail)%size;
        }
    }
    
template<class T>
T  circularBuffer<T>::deque(){
        if(isEmpty()){
            std::cout<<"buffer is isEmpty"<<std::endl;
        }
        auto ret = buf[head];
        head = ++head%size;
        return ret;
    };

template<class T>    
T circularBuffer<T>::front() const{
        return  buf[head];
    }

template<class T>
bool circularBuffer<T>::isEmpty() const {
        return (head==tail);
    }
    
template<class T>
bool circularBuffer<T>::isFull() const {
        return ((tail+1)%size==head);
    }

int main(){
    circularBuffer<int> cb(5);
    cb.enque(10);
    cb.enque(20);
    cb.enque(30);
    cb.enque(40);
    cb.enque(50);
    cb.enque(60);
    cb.enque(70);
    cb.enque(80);
    std::cout<<cb.deque()<<std::endl;
    std::cout<<cb.deque()<<std::endl;
    
    cb.enque(90);
    cb.enque(100);
    std::cout<<cb.front()<<std::endl;
    return 0;
}
