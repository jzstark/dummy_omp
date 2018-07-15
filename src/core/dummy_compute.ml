open Bigarray
open Dummy_core_types

external dummy_float32_sin : int -> ('a, 'b) dummy_arr -> ('a, 'b) dummy_arr -> unit = "float32_sin"

let _dummy_sin : type a b. (a, b) kind -> (a, b) dummy_arr_op09 = fun k l x y ->
  match k with
  | Float32   -> dummy_float32_sin l x y
  | _         -> failwith "_dummy_sin: unsupported operation"

external dummy_float32_cos : int -> ('a, 'b) dummy_arr -> ('a, 'b) dummy_arr -> unit = "float32_cos"

let _dummy_cos : type a b. (a, b) kind -> (a, b) dummy_arr_op09 = fun k l x y ->
  match k with
  | Float32   -> dummy_float32_cos l x y
  | _         -> failwith "_dummy_cos: unsupported operation"

external dummy_float32_exp : int -> ('a, 'b) dummy_arr -> ('a, 'b) dummy_arr -> unit = "float32_exp"

let _dummy_exp : type a b. (a, b) kind -> (a, b) dummy_arr_op09 = fun k l x y ->
  match k with
  | Float32   -> dummy_float32_exp l x y
  | _         -> failwith "_dummy_exp: unsupported operation"

external dummy_float32_log : int -> ('a, 'b) dummy_arr -> ('a, 'b) dummy_arr -> unit = "float32_log"

let _dummy_log : type a b. (a, b) kind -> (a, b) dummy_arr_op09 = fun k l x y ->
  match k with
  | Float32   -> dummy_float32_log l x y
  | _         -> failwith "_dummy_log: unsupported operation"
