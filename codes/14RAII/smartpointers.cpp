#include <iostream>
#include <memory>
#include <string>
#include <utility>

// ============================================================
// 0. Resource: Basic Resource Class
// ============================================================

class Resource {
private:
    std::string name_;

public:
    // 现代cpp构造函数规范: 单参数构造函数默认加 explict , 可以避免隐式类型转换, 进而避免很多可能的问题
    explicit Resource(std::string name)
        : name_(std::move(name)) {}     // move() 传参, 左右值均可接受, 此处聚焦于智能指针本身

    void use() const {
        std::cout << "Using " << name_ << '\n';
    }
};

// ============================================================
// 1. UniqueOwner: Exclusive Ownership
// ============================================================

class UniqueOwner {
private:
    std::unique_ptr<Resource> resource;

public:
    explicit UniqueOwner(std::unique_ptr<Resource> resource)
        : resource(std::move(resource)) {}

    void use() const {
        if (resource) {
            // uniquepointer 的 use()  函数
            resource->use();
        }
    }

    // get(): access without transferring ownership, 定义这个函数主要是遵循 class 的封装原则
    [[nodiscard]] Resource* get() const noexcept {
        // get() blongs to uniqueptr
        return resource.get();
    }
};

// ============================================================
// 2. SharedOwner: Shared Ownership
// ============================================================

class SharedOwner {
private:
    std::shared_ptr<Resource> resource;

public:
    explicit SharedOwner(std::shared_ptr<Resource> resource)
        : resource(std::move(resource)) {}

    void use() const {
        if (resource) {
            resource->use();
        }
    }

    [[nodiscard]] long use_count() const noexcept {
        return resource.use_count();
    }
};

// ============================================================
// 3. ResourceObserver: Non-owning Reference
// ============================================================

class ResourceObserver {
private:
    std::weak_ptr<Resource> resource;

public:
    explicit ResourceObserver(
        const std::shared_ptr<Resource>& resource
    ) : resource(resource) {}

    void use() const {
        // lock(): obtain temporary shared ownership
        // weakptr 只能访问, 不能修改对应 sharedptr 的生命周期
        // lock(): 当sharedptr 未被销毁: 获取临时sharedptr, 否则返回空的sharedptr
        if (auto ptr = resource.lock()) {
            ptr->use();
        }
    }

    [[nodiscard]] bool expired() const noexcept {
        return resource.expired();
    }
};