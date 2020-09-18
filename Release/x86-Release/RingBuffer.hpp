#pragma once
#include <iostream>

template <typename T>
class ring
{
private:
	int m_pos;
	int m_size;
	T* m_values;

public:
	class iterator;

public:
	ring(ring& other) = default;

	ring() : m_pos(0), m_size(5), m_values(nullptr) {
		m_values = new T[5];
	}

	ring(int size) : m_pos(0), m_size(size), m_values(nullptr) {
		m_values = new T[size];
	}        // *Constructor and Alocator

	~ring() {
		delete[] m_values;
	}        // *Destructor and Deletor

	int size() const {
		return m_size;
	}

	void push_fornt(T value)
	{
		m_values[0] = value;
	}

	iterator begin() {
		return iterator(0, *this);
	}

	iterator end() {
		return iterator(m_size, *this);
	}

	void push_back(T value)
	{
		m_values[m_pos++] = value;
		if (m_pos == m_size)
			m_pos = 0;
	}      // new: Updated PushBack

	const T& operator[](int pos) const {
		return m_values[pos];
	}  //New: Added Array Index Operator /const\

	T& operator[](int pos) {
		return m_values[pos];
	}  //New: Added Array Index Operator

	bool operator==(ring<T>& other)
	{
		bool chk = false;
		if (m_size == other.size())
		{
			int i = 0;
			for (auto data : other)
			{
				if (m_values[i++] == data)
					chk = true;
				else
					chk = false;
			}
			return chk;
		}
		else
			return chk;
	}

	bool operator!=(ring<T>& other)
	{
		bool chk = true;
		if (m_size == other.size())
		{
			int i = 0;
			for (auto data : other)
			{
				if (m_values[i++] == data)
					chk = false;
				else
					chk = true;
			}
			return chk;
		}
		else
			return chk;
	}
};

template<typename T>
class ring<T>::iterator
{
private:
	int m_pos;
	ring& m_ring;

public:
	iterator(int pos, ring& obj) : m_pos(pos), m_ring(obj)
	{}

	iterator& operator++(int)
	{
		m_pos++;
		return *this;
	}   // !Postfix ++ operator

	iterator& operator++()
	{
		m_pos++;
		return *this;
	}   // !Prefix ++ operator

	T& operator*() {
		return m_ring[m_pos];
	}   // ! *Dereference operator

	bool operator!=(const iterator& other) const {
		return m_pos != other.m_pos;
	}   // ! NotEquals operator
};