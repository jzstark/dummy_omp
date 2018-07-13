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
#define NUM_THREADS 4

CAMLprim value stub_compute(value vN, value vX, value vY)
{
    CAMLparam3(vN, vX, vY);

    struct caml_ba_array *X = Caml_ba_array_val(vX);
    float *x = (float *) X->data;
    struct caml_ba_array *Y = Caml_ba_array_val(vY);
    float *y = (float *) Y->data;
    int N = Long_val(vN);

    fprintf(stderr, "Compute on %d elements\n", N);

    caml_release_runtime_system();

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; ++i) {
        //int id = omp_get_thread_num();
        //fprintf(stderr, "ID:%d\n", id);
        float foo = x[i];
        y[i] = sinf(cos(sin(cos(tan(log(sin(exp(sin(foo)))))))));
    }

    caml_acquire_runtime_system();

    CAMLreturn(Val_unit);
}
