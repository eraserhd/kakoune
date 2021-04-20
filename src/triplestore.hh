#ifndef triplestore_hh_INCLUDED
#define triplestore_hh_INCLUDED

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

class Triple
{
public:

private:
    Id m_entity;
    Id m_attribute;
    String m_value;
};

class Triplestore : public Singleton<Triplestore>
{
public:
    void posit(Triple t);
    void retract(Triple t);

private:
};

}

#endif // triplestore_hh_INCLUDED
