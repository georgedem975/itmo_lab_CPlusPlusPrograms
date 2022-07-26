#include <iostream>
#include <vector>

template <class T>
class Alloc
{
    struct Node
    {
        T* point;
        char enter;
        Node* next;
    };

    public:
        typedef size_t size_type;
        typedef T* pointer;
        typedef T value_type;

        template<class T1> Alloc(const Alloc<T1>& other){}

        Alloc();

        ~Alloc() = default;

        Node* creationNode()
        {
            Node* temp = new Node;
            return temp;
        }

        Alloc(size_t size)
        {
            this->counter = size;
            T* ptr = static_cast<int *>(std::malloc(size * sizeof(T)));

            std::cout << "memory allocate\n";

            for (int i = 0; i < size; i++)
            {
                T* ptr = static_cast<int *>(std::malloc(sizeof(T)));

                this->temper = creationNode();
                this->temper->enter = 'a';
                this->temper->point = ptr;

                if (i == 0)
                {
                    this->first = this->temper;
                    this->last = this->temper;
                }
                else
                {
                    this->last->next = this->temper;
                    this->last = this->temper;
                }
            }
            this->last->next = NULL;
        }

        pointer allocate(size_t size)
        {
            if(this->first == nullptr)
                return static_cast<pointer>(malloc(size* sizeof(T)));
            Node* temperTwo;
            this->temper = this->first;
            while (this->temper != this->last)
            {
                if (this->temper->enter == 'a')
                {
                    int tempCount = size;
                    temperTwo = this->temper;
                    while (tempCount != 0)
                    {
                        if (temperTwo->enter != 'a')
                        {
                            break;
                        }
                        temperTwo = temperTwo->next;
                        tempCount--;
                    }
                    if (tempCount == 0)
                    {
                        this->temper->next = temperTwo->next;
                        this->temper->enter = 'b';
                        return this->temper->point;
                        std::cout << "get memory\n";
                    }
                }
                this->temper = this->temper->next;
            }
            throw ("no memory");
        }

        void deallocate(T *p, size_type sizeType)
        {
            if (this->first == nullptr)
                return;
            this->temper = this->first;
            while (this->temper->next->point != p)
            {
                if (this->temper->point == p)
                {
                    this->temper->enter = 'a';
                    std::cout << "deallocate memory\n";
                    return;
                }
                this->temper = this->temper->next;
            }
        }

    private:
        Node* first = nullptr;
        Node* last;
        Node* temper;
        size_t counter;
};

int main()
{
    std::vector<int, Alloc<int>> t(Alloc<int>(100));
    t.reserve(15);
    return 0;
}