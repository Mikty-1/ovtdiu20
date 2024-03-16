// Given kod för uppgift 3 - Minneshantering

// Här är given kod för en tänkt Stack. Tyvärr blev det "något fel" senast
// författaren sparade filen så du behöver komplettera med de delar som fallit
// bort.
#include <stdexcept>
class Stack{
public:
  Stack()
    : head{nullptr}
  {

  }

  ~Stack()
  {
    while (head !=nullptr)
    {
      pop();
    }
  }

  Stack(Stack const& other)
    : head {}
  {
    Node* curr = other.head;
    while(curr != nullptr)
    {
      int tmp = curr->value;
      push(tmp);
      curr = curr->next;
    }

  }

  void push(int value)
  {
    head = new Node {value, head};
  }
    
  void pop()
  {
    if(head != nullptr)
    {
      Node* popped {head};
      head = head->next;
      delete popped;
    }
  }

  int top()
  {
    if(head != nullptr)
    {
      return head->value;
    }
    throw std::runtime_error{"List Empty in top()"};
  }

  bool empty()
  {
    return head == nullptr;
  }
private:
  struct Node
  {
    int value;
    Node* next;
  };

  Node* head;

};


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("all")
{
    Stack A{};
    A.push(2);
    A.push(5);
    A.push(8);
    CHECK( ! A.empty() );
    CHECK( A.top() == 8 );

    Stack B{A};
    CHECK( ! B.empty() );
    CHECK( B.top() == 8 );
    
    B.pop();
    B.pop();
    CHECK( B.top() == 2);
    B.push(4);
    CHECK(! B.empty());
    CHECK(B.top()== 4);
    A.pop();
    CHECK(! A.empty()); 
    CHECK( A.top() == 5);

    // Lägg till testfall 3-12 här!

    // Glöm inte kontroll av minnesläckor med valgrind!
}
