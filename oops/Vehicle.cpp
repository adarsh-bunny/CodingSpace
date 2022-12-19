class Vehicle{
    private:
    int maxSpeed;
    protected:
    int numTyres;
    public:
    string color;

    Vehicle()
    {
        cout<<"Vehicle's default Constructor"<<endl;
    }
      Vehicle(int z)
    {
        cout<<"Vehicle's Pramaterized Constructor"<<endl;
        maxSpeed=z;
    }
    
    ~Vehicle()
    {
        cout<<"Vehicle's default destructor"<<endl;
    }
    
};