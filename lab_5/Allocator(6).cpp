#include <iostream>
#include <vector>

template <class T>
class MyAllocator
{
    enum Color
    {
        open,
        close   
    };

    class Node
    {
        public:
            T* point = nullptr;
            Node* next = nullptr;
            Node* down = nullptr;
            Color nodeColor = open;
            int size = 0;
    };

    class List
    {
        public:
            Node* first = nullptr;
            Node* temp = nullptr;
            Node* tempDown = nullptr;
    };

    List allocList;
    bool flagForAlloc = true;
    T* ptrAllMemory;
    Node* ptrMemoryForList;
    void* pointForStruct;

    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;


        MyAllocator(){}

        template<class countCells, class sizeCells>
        MyAllocator(int allCountOfMemory, int countCellsForList, countCells countCtorCells, sizeCells sizeCtorCells)
        {
            if (this->flagForAlloc)
            {
                this->flagForAlloc = false;
                this->ptrMemoryForList = static_cast<Node *>(std::malloc(countCellsForList * sizeof(Node)));
                this->ptrAllMemory = static_cast<T*>(std::malloc(allCountOfMemory* sizeof(T)));

                for (int i = 0; i < countCtorCells; i++)
                {
                    Node* temp = this->ptrMemoryForList;
                    this->ptrMemoryForList++;
                    if (this->allocList.first == nullptr)
                    {
                        this->allocList.first = temp;
                        this->allocList.temp = temp;
                    }
                    else
                    {
                        this->allocList.temp->next = temp;
                        this->allocList.temp = temp;
                        this->allocList.temp->down = nullptr;
                    }
                    this->allocList.temp->point = this->ptrAllMemory;
                    this->ptrAllMemory += sizeCtorCells;
                    this->allocList.temp->size = sizeCtorCells;
                }
                this->allocList.tempDown = this->allocList.first;
                this->allocList.first->down = nullptr;
                this->allocList.temp->next = nullptr;
                this->allocList.temp = this->allocList.first;
            }
            else
            {
                for (int i = 0; i < countCtorCells; i++)
                {
                    Node* temp = this->ptrMemoryForList;
                    this->ptrMemoryForList++;
                    if (i == 0)
                    {
                        this->allocList.tempDown = temp;
                        this->allocList.temp->down = this->allocList.tempDown;
                        this->allocList.temp = temp;
                    }
                    else
                    {
                        this->allocList.temp->next = temp;
                        this->allocList.temp = temp;
                        this->allocList.temp->down = nullptr;
                    }
                    this->allocList.temp->point = this->ptrAllMemory;
                    this->ptrAllMemory += sizeCtorCells;
                    this->allocList.temp->size = sizeCtorCells;
                }
                this->allocList.tempDown->down = nullptr;
                this->allocList.temp->next = nullptr;
                this->allocList.temp = this->allocList.tempDown;
            }
            std::cout << "in MyAllocator allocated: count_cells == " << static_cast<int>(countCtorCells) << "; size_cells == " << static_cast<int>(sizeCtorCells) << std::endl;
        }

