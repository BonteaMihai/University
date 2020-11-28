from Board import Board
from Game import Game
from UserInterface import UI

player_board = Board()
computer_board = Board()

game = Game(player_board, computer_board)
game.computer_place_planes()

ui = UI(game)
ui.choose_difficulty()
ui.place_planes()
ui.play()