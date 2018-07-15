#ifdef DUMMY_ENABLE_TEMPLATE

#define NUM_THREADS 4

#ifdef FUN4
CAMLprim value FUN4(value vN, value vX, value vY)
{
    CAMLparam3(vN, vX, vY);
    int N = Long_val(vN);

    struct caml_ba_array *X = Caml_ba_array_val(vX);
    float *x = (float *) X->data;

    struct caml_ba_array *Y = Caml_ba_array_val(vY);
    float *y = (float *) Y->data;

    fprintf(stderr, "Compute on %d elements\n", N);

    caml_release_runtime_system();

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; ++i) {
        float foo = x[i];
        y[i] = MAPFN(foo);
    }

    caml_acquire_runtime_system();

    CAMLreturn(Val_unit);
}
#endif

#undef MAPFN
#undef NUMBER
#undef FUN4

#endif
