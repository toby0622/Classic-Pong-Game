import pygame
import sys

# General Setup
pygame.init()
clock = pygame.time.Clock()

# Main Window Setup
screen_width = 1280
screen_height = 960
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption('Classic Pong')

while True:
    # Input Handler
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Window Update
    pygame.display.flip()
    clock.tick(60)
