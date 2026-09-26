F0024848: 9de3bf98                 save    %sp, -0x68, %sp
F002484C: 90100018                 mov     %i0, %o0
F0024850: d2020000                 ld      [%o0], %o1
F0024854: 92126100                 bset    0x100, %o1
F0024858: 7fffffc4                 call    _bwrite
F002485C: d2220000                 st      %o1, [%o0]
F0024860: 81c7e008                 ret
F0024864: 81e80000                 restore
