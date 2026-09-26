F00A4E60: 9de3bf98                 save    %sp, -0x68, %sp
F00A4E64: a0100018                 mov     %i0, %l0
F00A4E68: 80a66000                 cmp     %i1, 0
F00A4E6C: 14800005                 bg      loc_F00A4E80
F00A4E70: b0042008                 add     %l0, 8, %i0
F00A4E74: 113c0466                 sethi   %hi(aRmalloc), %o0! "rmalloc"
F00A4E78: 7ffdc0be                 call    _panic
F00A4E7C: 90122088                 bset    %lo(aRmalloc), %o0! "rmalloc"
F00A4E80: d0042008                 ld      [%l0+8], %o0
F00A4E84: 80a22000                 cmp     %o0, 0
F00A4E88: 02800020                 be      loc_F00A4F08
F00A4E8C: 94100018                 mov     %i0, %o2
F00A4E90: d0028000                 ld      [%o2], %o0
F00A4E94: 80a20019                 cmp     %o0, %i1
F00A4E98: 26800018                 bl,a    loc_F00A4EF8
F00A4E9C: 9402a008                 inc     8, %o2
F00A4EA0: f002a004                 ld      [%o2+4], %i0
F00A4EA4: d0028000                 ld      [%o2], %o0
F00A4EA8: 92060019                 add     %i0, %i1, %o1
F00A4EAC: d222a004                 st      %o1, [%o2+4]
F00A4EB0: 90220019                 sub     %o0, %i1, %o0
F00A4EB4: 80a22000                 cmp     %o0, 0
F00A4EB8: 12800015                 bne     locret_F00A4F0C
F00A4EBC: d0228000                 st      %o0, [%o2]
F00A4EC0: 9202a004                 add     %o2, 4, %o1
F00A4EC4: d0026004                 ld      [%o1+4], %o0
F00A4EC8: d0228000                 st      %o0, [%o2]
F00A4ECC: d0026008                 ld      [%o1+8], %o0
F00A4ED0: 9402a008                 inc     8, %o2
F00A4ED4: d0224000                 st      %o0, [%o1]
F00A4ED8: d0028000                 ld      [%o2], %o0
F00A4EDC: 80a22000                 cmp     %o0, 0
F00A4EE0: 12bffff9                 bne     loc_F00A4EC4
F00A4EE4: 92026008                 inc     8, %o1
F00A4EE8: d0040000                 ld      [%l0], %o0
F00A4EEC: 90022001                 inc     %o0
F00A4EF0: 10800007                 ba      locret_F00A4F0C
F00A4EF4: d0240000                 st      %o0, [%l0]
F00A4EF8: d0028000                 ld      [%o2], %o0
F00A4EFC: 80a22000                 cmp     %o0, 0
F00A4F00: 12bfffe6                 bne     loc_F00A4E98
F00A4F04: 80a20019                 cmp     %o0, %i1
F00A4F08: b0102000                 mov     0, %i0
F00A4F0C: 81c7e008                 ret
F00A4F10: 81e80000                 restore
