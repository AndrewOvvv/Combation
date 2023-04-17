cmake_minimum_required(VERSION 2.8) 

project(Combation)

set(SOURCE_SHELL_LIB shell.hpp)
set(SOURCE_ELEMENT_LIB element.hpp)
set(SOURCE_CARD_LIB card.hpp)
set(SOURCE_PLAYER_LIB player.hpp)
set(SOURCE_GAME_LIB game_instance.hpp)

add_library(shell STATIC ${SOURCE_SHELL_LIB})
add_library(element STATIC ${SOURCE_ELEMENT_LIB})
add_library(card STATIC ${SOURCE_CARD_LIB} shell element)
add_library(player STATIC ${SOURCE_PLAYER_LIB} shell element card)
