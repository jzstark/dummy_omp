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

CAMLprim value stub_compute(value vN)
{
    CAMLparam1(vN);
    int N = Long_val(vN);

    float *x = (float *) calloc(N, sizeof(float));
    float *y = (float *) calloc(N, sizeof(float));
    if (x == NULL || y == NULL) exit(1);
    memset(x, 1, sizeof(x));
    for (int i = 0; i < N; ++i)
        x[i] = i;

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; ++i) {
        //int id = omp_get_thread_num();
        //fprintf(stderr, "ID:%d\n", id);
        float foo = x[i];
        y[i] = sinf(cos(sin(cos(tan(log(sin(exp(sin(foo)))))))));
    }

    CAMLreturn(Val_unit);
}
