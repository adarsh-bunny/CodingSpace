using namespace std;
template<typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
        QueueUsingArray(int capacity)
        {
            this->capacity = capacity;
            data = new T[capacity];
            firstIndex=-1;
            nextIndex=0;
            size=0;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size==0;
        }

        // //insert element staticcally
        // void enqueue(T element)
        // {
        //     if(size==capacity){
        //         cout<<" Queue is full !!"<<endl;
        //         return;
        //     }
        //     data[nextIndex]= element;
        //     nextIndex=(nextIndex+1)%capacity;
        //     size++;
        //     if(firstIndex==-1)
        //     firstIndex=0;
        // }
      //insert element dynamically
        void enqueue(T element)
        {
            if(size==capacity){
              T *newData= new T[2*capacity];
              int j=0;
              for (int i = 0; i < capacity; i++)
              {
                newData[j]=data[i];
                j++;
              }
                for (int i = 0; i < firstIndex; i++)
              {
                newData[j]=data[i];
                j++;
              }
              delete []data;
              data=newData;
              firstIndex=0;
              nextIndex=capacity;
              capacity=2*capacity;

              
            }
            data[nextIndex]= element;
            nextIndex=(nextIndex+1)%capacity;
            size++;
            if(firstIndex==-1)
            firstIndex=0;
        }


        T front(){
            if(size==0){
                cout<<"Queue is empty!!"<<endl;
                return 0;
            }
            return data[firstIndex];
        }


        T dequeue()
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
};
