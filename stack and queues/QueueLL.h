using namespace std;
template<typename T>
class Node{
     public:
    T data;
    Node<T> *next;
   
    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};
template<typename T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
        Queue()
        {
            head=NULL;
            tail=nullptr;
            size=0;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size==0;
        }

        // //insert element 

        void enqueue(T element)
        {
            Node<T> *newNode= new Node<T>(element);
            if(head==NULL)
            {
                head=newNode;
                tail=newNode;

            }
            else 
            {
                tail->next=newNode;
                tail=tail->next;
            }
            size++;

        }


        T front(){
            if(head==NULL)
            {
                cout<<"Queue is empty!!!"<<endl;
                return 0;
            }
            return head->data;
       
        }


        T dequeue()
        {
            if(head==NULL)
            {
                 cout<<" queue is empty!!!"<<endl;
                return 0;
            }
            T ans=head->data;
            Node<T> *a=head;
            head=head->next;
            delete a;

            return ans;
            
          
        }
};
