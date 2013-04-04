CPP = g++
CPPFLAGS = -Wall --pedantic
TARGETS = store
OBJECTS = store-credit.o

default: $(DEPS) $(TARGETS)

$(TARGETS): $(OBJECTS)

store:
	$(CPP) -o $@ $^ $(CPPFLAGS)

test-sample: $(TARGETS)
	./store sample.in

clean:
	rm $(OBJECTS)
	rm $(TARGETS)
