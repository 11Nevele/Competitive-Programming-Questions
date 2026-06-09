
#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include <mutex>
#include <utility>
#include <type_traits>
using namespace std;

class IEventPool
{
public:
	virtual ~IEventPool() = default;
};

template<class T>
class EventPool final : public IEventPool
{
public:
	EventPool() = default;

	~EventPool() override
	{
		eventListeners.clear();

	}
	void AddListener(std::function<bool(const T&)> func)
	{
		eventListeners.push_back(func);
	}
	void Invoke(const T& data)
	{
		for (auto f : eventListeners)
		{
			f(data);
		}
	}
private:
	std::vector<std::function<bool(T)>> eventListeners;
};
using Entity = size_t;
class ISparseSet
{
public:
	virtual ~ISparseSet() = default;
	virtual void Delete(Entity) = 0;
	virtual void Clear() = 0;
	virtual std::size_t Size() = 0;
	virtual bool Contains(Entity id) = 0;
	virtual std::vector<Entity> GetEntityList() = 0;

};

template <typename Type>
struct SparseSet final : ISparseSet
{
private:
	std::vector<Type> objects;
	std::vector<Entity> dense;
	std::vector<size_t> sparse;
	uint32_t maxValue;
	const size_t Tombstone = UINT64_MAX;


	//add an element to the set

	size_t GetDenseID(Entity element)
	{
		if (!Contains(element))
			return Tombstone;
		return sparse[element];
	}
public:
	SparseSet(uint32_t maxValue = 1000)
	{
		this->maxValue = maxValue;
		sparse.resize(maxValue + 1, Tombstone);
	}
	~SparseSet() override
	{
		dense.clear();
		sparse.clear();
		objects.clear();
	}
	void Clear() override
	{
		dense.clear();
		sparse.clear();
		sparse.resize(1001);
		maxValue = 1000;
		objects.clear();
	}
	Type* Set(Entity element, Type obj)
	{
		if (Contains(element))
		{
			size_t ind = GetDenseID(element);
			objects[ind] = obj;
			return &objects[ind];
		}

		if (element > maxValue)
			sparse.resize(10 * maxValue);
		dense.push_back(element);
		objects.push_back(obj);
		sparse[element] = dense.size() - 1;
		return &objects.back();
	}
	bool Contains(Entity element) override
	{
		return sparse[element] < dense.size() && dense[sparse[element]] == element;
	}
	Type* Get(Entity id)
	{
		if (!Contains(id))
			return nullptr;
		std::size_t index = GetDenseID(id);
		return &objects[index];
	}

	Type& GetRef(Entity id)
	{
		if (!Contains(id))
			ECS_ASSERT(false, "GetRef called on invalid entity with ID " << id);
		std::size_t index = GetDenseID(id);

		return objects[index];
	}
	void Delete(Entity element) override
	{
		if (!Contains(element))
			return;

		Entity lastElement = dense.back();
		size_t targetInd = GetDenseID(element);
		dense[targetInd] = lastElement;
		sparse[lastElement] = targetInd;
		objects[targetInd] = objects.back();

		objects.pop_back();
		dense.pop_back();
	}
	std::size_t Size() override
	{
		return dense.size();
	}

	std::vector<Entity> GetEntityList() override
	{
		return dense;
	}

	bool IsEmpty() const
	{
		return dense.empty();
	}

	// Read-only dense list
	const std::vector<Type>& Data() const
	{
		return objects;
	}
	void PrintDense()
	{
		for (const Type& e : objects)
		{
			std::cout << e << ", ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	function<bool(int)> f = [](int i) {cout << i << endl; return true; };
	function<bool(int)> f2 = [](int i) {cout << i * 2 << endl; return true; };
	cout << f.target_type().hash_code() << endl;
	cout << f2.target_type().hash_code() << endl;

}
