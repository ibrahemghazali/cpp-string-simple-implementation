#pragma once
#include <iostream>


namespace my_containers
{

    class my_string 
    {
        private:
            char* data;
            size_t size;

        public:
            my_string();
            
            my_string(char* str);
            
            
            my_string(const my_string& other);
            
            my_string(my_string&& other);
            
            
            ~my_string();
            
            
            my_string& operator=(const my_string& other);
            
            my_string& operator=(my_string&& other);


            my_string& operator+=(my_string&& other);
            
            
            size_t length() const;
            
            const char* c_str() const;
            
            
            char& operator[](size_t index);
            
            
            void append(const my_string& other);
            
            
            friend std::ostream& operator<<(std::ostream& os, const my_string& str);
    };
}