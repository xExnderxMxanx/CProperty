//
// Created by xExnderxMxanx on 2023-12-19.
//

#include "CProperty.hpp"

template<typename Type, typename Owner>
Property<Type, Owner, ReadWrite>::operator Type() {
        return (m_owner->*m_getter)();
}

template<typename Type, typename Owner>
Property<Type, Owner, ReadWrite>& Property<Type, Owner, ReadWrite>::operator=(Type data) {
        (m_owner->*m_setter)(data);
        return *this;
}

template<typename Type, typename Owner>
void Property<Type, Owner, ReadWrite>::init(Owner* const owner, getter getmethod, setter setmethod) {
        m_owner = owner;
        m_getter = getmethod;
        m_setter = setmethod;
}

template<typename Type, typename Owner>
Property<Type, Owner, ReadOnly>::operator Type() {
        return (m_owner->*m_getter)();
}

template<typename Type, typename Owner>
void Property<Type, Owner, ReadOnly>::init(Owner* const owner, getter getmethod) {
        m_owner = owner;
        m_getter = getmethod;
}

template<typename Type, typename Owner>
Property<Type, Owner, WriteOnly>& Property<Type, Owner, WriteOnly>::operator=(Type data) {
        (m_owner->*m_setter)(data);
        return *this;
}

template<typename Type, typename Owner>
void Property<Type, Owner, WriteOnly>::init(Owner* const owner, setter setmethod) {
        m_owner = owner;
        m_setter = setmethod;
}