#ifndef facts_hh_INCLUDED
#define facts_hh_INCLUDED

#include "string.hh"
#include "utils.hh"

namespace Kakoune
{

// An Id is an opaque, inexhaustible identifier which can only be compared and assigned.
class Id
{
public:
    inline static Id alloc() { return Id(m_next++); }
    inline bool operator == (Id const& rhs) const { return m_value == rhs.m_value; }
    inline bool operator != (Id const& rhs) const { return !operator == (rhs); }

private:
    inline Id(long value) : m_value(value) {}

    static long m_next;
    long m_value;
};

// A fact is some piece of knowledge, a relationship between some entity and a value.
class Fact
{
public:
    inline Fact(Id entity, Id attribute, String value)
        : m_entity(entity)
        , m_attribute(attribute)
        , m_value(value)
    {}

    inline Id entity() const { return m_entity; }
    inline Id attribute() const { return m_attribute; }
    inline String const& value() const { return m_value; }

private:
    Id m_entity;
    Id m_attribute;
    String m_value;
};

class Database : public Singleton<Database>
{
public:
    void posit(Fact const& fact);

private:
};

}

#endif // facts_hh_INCLUDED
