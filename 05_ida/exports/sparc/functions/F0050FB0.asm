F0050FB0: 9de3bf98                 save    %sp, -0x68, %sp
F0050FB4: d2062128                 ld      [%i0+0x128], %o1
F0050FB8: d0526004                 ldsh    [%o1+4], %o0
F0050FBC: d202600c                 ld      [%o1+0xC], %o1
F0050FC0: d2026020                 ld      [%o1+0x20], %o1
F0050FC4: 7ffff345                 call    _iget
F0050FC8: 94102002                 mov     2, %o2
F0050FCC: b0920000                 orcc    %o0, %g0, %i0
F0050FD0: 32800006                 bne,a   loc_F0050FE8
F0050FD4: d2162044                 lduh    [%i0+0x44], %o1
F0050FD8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0050FDC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0050FE0: 10800011                 ba      locret_F0051024
F0050FE4: f04a2038                 ldsb    [%o0+0x38], %i0
F0050FE8: 1100003f901223fe         set     0xFFFE, %o0
F0050FF0: 920a4008                 and     %o1, %o0, %o1
F0050FF4: 808a6010                 btst    0x10, %o1
F0050FF8: 02800008                 be      loc_F0051018
F0050FFC: d2362044                 sth     %o1, [%i0+0x44]
F0051000: 1100003f901223ef         set     0xFFEF, %o0
F0051008: 900a4008                 and     %o1, %o0, %o0
F005100C: d0362044                 sth     %o0, [%i0+0x44]
F0051010: 7fff0776                 call    _wakeup
F0051014: 90100018                 mov     %i0, %o0
F0051018: 9006200c                 add     %i0, 0xC, %o0
F005101C: d0264000                 st      %o0, [%i1]
F0051020: b0102000                 mov     0, %i0
F0051024: 81c7e008                 ret
F0051028: 81e80000                 restore
