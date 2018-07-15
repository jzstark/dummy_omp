#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/callback.h>
#include <caml/bigarray.h>
#include <caml/signals.h>
#include <caml/threads.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define DUMMY_ENABLE_TEMPLATE

#define FUN4 float32_sin
#define NUMBER float
#define MAPFN(X) (sinf(X))
#include "compute_impl.h"

#define FUN4 float32_cos
#define NUMBER float
#define MAPFN(X) (cosf(X))
#include "compute_impl.h"

#define FUN4 float32_exp
#define NUMBER float
#define MAPFN(X) (expf(X))
#include "compute_impl.h"

#define FUN4 float32_log
#define NUMBER float
#define MAPFN(X) (logf(X))
#include "compute_impl.h"

#undef DUMMY_ENABLE_TEMPLATE
