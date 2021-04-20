#include "triplestore.hh"
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

}
