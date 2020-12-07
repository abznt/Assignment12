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
        game/AParticipant.h
        game/PokerGame.cpp
        game/PokerGame.h
        game/states/IState.h
        game/states/GameStart.cpp
        game/states/GameStart.h
        game/states/BettingRound.cpp
        game/states/BettingRound.h
        game/states/DealingRound.cpp
        game/states/DealingRound.h
        game/states/DrawRound.cpp
        game/states/DrawRound.h
        game/states/EvaluateRound.cpp
        game/states/EvaluateRound.h
        game/states/GameOver.cpp
        game/states/GameOver.h game/Player.cpp game/Player.h game/Cpu.cpp game/Cpu.h game/BettingOptions.cpp game/BettingOptions.h game/BettingResult.h)

add_library(${libname} STATIC ${sources})
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

unset(${libname})