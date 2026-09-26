F008A048: 9de3bf90                 save    %sp, -0x70, %sp! int
F008A04C: 90100018                 mov     %i0, %o0! int
F008A050: 9207bff4                 add     %fp, var_C, %o1! int
F008A054: 40003801                 call    _copyin
F008A058: 94102004                 mov     4, %o2
F008A05C: 80a22000                 cmp     %o0, 0
F008A060: 12800003                 bne     locret_F008A06C
F008A064: b0103fff                 mov     -1, %i0
F008A068: f007bff4                 ld      [%fp+var_C], %i0
F008A06C: 81c7e008                 ret
F008A070: 81e80000                 restore
