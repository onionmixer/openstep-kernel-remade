F0027994: 9de3bf50                 save    %sp, -0xB0, %sp
F0027998: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F002799C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00279A0: e2022024                 ld      [%o0+0x24], %l1
F00279A4: a407bfb8                 add     %fp, var_48, %l2
F00279A8: 400006bb                 call    _vattr_null
F00279AC: 90100012                 mov     %l2, %o0
F00279B0: 901421dc                 or      %l0, %lo(dword_F0133DDC), %o0
F00279B4: 92102002                 mov     2, %o1
F00279B8: 96102001                 mov     1, %o3
F00279BC: d4023ffc                 ld      [%o0-4], %o2
F00279C0: 98102000                 mov     0, %o4
F00279C4: d227bfb8                 st      %o1, [%fp+var_48]
F00279C8: d0046004                 ld      [%l1+4], %o0
F00279CC: 9a07bfb4                 add     %fp, var_4C, %o5
F00279D0: d212a16a                 lduh    [%o2+0x16A], %o1
F00279D4: 900a21ff                 and     %o0, 0x1FF, %o0
F00279D8: 922a0009                 andn    %o0, %o1, %o1
F00279DC: d237bfbc                 sth     %o1, [%fp+var_44]
F00279E0: 92102000                 mov     0, %o1
F00279E4: d0044000                 ld      [%l1], %o0
F00279E8: 40000503                 call    _vn_create
F00279EC: 94100012                 mov     %l2, %o2
F00279F0: d20421dc                 ld      [%l0+0x1DC], %o1
F00279F4: d02a6038                 stb     %o0, [%o1+0x38]
F00279F8: d00421dc                 ld      [%l0+0x1DC], %o0
F00279FC: d04a2038                 ldsb    [%o0+0x38], %o0
F0027A00: 80a22000                 cmp     %o0, 0
F0027A04: 12800004                 bne     locret_F0027A14
F0027A08: 01000000                 nop
F0027A0C: 40000456                 call    _vn_rele
F0027A10: d007bfb4                 ld      [%fp+var_4C], %o0
F0027A14: 81c7e008                 ret
F0027A18: 81e80000                 restore
