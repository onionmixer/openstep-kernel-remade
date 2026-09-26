F009BDE0: 9de3bf98                 save    %sp, -0x68, %sp
F009BDE4: e0062028                 ld      [%i0+0x28], %l0
F009BDE8: 7ffff35f                 call    _fpu_ctxfree
F009BDEC: 90100010                 mov     %l0, %o0
F009BDF0: c0262028                 clr     [%i0+0x28]
F009BDF4: 113c04f7                 sethi   %hi(_pcb_zone), %o0
F009BDF8: d0022200                 ld      [%o0+%lo(_pcb_zone)], %o0
F009BDFC: 7fff74f5                 call    _zfree
F009BE00: 92100010                 mov     %l0, %o1
F009BE04: 81c7e008                 ret
F009BE08: 81e80000                 restore
