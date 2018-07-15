open Bigarray
open Dummy_compute

let create n =
  let vec = Genarray.create Float32 c_layout [|n|] in
  Genarray.fill vec 1.;
  vec

let numel x = Array.fold_right (fun c a -> c * a) (Genarray.dims x) 1

let kind x = Genarray.kind x

(* mutable ops *)

let sin x =
  let y = x in
  _dummy_sin (kind x) (numel y) x y;
  y

let cos x =
  let y = x in
  _dummy_cos (kind x) (numel y) x y;
  y

let log x =
  let y = x in
  _dummy_log (kind x) (numel y) x y;
  y

let exp x =
  let y = x in
  _dummy_exp (kind x) (numel y) x y;
  y
