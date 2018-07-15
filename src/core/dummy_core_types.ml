open Bigarray

type ('a, 'b) dummy_arr = ('a, 'b, c_layout) Genarray.t

type ('a, 'b) dummy_arr_op09 = int -> ('a, 'b) dummy_arr -> ('a, 'b) dummy_arr -> unit
