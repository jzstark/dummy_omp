module N = Dummy_ndarray_generic

let _ = 
  let n = 100000000 in
  let x = N.create n in 
  N.(sin x |> cos |> sin |> log |> exp |> sin |> cos) 
