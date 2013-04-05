CPP = g++
CPPFLAGS = -ggdb -Wall --pedantic
TARGETS = solution
OBJECTS = solution.o

default: $(DEPS) $(TARGETS)

$(TARGETS): $(OBJECTS)

solution:
	@$(CPP) -o a.out $^ $(CPPFLAGS)

sample: $(TARGETS)
	@./a.out sample.in

small: $(TARGETS)
	@./a.out small-practice.in

large: $(TARGETS)
	@./a.out large-practice.in

clean:
	rm $(OBJECTS)
	rm $(TARGETS)
