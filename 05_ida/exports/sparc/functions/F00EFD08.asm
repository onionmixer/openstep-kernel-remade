F00EFD08: 9de3bf98                 save    %sp, -0x68, %sp
F00EFD0C: 80a66000                 cmp     %i1, 0
F00EFD10: 3280000a                 bne,a   loc_F00EFD38
F00EFD14: d0062020                 ld      [%i0+0x20], %o0
F00EFD18: 133c0506                 sethi   %hi(paError), %o1
F00EFD1C: 90100018                 mov     %i0, %o0! id
F00EFD20: d2026228                 ld      [%o1+%lo(paError)], %o1! SEL
F00EFD24: 153c03e89412a2d8         set     aInvalidSelecto, %o2! "invalid selector %s"
F00EFD2C: 400006d1                 call    _objc_msgSend
F00EFD30: 96102000                 mov     0, %o3
F00EFD34: d0062020                 ld      [%i0+0x20], %o0
F00EFD38: d6020000                 ld      [%o0], %o3
F00EFD3C: 98022008                 add     %o0, 8, %o4
F00EFD40: 940e400b                 and     %i1, %o3, %o2
F00EFD44: 912aa002                 sll     %o2, 2, %o0
F00EFD48: d2030008                 ld      [%o4+%o0], %o1
F00EFD4C: 80a26000                 cmp     %o1, 0
F00EFD50: 0280000a                 be      loc_F00EFD78
F00EFD54: 90100018                 mov     %i0, %o0
F00EFD58: d0024000                 ld      [%o1], %o0
F00EFD5C: 80a20019                 cmp     %o0, %i1
F00EFD60: 12800004                 bne     loc_F00EFD70
F00EFD64: 9402a001                 inc     %o2
F00EFD68: 10800007                 ba      locret_F00EFD84
F00EFD6C: f0026008                 ld      [%o1+8], %i0
F00EFD70: 10bffff5                 ba      loc_F00EFD44
F00EFD74: 940a800b                 and     %o2, %o3, %o2
F00EFD78: 40000133                 call    __class_lookupMethodAndLoadCache
F00EFD7C: 92100019                 mov     %i1, %o1
F00EFD80: b0100008                 mov     %o0, %i0
F00EFD84: 81c7e008                 ret
F00EFD88: 81e80000                 restore