        template<class countCells, class sizeCells, class... nextParameters>
        MyAllocator(int allCountOfMemory, int countCellsForList, countCells countCtorCells, sizeCells sizeCtorCells, nextParameters... nextParameters) : MyAllocator(allCountOfMemory, countCellsForList, nextParameters...)
        {
            if (this->flagForAlloc)
            {
                this->flagForAlloc = false;
                this->ptrMemoryForList = static_cast<Node *>(std::malloc(countCellsForList * sizeof(Node)));
                this->ptrAllMemory = static_cast<T*>(std::malloc(allCountOfMemory* sizeof(T)));

                for (int i = 0; i < countCtorCells; i++)
                {
                    Node* temp = this->ptrMemoryForList;
                    this->ptrMemoryForList++;
                    if (this->allocList.first == nullptr)
                    {
                        this->allocList.first = temp;
                        this->allocList.temp = temp;
                    }
                    else
                    {
                        this->allocList.temp->next = temp;
                        this->allocList.temp = temp;
                        this->allocList.temp->down = nullptr;
                    }
                    this->allocList.temp->point = this->ptrAllMemory;
                    this->ptrAllMemory += sizeCtorCells;
                    this->allocList.temp->size = sizeCtorCells;
                }
                this->allocList.tempDown = this->allocList.first;
                this->allocList.first->down = nullptr;
                this->allocList.temp->next = nullptr;
            }
            else
            {
                for (int i = 0; i < countCtorCells; i++)
                {
                    Node* temp = this->ptrMemoryForList;
                    this->ptrMemoryForList++;
                    if (i == 0)
                    {
                        this->allocList.tempDown = temp;
                        this->allocList.temp->down = this->allocList.tempDown;
                        this->allocList.temp = temp;
                    }
                    else
                    {
                        this->allocList.temp->next = temp;
                        this->allocList.temp = temp;
                        this->allocList.temp->down = nullptr;
                    }
                    this->allocList.temp->point = this->ptrAllMemory;
                    this->ptrAllMemory += sizeCtorCells;
                    this->allocList.temp->size = sizeCtorCells;
                }
                this->allocList.tempDown->down = nullptr;
                this->allocList.temp->next = nullptr;
                this->allocList.temp = this->allocList.tempDown;
            }
            std::cout << "in MyAllocator allocated: count_cells == " << static_cast<int>(countCtorCells) << "; size_cells == " << static_cast<int>(sizeCtorCells) << std::endl;
        }

        template<class U> MyAllocator(const MyAllocator<U>&){}

        pointer allocate(size_type n)
        {
            std::cout << "allocate " << n*sizeof(T) << " bytes\n";
            if (this->allocList.first == nullptr)
            {
                T* p;
                p = static_cast<pointer>(malloc(n*sizeof(T)));
                std::cout << p << std::endl;
                this->pointForStruct = p;
                return p;
            }

            else
            {
                this->allocList.tempDown = this->allocList.first;

                while (this->allocList.tempDown->down != nullptr && this->allocList.tempDown->size != n)
                {
                    if (this->allocList.tempDown->down == nullptr)
                        break;
                    this->allocList.tempDown = this->allocList.tempDown->down;
                }
                if (this->allocList.tempDown->size != n)
                    throw std::invalid_argument("Not this size cells");
                this->allocList.temp = this->allocList.tempDown;
                if (this->allocList.temp->nodeColor == close)
                {
                    while (this->allocList.temp->next != nullptr && this->allocList.temp->nodeColor != open)
                    {
                        if (this->allocList.temp->next == nullptr)
                            break;
                    }
                    if (this->allocList.temp->nodeColor != open)
                        throw std::invalid_argument("Not this size cells");
                }
                this->allocList.temp->nodeColor = close;
                return this->allocList.temp->point;
            }
        }

        ~MyAllocator() = default;

        void deallocate(pointer p, size_type n)
        {
            std::cout << "deallocate memory " << sizeof(T)*n << " bytes\n";
            if (this->allocList.first == nullptr)
            {
                free(p);
                return;
            }
            bfs(this->allocList.first, p, n)->nodeColor = open;
        }

        Node* bfs(Node* t, pointer p, int n)
        {
            if (t->point == p)
                return t;
            if (t->next != nullptr)
                this->bfs(t->next, p, n);
            if (t->down != nullptr)
                this->bfs(t->down, p, n);
        }

        void construct(pointer p, const T& val)
        {
            std::cout << "construct element\nadres: " << p << std::endl;
            new(static_cast<void*>(p)) T(val);
        }

        void construct(pointer p)
        {
            std::cout << "construct\n";
            new(static_cast<void*>(p)) T();
        }

        void destroy(pointer p)
        {
            std::cout << "destroy\n";
            p->~T();
        }
};

int main()
{
    std::allocator_traits<MyAllocator<int>> at;
    std::vector<int, MyAllocator<int>> temp(MyAllocator<int>(16, 4, 4, 4));
    temp.reserve(4);
    temp.push_back(100);
    temp.push_back(2);
    return 0;
}