#include <boost/test/unit_test.hpp>

#include "main.h"

BOOST_AUTO_TEST_SUITE(GetBlockValue_tests)

BOOST_AUTO_TEST_CASE(GetBlockValue_limits)
{
    //
    // Check that the decrease of the block reward is working
    // according to the model data.
    //
    BOOST_CHECK_EQUAL(_GetBlockValue(0,0,0),     1000*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(1,0,0),     100000*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(499,0,0),      100000*COIN);

    // Segment 1:
    BOOST_CHECK_EQUAL(_GetBlockValue(500,0,0),     25000*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(10000,0,0),   25000*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(10579,0,0),   25000*COIN);
    
    // Segment 2:
    BOOST_CHECK_EQUAL(_GetBlockValue(10580,0,0),   15000*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(20659,0,0),   15000*COIN);
    
    // Segment 3:
    BOOST_CHECK_EQUAL(_GetBlockValue(20660,0,0),   7500*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(30739,0,0),   7500*COIN);
    
    // Week 9:
    BOOST_CHECK_EQUAL(_GetBlockValue(81440,0,0),   1000*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(91219,0,0),   1000*COIN);
    
    // Starting 8% reduction
    BOOST_CHECK_EQUAL(_GetBlockValue(91220,0,0),   920*COIN);
    BOOST_CHECK_EQUAL(_GetBlockValue(101299,0,0),   920*COIN);
    
    BOOST_CHECK_EQUAL(_GetBlockValue(171860,0,0),   47216135);
    BOOST_CHECK_EQUAL(_GetBlockValue(181939,0,0),   47216135);
    
    BOOST_CHECK_EQUAL(_GetBlockValue(252500,0,0),   24232209);
    BOOST_CHECK_EQUAL(_GetBlockValue(262579,0,0),   24232209);
    
    BOOST_CHECK_EQUAL(_GetBlockValue(323060,0,0),   13517853);
    BOOST_CHECK_EQUAL(_GetBlockValue(333139,0,0),   13517853);
    
    BOOST_CHECK_EQUAL(_GetBlockValue(423860,0,0),   5871995);
    BOOST_CHECK_EQUAL(_GetBlockValue(433939,0,0),   5871995);
    
    BOOST_CHECK_EQUAL(_GetBlockValue(494420,0,0),   3275670);
    BOOST_CHECK_EQUAL(_GetBlockValue(504499,0,0),   3275670);
    
    // Fixed reward
    BOOST_CHECK_EQUAL(_GetBlockValue(504500,0,0),   3000000);
    BOOST_CHECK_EQUAL(_GetBlockValue(1000000,0,0),  3000000);
    BOOST_CHECK_EQUAL(_GetBlockValue(10000000,0,0), 3000000);
    BOOST_CHECK_EQUAL(_GetBlockValue(13104498,0,0), 3000000);
    BOOST_CHECK_EQUAL(_GetBlockValue(13104499,0,0), 3000000);
    
    // No reward
    BOOST_CHECK_EQUAL(_GetBlockValue(13104500,0,0), 0);
    BOOST_CHECK_EQUAL(_GetBlockValue(20000000,0,0), 0);
    
}

BOOST_AUTO_TEST_SUITE_END()
