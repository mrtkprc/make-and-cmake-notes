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




#### References:
-   makefiletutorial.com