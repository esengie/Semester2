#pragma once
#include "iostream"
#include <string>

/// Calculator Tree Interface

class CalcTree
{
public:
    /// Give result
    virtual int result () const = 0;
    /// Prints result  in std::cout
    virtual void print() const = 0;
    virtual ~CalcTree() {}
};

/// Leaf Class

class Leaf : public CalcTree
{
private: 
	int val; 
public:
    Leaf(std::string& s)
    {
        val = s[0] - '0';
        s.erase(0, 1);
    }
    int result (void) const
    {
        return val;
    }
    void print (void) const
    {
        std::cout << ' ' << val;
    }
};
class Operation : public CalcTree
{
private:
    char operand;
    CalcTree* left;
    CalcTree* right;
public:
    Operation (std::string& s);
    ~Operation (void)
    {
        delete left;
        delete right;
    }
    int result (void) const;
    void print (void) const;
    /// Builds a Calculator Subtree

    CalcTree* build(std::string& s);
};
