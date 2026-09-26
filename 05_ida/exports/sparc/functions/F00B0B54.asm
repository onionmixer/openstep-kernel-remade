F00B0B54: 9de3bf98                 save    %sp, -0x68, %sp
F00B0B58: 90100018                 mov     %i0, %o0! __s1
F00B0B5C: 133c0471                 sethi   %hi(aObio), %o1! "obio"
F00B0B60: 7ffd5d93                 call    _strcmp
F00B0B64: 921260e0                 bset    %lo(aObio), %o1! "obio"
F00B0B68: 80a00008                 cmp     %g0, %o0
F00B0B6C: b0603fff                 subc    %g0, -1, %i0
F00B0B70: 81c7e008                 ret
F00B0B74: 81e80000                 restore
