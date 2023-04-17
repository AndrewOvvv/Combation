#include <string>

#pragma once


namespace shell
{

enum class ShellType 
{
    none,
    offensive,
    defence,
    utility
}; // enum class ShellType


class Shell 
{
private:
    std::string name_{};
    std::string description_{};
    ShellType type_{ShellType::none};
    // name - NAME of shell (uses for output, debugging, domain using and user)
    // decription - string desribes shell (especially for players)
    // type - type of shell which describes effects of current shell 
public:
    Shell() = default;

    // GETTERS
    /// @brief get name of shell 
    /// @return name of shell
    std::string name() const {
        return name_;
    }

    /// @brief get description of shell
    /// @return description of shell
    std::string description() const {
        return description_;
    }

    /// @brief get type of shell
    /// @return type of shell
    ShellType type() const {
        return type_;
    }

}; // class Shell

} // namespace shell
