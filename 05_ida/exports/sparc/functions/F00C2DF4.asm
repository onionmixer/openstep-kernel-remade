F00C2DF4: 9de3bf98                 save    %sp, -0x68, %sp
F00C2DF8: 7fffff73                 call    sub_F00C2BC4
F00C2DFC: 90100018                 mov     %i0, %o0
F00C2E00: 92920000                 orcc    %o0, %g0, %o1
F00C2E04: 02800009                 be      locret_F00C2E28
F00C2E08: 113c04cf                 sethi   %hi(_active_u), %o0
F00C2E0C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00C2E10: d0020000                 ld      [%o0], %o0
F00C2E14: 80a22000                 cmp     %o0, 0
F00C2E18: 02800004                 be      locret_F00C2E28
F00C2E1C: 90100009                 mov     %o1, %o0
F00C2E20: 7fffff85                 call    sub_F00C2C34
F00C2E24: 92100018                 mov     %i0, %o1
F00C2E28: 81c7e008                 ret
F00C2E2C: 81e80000                 restore
