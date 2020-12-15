#pragma once
#include "strategy.h"
#include <iostream>
#include <unordered_map>


template<class Product, class id>
struct DefaultErrorPolicy {
    static Product *IdNotFound(const id &name) {
        throw std::runtime_error("! ! ! WRONG ARGUMENTS ! ! !\n" + name);
    }
};

template<class Product, class id, typename Creator, class ErrorPolicy = DefaultErrorPolicy<Product, id>>
class Factory {
    typedef Product *(*creator_t)();

public:
    Product *makeObject(const id &name) {
        auto it = creators_.find(name);
        if (it == creators_.end()) {
            return ErrorPolicy::IdNotFound(name);
        }
        std::pair<id, Creator> element = *it;
        return element.second();
    }
    void addCreator(const id name, creator_t c) {
        creators_[name] = c;
    }

    static Factory *getInstance() {
        static Factory f;
        return &f;
    }

private:
    Factory() = default;
    ~Factory() = default;
    Factory(const Factory &);
    Factory &operator=(const Factory &);

    std::unordered_map<id, Creator> creators_;
};
