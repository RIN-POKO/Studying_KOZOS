PREFIX  = /usr/local
ARCH    = h8300-elf
BINDIR  = $(PREFIX)/bin
ADDNAME = $(ARCH)-

AR      = $(BINDIR)/$(ADDNAME)ar
AS      = $(BINDIR)/$(ADDNAME)as
CC      = $(BINDIR)/$(ADDNAME)gcc
LD      = $(BINDIR)/$(ADDNAME)ld
NM      = $(BINDIR)/$(ADDNAME)nm
OBJCOPY = $(BINDIR)/$(ADDNAME)objcopy
OBJDUMP = $(BINDIR)/$(ADDNAME)objdump
RANLIB  = $(BINDIR)/$(ADDNAME)ranlib
STRIP   = $(BINDIR)/$(ADDNAME)strip

OBJS    = startup.o main.o interrupt.o
OBJS   += lib.o serial.o

# sources of kozos
OBJS	+= kozos.o syscall.o test08_1.o

TARGET  = kozos

CFLAGS  = -Wall -mh -nostdinc -nostdlib -fno-builtin
#CFLAGS += -mint32      # intを32ビットにすると掛算/割算ができなくなる
CFLAGS += -I.
#CFLAGS += -g
CFLAGS += -Os 
CFLAGS += -DKOZOS

LFLAGS = -static -T ld.scr -L.

.SUFFIXES:	.c .o
.SUFFIXEs:	.s .o
.SUFFIXEs:	.S .o

all:		$(TARGET)

$(TARGET):	$(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
		cp $(TARGET) $(TARGET).elf
		$(STRIP) $(TARGET)

.c.o:		$<
		$(CC) -c $(CFLAGS) $<

.s.o:		$<
		$(CC) -c $(CFLAGS) $<

.S.o:		$<
		$(CC) -c $(CFLAGS) $<
		
clean:
		rm -f $(OBJS) $(TARGET) $(TARGET).elf
