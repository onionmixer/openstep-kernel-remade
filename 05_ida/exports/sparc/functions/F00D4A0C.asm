F00D4A0C: 9de3bf80                 save    %sp, -0x80, %sp
F00D4A10: f837bfe8                 sth     %i4, [%fp+var_18]
F00D4A14: d407a06c                 ld      [%fp+arg_6C], %o2
F00D4A18: d607a070                 ld      [%fp+arg_70], %o3
F00D4A1C: 113c0504                 sethi   %hi(paLock), %o0
F00D4A20: d2022000                 ld      [%o0+%lo(paLock)], %o1! SEL
F00D4A24: 852aa008                 sll     %o2, 8, %g2
F00D4A28: 9132e018                 srl     %o3, 24, %o0
F00D4A2C: 9a108008                 or      %g2, %o0, %o5
F00D4A30: d007a068                 ld      [%fp+arg_68], %o0
F00D4A34: 9932a018                 srl     %o2, 24, %o4
F00D4A38: d407a05c                 ld      [%fp+arg_5C], %o2
F00D4A3C: fa37bfe6                 sth     %i5, [%fp+var_1A]
F00D4A40: d607a064                 ld      [%fp+arg_64], %o3
F00D4A44: 912a2018                 sll     %o0, 24, %o0
F00D4A48: 913a2018                 sra     %o0, 24, %o0
F00D4A4C: d037bfe2                 sth     %o0, [%fp+var_1E]
F00D4A50: d437bfe4                 sth     %o2, [%fp+var_1C]
F00D4A54: d007a060                 ld      [%fp+arg_60], %o0
F00D4A58: d637bfe0                 sth     %o3, [%fp+var_20]
F00D4A5C: d037bfea                 sth     %o0, [%fp+var_16]
F00D4A60: d0062110                 ld      [%i0+0x110], %o0! id
F00D4A64: 40007383                 call    _objc_msgSend
F00D4A68: b810000d                 mov     %o5, %i4
F00D4A6C: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D4A70: 80a22000                 cmp     %o0, 0
F00D4A74: 02800013                 be      loc_F00D4AC0
F00D4A78: 113c0505                 sethi   %hi(paPosteventAtAtt), %o0
F00D4A7C: 153fe03f                 sethi   -0x7F0400, %o2
F00D4A80: d2022314                 ld      [%o0+%lo(paPosteventAtAtt)], %o1! SEL
F00D4A84: 9412a380                 bset    0x380, %o2
F00D4A88: d8062168                 ld      [%i0+0x168], %o4
F00D4A8C: 9a07bfe0                 add     %fp, var_20, %o5
F00D4A90: d603200c                 ld      [%o4+0xC], %o3
F00D4A94: 90100018                 mov     %i0, %o0! id
F00D4A98: 960ac00a                 and     %o3, %o2, %o3
F00D4A9C: 15001fc09412a07f         set     0x7F007F, %o2
F00D4AA4: 940ec00a                 and     %i3, %o2, %o2
F00D4AA8: 9612c00a                 bset    %o2, %o3
F00D4AAC: d623200c                 st      %o3, [%o4+0xC]
F00D4AB0: 9410001a                 mov     %i2, %o2
F00D4AB4: 960621a8                 add     %i0, 0x1A8, %o3
F00D4AB8: 4000736e                 call    _objc_msgSend
F00D4ABC: 9810001c                 mov     %i4, %o4
F00D4AC0: d0062110                 ld      [%i0+0x110], %o0! id
F00D4AC4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4AC8: 4000736a                 call    _objc_msgSend
F00D4ACC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D4AD0: 81c7e008                 ret
F00D4AD4: 81e80000                 restore
