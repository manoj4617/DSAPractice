#include <iostream>
#include <algorithm>
#include <ostream>

template<typename T>
class UniquePtr {
    private:
        T* m_pointer = nullptr;
    public:
        // disabling copy constructor and copy assignment
        // to maintain single ownership
        UniquePtr(const UniquePtr&) noexcept = delete;
        UniquePtr operator=(const UniquePtr&) = delete;

        // Move constructor
        constexpr UniquePtr(const UniquePtr&& other) noexcept : m_pointer(other.m_pointer) {
            other.m_pointer = nullptr;
        }

        // Move assignment
        /**
         * @brief Move assignment operator for UniquePtr.
         * 
         * This operator transfers ownership of the resource from the given rvalue 
         * reference `other` to the current UniquePtr instance. It ensures that the 
         * current instance takes over the resource managed by `other`, and `other` 
         * is left in a null state.
         * 
         * @param other The rvalue reference to another UniquePtr instance.
         * @return UniquePtr& A reference to the current instance after assignment.
         */
        constexpr UniquePtr& operator=(const UniquePtr&& other) noexcept{
            // `reset` call takes ownership of the resource held by other.m_pointer
            // transfers ownership to *this
            reset(other.m_pointer);
            other.m_pointer = nullptr;
            return *this;
        }

        //Constructor
        constexpr explicit UniquePtr(T* pointer = nullptr) noexcept : m_pointer(pointer){}

        ~UniquePtr() noexcept {
            delete m_pointer;
        }

        constexpr void swap(UniquePtr<T>& other) noexcept {
            std::swap(m_pointer, other.m_pointer);
        }

        /*
        [[nodiscard]]: Warns if the return value is ignored.
        constexpr: Indicates that the function can be evaluated at compile time.
        const: Indicates that the function does not modify the state of the object.
        noexcept: Specifies that the function does not throw exceptions.
        */

        [[nodiscard]] constexpr T& operator*() const noexcept {
            return *m_pointer;
        }
        
        [[nodiscard]] constexpr T* operator->() const noexcept {
            return m_pointer;
        }

        [[nodiscard]] constexpr T* get() const noexcept {
            return m_pointer;
        }

        constexpr void reset(T* pointer = nullptr) noexcept {
            delete m_pointer;
            m_pointer = pointer;
        }

        constexpr explicit operator bool() const noexcept {
            return static_cast<bool>(m_pointer);
        }

        constexpr T* release() noexcept {
            auto tmp = m_pointer;
            m_pointer = nullptr;
            return tmp;
        }
};

struct Foo {
    Foo() noexcept {
        std::cout << __func__ << std::endl;
    }
    ~Foo() noexcept {
        std::cout << __func__ << std::endl;
    }

    void bar() const {
        std::cout << "Calling: " << __func__ << std::endl;
    }
};

int main(){
    UniquePtr<int> ptr1(new int(5));
    std::cout << "Value pointed by ptr1: " << *ptr1 << std::endl;

    UniquePtr<Foo> ptr2(new Foo());
    ptr2->bar();

    std::cout << "Pointer address: " << ptr1.get() << std::endl;

    ptr1.reset(new int(10));
    std::cout << "Reset ptr1 to new value: " << *ptr1 << std::endl;

    UniquePtr<int> releasePtr(ptr1.release());
    std::cout << "Released pointer value: " << *releasePtr << std::endl;
    if(!ptr1){
        std::cout << "ptr1 is null!" << std::endl;
    }

    releasePtr.swap(ptr1);
    if(!ptr1){
        std::cout << "ptr1 is null!" << std::endl;
    }

    if(!releasePtr){
        std::cout << "releasePtr is null!" << std::endl;
    }

    return 0;
}
