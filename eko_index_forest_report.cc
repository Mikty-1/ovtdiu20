#include "eko_index_forest_report.h"

Eko_Index::Eko_Index(std::initializer_list<std::string> list)
    :eko_index {}
{
    for(std::string s : list)
    {
        eko_index.push_back(s);
    }

}

bool Eko_Index::check_list(std::string const& s) const
{
    for(std::string eko_word : eko_index)
    {
        if(s == eko_word) return true;
    }
    return false;
}

int Eko_Index::get_eko_value(std::string const& s) const
{
    std::stringstream ss(s);
    std::string word {};
    int sum {};
    while(getline(ss, word, ' '))
    {
        for(std::string eko_word : eko_index)
        {
            if(word == eko_word) sum++;
        }
    }
    return sum*sum;
}

Forest_Report::Forest_Report(Eko_Index& index, std::string const& name)
    : index {index}, name{name}
{
    
}

void Forest_Report::add_tree_values(std::string const& s)
{
    forest_index.push_back(s);
}

int Forest_Report::get_forest_eko_value() const
{
    int sum {};
    for(std::string s : forest_index)
    {
        sum += index.get_eko_value(s);
    }
    return sum;
}

std::string Forest_Report::get_forest_name() const
{
    return name;
}