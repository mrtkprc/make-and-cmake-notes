# My makefile notes

### Targets and prerequistes:

```make
targets: prerequisites
    commands-1
    commands-2
```

-   The commands are series of the steps typically used to make targets. These need to start with a tab character, not **spaces**
    -   Above example, commands-1 and commands2 start with **a tab character (\t)** 

-   The prerequisites are also file names and they are seperated by spaces. 
-   Prerequisites need to exist before commands for target are run. **These are called dependencies.**

-   Default target is **first target.**

### Variables
Example: [01_variables](examples/01_variables/Makefile)

```make
files = file1 file2
main_file: $(files)
	@echo "Look at this variable: " $(files)
	touch main_file
file1: 
	touch file1
file2:
	touch file2
clean:
	rm -rf main_file $(files)
```
### **You can use variable as $(x) or ${x} but $x is not preferred.**

### Manual way without Static Pattern Rules

A typically use case is to compile .c files into .o files. 

Here's manual way: [02_manual_compiling](examples/02_manual_compiling/Makefile)

```make
objects = foo.o bar.o all.o
all: $(objects)
foo.o: foo.c
bar.o: bar.c
all.o: all.c

all.c:
	@echo "int main(){return 0;}" > all.c
%.c:
	touch $@
clean:
	rm -rf *.c *.o all

```
### Static Pattern Rules

```make
objects = foo.o bar.o all.o
all: $(objects)
$(objects): %.o: %.c
all.c:
	@echo "int main(){return 0;}" > all.c
%.c:
	touch $@
clean:
	rm -rf *.c *.o all
```

#### **$(objects): %.o: %.c** means:
``All *o* files depend on *c* files within object file list.``

### Static pattern rules with filter

```make
$(filter %.o, $(objects)): %.o: %.c
    @echo "target: $@ prerequisites $<"
```

### Implicit rules

**Compiling a C++ program implicitly**

-   x.o is made automatically from n.cc/n.cpp with a command of the form:
    -   `` $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) ``

**Linking a single object file:**
-   n is made automatically from n.o by running the command:
    -   ``$(CXX) $(LDFLAGS) n.o $(LOADLIBS) $(LDLIBS)``

### Important variables
-   CC: Program for compiling c programs: default cc
-   CXX: Program for C++: default g++

### If you define CXX, then Makefile carries on some rules implicitly.

Example: [04_implicit_rules](examples/04_implicit_rules/Makefile)

```make
CXX = g++
foo:
clean:
	rm -rf foo foo.o
```
### Pattern rules

```make
%.o: %.c:
    $(CC) -c $(CFLAGS) $< -o $@
```

### Diffrence among assignments

-   **``:=``** (simply expanded variable.) Assignment will be performed immediately.

-   **=** (recursively expanded variable.)
Assignment will be performed on demand.

-   **+=** for appending. Simply concanetation will be performed.



### Command and Execution

-   You can also run make with **-s** to build silently.
-   Add an **@** before a command to stop it from being printed. 
    -   For example; ``@echo "mert"`` only shows execution output not trace output
-   Each command is run in a new shell.

Different shell execution:
```make
all:
    cd .. # This doesn't affect following command
    echo `pwd`
```

Same shell execution:
```make
all:
    cd ..;echo `pwd` # This cd affects the next command. 
```
or
```make
all:
    cd .. \ 
    echo `pwd` # This cd affects the next command. 
```



#### References:
-   makefiletutorial.com