#include <iostream>
#include <map>
#include <vector>

template <typename T>
class CustomAllocator {
public:
    using value_type = T;

    CustomAllocator(size_t chunkSize) : chunkSize_(chunkSize) {}

    template <typename U>
    CustomAllocator(const CustomAllocator<U>& other) : chunkSize_(other.chunkSize_) {}

    T* allocate(std::size_t n) {
        if (n == 0) {
            return nullptr;
        }

        if (n > chunkSize_) {
            throw std::bad_alloc();
        }

        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) {
        if (p != nullptr) {
            ::operator delete(p);
        }
    }

private:
    template <typename U>
    friend class CustomAllocator;

    size_t chunkSize_;
};

template <typename Key, typename Value, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, Value>>>
class CustomMap {
public:
    using container_type = std::map<Key, Value, Compare, Allocator>;
    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;

    CustomMap(size_t chunkSize) : allocator_(chunkSize) {}

    void reserve(size_t count) {
        container_.get_allocator().reserve(count);
    }

    void insert(const Key& key, const Value& value) {
        container_[key] = value;
    }

    iterator begin() {
        return container_.begin();
    }

    iterator end() {
        return container_.end();
    }

    const_iterator begin() const {
        return container_.begin();
    }

    const_iterator end() const {
        return container_.end();
    }

private:
    container_type container_;
    CustomAllocator<std::pair<const Key, Value>> allocator_;
};

template <typename T, typename Allocator = std::allocator<T>>
class CustomQueue {
public:
    using container_type = std::vector<T, Allocator>;
    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;

    void push(const T& value) {
        container_.push_back(value);
    }

    void pop() {
        container_.erase(container_.begin());
    }

    T& front() {
        return container_.front();
    }

    const T& front() const {
        return container_.front();
    }

    bool empty() const {
        return container_.empty();
    }

    iterator begin() {
        return container_.begin();
    }

    iterator end() {
        return container_.end();
    }

    const_iterator begin() const {
        return container_.begin();
    }

    const_iterator end() const {
        return container_.end();
    }

private:
    container_type container_;
};

int main() {
    CustomMap<int, int> customMap(10);

    for (int i = 0; i < 10; ++i) {
        int factorial = 1;
        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }
        customMap.insert(i, factorial);
    }

    for (const auto& pair : customMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    CustomQueue<int> customQueue;
  
    for (int i = 0; i < 5; ++i) {
        customQueue.push(i);
    }

    for (const auto& value : customQueue) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
