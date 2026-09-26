F0089FF4: 9de3bf90                 save    %sp, -0x70, %sp! int
F0089FF8: 90100018                 mov     %i0, %o0! int
F0089FFC: 9207bff4                 add     %fp, var_C, %o1! int
F008A000: 40003816                 call    _copyin
F008A004: 94102004                 mov     4, %o2
F008A008: 80a22000                 cmp     %o0, 0
F008A00C: 12800003                 bne     locret_F008A018
F008A010: b0103fff                 mov     -1, %i0
F008A014: f007bff4                 ld      [%fp+var_C], %i0
F008A018: 81c7e008                 ret
F008A01C: 81e80000                 restore
