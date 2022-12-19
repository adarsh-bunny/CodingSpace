using namespace std;
template<typename T>
class deQueue{
    T *data;
    int rear;
    int front;
    int size;
    int capacity;
    public:
        deQueue(int capacity)
        {
            this->capacity = capacity;
            data = new T[capacity];
            front=-1;
            rear=0;
            size=0;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size==0;
        }

        //insert element staticcally
        void insertFront(T element)
        {
            if(size==capacity){
                cout<<" Queue is full !!"<<endl;
                return;
            }
            if(size==0)
            {
            front = 0;
            rear = 0;
            }
            firstIndex=(firstIndex-1)%capacity;
            data[firstIndex]= element;
            
            size++;
            if(firstIndex==-1)
            firstIndex=0;
        }
           void insertRear(T element)
        {
            if(size==capacity){
                cout<<" Queue is full !!"<<endl;
                return;
            }
            data[nextIndex]= element;
            nextIndex=(nextIndex+1)%capacity;
            size++;
            if(firstIndex==-1)
            firstIndex=0;
        }


        T getFront(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return 0;
            }
            return data[firstIndex];
        }
            T getRear(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return -1;
            }
            return data[nextIndex-1];
        }


        T deleteFront()
        {
               if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return 0 ;
            }
            T ans = data[firstIndex];

            firstIndex=(firstIndex+1)%capacity;
            size--;
               if(size==0){
                   nextIndex=0;     
              firstIndex=-1;
            }
            return ans;

        }
        
        T deleteRear()
        {
               if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return 0 ;
            }
            T ans = data[nextIndex-1];
            

            nextIndex=(nextIndex-1)%capacity;
            size--;
               if(size==0){
                   nextIndex=0;     
              firstIndex=-1;
            }
            return ans;

        }
};
