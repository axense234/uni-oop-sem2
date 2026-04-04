run:
	g++ -o main src/domain/*.cpp src/helpers/*.cpp src/repo/*.cpp src/services/*.cpp src/ui/*.cpp src/main.cpp && \
	./main

testAndGenCoverage:
	g++ -fprofile-arcs -ftest-coverage -g -o test_bin src/domain/*.cpp src/helpers/*.cpp src/repo/*.cpp src/services/*.cpp src/ui/*.cpp tests/tests.cpp  tests/domain/*.cpp tests/repo/*.cpp tests/services/*.cpp && \
	./test_bin && \
	lcov --capture --directory . --output-file coverage.info && \
	genhtml coverage.info --output-directory coverage_report


test:
	g++ -Werror -g -o test_bin src/domain/*.cpp src/helpers/*.cpp src/repo/*.cpp src/services/*.cpp src/ui/*.cpp tests/tests.cpp  tests/domain/*.cpp tests/repo/*.cpp tests/services/*.cpp && \
	./test_bin
