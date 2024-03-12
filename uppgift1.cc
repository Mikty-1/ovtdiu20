#include <stdexcept>
#include <iostream>

using namespace std;

class Number
{
public:
  Number(int const n);

  int get_number() const;
  void new_number(int const n);
  

private:
  int num{};
  void check_range(int const n) const;
};

Number::Number(int const n)
  : num{}
{
  check_range(n);
  num = n;
}

int Number::get_number() const
{
  return num;
}

void Number::new_number(int const n)
{
  check_range(n);
  num = n;
}

void Number::check_range(int const n) const
{
  if(n < 15 or n > 35) throw out_of_range("The number must be between 15 and 35");
}

int main()
{
  Number n1{17};
  Number n2{30};
  
  cout << n1.get_number() << endl;

  cout << n2.get_number() << endl;
  try
    {
      n2.new_number(125);
    }
  catch (out_of_range const& ex)
    {
      cout << "#1: " << ex.what() << endl;
    }
  
  cout << n2.get_number() << endl;
  
  return 0;
}
