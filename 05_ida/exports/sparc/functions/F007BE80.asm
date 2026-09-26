F007BE80: 9de3bf70                 save    %sp, -0x90, %sp
F007BE84: f227bff4                 st      %i1, [%fp+var_C]
F007BE88: c02fbfd3                 clrb    [%fp+var_2D]
F007BE8C: 90102028                 mov     0x28, %o0 ! '('
F007BE90: d027bfd4                 st      %o0, [%fp+var_2C]
F007BE94: c027bfd8                 clr     [%fp+var_28]
F007BE98: f027bfe0                 st      %i0, [%fp+var_20]
F007BE9C: c027bfdc                 clr     [%fp+var_24]
F007BEA0: 901020ca                 mov     0xCA, %o0
F007BEA4: d027bfe4                 st      %o0, [%fp+var_1C]
F007BEA8: 9007bfd0                 add     %fp, var_30, %o0
F007BEAC: 133c03d3                 sethi   %hi(dword_F00F4E40), %o1
F007BEB0: d4026240                 ld      [%o1+%lo(dword_F00F4E40)], %o2
F007BEB4: b52ea003                 sll     %i2, 3, %i2
F007BEB8: 92126240                 bset    %lo(dword_F00F4E40), %o1
F007BEBC: d427bfe8                 st      %o2, [%fp+var_18]
F007BEC0: d6026004                 ld      [%o1+4], %o3
F007BEC4: 94102000                 mov     0, %o2
F007BEC8: d2026008                 ld      [%o1+8], %o1
F007BECC: d627bfec                 st      %o3, [%fp+var_14]
F007BED0: d227bff0                 st      %o1, [%fp+var_10]
F007BED4: f427bff0                 st      %i2, [%fp+var_10]
F007BED8: 7fffa77f                 call    _msg_send
F007BEDC: 92102000                 mov     0, %o1
F007BEE0: 81c7e008                 ret
F007BEE4: 91e80008                 restore %g0, %o0, %o0
