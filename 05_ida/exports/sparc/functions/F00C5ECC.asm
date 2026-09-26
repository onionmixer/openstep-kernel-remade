F00C5ECC: 9de3bf90                 save    %sp, -0x70, %sp
F00C5ED0: 113c0503                 sethi   %hi(paAlloc), %o0! id
F00C5ED4: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F00C5ED8: 4000ae66                 call    _objc_msgSend
F00C5EDC: 90100018                 mov     %i0, %o0! __s
F00C5EE0: b0100008                 mov     %o0, %i0
F00C5EE4: 7ffd0555                 call    _strlen
F00C5EE8: 9010001a                 mov     %i2, %o0
F00C5EEC: a2022001                 add     %o0, 1, %l1
F00C5EF0: 11000004                 sethi   0x1000, %o0
F00C5EF4: 80a44008                 cmp     %l1, %o0
F00C5EF8: 34800002                 bg,a    loc_F00C5F00
F00C5EFC: a2100008                 mov     %o0, %l1
F00C5F00: 4000000c                 call    _IOMalloc
F00C5F04: 90100011                 mov     %l1, %o0
F00C5F08: a0100008                 mov     %o0, %l0
F00C5F0C: 9010001a                 mov     %i2, %o0! void *
F00C5F10: 92100010                 mov     %l0, %o1! void *
F00C5F14: 7fff3aff                 call    _bcopy
F00C5F18: 94047fff                 add     %l1, -1, %o2
F00C5F1C: 90044010                 add     %l1, %l0, %o0
F00C5F20: c02a3fff                 clrb    [%o0-1]
F00C5F24: e0262004                 st      %l0, [%i0+4]
F00C5F28: 81c7e008                 ret
F00C5F2C: 81e80000                 restore
