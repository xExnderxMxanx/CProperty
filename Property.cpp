//
// Created by xExnderxMxanx on 2023-12-08.
//

#ifndef PROPERTY_HPP
#define PROPERTY_HPP

// Forward declaration of ReadOnly, WriteOnly, and ReadWrite classes.
class ReadOnly;
class WriteOnly;
class ReadWrite;

// The Property class template is a utility for creating properties with different access levels.
// Type is the type of the property, Owner is the class that owns the property, and Access is the access level of the property.
template<typename Type, typename Owner, typename Access>
class Property{
};

// Specialization of the Property class template for read-write properties.
template<typename Type, typename Owner>
class Property<Type, Owner, ReadWrite>{
protected:
    // Type aliases for getter and setter member function pointers.
    typedef Type (Owner::*getter)();

    typedef void (Owner::*setter)(Type);

    // Pointer to the owner of the property.
    Owner* m_owner;

    // Getter and setter member function pointers.
    getter m_getter;
    setter m_setter;

public:
    // Conversion operator to Type. Calls the getter member function.
    explicit operator Type() const {
        return (m_owner->*m_getter)();
    }

    // Assignment operator. Calls the setter member function.
    Property& operator =(Type data) {
        (m_owner->*m_setter)(data);
        return *this;
    }

    // Default constructor. Initializes all member variables to 0.
    Property() : m_owner(0),
                 m_getter(0),
                 m_setter(0) {
    }

    // Constructor. Initializes all member variables with the provided arguments.
    Property(Owner* const owner, getter getmethod, setter setmethod) : m_owner(owner),
                                                                       m_getter(getmethod),
                                                                       m_setter(setmethod) {
    }

    // Initializes all member variables with the provided arguments.
    void init(Owner* const owner, getter getmethod, setter setmethod) {
        m_owner = owner;
        m_getter = getmethod;
        m_setter = setmethod;
    }
};

// Other specializations of the Property class template would go here...


template<typename Type, typename Owner>
class Property<Type, Owner, ReadOnly>{
protected:
    typedef Type (Owner::*getter)();

    Owner* m_owner;
    getter m_getter;

public:
    explicit operator Type() {
        return (m_owner->*m_getter)();
    }


    Property() : m_owner(0),
                 m_getter(0) {
    }

    Property(Owner* const owner, getter getmethod) : m_owner(owner),
                                                     m_getter(getmethod) {
    }

    void init(Owner* const owner, getter getmethod) {
        m_owner = owner;
        m_getter = getmethod;
    }
};


template<typename Type, typename Owner>
class Property<Type, Owner, WriteOnly>{
protected:
    typedef void (Owner::*setter)(Type);

    Owner* m_owner;
    setter m_setter;

public:
    Property& operator =(Type data) {
        (m_owner->*m_setter)(data);
        return *this;
    }

    Property() : m_owner(0),
                 m_setter(0) {
    }

    Property(Owner* const owner, setter setmethod) : m_owner(owner),
                                                     m_setter(setmethod) {
    }

    void init(Owner* const owner, setter setmethod) {
        m_owner = owner;
        m_setter = setmethod;
    }
};

#endif //PROPERTY_HPP
