F00C3E88: 9de3bf90                 save    %sp, -0x70, %sp
F00C3E8C: 113c0504                 sethi   %hi(paItem_0), %o0! id
F00C3E90: d202211c                 ld      [%o0+%lo(paItem_0)], %o1! SEL
F00C3E94: 4000b677                 call    _objc_msgSend
F00C3E98: 90100018                 mov     %i0, %o0
F00C3E9C: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3EA0: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F00C3EA4: 4000b673                 call    _objc_msgSend
F00C3EA8: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F00C3EAC: f027bff0                 st      %i0, [%fp+var_10]
F00C3EB0: 133c0507                 sethi   %hi(stru_F0141E1C.ext), %o1
F00C3EB4: d4026248                 ld      [%o1+%lo(stru_F0141E1C.ext)], %o2
F00C3EB8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C3EBC: 133c0504                 sethi   %hi(paSuspend), %o1
F00C3EC0: d20260d4                 ld      [%o1+%lo(paSuspend)], %o1! SEL
F00C3EC4: 4000b6ae                 call    _objc_msgSendSuper
F00C3EC8: d427bff4                 st      %o2, [%fp+var_C]
F00C3ECC: d04e2035                 ldsb    [%i0+0x35], %o0
F00C3ED0: 80a22000                 cmp     %o0, 0
F00C3ED4: 32800002                 bne,a   loc_F00C3EDC
F00C3ED8: c02e2035                 clrb    [%i0+0x35]
F00C3EDC: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3EE0: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F00C3EE4: 4000b663                 call    _objc_msgSend
F00C3EE8: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F00C3EEC: 81c7e008                 ret
F00C3EF0: 81e80000                 restore
