#include <iostream>
#include <vector>

// Your code here
class Inventory_Space
{
public:
  Inventory_Space(int* n);
  Inventory_Space();
  ~Inventory_Space() = default;
  
  void print() const;
  void merge(Inventory_Space& space);

  bool operator==(Inventory_Space& rhs);
private:
  int* number{};
};

Inventory_Space::Inventory_Space(int* n)
  : number{n}
{
  
}

Inventory_Space::Inventory_Space()
  : number{nullptr}
{
  
}

void Inventory_Space::print() const
{
  if(number != nullptr)
    {
      std::cout << *number;
    }
  else
    {
      std::cout << '-';
    }
}

void Inventory_Space::merge(Inventory_Space& space)
{
  int* ptr_space = space.number;
  int space_int = *ptr_space;
  
  if(*this == space)
    {
      return;
    }
      
  if(number == nullptr)
    {
      *number = space_int;
    }

  if(*number == space_int)
    {
      (*number)++;

      space.number = nullptr;
    }
}

bool Inventory_Space::operator==(Inventory_Space& rhs)
{
  if(number == rhs.number)
    {
      return true;
    }
  else
    {
      return false;
    }
}
  
int main()
{
  std::vector<Inventory_Space> v {};

  // Create 8 spaces
  for ( unsigned int i{}; i < 8; ++i )
  {
    v.push_back(Inventory_Space{new int{1}});
  }

  for ( unsigned int i{0}; i < v.size(); ++i )
  {
    // Merge each space with the next. Empty spaces will "bubble" to
    // the end as each iteration drop the next space into it.
    for ( unsigned int j{1}; j < v.size(); ++j )
    {
      v.at(j-1).merge( v.at(j) );
    }

    // Print all spaces after each iteration (one line of output)
    for ( unsigned int k{0}; k < v.size(); ++k )
    {
      v.at(k).print();
    }
    std::cout << std::endl;
  }
  
  return 0;
}
