#include <stdio.h>
#include <math.h>

#define H_STEPS 100
#define H0 0.1
#define T1 0.1
#define T2 1.0
#define T3 100.0

long double f1(long double t)
{
    return cos(t);
}

long double f2(long double t)
{
    return exp(t);
}

long double fwd_diff(long double (*f)(long double), double t, double h)
{
    long double df = f(t+h) - f(t);
    return df / h;
}

long double ctr_diff(long double (*f)(long double), double t, double h)
{
    long double df = f(t+h/2.0) - f(t-h/2.0);
    return df/h;
}

long double ext_diff(long double (*f)(long double), double t, double h)
{
    long double df = (8.0 * (f(t+h/4.0) - f(t-h/4.0)) - (f(t+h/2.0) - f(t-h/2.0)))/3.0;

    return df/h;
}

void do_diffs(const char *file_name, long double (*f)(long double), double t, long double exact_diff)
{
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        return;
    }

    double h = H0;
    for (int i = 0; i < H_STEPS; i++) {
        long double diff_fwd = fwd_diff(f, t, h);
        long double diff_ctr = ctr_diff(f, t, h);
        long double diff_ext = ext_diff(f, t, h);

        long double err_fwd = exact_diff - diff_fwd;
        long double err_ctr = exact_diff - diff_ctr;
        long double err_ext = exact_diff - diff_ext;

        fprintf(fp, "%03d %e %Le %Le %Le %Le %Le %Le\n", i, h,
                diff_fwd, diff_ctr, diff_ext,
                err_fwd, err_ctr, err_ext);

        h /= 2.0;
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    do_diffs("numdiff_cos_t1.dat", f1, T1, -sin(T1));
    do_diffs("numdiff_exp_t1.dat", f2, T1, expl(T1));
    do_diffs("numdiff_cos_t2.dat", f1, T2, -sin(T2));
    do_diffs("numdiff_exp_t2.dat", f2, T2, expl(T2));
    do_diffs("numdiff_cos_t3.dat", f1, T3, -sin(T3));
    do_diffs("numdiff_exp_t3.dat", f2, T3, expl(T3));

    return 0;
}
