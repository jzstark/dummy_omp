# Example

Here is an example to use this dummy library:

```ocaml
#require "dummy";;
let f () = Dummy.compute 100000000;;
Owl_utils.time f;;
```

Note that `compute` function returns nothing.

Here is the command generated by `jbuilder` (version: 1.0+beta19.1):
```
Running[1]: (ocamldep.opt -modules -impl dummy.ml) > _build/default/dummy.ml.d
Running[2]: (ocamlc.opt -g -I lib/bytes -I lib/ctypes -I lib/integers -ccopt -fopenmp -o compute.o compute.c)
Running[3]: (ocamlc.opt -w -40 -safe-string -g -bin-annot -I .dummy.objs -I lib/bytes -I lib/ctypes -I lib/integers -no-alias-deps -o .dummy.objs/dummy.cmo -c -impl dummy.ml)
Running[4]: (ocamlopt.opt -w -40 -safe-string -g -I .dummy.objs -I lib/bytes -I lib/ctypes -I lib/integers -intf-suffix .ml -no-alias-deps -o .dummy.objs/dummy.cmx -c -impl dummy.ml)
Running[5]: (ocamlc.opt -w -40 -safe-string -g -a -o dummy.cma -dllib -ldummy_stubs -cclib -ldummy_stubs -cclib -lm -cclib -lgomp .dummy.objs/dummy.cmo)
Running[6]: (ocamlopt.opt -w -40 -safe-string -g -a -o dummy.cmxa -cclib -ldummy_stubs -cclib -lm -cclib -lgomp .dummy.objs/dummy.cmx)
Running[7]: (ocamlmklib.opt -g -o dummy_stubs compute.o -lm -lgomp)
Running[8]: (ocamlopt.opt -w -40 -safe-string -g -shared -linkall -I . -o dummy.cmxs dummy.cmxa)
```