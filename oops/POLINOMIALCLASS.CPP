#include <bits/stdc++.h>

using namespace std;

class Polynomial
{

public:
    int *coeff;
    int capacity;
    //default constructor
    Polynomial()
    {
        coeff = new int[5];
        for (int i = 0; i < 5; i++)
            coeff[i] = 0;
        capacity = 5;
    }
    //copy constructor
    Polynomial(Polynomial const &p)
    {
        // this->coeff=p.coeff; //shallow copy
        //deep copy
        this->coeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->coeff[i] = p.coeff[i];
        }

        this->capacity = p.capacity;
    }

    void operator=(Polynomial const &p)
    {
        //deep copy
        this->coeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++)
        {
            this->coeff[i] = p.coeff[i];
        }

        this->capacity = p.capacity;
       //  return *this;
    }
    Polynomial operator+(Polynomial &p)
    {
        Polynomial newP;
        newP.capacity = max(p.capacity, capacity);

        newP.coeff = new int[newP.capacity];

        if (this->capacity < p.capacity)
        {
            int k;
            for (k = 0; k < this->capacity; k++)
            {
                newP.coeff[k] = this->coeff[k] + p.coeff[k];
            }
            for (; k < p.capacity; k++)
            {
                newP.coeff[k] = p.coeff[k];
            }
        }
        else
        {
            int k;
            for (k = 0; k < p.capacity; k++)
            {
                newP.coeff[k] = this->coeff[k] + p.coeff[k];
            }
            for (; k < capacity; k++)
            {
                newP.coeff[k] = this->coeff[k];
            }
        }
        return newP;
    }

    void setCoefficient(int deg, int coeff)
    {
        if (deg >= capacity)
        {
            //int size = this->capacity;
            int size = deg + 1;
            int *newarr = new int[size];
            for (int i = 0; i < capacity; i++)
                newarr[i] = this->coeff[i];
            for (int i = capacity; i < size; i++)
                newarr[i] = 0;
            delete[] this->coeff;
            this->coeff = newarr;
            this->capacity = size;
        }
        this->coeff[deg] = coeff;
    }

    void print() const
    {
        cout<<"Polynomial equation =";
        for (int i = 0; i < capacity; i++)
        {
            if (coeff[i])
                cout << coeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
};