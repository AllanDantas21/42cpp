#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string _ideas[100];
    
public:
    Brain();
    Brain(Brain const& src);
    ~Brain();

    Brain& operator=(Brain const& other);
    void getIdea() const;
};

#endif