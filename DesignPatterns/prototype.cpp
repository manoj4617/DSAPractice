#include <iostream>
#include <unordered_map>

using namespace std;

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype {
    protected:
    string proto_name;
    float proto_field;

    public:
    Prototype();
    Prototype(string name) : proto_name(name) {}
    virtual ~Prototype(){}
    virtual Prototype *Clone() const = 0;
    virtual void Method(float field){
        this->proto_field = field;
        cout << "Call from Method " << proto_name << "With field " << proto_field << "\n";
    }
};

class ConcretePrototype_1 : public Prototype{
    private:
    float concrete_prototype_field1_;

    public:
    ConcretePrototype_1(string prototype_name, float concrete_prototype_field)
          : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}

    Prototype *Clone()  const override {
        return new ConcretePrototype_1(*this);
    }
};

class ConcretePrototype_2 : public Prototype{
    private:
    float concrete_prototype_field1_;

    public:
    ConcretePrototype_2(string prototype_name, float concrete_prototype_field)
          : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {}

    Prototype *Clone()  const override {
        return new ConcretePrototype_2(*this);
    }
};

class PrototypeFactory{
    private:
    unordered_map<Type, Prototype*, hash<int>> prototypes_;

    public:
    PrototypeFactory(){
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype_1("Prototype_1", 1.0f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype_2("Prototype_2", 2.0f);
    }

    ~PrototypeFactory(){
        delete prototypes_[PROTOTYPE_1];
        delete prototypes_[PROTOTYPE_2];
    }

    Prototype *CreatePrototype(Type type){
        return prototypes_[type]->Clone();
    }
};

void Client(PrototypeFactory &prototype_factory) {
  std::cout << "Let's create a Prototype 1\n";

  Prototype *prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
  prototype->Method(90);
  delete prototype;

  std::cout << "\n";

  std::cout << "Let's create a Prototype 2 \n";

  prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
  prototype->Method(10);

  delete prototype;
}

int main() {
  PrototypeFactory *prototype_factory = new PrototypeFactory();
  Client(*prototype_factory);
  delete prototype_factory;

  return 0;
}