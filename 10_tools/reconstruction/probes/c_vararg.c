/* c_vararg.c -- probe (plan 412): a variadic callee through the SDK <stdarg.h>. */
#include <stdarg.h>

struct v_s { short a; char b; };

double kr_vsum(int n, ...)
{
    va_list ap;
    double t = 0;
    struct v_s s;

    va_start(ap, n);
    t += va_arg(ap, int);               /* promoted char */
    t += va_arg(ap, int);               /* promoted short */
    t += va_arg(ap, double);            /* promoted float */
    t += va_arg(ap, long long);
    t += (long)va_arg(ap, char *);
    s = va_arg(ap, struct v_s);
    t += s.a + s.b;
    t += va_arg(ap, int);
    va_end(ap);
    return t + n;
}
