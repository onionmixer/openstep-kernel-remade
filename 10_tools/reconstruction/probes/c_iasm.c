/* c_iasm.c -- probe (plan 412): m68k inline asm with the constraint letters
 * =a, a, =dm, =m, Jdm and the "cc" and "memory" clobbers. */
unsigned short kr_ia_sr;
int kr_ia_word;

void *kr_ia_fp(void)
{
    void *fp;

    asm("movl a6,%0" : "=a" (fp));
    return fp;
}

void *kr_ia_ret(void *frame)
{
    void *pc;

    asm("movl %1@(4),%0" : "=a" (pc) : "a" (frame));
    return pc;
}

unsigned short kr_ia_getsr(void)
{
    unsigned short sr;

    asm volatile ("movw sr,%0" : "=dm" (sr));
    return sr;
}

void kr_ia_setsr(unsigned short v)
{
    asm volatile ("movw %1,sr" : "=m" (*(char *)0) : "Jdm" (v));
}

void kr_ia_setsr_k(void)
{
    asm volatile ("movw %1,sr" : "=m" (*(char *)0) : "Jdm" (0x2700));
}

int kr_ia_clob(int x)
{
    asm volatile ("addql #1,%0" : "=d" (x) : "0" (x) : "cc", "memory");
    return x + kr_ia_word;
}
