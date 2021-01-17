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