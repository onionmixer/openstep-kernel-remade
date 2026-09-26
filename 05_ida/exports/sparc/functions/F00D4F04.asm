F00D4F04: 9de3bf88                 save    %sp, -0x78, %sp
F00D4F08: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D4F0C: 80a22001                 cmp     %o0, 1
F00D4F10: 12800019                 bne     locret_F00D4F74
F00D4F14: 01000000                 nop
F00D4F18: d0168000                 lduh    [%i2], %o0
F00D4F1C: d24e2211                 ldsb    [%i0+0x211], %o1
F00D4F20: d03621a8                 sth     %o0, [%i0+0x1A8]
F00D4F24: d016a002                 lduh    [%i2+2], %o0
F00D4F28: 80a26000                 cmp     %o1, 0
F00D4F2C: 12800012                 bne     locret_F00D4F74
F00D4F30: d03621aa                 sth     %o0, [%i0+0x1AA]
F00D4F34: 113c0505                 sethi   %hi(paSetcursorposit_0), %o0
F00D4F38: e00222c0                 ld      [%o0+%lo(paSetcursorposit_0)], %l0
F00D4F3C: 7fffc468                 call    _IOGetTimestamp
F00D4F40: 9007bfe8                 add     %fp, var_18, %o0
F00D4F44: d41fbfe8                 ldd     [%fp+var_18], %o2
F00D4F48: 9b2aa008                 sll     %o2, 8, %o5
F00D4F4C: 9932e018                 srl     %o3, 24, %o4
F00D4F50: 9213400c                 or      %o5, %o4, %o1
F00D4F54: 96924000                 orcc    %o1, %g0, %o3
F00D4F58: 12800003                 bne     loc_F00D4F64
F00D4F5C: 9132a018                 srl     %o2, 24, %o0
F00D4F60: 96102001                 mov     1, %o3
F00D4F64: 90100018                 mov     %i0, %o0! id
F00D4F68: 92100010                 mov     %l0, %o1! SEL
F00D4F6C: 40007241                 call    _objc_msgSend
F00D4F70: 9410001a                 mov     %i2, %o2
F00D4F74: 81c7e008                 ret
F00D4F78: 81e80000                 restore
