#include <iostream>
#include <vector>
#include <list>

template <class T>
class Allocator
{
    enum Condition
    {
        haveMemory,
        haventMemory
    };

    public:
        typedef T value_type;
        typedef size_t size_type;
        typedef T& reference;
        typedef T* pointer;

        pointer allocate(size_t size)
        {
            if (this->sizes.size() == 0)
            {
                return static_cast<pointer > (malloc(size* sizeof(T)));
            }
            std::cout << "allocate\n";
            T* pointMem = nullptr;
            std::list<int>::iterator it;
            it = this->sizes.begin();
            for (int i = 0; i < this->memory.size(); i++)
            {
                if (this->memory[i].first == haveMemory && *it == size)
                {
                    pointMem = this->memory[i].second;
                    this->memory[i].first = haventMemory;
                }
                ++it;
            }
            if (pointMem == nullptr)
            throw ("no memory");
            return pointMem;
        }

        Allocator(std::list<int> tmp)
        {
            std::list<int>::iterator it;
            it = tmp.begin();
            for (int i = 0; i < tmp.size(); i++)
            {
                std::pair<condition, T*> temp;
                temp.first = haveMemory;
                temp.second = static_cast<int *>(malloc(*it * sizeof(T)));
                this->memory.push_back(temp);
                ++it;
            }
            this->sizes = tmp;
        }

        void deallocate(T *p, size_type sizeType)
        {
            for (int i = 0; i < this->memory.size(); i++)
            {
                if (this->memory[i].second == p)
                {
                    this->memory[i].first = haveMemory;
                    std::cout << "deallocate\n";
                }
            }
            return;
        }

        template<class T1> Allocator(const Allocator<T1>&){}

        Allocator();

        ~Allocator() = default;
    private:
        std::vector<std::pair<condition, T*>> memory;
        std::list<int> sizes;
};

int main()
{
    std::list<int> r;
    r.push_back(3);
    r.push_back(2);
    std::vector<int, Allocator<int>> v(r);

    v.reserve(2);
    return 0;
}