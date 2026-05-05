CC = clang
CFLAGS = -I/usr/include/libevdev-1.0 -Isrc
LDFLAGS = -lpthread -lm -levdev -ludev -lcjson

TARGET = keysound
CTL_TARGET = keysound-ctl

SRC = src/main.c src/input.c src/keymap.c src/audio.c
OBJ = $(SRC:.c=.o)

all: $(TARGET) $(CTL_TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(CTL_TARGET): keysound-ctl.c
	$(CC) keysound-ctl.c -o $(CTL_TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

PREFIX ?= /usr
BINDIR = $(PREFIX)/bin
SYSTEMDDIR = $(PREFIX)/lib/systemd/user

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -Dm755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)
	install -Dm755 $(CTL_TARGET) $(DESTDIR)$(BINDIR)/$(CTL_TARGET)
	install -d $(DESTDIR)$(SYSTEMDDIR)
	install -Dm644 keysound.service $(DESTDIR)$(SYSTEMDDIR)/keysound.service

clean:
	rm -f $(OBJ) $(TARGET) $(CTL_TARGET)