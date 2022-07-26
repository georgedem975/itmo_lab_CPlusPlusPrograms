#include <iostream>
#include <set>
#include <vector>

template <class T>
class AllocatorWithMultiSet
{
    struct Group
    {
        public:
            Group(int size, bool mod, T* p)
            {
                this->size = size;
                this->mod = mod;
                this->p = p;
            }
            int size;
            T* p;
            bool mod;
    };

    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;

        AllocatorWithMultiSet(std::vector<int> parameters)
        {
            for (int i = 0; i < parameters.size(); i++)
            {
                T* p = static_cast<int *>(std::malloc(parameters[i] * sizeof(T)));

                this->mySet.push_back(Group(parameters[i], 0, p));
            }
        }

        pointer allocate(size_t size)
        {
            if (this->mySet.empty())
                return static_cast<pointer>(std::malloc(size * sizeof(T)));
            int i = 0;
            for (; i < this->mySet.size(); i++)
            {
                if (this->mySet[i].size == size)
                    break;
            }
            if (i == this->mySet.size())
                throw ("no memory for allocate\n");
            this->mySet[i].mod = 1;
            std::cout << "memory allocate\n";
            return this->mySet[i].p;
        }

        void deallocate(pointer p, size_type sizeType)
        {
            for (int i = 0; i < this->mySet.size(); i++)
            {
                if (this->mySet[i].p == p)
                {
                    std::cout << "memory deallocate\n";
                    this->mySet[i].mod = 0;
                    return;
                }
            }
        }

        template<class T1> AllocatorWithMultiSet(const AllocatorWithMultiSet<T1>& other){}

        ~AllocatorWithMultiSet() = default;

    private:
        std::vector<Group> mySet;
};

int main()
{
    std::vector<int> t = {1, 3, 5, 129, 3};
    std::vector<int, AllocatorWithMultiSet<int>> q(t);
    q.reserve(129);

    return 0;
}