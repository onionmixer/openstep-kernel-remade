F00EA764: 9de3bf80                 save    %sp, -0x80, %sp
F00EA768: 133c0504                 sethi   %hi(paClass), %o1! SEL
F00EA76C: 90100018                 mov     %i0, %o0! id
F00EA770: 40001c40                 call    _objc_msgSend
F00EA774: d2026014                 ld      [%o1+%lo(paClass)], %o1
F00EA778: 133c0506                 sethi   %hi(paAllocfromzone), %o1
F00EA77C: d2026260                 ld      [%o1+%lo(paAllocfromzone)], %o1! SEL
F00EA780: 40001c3c                 call    _objc_msgSend
F00EA784: 9410001a                 mov     %i2, %o2
F00EA788: 133c0506                 sethi   %hi(paInitkeydescVal_0), %o1
F00EA78C: d2026258                 ld      [%o1+%lo(paInitkeydescVal_0)], %o1! SEL
F00EA790: d4062008                 ld      [%i0+8], %o2
F00EA794: d606200c                 ld      [%i0+0xC], %o3
F00EA798: 40001c36                 call    _objc_msgSend
F00EA79C: d8062004                 ld      [%i0+4], %o4
F00EA7A0: b4100008                 mov     %o0, %i2
F00EA7A4: 133c0504                 sethi   %hi(paInitstate), %o1
F00EA7A8: 9007bfe8                 add     %fp, var_18, %o0
F00EA7AC: d023a040                 st      %o0, [%sp+0x80+var_40]
F00EA7B0: 90100018                 mov     %i0, %o0! id
F00EA7B4: d2026104                 ld      [%o1+%lo(paInitstate)], %o1! SEL
F00EA7B8: 40001c2e                 call    _objc_msgSend
F00EA7BC: 01000000                 nop
F00EA7C0: 00000008                 illtrap
F00EA7C4: 233c0504                 sethi   -0xFEBF000, %l1
F00EA7C8: 213c0504                 sethi   -0xFEBF000, %l0
F00EA7CC: 90100018                 mov     %i0, %o0! id
F00EA7D0: d2046108                 ld      [%l1+0x108], %o1! SEL
F00EA7D4: 9407bfe8                 add     %fp, var_18, %o2
F00EA7D8: 9607bfe4                 add     %fp, var_1C, %o3
F00EA7DC: 40001c25                 call    _objc_msgSend
F00EA7E0: 9807bfe0                 add     %fp, var_20, %o4
F00EA7E4: 912a2018                 sll     %o0, 24, %o0
F00EA7E8: 80a22000                 cmp     %o0, 0
F00EA7EC: 02800008                 be      locret_F00EA80C
F00EA7F0: 9010001a                 mov     %i2, %o0! id
F00EA7F4: d2042068                 ld      [%l0+0x68], %o1! SEL
F00EA7F8: d407bfe4                 ld      [%fp+var_1C], %o2
F00EA7FC: 40001c1d                 call    _objc_msgSend
F00EA800: d607bfe0                 ld      [%fp+var_20], %o3
F00EA804: 10bffff3                 ba      loc_F00EA7D0
F00EA808: 90100018                 mov     %i0, %o0
F00EA80C: 81c7e008                 ret
F00EA810: 91e8001a                 restore %g0, %i2, %o0
