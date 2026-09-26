F0006BC0: 9de3bfa0                 save    %sp, -0x60, %sp
F0006BC4: 90100018                 mov     %i0, %o0
F0006BC8: 7ffffe4e                 call    _umul
F0006BCC: 92100019                 mov     %i1, %o1
F0006BD0: d0268000                 st      %o0, [%i2]
F0006BD4: d226a004                 st      %o1, [%i2+4]
F0006BD8: b0102001                 mov     1, %i0
F0006BDC: 81c7e008                 ret
F0006BE0: 81e80000                 restore
