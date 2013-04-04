CPP = g++
CPPFLAGS = -Wall --pedantic
TARGETS = store
OBJECTS = store-credit.o

default: $(DEPS) $(TARGETS)

$(TARGETS): $(OBJECTS)

store:
	$(CPP) -o a.out $^ $(CPPFLAGS)

test-sample: $(TARGETS)
	./a.out sample.in

clean:
	rm $(OBJECTS)
	rm $(TARGETS)
