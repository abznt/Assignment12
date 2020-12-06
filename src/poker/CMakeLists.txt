set(libname poker)

set(sources
        Suit.h
        Face.h
        Card.cpp
        Card.h
        CardConversions.cpp
        CardConversions.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        HandEvaluator.h
        HandEvaluator.cpp
        HandComparator.cpp
        HandComparator.h)

add_library(${libname} STATIC ${sources})
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

unset(${libname})