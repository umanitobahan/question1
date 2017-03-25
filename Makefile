CC = clang
CFLAGS = -g -Wall

PROG = table

OBJDIR = objects
OBJS = $(OBJDIR)/table.o $(OBJDIR)/main.o

$(PROG): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

$(OBJDIR)/%.o: %.c $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(PROG)
