/* c_codegen.c -- probe: code shapes for the L1 comparison tool tests. */
extern int kr_ext(int);
int kr_global;
static int kr_table_data[4] = { 5, 6, 7, 8 };

static int kr_static(int x)
{
    return x * 3 + 1;
}

int kr_leaf(int a, int b)
{
    return (a ^ b) + (a << 2);
}

int kr_calls(int a)
{
    return kr_static(a) + kr_ext(a) + kr_global + kr_table_data[a & 3];
}

const char *kr_str(void)
{
    return "kr-string";
}

int kr_switch(int x)
{
    switch (x) {
    case 0: return 11;
    case 1: return 22;
    case 2: return 33;
    case 3: return 44;
    case 4: return 55;
    case 5: return 66;
    case 6: return 77;
    default: return -1;
    }
}

void kr_store(int v)
{
    kr_global = v;
}
