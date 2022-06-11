# Author: Teshan Liyanage <teshanuka@gmail.com>

import ctypes
from ctypes import c_int, c_float, POINTER

def load_simple_c(libfile: str):
    lib = ctypes.CDLL(libfile)
    
    # We can define argtypes and restype for better exceptions and handling complex data types
    lib.mult.argtypes = (c_int, c_int)
    # Optional in this case since int is supported as is
    lib.mult.restype = c_int

    lib.arr_sum.argtypes = (POINTER(c_float), c_int)
    # This is not optional. Otherwise the return value will be an int
    lib.arr_sum.restype = c_float

    return lib

def list2c_arr(l: list, typ):
    # Create a sequence of type `typ` of the size of the array
    seq = typ * len(l)
    # Init the sequence with values in array
    return seq(*l)

if __name__ == '__main__':
    lib = load_simple_c("build/libsimple_demo.so")

    lib.print_something()
    print(lib.mult(10, 20))

    arr = [1.0, 2.3, 3.4, 2.1, 1.2]
    print(lib.arr_sum(list2c_arr(arr, c_float), len(arr)))
