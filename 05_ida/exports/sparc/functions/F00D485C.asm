F00D485C: 9de3bf80                 save    %sp, -0x80, %sp
F00D4860: d0062110                 ld      [%i0+0x110], %o0! id
F00D4864: d81fa060                 ldd     [%fp+arg_60], %o4
F00D4868: 133c0504                 sethi   %hi(paLock), %o1
F00D486C: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D4870: 872b2008                 sll     %o4, 8, %g3
F00D4874: 85336018                 srl     %o5, 24, %g2
F00D4878: 9610c002                 or      %g3, %g2, %o3
F00D487C: 95332018                 srl     %o4, 24, %o2
F00D4880: 400073fc                 call    _objc_msgSend
F00D4884: a210000b                 mov     %o3, %l1
F00D4888: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D488C: 80a22000                 cmp     %o0, 0
F00D4890: 32800006                 bne,a   loc_F00D48A8
F00D4894: fa2e21c0                 stb     %i5, [%i0+0x1C0]
F00D4898: d0062110                 ld      [%i0+0x110], %o0
F00D489C: 133c0504                 sethi   %hi(paUnlock), %o1
F00D48A0: 10800057                 ba      loc_F00D49FC
F00D48A4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D48A8: d256c000                 ldsh    [%i3], %o1
F00D48AC: d05621a8                 ldsh    [%i0+0x1A8], %o0
F00D48B0: 80a24008                 cmp     %o1, %o0
F00D48B4: 12800007                 bne     loc_F00D48D0
F00D48B8: 94100009                 mov     %o1, %o2
F00D48BC: d256e002                 ldsh    [%i3+2], %o1
F00D48C0: d05621aa                 ldsh    [%i0+0x1AA], %o0
F00D48C4: 80a24008                 cmp     %o1, %o0
F00D48C8: 2280000f                 be,a    loc_F00D4904
F00D48CC: d24e21c1                 ldsb    [%i0+0x1C1], %o1
F00D48D0: d43621a8                 sth     %o2, [%i0+0x1A8]
F00D48D4: d016e002                 lduh    [%i3+2], %o0
F00D48D8: d24e2211                 ldsb    [%i0+0x211], %o1
F00D48DC: 80a26000                 cmp     %o1, 0
F00D48E0: 12800008                 bne     loc_F00D4900
F00D48E4: d03621aa                 sth     %o0, [%i0+0x1AA]
F00D48E8: 90100018                 mov     %i0, %o0! id
F00D48EC: 133c0505                 sethi   %hi(paSetcursorposit_0), %o1
F00D48F0: d20262c0                 ld      [%o1+%lo(paSetcursorposit_0)], %o1! SEL
F00D48F4: 940621a8                 add     %i0, 0x1A8, %o2
F00D48F8: 400073de                 call    _objc_msgSend
F00D48FC: 96100011                 mov     %l1, %o3
F00D4900: d24e21c1                 ldsb    [%i0+0x1C1], %o1
F00D4904: 912f2018                 sll     %i4, 24, %o0
F00D4908: 913a2018                 sra     %o0, 24, %o0
F00D490C: 80a24008                 cmp     %o1, %o0
F00D4910: 02800015                 be      loc_F00D4964
F00D4914: 80a22001                 cmp     %o0, 1
F00D4918: 12800014                 bne     loc_F00D4968
F00D491C: 912f2018                 sll     %i4, 24, %o0
F00D4920: a007bfe0                 add     %fp, var_20, %l0
F00D4924: d6062168                 ld      [%i0+0x168], %o3
F00D4928: 90100010                 mov     %l0, %o0! void *
F00D492C: d402e00c                 ld      [%o3+0xC], %o2
F00D4930: 9210200c                 mov     0xC, %o1! size_t
F00D4934: 9412a080                 bset    0x80, %o2
F00D4938: d422e00c                 st      %o2, [%o3+0xC]
F00D493C: 7fff0147                 call    _bzero
F00D4940: 01000000                 nop
F00D4944: 90100018                 mov     %i0, %o0! id
F00D4948: 9410200c                 mov     0xC, %o2
F00D494C: 960621a8                 add     %i0, 0x1A8, %o3
F00D4950: 98100011                 mov     %l1, %o4
F00D4954: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D4958: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D495C: 400073c5                 call    _objc_msgSend
F00D4960: 9a100010                 mov     %l0, %o5
F00D4964: 912f2018                 sll     %i4, 24, %o0
F00D4968: a13a2018                 sra     %o0, 24, %l0
F00D496C: 80a42001                 cmp     %l0, 1
F00D4970: 32800009                 bne,a   loc_F00D4994
F00D4974: d04e21c1                 ldsb    [%i0+0x1C1], %o0
F00D4978: 90100018                 mov     %i0, %o0! id
F00D497C: 133c0505                 sethi   %hi(paSetbuttonstate), %o1
F00D4980: d2026284                 ld      [%o1+%lo(paSetbuttonstate)], %o1! SEL
F00D4984: 9410001a                 mov     %i2, %o2
F00D4988: 400073ba                 call    _objc_msgSend
F00D498C: 96100011                 mov     %l1, %o3
F00D4990: d04e21c1                 ldsb    [%i0+0x1C1], %o0
F00D4994: 80a20010                 cmp     %o0, %l0
F00D4998: 02800015                 be      loc_F00D49EC
F00D499C: 80a42000                 cmp     %l0, 0
F00D49A0: 32800014                 bne,a   loc_F00D49F0
F00D49A4: d0062110                 ld      [%i0+0x110], %o0
F00D49A8: a007bfe0                 add     %fp, var_20, %l0
F00D49AC: d6062168                 ld      [%i0+0x168], %o3
F00D49B0: 90100010                 mov     %l0, %o0! void *
F00D49B4: d402e00c                 ld      [%o3+0xC], %o2
F00D49B8: 9210200c                 mov     0xC, %o1! size_t
F00D49BC: 940abf7f                 and     %o2, -0x81, %o2
F00D49C0: d422e00c                 st      %o2, [%o3+0xC]
F00D49C4: 7fff0125                 call    _bzero
F00D49C8: 01000000                 nop
F00D49CC: 90100018                 mov     %i0, %o0! id
F00D49D0: 9410200c                 mov     0xC, %o2
F00D49D4: 960621a8                 add     %i0, 0x1A8, %o3
F00D49D8: 98100011                 mov     %l1, %o4
F00D49DC: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D49E0: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D49E4: 400073a3                 call    _objc_msgSend
F00D49E8: 9a100010                 mov     %l0, %o5
F00D49EC: d0062110                 ld      [%i0+0x110], %o0! id
F00D49F0: 133c0504                 sethi   %hi(paUnlock), %o1
F00D49F4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D49F8: f82e21c1                 stb     %i4, [%i0+0x1C1]
F00D49FC: 4000739d                 call    _objc_msgSend
F00D4A00: 01000000                 nop
F00D4A04: 81c7e008                 ret
F00D4A08: 81e80000                 restore
