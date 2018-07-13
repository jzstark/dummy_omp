open Bigarray

type comp = SIN | COS

external compute_sin : int -> ('a, 'b, c_layout) Genarray.t -> ('a, 'b, c_layout) Genarray.t -> unit = "c_stub_sin"

let create n =
  let vec = Genarray.create Float32 c_layout [|n|] in
  Genarray.fill vec 1.;
  vec

let numel x = Array.fold_right (fun c a -> c * a) (Genarray.dims x) 1

let compute t x =
  let y = x in (* mutable op *)
  let _ = match t with
  | SIN -> compute_sin (numel x) x y
  | COS -> compute_sin (numel x) x y
  in y
