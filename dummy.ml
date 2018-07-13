open Bigarray

external c_compute : int -> ('a, 'b, c_layout) Genarray.t -> ('a, 'b, c_layout) Genarray.t -> unit = "stub_compute"

let compute n =
  let vec = Genarray.create Float32 c_layout [|n|] in
  let out = Genarray.create Float32 c_layout [|n|] in (* should use copy *)
  Genarray.fill vec 1.;
  c_compute n vec out;
  out
