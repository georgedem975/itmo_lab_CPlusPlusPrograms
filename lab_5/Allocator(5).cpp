#include <iostream>
#include <vector>

enum Color
{
    open, 
    close
};

template <class T>
struct Node
{
    Node()
    {
        this->next = nullptr;
        this->memory = nullptr;
        this->access = open;
    }
    ~Node()
    {
        this->memory = nullptr;
        this->next = nullptr;
    }
    Color access;
    T* memory;
    size_t size = 0;
    Node* next;
};

template <class T>
struct List
{
    List()
    {
        this->first = nullptr;
        this->temp = nullptr;
        this->end = nullptr;
    }

    ~List()
    {
        this->first = nullptr;
        this->end = nullptr;
        this->temp = nullptr;
    }

    Node<T>* createNode()
    {
        Node<T>* temp = new Node<T>;
        return temp;
    }

    void add(T* &point, size_t s)
    {
        if (this->first == nullptr)
        {
            this->first = createNode();
            this->first->memory = point;
            this->end = this->first;
            this->temp = this->first;
        }
        else
        {
            this->end = createNode();
            this->temp->next = this->end;
            this->end->memory = point;
            this->temp = this->end;
        }
        this->temp->size = s;
    }

    T* getMemory(size_t size)
    {
        this->temp = this->first;
        while (this->temp != this->end)
        {
            if (this->temp->size == size && this->temp->access == open)
            {
                this->temp->access = close;
                return this->temp->memory;
            }
            this->temp = this->temp->next;
        }
        return nullptr;
    }

    void setMemory(T* ptr)
    {
        if (this->first == nullptr)
            return;
        this->temp = this->first;
        while (this->temp->memory != ptr)
        {
            if (this->temp->memory == ptr)
            {
                this->temp->access = open;
                break;
            }
            this->temp = this->temp->next;
        }
    }
    
    Node<T>* first;
    Node<T>* temp;
    Node<T>* end;
};

template<class T>
class BazeAllocator
{
    List<T> memoryList;
    bool flag = false;

    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;

        template<class arg, class... args>
        BazeAllocator(arg thatArg, args... otherArgs) : BazeAllocator(otherArgs...)
        {
            T* tempPointer = static_cast<int *>(std::malloc(sizeof(T) * (thatArg)));
            this->memoryList.add(tempPointer, thatArg);
        }

        template<class arg>
        BazeAllocator(arg thatArg)
        {
            this->flag = true;
            T*tempPointer = static_cast<int *>(std::malloc(sizeof(T) * ((int) thatArg)));
            this->memoryList.add(tempPointer, thatArg);
        }

        template<class T1> BazeAllocator(const BazeAllocator<T1>&){}

        BazeAllocator();

        ~BazeAllocator() = default;

        pointer allocate(size_t size)
        {
            T* p = this->memoryList.getMemory(size);
            if (p == nullptr && flag)
            {
                throw ("can't alloc");
            }
            if (!flag)
                return static_cast<pointer>(malloc(8));
            return p;
        }

        void deallocate(T *p, size_type sizeType)
        {
            this->memoryList.setMemory(p);
        }
};

int main()
{
    std::vector<int, BazeAllocator<int>> v(BazeAllocator<int>(5,2,5,1,8));

    v.reserve(5);

    return 0;
}