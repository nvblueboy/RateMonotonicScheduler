executable: *.cpp
	g++ *.cpp -o ./executable.out -std=c++11 -pthread

clean:
	rm *.out