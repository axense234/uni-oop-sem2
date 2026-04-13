run:
	g++ -o main -Wall -Werror -Wextra src/domain/*.cpp src/helpers/*.cpp src/repo/*.cpp src/services/*.cpp src/ui/*.cpp src/main.cpp && \
	./main textfile src/repo/data

testAndGenCoverage:
	g++ -fprofile-arcs -ftest-coverage -g -o test_bin src/domain/*.cpp src/helpers/*.cpp src/repo/*.cpp src/services/*.cpp src/ui/*.cpp tests/tests.cpp tests/domain/*.cpp tests/helpers/*.cpp tests/repo/*.cpp tests/services/*.cpp && \
	./test_bin && \
	lcov --capture --directory . --output-file coverage.info && \
	lcov --remove coverage.info \
		'src/ui/*' \
		'tests/*' \
		'/usr/include/c++/13/*' \
		'/usr/include/x86_64-linux-gnu/c++/13/*' \
		--output-file coverage_filtered.info && \
	genhtml coverage_filtered.info --output-directory coverage_report


test:
	g++ -Werror -g -o test_bin src/domain/*.cpp src/helpers/*.cpp src/repo/*.cpp src/services/*.cpp src/ui/*.cpp tests/tests.cpp  tests/domain/*.cpp tests/repo/*.cpp tests/helpers/*.cpp tests/services/*.cpp && \
	./test_bin
