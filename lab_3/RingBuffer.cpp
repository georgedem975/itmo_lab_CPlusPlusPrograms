#include <iostream>
#include <vector>

namespace predicats
{
    template <class T, class U>
    class EqualTo
    {
    public:
        bool operator ()(T data1, U data2)
        {
            return data1 == data2;
        }
    };

    template <class T, class U>
    class NotEqualTo
    {
    public:
        bool operator ()(T data1, U data2)
        {
            return data1 != data2;
        }
    };

    template <class T, class U>
    class Greater
    {
    public:
        bool operator ()(T data1, U data2)
        {
            return data1 > data2;
        }
    };

    template <class T, class U>
    class Less
    {
    public:
        bool operator ()(T data1, U data2)
        {
            return data1 < data2;
        }
    };

    template <class T, class U>
    class GreaterEqual
    {
    public:
        bool operator ()(T data1, U data2)
        {
            return data1 >= data2;
        }
    };

    template <class T, class U>
    class LessEqual
    {
    public:
        bool operator ()(T data1, U data2)
        {
            return data1 <= data2;
        }
    };

    namespace logical
    {
        template <class T, class U>
        class LogicalAnd
        {
        public:
            bool operator ()(T data1, U data2)
            {
                return data1 && data2;
            }
        };

        template <class T, class U>
        class LogicalOr
        {
        public:
            bool operator ()(T data1, U data2)
            {
                return data1 || data2;
            }
        };

        template <class T>
        class LogicalNot
        {
        public:
            bool operator ()(T data1)
            {
                return !data1;
            }
        };
    }
}

namespace functions
{
    namespace all_of
    {
        template <class T, class U, class Z>
        bool all_of(T type, U predicat, Z val)
        {
            for (auto t : type)
            {
                if (!predicat(t, val))
                {
                    return false;
                }
            }
            return true;
        }

        template <class T, class U, class Z, class Y>
        bool all_of(T type, U predicat, Z val, Y start, Y finish, Y allStart)
        {
            Y counter = allStart;
            for (auto t : type)
            {
                if (counter >= start && counter <= finish)
                {
                    if (!predicat(t, val))
                    {
                        return false;
                    }
                }
                counter++;
            }
            return true;
        }
    }

    namespace any_of
    {
        template <class T, class U, class Z>
        bool any_of(T type, U predicat, Z val)
        {
            for (auto t : type)
            {
                if (predicat(t, val))
                {
                    return true;
                }
            }
            return false;
        }

        template <class T, class U, class Z, class Y>
        bool any_of(T type, U predicat, Z val, Y start, Y finish, Y allStart)
        {
            Y counter = allStart;
            for (auto t : type)
            {
                if (counter >= start && counter <= finish)
                {
                    if (predicat(t, val))
                    {
                        return true;
                    }
                }
                counter++;
            }
            return false;
        }
    }


    namespace none_of
    {
        template <class T, class U, class Z>
        bool none_of(T type, U predicat, Z val)
        {
            for (auto t : type)
            {
                if (predicat(t, val))
                {
                    return false;
                }
            }
            return true;
        }
        template <class T, class U, class Z, class Y>
        bool none_of(T type, U predicat, Z val, Y start, Y finish, Y allStart)
        {
            Y counter = allStart;
            for (auto t : type)
            {
                if (counter >= start && counter <= finish)
                {
                    if (predicat(t, val))
                    {
                        return false;
                    }
                }
                counter++;
            }
            return true;
        }
    }

