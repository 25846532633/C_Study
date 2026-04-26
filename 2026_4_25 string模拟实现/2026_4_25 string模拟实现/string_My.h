#pragma once
#include <iostream>
#include <string>
namespace Test
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const bit::string& s);
        friend istream& operator>>(istream& _cin, bit::string& s);
    public:
        typedef char* iterator;
    public:
        string(const char* str = "")
            :_size(strlen(str))
        {
            _capacity = _size;//容量
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        string(const string& s);
        {
            string tmp(s._str);
            swap(tmp);
        }

        string& operator=(string ss)
        {
            swap(ss);
            return *this;
        }

        string& operator=(const string& s)
        {
            string ss(s);

            swap(ss);
            return *this;
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _capcity = _size = 0;
        }

         // iterator
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        // modify
        void push_back(char c)
        {
            insert(_size, c);
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }

        void append(const char* str);
        {
            insert(_size, str);
        }
        
        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void clear()
        {
            _size = 0;
            _str[_size] = '\0';
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return _str;
        }


        // capacity
        size_t size()const
        {
            return _size;
        }
        size_t capacity()const
        {
            return _capacity;
        }
        bool empty()const
        {
            return _size == 0;
        }
        void resize(size_t n, char c = '\0')
        {
            if (n <= size)
            {
                _str[n] = '\0';
                _size = n;
            }
            else
            {
                reserve(n);//要扩容
                //用指定字符c填充新增位置
                for (size_t i = _size; i < n; i++)
                {
                    _str[i] = c;
                }
                _str[n] = '\0';
                _size = n;
            }
        }
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];//要存'\0';
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }

        // access
        char& operator[](size_t index)
        {
            assert(index < _size);
            return _str[index];
        }
            
        const char& operator[](size_t index)const
        {
            assert(index < _size);
            return _str[index];
        }

        //relational operators
        bool operator==(const string& s1, const string& s2)
        {
            int ret = strcmp(s1.c_str(), s2.c_str());
            return ret == 0;
        }

        bool operator<(const string& s1, const string& s2)
        {
            int ret = strcmp(s1.c_str(), s2.c_str());
            return ret < 0;
        }

        bool operator<=(const string& s1, const string& s2)
        {
            return s1 < s2 || s1 == s2;
        }

        bool operator>(const string& s1, const string& s2)
        {
            return !(s1 <= s2);
        }

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {
            assert(pos < _size);

            for (size_t i = pos; i < _size; i++)
            {
                if (_str[pos] == c)
                    return i;
            }
            return npos;//没找到
        }
        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const
        {
            assert(pos < _size);
            const char* p = strstr(_str + pos, s);
            if (p)
                return p - str;
            else
                return npos;
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {
            assert(pos <= _size);

            if (_size == _capacity)
            {
                reserve(_capacity == 0 : 4 : 2 * _capacity);
            }

            size_t end = _size + 1;
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                end--;
            }

            _str[pos] = c;
            ++_size;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);

            size_t len = strlen(str);
            if (_size + len > _capacity)
            {
                reserve(_size + len);
            }
            size_t end = _size + len;
            while (end > pos + len - 1)
            {
                _str[end] = _str[end - len];
                end--;
            }
            strcnpy(_str + pos, str, len);
            _size += len;
        }
        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len)
        {
            assert(pos < _ size);

            //要删除pos位置后的len个元素（已经超出原本已有的元素）
            if (len == npos || len >= _size - pos)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len);
                _size -= len;
            }
        }

    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    }

    ostream& operator<<(ostream& out, const string& s)
    {
        for (auto ch : s)
        {
            out << ch;
        }
        return out;
    }
    istream& operator>>(istream& in, string& s)
    {
        s.clear();

        char ch;
        ch = in.get();
        char buff[128];
        size_t i = 0;
        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            //每128个字符，再加入到string，减少开销
            if (i == 127)
            {
                buff[127] = '\0';
                s += buff;
                i = 0;
            }
            ch = in.get();
        }
        //添加'\0'
        if (i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }


    void test1()
    {

    }
};