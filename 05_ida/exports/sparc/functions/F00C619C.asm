F00C619C: 9de3bf98                 save    %sp, -0x68, %sp
F00C61A0: a0100019                 mov     %i1, %l0
F00C61A4: d0042004                 ld      [%l0+4], %o0
F00C61A8: 80a22000                 cmp     %o0, 0
F00C61AC: 22800012                 be,a    locret_F00C61F4
F00C61B0: b0103d3e                 mov     -0x2C2, %i0
F00C61B4: b2066004                 inc     4, %i1
F00C61B8: d0064000                 ld      [%i1], %o0! __s1
F00C61BC: 7ffd07fc                 call    _strcmp
F00C61C0: 92100018                 mov     %i0, %o1
F00C61C4: 80a22000                 cmp     %o0, 0
F00C61C8: 12800006                 bne     loc_F00C61E0
F00C61CC: b2066008                 inc     8, %i1
F00C61D0: d0040000                 ld      [%l0], %o0
F00C61D4: b0102000                 mov     0, %i0
F00C61D8: 10800007                 ba      locret_F00C61F4
F00C61DC: d0268000                 st      %o0, [%i2]
F00C61E0: d0064000                 ld      [%i1], %o0
F00C61E4: 80a22000                 cmp     %o0, 0
F00C61E8: 12bffff5                 bne     loc_F00C61BC
F00C61EC: a0042008                 inc     8, %l0
F00C61F0: b0103d3e                 mov     -0x2C2, %i0
F00C61F4: 81c7e008                 ret
F00C61F8: 81e80000                 restore
