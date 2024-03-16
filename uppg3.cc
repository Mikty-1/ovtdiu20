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
        delete_all();
    }

    Stack(Stack const& other)
        : head {}
    {
        Stack s1 {};
        s1.clone(other);
        
        clone(s1);
    }

    Stack& operator=(Stack const& other)
    {
        delete_all();

        Stack s1 {};
        s1.clone(other);
        clone(s1);

        return *this;
    }

    Stack(Stack && other)
        : head{other.head}
    {
        other.head = nullptr;
    }

    Stack& operator=(Stack && other)
    {
        std::swap(head, other.head);
        return *this;
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

    void clone(Stack const& other)
    {
        Node* curr = other.head;
        while(curr != nullptr)
        {
            int tmp = curr->value;
            push(tmp);
            curr = curr->next;
        }
    }

    void delete_all()
    {
        while (head !=nullptr)
        {
            pop();
        }
    }
    
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
    //1
    Stack A{};
    A.push(2);
    A.push(5);
    A.push(8);
    CHECK( ! A.empty() );
    CHECK( A.top() == 8 );
    //2
    Stack B{A};
    CHECK( ! B.empty() );
    CHECK( B.top() == 8 );
    //3
    B.pop();
    B.pop();
    CHECK( B.top() == 2);
    //4
    B.push(4);
    CHECK(! B.empty());
    CHECK(B.top()== 4);
    //5
    A.pop();
    CHECK(! A.empty()); 
    CHECK( A.top() == 5);
    //6
    A.pop();
    A.pop();
    CHECK(A.empty());
    //7
    A = std::move(B);
    CHECK(B.empty());
    CHECK(! A.empty());
    CHECK(A.top() == 4);
    //8
    Stack C{std::move(A)};
    CHECK(A.empty());
    CHECK(! C.empty());
    CHECK(C.top() == 4);
    //9
    Stack D {};
    D.push(3);
    CHECK(! D.empty());
    CHECK( D.top() == 3);
    //10
    C = D;
    CHECK(! C.empty());
    CHECK( C.top() == 3);
    //11
    C.pop();
    CHECK(C.empty());
    CHECK(! D.empty());
    CHECK(D.top() == 3);
    //12
    D.push(1);
    D.push(2);
    D.push(6);
    D.push(7);
    
    
    // Lägg till testfall 3-12 här!

    // Glöm inte kontroll av minnesläckor med valgrind!
}
