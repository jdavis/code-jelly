CPP = g++
CPPFLAGS = -Wall --pedantic
TARGETS = store
OBJECTS = store-credit.o

default: $(DEPS) $(TARGETS)

$(TARGETS): $(OBJECTS)

store:
	@$(CPP) -o a.out $^ $(CPPFLAGS)

sample: $(TARGETS)
	@./a.out sample.in

small: $(TARGETS)
	@./a.out A-small-practice.in

large: $(TARGETS)
	@./a.out A-large-practice.in

clean:
	rm $(OBJECTS)
	rm $(TARGETS)
