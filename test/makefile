all:csv_read_test quick_sort_test clean
.PHONY:all clean
csv_read_test:csv_read_test.o ../release/version1/csv_read.o ../release/version1/*.h
	g++ $^ -o $@
csv_read_test.o:csv_read_test.cpp 
	g++ -c $< -o $@
../release/version1/csv_read.o:../release/version1/csv_read.cpp
	g++ -c $< -o $@

quick_sort_test:quick_sort_test.o ../release/version1/quick_sort.o ../release/version1/csv_read.o
	g++ $^ -o $@
clean:
	-rm csv_read_test quick_sort_test *.o