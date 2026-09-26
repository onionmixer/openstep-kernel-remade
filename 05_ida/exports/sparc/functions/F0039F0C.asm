F0039F0C: 9de3bf98                 save    %sp, -0x68, %sp
F0039F10: 113c04ea                 sethi   %hi(_exported), %o0
F0039F14: d20220c8                 ld      [%o0+%lo(_exported)], %o1
F0039F18: 80a26000                 cmp     %o1, 0
F0039F1C: 0280001f                 be      loc_F0039F98
F0039F20: a01220c8                 or      %o0, %lo(_exported), %l0
F0039F24: 92100018                 mov     %i0, %o1! void *
F0039F28: d0040000                 ld      [%l0], %o0! void *
F0039F2C: 94102008                 mov     8, %o2! size_t
F0039F30: 7fff300b                 call    _bcmp
F0039F34: 90022020                 inc     0x20, %o0 ! ' '
F0039F38: 80a22000                 cmp     %o0, 0
F0039F3C: 12800013                 bne     loc_F0039F88
F0039F40: d0040000                 ld      [%l0], %o0
F0039F44: d2022028                 ld      [%o0+0x28], %o1! void *
F0039F48: d4124000                 lduh    [%o1], %o2! size_t
F0039F4C: d0164000                 lduh    [%i1], %o0
F0039F50: 80a28008                 cmp     %o2, %o0
F0039F54: 3280000d                 bne,a   loc_F0039F88
F0039F58: d0040000                 ld      [%l0], %o0
F0039F5C: 90026002                 add     %o1, 2, %o0! void *
F0039F60: 7fff2fff                 call    _bcmp
F0039F64: 92066002                 add     %i1, 2, %o1
F0039F68: 80a22000                 cmp     %o0, 0
F0039F6C: 12800007                 bne     loc_F0039F88
F0039F70: d0040000                 ld      [%l0], %o0
F0039F74: d202202c                 ld      [%o0+0x2C], %o1
F0039F78: 40000136                 call    _exportfree
F0039F7C: d2240000                 st      %o1, [%l0]
F0039F80: 10800007                 ba      locret_F0039F9C
F0039F84: b0102000                 mov     0, %i0
F0039F88: d202202c                 ld      [%o0+0x2C], %o1
F0039F8C: 80a26000                 cmp     %o1, 0
F0039F90: 12bfffe5                 bne     loc_F0039F24
F0039F94: a002202c                 add     %o0, 0x2C, %l0 ! ','
F0039F98: b0102016                 mov     0x16, %i0
F0039F9C: 81c7e008                 ret
F0039FA0: 81e80000                 restore
