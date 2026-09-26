F00C3EF4: 9de3bf90                 save    %sp, -0x70, %sp
F00C3EF8: 113c0504                 sethi   %hi(paItem_0), %o0! id
F00C3EFC: d202211c                 ld      [%o0+%lo(paItem_0)], %o1! SEL
F00C3F00: 4000b65c                 call    _objc_msgSend
F00C3F04: 90100018                 mov     %i0, %o0
F00C3F08: a0100008                 mov     %o0, %l0
F00C3F0C: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3F10: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F00C3F14: 4000b657                 call    _objc_msgSend
F00C3F18: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F00C3F1C: f027bff0                 st      %i0, [%fp+var_10]
F00C3F20: 133c0507                 sethi   %hi(stru_F0141E1C.ext), %o1
F00C3F24: d4026248                 ld      [%o1+%lo(stru_F0141E1C.ext)], %o2
F00C3F28: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C3F2C: 133c0504                 sethi   %hi(paResume), %o1
F00C3F30: d20260d8                 ld      [%o1+%lo(paResume)], %o1! SEL
F00C3F34: 4000b692                 call    _objc_msgSendSuper
F00C3F38: d427bff4                 st      %o2, [%fp+var_C]
F00C3F3C: 80a22000                 cmp     %o0, 0
F00C3F40: 22800011                 be,a    loc_F00C3F84
F00C3F44: d006202c                 ld      [%i0+0x2C], %o0
F00C3F48: d04e2035                 ldsb    [%i0+0x35], %o0
F00C3F4C: 80a22000                 cmp     %o0, 0
F00C3F50: 3280000d                 bne,a   loc_F00C3F84
F00C3F54: d006202c                 ld      [%i0+0x2C], %o0
F00C3F58: 90100010                 mov     %l0, %o0
F00C3F5C: 133c031092126310         set     _SPARCKernBusInterruptDispatch, %o1
F00C3F64: 94102000                 mov     0, %o2
F00C3F68: 96102000                 mov     0, %o3
F00C3F6C: 98100018                 mov     %i0, %o4
F00C3F70: 7fff543b                 call    _addintr
F00C3F74: 9a102000                 mov     0, %o5
F00C3F78: 90102001                 mov     1, %o0
F00C3F7C: d02e2035                 stb     %o0, [%i0+0x35]
F00C3F80: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3F84: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F00C3F88: 4000b63a                 call    _objc_msgSend
F00C3F8C: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F00C3F90: 81c7e008                 ret
F00C3F94: 81e80000                 restore
