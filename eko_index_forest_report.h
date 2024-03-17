#ifndef EKO_INDEX_FOREST_REPORT
#define EKO_INDEX_FOREST_REPORT
#include <initializer_list>
#include <string>
#include <vector>
#include <sstream>

class Eko_Index 
{
public: 
    Eko_Index(std::initializer_list<std::string> i);

    bool check_list(std::string const& s) const;
    int get_eko_value(std::string const& s) const;
private:
    std::vector<std::string> eko_index;
};

class Forest_Report
{
public:
    Forest_Report(Eko_Index& index, std::string const& name);
    void add_tree_values(std::string const& s);
    int get_forest_eko_value() const;
    std::string get_forest_name() const;

private:
    std::vector<std::string> forest_index;
    std::string name{};
    Eko_Index& index;
};

#endif