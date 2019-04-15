CCipher:= $(wildcard Cipher/* .c) \
		$(wildcard *.c)

OBJ:= $(CCipher:.c=.o)

LDFLAGS:= -lssl -lcrypto

exe: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) 

.PHONY: clean
clean:	
	rm -f $(OBJ) exe
