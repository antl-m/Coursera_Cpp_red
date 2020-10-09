#ifndef MY_DEQUE_MY_DEQUE_H
#define MY_DEQUE_MY_DEQUE_H

#include <vector>
#include <stdexcept>

template<typename T>
class Deque {
public:
    Deque() = default;

    bool Empty() const {
        return !(front_v.size() || back_v.size());
    }

    std::size_t Size() const {
        return front_v.size() + back_v.size();
    }

    T &operator[](std::size_t index) {
        if (index >= front_v.size())
            return back_v[index - front_v.size()];
        else
            return front_v[front_v.size() - index - 1];
    }

    const T &operator[](std::size_t index) const {
        if (index >= front_v.size())
            return back_v[index - front_v.size()];
        else
            return front_v[front_v.size() - index - 1];
    }

    T &At(std::size_t index) {
        if(index < Size()){
            if (index >= front_v.size())
                return back_v[index - front_v.size()];
            else
                return front_v[front_v.size() - index - 1];
        }
        throw std::out_of_range("out of range");
    }

    const T &At(std::size_t index) const {
        if(index < Size()){
            if (index >= front_v.size())
                return back_v[index - front_v.size()];
            else
                return front_v[front_v.size() - index - 1];
        }
        throw std::out_of_range("out of range");
    }

    T &Front() {
        return (front_v.size() ? front_v.back() : back_v.front());
    }

    const T &Front() const {
        return (front_v.size() ? front_v.back() : back_v.front());
    }

    T &Back() {
        return (back_v.size() ? back_v.back() : front_v.front());
    }

    const T &Back() const{
        return (back_v.size() ? back_v.back() : front_v.front());
    }

    void PushFront(const T& item){
        front_v.push_back(item);
    }

    void PushBack(const T& item){
        back_v.push_back(item);
    }

private:
    std::vector<T> front_v, back_v;
};

#endif //MY_DEQUE_MY_DEQUE_H
