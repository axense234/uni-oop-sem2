run:
	g++ -o main -Wall -Werror -Wextra src/domain/*.cpp src/repo/*.cpp src/services/*.cpp src/ui/*.cpp src/main.cpp && \
	./main
