#include "string.hpp"
#include <cstring>
#include <iostream>

namespace my_containers {

// default
my_string::my_string() : data(nullptr), size(0) {}

// from C string
my_string::my_string(char* str) 
{
    if(nullptr==str)
    {
        data=nullptr;
        size=0;
    }
    else
    {
        size=strlen(str)+1;
        data =new char[size];
        memcpy(data,str,size);
    }

}

// copy constructor
my_string::my_string(const my_string& other) 
{
    if(nullptr==other.data)
    {
        this->data=nullptr;
        this->size=0;
    }
    else
    {
        this->size=other.size;
        data=new char[this->size];
        memcpy(this->data,other.data,this->size);
    }
}

// move constructor
my_string::my_string(my_string&& other) 
{

    this->data=other.data;
    this->size=other.size;

    other.data=nullptr;
    other.size=0;
}


// destructor
my_string::~my_string() 
{

    size=0;
    delete [] this->data;

}

// copy assignment
my_string& my_string::operator=(const my_string& other) 
{
    if(other.data!=this->data)
    {
        if(other.data!=nullptr)
        {
            delete [] this->data;
            this->size=other.size;
            this->data=new char[size];
            memcpy(this->data,other.data,this->size);
        }
        else
        {
            this->data=nullptr;
            size=0;
        }
    }
    else
    {
        //nothing 
    }
    return *this;
}

// move assignment
my_string& my_string::operator=(my_string&& other) 
{
    if(this->data!=other.data)
    {
        delete []this->data;
        this->data=other.data;
        this->size=other.size;
        other.data=nullptr;
        other.size=0;
    }
    return *this;
}
// length
size_t my_string::length() const {
    return size;
}

// c_str
const char* my_string::c_str() const {
    return data;
}

// operator[]
char& my_string::operator[](size_t index) {
    return this->data[index];
}

// append
void my_string::append(const my_string& other) {
    // create new string have the two stirngs toghether

    if(other.data!=nullptr )
    {
        if(this->data!=nullptr)
        {
            //create new
            char *temp=new char[this->size+other.size];
            //copying data
            memcpy(temp,this->data,this->size);
            memcpy(temp+this->size,other.data,other.size);
            this->size+=other.size;
            //delete the previous one
            delete []data;
            this->data=temp;
        }
        else
        {
            this->data=new char[other.size];
            this->size=other.size;
            memcpy(this->data,other.data,this->size);

        }


    }


}

// operator<<
std::ostream& operator<<(std::ostream& os, const my_string& str) 
{
    if(nullptr==str.data)
    {
        os<<""<<std::endl;
    }
    else
    {
        for(int i=0;i<str.size;i++)
        {
            os<<str.data[i];
        }
        os<<std::endl;
    }
    return os;
}

} // namespace