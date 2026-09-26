F000B69C: 9de3bf98                 save    %sp, -0x68, %sp
F000B6A0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000B6A4: d80221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o4
F000B6A8: d6032024                 ld      [%o4+0x24], %o3
F000B6AC: 901221dc                 bset    %lo(dword_F0133DDC), %o0
F000B6B0: d2023ffc                 ld      [%o0-4], %o1
F000B6B4: d402c000                 ld      [%o3], %o2
F000B6B8: d0026158                 ld      [%o1+0x158], %o0
F000B6BC: 80a28008                 cmp     %o2, %o0
F000B6C0: 1a80000d                 bcc     loc_F000B6F4
F000B6C4: 113c04cf                 sethi   -0xFECC400, %o0
F000B6C8: d202614c                 ld      [%o1+0x14C], %o1
F000B6CC: 912aa002                 sll     %o2, 2, %o0
F000B6D0: d4024008                 ld      [%o1+%o0], %o2
F000B6D4: 80a2a000                 cmp     %o2, 0
F000B6D8: 02800007                 be      loc_F000B6F4
F000B6DC: 113c04cf                 sethi   -0xFECC400, %o0
F000B6E0: 113fffc0                 sethi   -0x10000, %o0
F000B6E4: 80a28008                 cmp     %o2, %o0
F000B6E8: 32800006                 bne,a   loc_F000B700
F000B6EC: d052a00c                 ldsh    [%o2+0xC], %o0
F000B6F0: 113c04cf                 sethi   -0xFECC400, %o0
F000B6F4: d20221dc                 ld      [%o0+0x1DC], %o1
F000B6F8: 1080001d                 ba      loc_F000B76C
F000B6FC: 90102009                 mov     9, %o0
F000B700: 80a22001                 cmp     %o0, 1
F000B704: 02800004                 be      loc_F000B714
F000B708: 9010202d                 mov     0x2D, %o0 ! '-'
F000B70C: 10800019                 ba      locret_F000B770
F000B710: d02b2038                 stb     %o0, [%o4+0x38]
F000B714: d002e004                 ld      [%o3+4], %o0
F000B718: 808a2008                 btst    8, %o0
F000B71C: 02800006                 be      loc_F000B734
F000B720: 808a2002                 btst    2, %o0
F000B724: 9010000a                 mov     %o2, %o0
F000B728: 40006c66                 call    _vno_bsd_unlock
F000B72C: 92102180                 mov     0x180, %o1
F000B730: 30800010                 ba,a    locret_F000B770
F000B734: 32800008                 bne,a   loc_F000B754
F000B738: 900a3ffe                 and     %o0, -2, %o0
F000B73C: 808a2001                 btst    1, %o0
F000B740: 32800007                 bne,a   loc_F000B75C
F000B744: d202e004                 ld      [%o3+4], %o1
F000B748: 90102016                 mov     0x16, %o0
F000B74C: 10800009                 ba      locret_F000B770
F000B750: d02b2038                 stb     %o0, [%o4+0x38]
F000B754: d022e004                 st      %o0, [%o3+4]
F000B758: d202e004                 ld      [%o3+4], %o1
F000B75C: 40006bc9                 call    _vno_bsd_lock
F000B760: 9010000a                 mov     %o2, %o0
F000B764: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000B768: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F000B76C: d02a6038                 stb     %o0, [%o1+0x38]
F000B770: 81c7e008                 ret
F000B774: 81e80000                 restore
