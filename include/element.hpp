#include <map>
#include <string>


#pragma once


namespace element
{

class Element 
{
private:
    std::string name_{};
    std::string decription_();
    // name - NAME of element (for output, debugging, domestic using and for user)
    // decription - string describes Element (especially for players)
public:
    std::string name() const {
        return name_;
    } // return Element::name_ 
    
    std::string decription() const {
        return decription_;
    } // return Element::decription_
    
    virtual auto affect() const = 0;

}; // class Element

} // namespace element
