# Makefile for building the main application
#
# Usage:
#   make        - Build the main application executable
#   make clean  - Remove build artifacts
#
CC = gcc
CFLAGS = -Iinc -Iinc/app -Iinc/hal -Iinc/services -Itests -Wall -Wextra -std=c99
SRC = main.c src/app/appmain.c src/hal/led_hal.c src/services/delay_service.c tests/mock_avr_io.c
OUT = main_app.exe

CFLAGS += -DUNIT_TEST -I. # Use mocks for PC build

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OUT)
