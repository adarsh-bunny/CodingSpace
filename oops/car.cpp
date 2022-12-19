
class Car:public Vehicle
{
    public:
    int numGears;

    // initialization technique
    Car (): Vehicle(5)
    {
        cout<<"Car's default constructor"<<endl;
    }

    // or
    /* Car (int x): Vehicle(x)
    {
        cout<<"Car's default constructor"<<endl;
    }   */
     ~Car ()
    {
        cout<<"Car's default destructor"<<endl;
    }
    void print()
    {
        cout<<"numTyres: "<<numTyres<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Num Gears: "<<numGears<<endl;
        // cout<<"Max Speed: "<<maxSpeed<<endl; .// not accessible


    }

};