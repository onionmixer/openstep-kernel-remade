F0006BE4: 9de3bfa0                 save    %sp, -0x60, %sp
F0006BE8: 90100018                 mov     %i0, %o0
F0006BEC: 7ffffdfe                 call    _mul
F0006BF0: 92100019                 mov     %i1, %o1
F0006BF4: d0268000                 st      %o0, [%i2]
F0006BF8: d226a004                 st      %o1, [%i2+4]
F0006BFC: b0102001                 mov     1, %i0
F0006C00: 81c7e008                 ret
F0006C04: 81e80000                 restore
