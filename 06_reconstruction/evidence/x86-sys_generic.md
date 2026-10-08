# x86 `src/bsd/kern/sys_generic.c` (plan 182 (S5-P155), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 182 (S5-P155). Final run `s5p155-it2`; 07 file SHA-256 `4f2e67c0b28f58dcb2493d057a41c5092b19304943a47e5be5c7f8d3ef8bcbc3`; diff `x86-sys_generic.diff`.

- Object [0x10cd54, 0x10d84f) 2811 B, 13 functions (_read, _readv, _write, _writev, _rwuio, _ioctl, _select, _selcont, _selscan, _seltrue, _selthreadcache, _selthreadclear, _selwakeup). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x10d850.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p155-it2-l1-sys_generic-F-20261002.json`). Grade **A**.

uthread layout from the SDK sys/user.h (uu_state.ss_select at +0x88); thread->active at +0x178 confirmed in the original thread_terminate (0x1672c8). Iterations: rwuio variant r1 (volatile on_master) 0 differences; it1 11 functions MATCH, select_zero in __bss and the wait-result test in selcont differing; variants: u.u_select direct access (no, reloads), unsigned range test t1 and two-value if t3 both 0 differences (t3 taken); it2 with `static const struct _select select_zero = { 0 }` OBJECT_MATCH 14/14 including __TEXT,__const (208 B at 0x1d10dc).
