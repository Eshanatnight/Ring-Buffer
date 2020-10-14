#include <iostream>
#include <iterator>
#include <cstdint>
#include <initializer_list>

template <class T>
class CircularBuffer
{
	public:
		typedef T valueType;
		typedef T& referenceType;

	public:
		class iterator;
		class const_iterator;

	public:



	/* DEFAULT CONSTRUCTOR */
		CircularBuffer(std::size_t size) : m_pos(0), m_size(size), m_values(nullptr)
		{
			m_values = new T[size];
		}



	/* CONSTRUCTOR WITH SUPPORT FOR INIT LISTS */
		CircularBuffer(std::initializer_list<T> _list) : m_pos(0), m_size(_list.size()), m_values(nullptr)
		{
			m_values = new T[_list.size()];
			uint8_t i = 0;
			for (auto item : _list)
			{
				m_values[i++] = item;
			}
		}



	/* Destructor */
	/* TO DEALOCATE THE MEMORY */
		~CircularBuffer()
		{
			delete[] m_values;
		}



	/* Size Function */
		std::size_t size()
		{
			return m_size;
		}



	/* begin function */
	/* for range-based & iterator-based for loop */
		iterator begin()
		{
			return iterator(m_values);
		}



	/* end Function */
	/* for range-based & iterator-based for loop */
		iterator end()
		{
			return iterator(m_values + m_size);
		}



	/* const begin function */
	/* for range-based & iterator-based for loop */
		const_iterator begin() const
		{
			return const_iterator(m_values);
		}



	/* const end Function */
	/* for range-based & iterator-based for loop */
		const_iterator end() const
		{
			return const_iterator(m_values + m_size);
		}



	/* Functions that Adds to the BUFFER */
	/* for range-based & iterator-based for loop */
		void add(T value)
		{
			m_values[m_pos++] = value;

			if (m_pos == m_size)
				m_pos = 0;
		}



	/* Indexing Function */
		referenceType get(int pos)
		{
			return m_values[pos];
		}



	/* Indexing Operator */
		referenceType operator[](int pos)
		{
			return m_values[pos];
		}



	/* const Indexing Operator */
		const referenceType operator[](int index) const
		{
			return m_values[index];
		}



	/* Pushes to the back[/end] of the Buffer */
		void push_back(T other)
		{
			m_values[m_pos++] = other;

			if (m_pos == m_size)
				m_pos = 0;
		}



	/* Pushes to the front of the Buffer */
		void push_front(T other)
		{
			m_values[0] = other;
		}


	private:
		int m_pos;
		std::size_t m_size;
		T* m_values;

};

template <typename T>
class CircularBuffer<T>::iterator
{
	public:
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;

	public:
		iterator(pointer ptr) : ptr_(ptr) {}

		self_type operator++()
		{
			self_type i = *this;
			ptr_++;
			return i;
		}

		self_type operator++(int)
		{
			ptr_++;
			return *this;
		}

		reference operator*()
		{
			return *ptr_;
		}

		pointer operator->()
		{
			return ptr_;
		}

		bool operator==(const self_type& rhs)
		{
			return ptr_ == rhs.ptr_;
		}

		bool operator!=(const self_type& rhs)
		{
			return ptr_ != rhs.ptr_;
		}

	private:
		pointer ptr_;
};

template <typename T>
class CircularBuffer<T>::const_iterator
{
	public:
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;

	public:
		const_iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++() { self_type i = *this; ptr_++; return i; }
		self_type operator++(int junk) { ptr_++; return *this; }
		const reference operator*() { return *ptr_; }
		const pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }

	private:
		pointer ptr_;
};