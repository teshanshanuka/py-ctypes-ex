# Author: Teshan Liyanage <teshanuka@gmail.com>

import ctypes
from ctypes import c_bool, c_int, c_float, POINTER, Structure

from traitlets import CFloat
import numpy as np

class CppObj(Structure):
    """Something to specify as object type"""

class CPolygonData(Structure):
    """Defined in sample_lib.hh
    struct PolygonData {
        int n_sides;
        int n_verts;
    };
    """
    _fields_ = [
        ("n_sides", c_int),
        ("n_verts", c_int),
    ]

def np_arr2c_ptr(arr: np.ndarray, type_c, type_np):
    # The numpy type and ctype should match (e.g. float-np.float32, double-np.float64 ...etc.)
    arr = arr.astype(type_np)
    c_p = POINTER(type_c)
    arr_p = arr.ctypes.data_as(c_p)
    return arr, arr_p

def load_polygon_lib(libfile: str):
    lib = ctypes.CDLL(libfile)
    
    lib.getPolygonObj.restype = POINTER(CppObj)
    lib.getData.restype = CPolygonData

    lib.setEdgeLengths.argtypes = (POINTER(CppObj), POINTER(c_float))
    lib.setEdgeLengths.restype = c_bool
    
    lib.sumEdgeLengths.argtypes = (POINTER(CppObj),)
    lib.sumEdgeLengths.restype = c_float

    lib.getEdgesBy2.argtypes = (POINTER(CppObj), POINTER(c_float))

    return lib

if __name__ == '__main__':
    lib = load_polygon_lib("build/libcpp_demo.so")

    poly_edge_lens = np.array([1, 4.5, 3.5, 4.5, 6.5])
    poly = lib.getPolygonObj(len(poly_edge_lens))

    # Need an C array pointer to pass the array to setEdgeLengths
    _, arr_ptr = np_arr2c_ptr(poly_edge_lens, c_float, np.float32)
    success = lib.setEdgeLengths(poly, arr_ptr)
    print("Set success=", success)

    print("Edge len sum:", lib.sumEdgeLengths(poly))

    # Get a new array and a array pointer to receive float array
    edges_x2, ex2_ptr = np_arr2c_ptr(poly_edge_lens, c_float, np.float32)
    lib.getEdgesBy2(poly, ex2_ptr)
    print("Edges x2:", edges_x2)

    lib.delPolygonObj(poly)
