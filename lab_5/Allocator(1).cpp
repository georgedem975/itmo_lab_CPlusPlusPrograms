#include <iostream>
#include <vector>
#include <string>
#include <list>

template <class T>
class MyOwnAllocator : protected std::allocator<T>
{
    class Memory;

    std::list<Memory> usedMemory;
    std::list<Memory> deletedMemory;

    private:
        int getNumber(std::string str)
        {
            int result = 0, temp = 0;
            for (int i = 0; i < str.size(); i++)
            {
                temp = ((int)str[i]) - 48;
                result = result * pow(10, i) + temp;
            }
            return result;
        }

        int getSizeOfGroup(std::string str)
        {
            int i = 0;
            std::string stringNumber;
            while (str[i] != '[')
            {
                stringNumber.push_back(str[i]);
                ++i;
            }
            return this->getNumber(stringNumber);
        }
        
        public:
            typedef T value_type;

            MyOwnAllocator();

            ~MyOwnAllocator() = default;

            template<class U> MyOwnAllocator(const MyOwnAllocator<U>& other){}

            MyOwnAllocator(const char *parameters)
            {
                int countOfGroups = this->getSizeOfGroup(parameters);
                int j = 0, k = 0;
                std::vector<std::list<int>> structMemory;
                while (parameters[j] != '['){j++;}
                ++j;
                for (int i = 0; i < countOfGroups; ++i)
                {
                    std::string s;
                    std::list<int> tempMemory;
                    while (parameters[j] != ']')
                    {
                        if (parameters[j] != '{' && parameters[j] != '}' && parameters[j] != '[' && parameters[j] != ',')
                        {
                            s.push_back(parameters[j]);
                        }
                        else if (parameters[j] == '}')
                        {
                            tempMemory.push_back(this->getNumber(s));
                            while (!s.empty()){s.pop_back();}
                        }
                        j++;
                    }
                    structMemory.push_back(tempMemory);
                    j++;
                }

                for (int i = 0; i < structMemory.size(); ++i) 
                {
                    std::list<int>::iterator it;
                    it = structMemory[i].begin();
                    std::cout << "group: ";
                    for (int l = 0; l < structMemory[i].size(); ++l) 
                    {
                        std::cout << *it << " ";
                        ++it;
                    }
                    std::cout << std::endl;
                }

                for (int i = 0; i < structMemory.size(); i++)
                {
                    std::list<int>::iterator it;
                    it = structMemory[i].begin();
                    for (int l = 0; l < structMemory[i].size(); ++l)
                    {
                        T* p = static_cast<int *>(std::malloc(*it * sizeof(T)));
                        Memory temp(p, *it);
                        this->usedMemory.push_back(temp);
                        ++it;
                    }
                }
            }

            pointer allocate(size_t size)
            {
                if (this->usedMemory.size() == 0 && this->deletedMemory.size() == 0)
                    return static_cast<pointer>(malloc(size*sizeof(T)));
                else if (this->usedMemory.size() == 0)
                    throw ("bad");
                else
                {
                    std::list<Memory>::iterator it;
                    it = this->usedMemory.begin();
                    for (int i = 0; i < this->usedMemory.size(); i++)
                    {
                        if (it->getSize() == size)
                        {
                            std::cout << "memory allocated\n";
                            break;
                        }
                        else if (i == this->usedMemory.size() - 1)
                        {
                            throw("bad");
                        }
                        ++it;
                    }
                    this->deletedMemory.push_back(*it);
                    this->usedMemory.erase(it);
                }
            }

            void deallocate(T *p, size_type sizeType)
            {
                std::list<Memory>::iterator it;
                it = this->deletedMemory.begin();
                if (this->deletedMemory.size() == 0)
                {
                    return;
                }
                for (int i = 0; i < this->deletedMemory.size(); i++)
                {
                    if (it->getPoint() == p){break;}
                    ++it;
                }
                this->usedMemory.push_back(*it);
                this->deletedMemory.erase(it);
            }

private:

            class Memory
            {
                public:
                    Memory(T* point, int size)
                    {
                        this->point = point;
                        this->size = size;
                    }
                
                    T* getPoint()
                    {
                        return this->point;
                    }
                
                    int getSize()
                    {
                        return this->size;
                    }
                private:
                    T* point;
                    int size;

            };
};

int main()
{
    MyOwnAllocator<int> t("3[{3},{3},{2}][{5},{4}][{7},{1}]");

    std::vector<int, MyOwnAllocator<int>> v("3[{3},{3},{2}][{5},{4}][{7},{1}]");

    v.reserve(7);

    return 0;
}