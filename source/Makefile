
_mcgrp_utils.so : main.o interface_wrap.o
	g++ -shared interface_wrap.o main.o -o _mcgrp_utils.so

main.o : main.cpp
	g++ -c -fpic main.cpp -I /home/luke/anaconda3/pkgs/python-3.7.4-h265db76_1/include/python3.7m

interface_wrap.o : interface_wrap.cxx
	g++ -c -fpic interface_wrap.cxx -I /home/luke/anaconda3/pkgs/python-3.7.4-h265db76_1/include/python3.7m

interface_wrap.cxx : interface.i
	swig -python -c++ interface.i


clean :
	rm _mcgrp_utils.so	mcgrp_utils.py	main.o	interface_wrap.o	interface_wrap.cxx