    namespace one_of
    {
        template <class T, class U, class Z>
        bool one_of(T type, U predicat, Z val)
        {
            int countOfNumbers = 0;
            for (auto t : type)
            {
                if (predicat(t, val))
                {
                    countOfNumbers++;
                }
                if (countOfNumbers == 2)
                {
                    return false;
                }
            }
            if (countOfNumbers == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        template <class T, class U, class Z, class Y>
        bool one_of(T type, U predicat, Z val, Y start, Y finish, Y all_start)
        {
            Y counter = all_start;
            int countOfNumbers = 0;
            for (auto t : type)
            {
                if (counter >= start && counter <= finish)
                {
                    if (predicat(t, val))
                    {
                        countOfNumbers++;
                    }
                    if (countOfNumbers == 2)
                    {
                        return false;
                    }
                }
                counter++;
            }
            if (countOfNumbers == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    namespace is_sorted
    {
        template <class T, class U, class Y>
        bool is_sorted(T type, U predicat, Y start, Y finish)
        {
            auto t1 = *(++start);
            bool flag = false;
            for (auto t : type)
            {
                if (flag)
                {
                    if (!predicat(t1, t))
                    {
                        return false;
                    }
                }
                if (flag)
                {
                    t1 = t;
                }
                flag = true;
            }
            return true;
        }
    }

    namespace is_partitioned
    {
        template <class T, class U, class Y>
        bool is_partitioned(T type, U predicat, Y start, Y finish)
        {
            auto t1 = *(++start);
            bool flag1 = false, flag2 = false;
            for (auto t : type)
            {
                if (flag1 && !flag2)
                {
                    if (!predicat(t1, t))
                    {
                        flag2 = true;
                    }
                }
                else if (flag1 && flag2)
                {
                    if (predicat(t1, t))
                    {
                        return false;
                    }
                }

                if (flag1)
                {
                    t1 = t;
                }
                flag1 = true;
            }
            if (flag1 && flag2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    namespace find_not
    {
        template <class T, class U, class Z, class Y>
        Z find_not(T type, U predicat, Y start, Y finish, Z val)
        {
            for (auto t : type)
            {
                if (!predicat(t, val))
                {
                    return t;
                }
            }
            return *finish;
        }
    }

    namespace find_backward
    {
        template <class T, class U, class Z, class Y>
        Z find_backward(T type, U predicat, Y start, Y finish, Z val)
        {

            for (auto t : type)
            {
                if (predicat(t, val))
                {
                    return t;
                }
            }
            return *start;
        }
    }

    namespace is_palindrome
    {
        template <class T, class U, class Z, class Y>
        bool is_palindrome(T type, U predicat, Y start, Z finish, Y average)
        {
            if (start == average)
            {
                return true;
            }
            else
            {
                bool flag = true;
                int counter = 0;
                for (auto t : type)
                {
                    if (counter != 0)
                    {
                        break;
                    }
                    for (auto f : type)
                    {
                        if (!predicat(t, f))
                        {
                            flag = false;
                        }
                        else
                        {
                            flag = true;
                        }
                    }
                    counter++;
                }
                if (flag)
                {
                    if (start != average)
                    {
                        is_palindrome(type, predicat, ++start, --finish, average);
                    }
                    return true;
                }
                return false;
            }
        }
    }

}

namespace ring_buffer
{
    template <class T>
    class RingBuffer
    {
        class Node;
    public:
        RingBuffer()
        {
            this->head = NULL;
            this->tail = NULL;
            this->capacity = 0;
        }

        RingBuffer(int size) : RingBuffer()
        {
            if (size < 2)
            {
                exit(1);
            }

            this->capacity = size;

            for (int i = 0; i < this->capacity; i++)
            {
                Node* temp = createNode(0);
                if (this->head == NULL)
                {
                    this->head = temp;
                    this->that = this->head;
                }
                else if (i != this->capacity - 1)
                {
                    this->tail = temp;
                    this->that->next = this->tail;
                    this->tail->prev = this->that;
                    this->that = this->tail;
                }
                else
                {
                    this->tail = temp;
                    this->that->next = this->tail;
                    this->tail->prev = this->that;
                    this->head->prev = this->tail;
                    this->tail->next = this->head;
                    this->tail = this->head;
                    this->that = this->head;
                }

                this->capacityColor = empty;
            }
        }
        ~RingBuffer()
        {
            this->tail = NULL;
            this->head = NULL;
            this->that = NULL;
        }

        class Iterator
        {
        public:
            friend class RingBuffer<T>;
            Iterator() : iterNode(0) {}
            Iterator(Node* newIterNode) : iterNode(newIterNode) {}
            Iterator(const Iterator& iter) : iterNode(iter.iterNode) {}

            Iterator& operator=(const Iterator& iter)
            {
                iterNode = iter.iterNode;
                return *this;
            }

            bool operator ==(const Iterator& iter)
            {
                return iterNode == iter.iterNode;
            }

            bool operator != (const Iterator& iter)
            {
                return !((Iterator)iter == *this);
            }

            Iterator& operator++()
            {
                if (iterNode != 0 && iterNode->next->GetColor() != close)
                {
                    iterNode = iterNode->next;
                    return *this;
                }
            }

            Iterator& operator--()
            {
                if (iterNode != 0 && iterNode->next->GetColor() != close)
                {
                    iterNode = iterNode->prev;
                    return *this;
                }
            }

            T operator*()
            {
                if (iterNode != 0)
                {
                    return iterNode->GetData();
                }
            }
        private:
            Node* iterNode;
        };

        int size()
        {
            if (this->head->GetColor() == close)
            {
                return 0;
            }
            int counter = 1;
            this->that = this->head->next;
            while (this->that != this->head)
            {
                if (this->that->GetColor() != close)
                {
                    counter++;
                }
                this->that = this->that->next;
            }
            return counter;
        }

        Iterator begin()
        {
            return this->head;
        }

        Iterator end()
        {
            return this->tail;
        }

        void pushBack(T newData)
        {
            if (this->capacityColor == empty)
            {
                this->head->SetData(newData);
                this->head->SetColor(open);
                this->tail = this->head->next;
                this->capacityColor = notFull;
            }
            else if (this->capacityColor == notFull)
            {
                this->tail->SetData(newData);
                this->tail->SetColor(open);
                if (this->tail->next == this->head)
                {
                    this->capacityColor = full;
                }
                else
                {
                    this->tail = this->tail->next;
                }
            }
            else if (this->capacityColor == full)
            {
                this->tail = this->head;
                this->head = this->head->next;
                this->tail->SetData(newData);
            }
        }

        void popBack()
        {
            if (this->capacityColor != empty)
            {
                if (this->tail->prev == this->head)
                {
                    this->tail->prev->SetColor(close);
                    this->tail = this->tail->prev;
                    this->capacityColor = empty;
                }
                else
                {
                    this->tail->prev->SetColor(close);
                    this->tail = this->tail->prev;
                }
            }
        }

        void pushFirst(T newData)
        {
            if (this->capacityColor != full)
            {
                if (this->capacityColor == empty)
                {
                    this->pushBack(newData);
                }
                else if (this->head->prev == tail)
                {
                    this->tail->SetData(newData);
                    this->tail->SetColor(open);
                    this->head = this->tail;
                    this->tail = this->tail->prev;
                    this->capacityColor = full;
                }
                else
                {
                    this->head->prev->SetData(newData);
                    this->head->prev->SetColor(open);
                    this->head = this->head->prev;
                }
            }
            else
            {
                this->tail->SetData(newData);
                this->tail->SetColor(open);
                this->head = this->tail;
                this->tail = this->tail->prev;
            }
        }

        void popFirst()
        {
            if (this->capacityColor != empty)
            {
                if (this->tail->prev == this->head)
                {
                    this->head->SetColor(close);
                    this->capacityColor = empty;
                }
                else
                {
                    this->head->SetColor(close);
                    this->head = this->head->next;
                }
            }
        }

        T front()
        {
            if (this->capacityColor != empty)
            {
                if (this->head->GetColor() != close)
                    return this->head->GetData();
            }
        }

        T back()
        {
            if (this->capacityColor != empty)
            {
                if (this->tail->prev->GetColor() != close)
                    return this->tail->prev->GetData();
            }
        }

        T operator [] (const int index)
        {
            int counter = 0;
            int newIndex = index + 1;
            if (index > this->size())
            {
                exit(1);
            }
            else if (index < 0)
            {
                exit(1);
            }
            else
            {
                this->that = this->head;
                while (counter != newIndex)
                {
                    if (this->that->GetColor() == open)
                    {
                        counter++;
                    }
                    this->that = this->that->next;
                }
                this->that = this->that->prev;
                return this->that->GetData();
            }
        }

        void resize(int newSize)
        {
            if (newSize < 2)
            {
                exit(0);
            }
            if (newSize == this->capacity)
            {
                return;
            }

            if (newSize > this->capacity)
            {
                int counter = newSize - this->capacity;
                for (int i = 0; i < counter; i++)
                {
                    Node* temp = createNode(0);
                    temp->next = this->tail->next;
                    this->that = this->tail->next;
                    this->that->prev = temp;
                    temp->prev = this->tail;
                    this->tail->next = temp;
                }
            }
            else if (newSize < this->capacity)
            {
                int counter = this->capacity - newSize;
                for (int i = 0; i < counter; i++)
                {
                    Node* temp = createNode(0);
                    temp->next = this->tail->next;
                    this->that = this->tail->next;
                    this->that->prev = temp;
                    temp->prev = this->tail;
                    this->tail->next = temp;
                }
            }
            this->capacity = newSize;
        }

    private:
        enum ColorCapacity
        {
            empty,
            notFull,
            full
        };

        enum Color
        {
            close,
            open
        };

        class Node
        {
        public:
            Node()
            {
                this->next = NULL;
                this->prev = NULL;
                this->mark = close;
            }
            Node(T data) : Node()
            {
                this->data = data;
            }
            ~Node()
            {
                this->prev = NULL;
                this->prev = NULL;
            }

            void SetAll(T data, Node* next, Node* prev, Color mark)
            {
                this->data = data;
                this->next = next;
                this->prev = prev;
                this->mark = mark;
            }

            void SetColor(Color mark)
            {
                this->mark = mark;
            }

            Color GetColor()
            {
                return this->mark;
            }

            void SetData(T data)
            {
                this->data = data;
            }

            T GetData()
            {
                return this->data;
            }

            Node* next;
            Node* prev;

        private:
            T data;
            Color mark;
        };

        Node* createNode(T newData)
        {
            Node* temp = new Node();
            temp->SetAll(newData, NULL, NULL, close);
            return temp;
        }

        Node* head;
        Node* that;
        Node* tail;
        int capacity;
        ColorCapacity capacityColor;
    };
}


int main()
{
    return 0;
}