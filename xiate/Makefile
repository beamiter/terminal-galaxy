CFLAGS += -std=c99 -Wall -Wextra -O3
__NAME__ = xiate
__NAME_CAPITALIZED__ = Xiate

INSTALL = install
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644

prefix = /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
datarootdir = $(prefix)/share
mandir = $(datarootdir)/man
man1dir = $(mandir)/man1


.PHONY: all clean install installdirs

all: $(__NAME__)

$(__NAME__): terminal.c defaults.h
	$(CC) $(CFLAGS) $(LDFLAGS) \
		-D__NAME__=\"$(__NAME__)\" \
		-D__NAME_CAPITALIZED__=\"$(__NAME_CAPITALIZED__)\" \
		-o $@ $< \
		`pkg-config --cflags --libs glib-2.0 gtk+-3.0 vte-2.91`

install: $(__NAME__) installdirs
	$(INSTALL_PROGRAM) $(__NAME__) $(DESTDIR)$(bindir)/$(__NAME__)
	$(INSTALL_DATA) $(__NAME__).1 $(DESTDIR)$(man1dir)/$(__NAME__).1
	$(INSTALL_DATA) config.example.ini \
		$(DESTDIR)$(datarootdir)/$(__NAME__)/config.example.ini

installdirs:
	mkdir -p $(DESTDIR)$(bindir) $(DESTDIR)$(man1dir) \
		$(DESTDIR)$(datarootdir)/$(__NAME__)

clean:
	rm -f $(__NAME__)
