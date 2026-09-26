F003CBE4: 9de3bf98                 save    %sp, -0x68, %sp
F003CBE8: d006a030                 ld      [%i2+0x30], %o0! void *
F003CBEC: 92100018                 mov     %i0, %o1! void *
F003CBF0: 94102020                 mov     0x20, %o2 ! ' '! size_t
F003CBF4: 40015fc7                 call    _bcopy
F003CBF8: 90022040                 inc     0x40, %o0 ! '@'
F003CBFC: f2262020                 st      %i1, [%i0+0x20]
F003CC00: 81c7e008                 ret
F003CC04: 81e80000                 restore
