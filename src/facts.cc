#include "facts.hh"
#include "unit_tests.hh"

namespace Kakoune
{

long Id::m_next = 1;

UnitTest test_id{[]()
{
    Id id1 = Id::alloc();
    Id id2 = Id::alloc();
    Id id3 = id2;
    kak_assert(id1 == id1);
    kak_assert(id2 != id1);
    kak_assert(id3 == id2);
}};


UnitTest test_fact{[]()
{
    Id entity1 = Id::alloc();
    Id attr1 = Id::alloc();
    Fact fact1(entity1, attr1, "foo");
    kak_assert(fact1.entity() == entity1);
    kak_assert(fact1.attribute() == attr1);
    kak_assert(fact1.value() == "foo");
}};


void Database::posit(Fact const& fact)
{
}

UnitTest test_database{[]()
{
    Id entity1 = Id::alloc();
    Id attr1 = Id::alloc();
    Database::instance().posit(Fact(entity1, attr1, "foo"));
}};

}
