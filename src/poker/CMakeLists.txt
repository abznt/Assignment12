set(libname poker)

set(sources
        framework/Suit.h
        framework/Face.h
        framework/Card.cpp
        framework/Card.h
        framework/CardConversions.h
        framework/Deck.cpp
        framework/Deck.h
        framework/Hand.cpp
        framework/Hand.h
        framework/HandEvaluator.h
        framework/HandEvaluator.cpp
        framework/HandComparator.cpp
        framework/HandComparator.h
        game/IParticipant.h)

add_library(${libname} STATIC ${sources})
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

unset(${libname})