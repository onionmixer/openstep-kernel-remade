F00AFAFC: 9de3bf98                 save    %sp, -0x68, %sp
F00AFB00: b12e2018                 sll     %i0, 24, %i0
F00AFB04: 7ffffe38                 call    _prom_mayput
F00AFB08: 913e2018                 sra     %i0, 24, %o0
F00AFB0C: 80a23fff                 cmp     %o0, -1
F00AFB10: 02bffffd                 be      loc_F00AFB04
F00AFB14: 01000000                 nop
F00AFB18: 81c7e008                 ret
F00AFB1C: 81e80000                 restore
