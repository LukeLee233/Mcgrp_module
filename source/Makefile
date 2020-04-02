
# This is the solution of SWIG, which has been deprecated
#
##@ means not output the command
#_mcgrp_utils.so : main.o interface_wrap.o
#	@g++ -shared interface_wrap.o main.o -o _mcgrp_utils.so
#	@echo build finish!
#
#main.o : main.cpp
#	@g++ -c -fpic main.cpp -I /home/luke/anaconda3/pkgs/python-3.7.4-h265db76_1/include/python3.7m
#
#interface_wrap.o : interface_wrap.cxx
#	@g++ -c -fpic interface_wrap.cxx -I /home/luke/anaconda3/pkgs/python-3.7.4-h265db76_1/include/python3.7m
#
#interface_wrap.cxx : interface.i
#	@swig -python -c++ interface.i
#
#
#.PHONY : clean
#clean :
#	@-rm _mcgrp_utils.so	mcgrp_utils.py	main.o	interface_wrap.o	interface_wrap.cxx
#	@echo clean finish!



# I choose to use pybind11 to my new solution cause it has bettert support on C++11
output := McgrpUtils`python3-config --extension-suffix`

object_files := wrapper.o source.o file.o MCGRP.o

CFLAGS += -D NODEBUG

$(output) : $(object_files)
	@echo start build...
# `python3 -m pybind11 --includes` means -I/home/luke/anaconda3/include/python3.7m -I/home/luke/anaconda3/include on my machine
# `python3-config --extension-suffix` means .cpython-37m-x86_64-linux-gnu.so on my machine
# `-L/usr/local/lib/ -lgsl -lgslcblas` will link gsl library to my extension
	@g++ -shared $(object_files) -o $(output) -L/usr/local/lib/ -lgsl -lgslcblas
	@echo build finish!



# Warinig: if you use -O3 optimization flag, some warning infomation will be caused
wrapper.o : wrapper.cpp source.h file.h RNG.h MCGRP.h
	@g++ $(CFLAGS) -O3 -Wall -c -std=c++11 -fPIC `python3 -m pybind11 --includes` wrapper.cpp

source.o : source.h source.cpp
	@g++ $(CFLAGS) -O3 -Wall -c -std=c++11 -fPIC source.cpp


file.o : file.h file.cpp
	@g++ $(CFLAGS) -O3 -Wall -c -std=c++11 -fPIC file.cpp


MCGRP.o : MCGRP.h MCGRP.cpp
	@g++ $(CFLAGS) -O3 -Wall -c -std=c++11 -fPIC MCGRP.cpp


.PHONY : clean
clean :
	@-rm -r *.o
	@-rm -r *.so
	@echo clean finish!


#install my library to correspending python interpreter module directory
.PHONY : install
install :
	@cp $(output)  /home/luke/anaconda3/envs/tensorflow/lib/python3.7/site-packages/
	@echo install finish!


#install my library to correspending python interpreter module directory
.PHONY : uninstall
uninstall :
	@-rm /home/luke/anaconda3/envs/tensorflow/lib/python3.7/site-packages/$(output)
	@echo uninstall finish!
