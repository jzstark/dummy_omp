let _ =
  let n = 100000000 in
  let x = Dummy.create n in
  Dummy.(compute SIN x |> compute SIN |> compute SIN |> compute SIN |> compute SIN |> compute SIN |> compute SIN)
