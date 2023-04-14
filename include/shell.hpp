#include <string>


#pragma once


namespace shell
{

enum class ShellType 
{
    offensive,
    defence
}; // enum class ShellType


class Shell 
{
private:
    std::string name_{};
    std::string decription_{};
    ShellType type_;
    // name - NAME of shell (uses for output, debugging, domain using and user)
    // decription - string desribes shell (especially for players)
    // type - type of shell which describes effects of current shell 
public:
    std::string name() const {
        return name_;
    } // return Shell::name_

    std::string decription() const {
        return decription_;
    } // return Shell::decription_

    ShellType type() const {
        return type_;
    } // return Shell::type_
    
    virtual auto affect() const = 0;

}; // class Shell

} // namespace shell
