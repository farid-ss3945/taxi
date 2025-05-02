#include <iostream>

template <typename TType>
struct LinkedListNode
{
    TType My_Value{};
    LinkedListNode* My_Next{};
    LinkedListNode* My_Prev{};
};

template <typename TType>
class LinkedList
{
public:
    ~LinkedList()
    {
        if (My_Length == 0)
        {
            return;
        }

        auto Current = My_Head;

        while (Current != nullptr)
        {
            auto Temp = Current->My_Next;

            delete Current;

            Current = Temp;
        }
    }

    LinkedList() : My_Head{}, My_Tail{}, My_Length{0}
    {
    }

    LinkedList(const LinkedList& other) : My_Head(nullptr), My_Tail(nullptr), My_Length(0)
    {
        auto* current = other.My_Head;
        while (current != nullptr)
        {
            InsertAtEnd(current->My_Value);
            current = current->My_Next;
        }
    }

    LinkedList(LinkedList&& other) noexcept
    : My_Head(other.My_Head), My_Tail(other.My_Tail), My_Length(other.My_Length)
    {
        other.My_Head = nullptr;
        other.My_Tail = nullptr;
        other.My_Length = 0;
    }


    LinkedList& operator=(const LinkedList& other)
    {
        if (this != &other)
        {
            Clear(); 
            auto* current = other.My_Head;
            while (current != nullptr)
            {
                InsertAtEnd(current->My_Value);
                current = current->My_Next;
            }
        }
        return *this;
    }

    LinkedList& operator=(LinkedList&& other) noexcept
    {
        if (this != &other)
        {
            Clear();

            My_Head = other.My_Head;
            My_Tail = other.My_Tail;
            My_Length = other.My_Length;

            other.My_Head = nullptr;
            other.My_Tail = nullptr;
            other.My_Length = 0;
        }
        return *this;
    }

    
    size_t Get_Length()
    {
        return My_Length;
    }

    LinkedListNode<TType>& InsertAtEnd(const TType& Value)
    {
        auto NewNode = new LinkedListNode<TType>;
        NewNode->My_Value = Value;

        if (My_Length == 0)
        {
            My_Head = My_Tail = NewNode;
        }
        else
        {
            My_Tail->My_Next = NewNode;
            NewNode->My_Prev = My_Tail;

            My_Tail = NewNode;
        }

        ++My_Length;

        return *NewNode;
    }
    
    void PopFront()
    {
        if (My_Head != nullptr)
        {
            auto* OldHead = My_Head;
            My_Head = My_Head->My_Next;

            if (My_Head != nullptr)
            {
                My_Head->My_Prev = nullptr;
            }
            else
            {
                My_Tail = nullptr;
            }

            delete OldHead;
            --My_Length;
        }
    }

    void PopBack()
    {
        if (My_Tail != nullptr)
        {
            auto* OldTail = My_Tail;
            My_Tail = My_Tail->My_Prev;

            if (My_Tail != nullptr)
            {
                My_Tail->My_Next = nullptr;
            }
            else
            {
                My_Head = nullptr;
            }

            delete OldTail;
            --My_Length;
        }
    }
    
    void Clear()
    {
        if (My_Length != 0)
        {
            auto Current = My_Head;
            while (Current != nullptr)
            {
                
                auto Temp = Current->My_Next;

                delete Current;

                Current = Temp;
                
                --My_Length;
            }
        }
    }
    TType GetHeadValue() const
    {
        if (My_Head != nullptr)
        {
            return My_Head->My_Value;
        }
    }
    TType GetTailValue() const
    {
        if (My_Tail != nullptr)
        {
            return My_Tail->My_Value;
        }
    }

    bool IsEmpty()
    {
        if (My_Length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void InsertAfter(TType value,LinkedListNode<TType>& node)
    {
        auto* NewNode = new LinkedListNode<TType>;
        NewNode->My_Value = value;
        auto Temp = node.My_Next;
        node.My_Next = NewNode;
        NewNode->My_Next = Temp;
    }

    void RemoveAfter(LinkedListNode<TType>& node)
    {
        if (node.My_Next != nullptr)
        {
            auto* temp = node.My_Next;
            node.My_Next = temp->My_Next;
            delete temp;
        }
    }

    void Reverse()
    {
        if (My_Head == nullptr || My_Head == My_Tail)
            return;

        auto* current = My_Head;

        while (current != nullptr)
        {
            auto* temp = current->My_Next;
            current->My_Next = current->My_Prev;
            current->My_Prev = temp;
            current = current->My_Prev;
        }

        auto* temp = My_Head;
        My_Head = My_Tail;
        My_Tail = temp;
    }


private:
    LinkedListNode<TType>* My_Head;
    LinkedListNode<TType>* My_Tail;
    size_t My_Length;
};

int main()
{
    LinkedList<int> MyLL;
    
    MyLL.InsertAtEnd(10);
    auto Middle = MyLL.InsertAtEnd(20);
    MyLL.InsertAtEnd(30);
    // MyLL.PopFront();
    // MyLL.PopBack();
    // std::cout << MyLL.Get_Length() << std::endl;
    std::cout<<MyLL.IsEmpty()<<"\n";
    MyLL.Reverse();
    std::cout<<MyLL.GetHeadValue()<<MyLL.GetTailValue()<<"\n";
    MyLL.RemoveAfter(Middle);
    std::cout<<Middle.My_Value<<"\n";
    MyLL.InsertAfter(25,Middle);
    std::cout<<Middle.My_Next->My_Value<<"\n";
    MyLL.Clear();
    std::cout<<MyLL.Get_Length()<<"\n";
    std::cout<<MyLL.IsEmpty();

    return 0;
}
