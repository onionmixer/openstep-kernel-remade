F000915C: 9de3bf98                 save    %sp, -0x68, %sp
F0009160: 7ffff8b6                 call    _strlen
F0009164: 90100018                 mov     %i0, %o0! void *
F0009168: 94102011                 mov     0x11, %o2
F000916C: 133c04cf                 sethi   %hi(_active_u), %o1
F0009170: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F0009174: 80a22010                 cmp     %o0, 0x10
F0009178: 18800003                 bgu     loc_F0009184
F000917C: 92026008                 inc     8, %o1! void *
F0009180: 94022001                 add     %o0, 1, %o2! size_t
F0009184: 40022e63                 call    _bcopy
F0009188: 90100018                 mov     %i0, %o0
F000918C: 81c7e008                 ret
F0009190: 81e80000                 restore
