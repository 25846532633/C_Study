#pragma once
#include <atomic>


namespace bit
{
	template<class T>
	class shared_ptr
	{
	public:
		//构造
		shared_ptr(T* ptr)
			:_ptr(ptr),
			 _pcount(new atomic<int>(1))
		{}

		//拷贝构造
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr),
			_pcount(sp._pcount)
		{
			(*_pcount)++;
		}

		void release()
		{
			//最后一个管理对象也没了
			if (--(*_pcount) == 0)
			{
				delete _ptr;
				delete _pcount;
			}
		}

		//赋值重载
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//避免自赋值
			if (_ptr != sp._ptr)
			{
				this->release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;

				++(*_pcount);
			}

			return *this;
		}

		//析构
		~shared_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_pcount;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
		atomic<int>* _pcount;
	};
}