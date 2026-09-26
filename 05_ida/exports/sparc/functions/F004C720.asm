F004C720: 9de3bf98                 save    %sp, -0x68, %sp
F004C724: a0100018                 mov     %i0, %l0
F004C728: 90100010                 mov     %l0, %o0
F004C72C: 92102000                 mov     0, %o1
F004C730: 94102000                 mov     0, %o2
F004C734: f0042050                 ld      [%l0+0x50], %i0
F004C738: 96102400                 mov     0x400, %o3
F004C73C: 7ffff8ee                 call    _bmap
F004C740: 98102000                 mov     0, %o4
F004C744: a2920000                 orcc    %o0, %g0, %l1
F004C748: 04800008                 ble     loc_F004C768
F004C74C: 113c04cf                 sethi   -0xFECC400, %o0
F004C750: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F004C754: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F004C758: d04a2038                 ldsb    [%o0+0x38], %o0
F004C75C: 80a22000                 cmp     %o0, 0
F004C760: 02800009                 be      loc_F004C784
F004C764: 113c04cf                 sethi   -0xFECC400, %o0
F004C768: d00221dc                 ld      [%o0+0x1DC], %o0
F004C76C: d04a2038                 ldsb    [%o0+0x38], %o0
F004C770: 80a22000                 cmp     %o0, 0
F004C774: 0280003a                 be      locret_F004C85C
F004C778: b010201c                 mov     0x1C, %i0
F004C77C: 10800038                 ba      locret_F004C85C
F004C780: b0100008                 mov     %o0, %i0
F004C784: d0062034                 ld      [%i0+0x34], %o0
F004C788: 80a223ff                 cmp     %o0, 0x3FF
F004C78C: 34800006                 bg,a    loc_F004C7A4
F004C790: 90102400                 mov     0x400, %o0
F004C794: 113c043a                 sethi   %hi(aDirblksizFsize_0), %o0! "DIRBLKSIZ > fsize"
F004C798: 7fff2276                 call    _panic
F004C79C: 901222f0                 bset    %lo(aDirblksizFsize_0), %o0! "DIRBLKSIZ > fsize"
F004C7A0: 90102400                 mov     0x400, %o0
F004C7A4: d0242070                 st      %o0, [%l0+0x70]
F004C7A8: d2142044                 lduh    [%l0+0x44], %o1
F004C7AC: 90100019                 mov     %i1, %o0
F004C7B0: 92126042                 bset    0x42, %o1 ! 'B'
F004C7B4: d2342044                 sth     %o1, [%l0+0x44]
F004C7B8: d6166066                 lduh    [%i1+0x66], %o3
F004C7BC: 92102001                 mov     1, %o1
F004C7C0: d4166044                 lduh    [%i1+0x44], %o2
F004C7C4: 9602e001                 inc     %o3
F004C7C8: d6366066                 sth     %o3, [%i1+0x66]
F004C7CC: 9412a040                 bset    0x40, %o2 ! '@'
F004C7D0: 4000075d                 call    _iupdat
F004C7D4: d4366044                 sth     %o2, [%i1+0x44]
F004C7D8: d0042040                 ld      [%l0+0x40], %o0
F004C7DC: d2062064                 ld      [%i0+0x64], %o1
F004C7E0: d4062034                 ld      [%i0+0x34], %o2
F004C7E4: 7fff5f4f                 call    _bread
F004C7E8: 932c4009                 sll     %l1, %o1, %o1
F004C7EC: d204a1dc                 ld      [%l2+0x1DC], %o1
F004C7F0: f04a6038                 ldsb    [%o1+0x38], %i0
F004C7F4: 80a62000                 cmp     %i0, 0
F004C7F8: 12800019                 bne     locret_F004C85C
F004C7FC: 96100008                 mov     %o0, %o3
F004C800: d402e020                 ld      [%o3+0x20], %o2
F004C804: 113c043a                 sethi   %hi(_mastertemplate), %o0
F004C808: d20221f0                 ld      [%o0+%lo(_mastertemplate)], %o1
F004C80C: d2228000                 st      %o1, [%o2]
F004C810: 901221f0                 bset    %lo(_mastertemplate), %o0
F004C814: d2022004                 ld      [%o0+4], %o1
F004C818: d222a004                 st      %o1, [%o2+4]
F004C81C: d2022008                 ld      [%o0+8], %o1
F004C820: d222a008                 st      %o1, [%o2+8]
F004C824: d202200c                 ld      [%o0+0xC], %o1
F004C828: d222a00c                 st      %o1, [%o2+0xC]
F004C82C: d2022010                 ld      [%o0+0x10], %o1
F004C830: d222a010                 st      %o1, [%o2+0x10]
F004C834: d0022014                 ld      [%o0+0x14], %o0
F004C838: d022a014                 st      %o0, [%o2+0x14]
F004C83C: d0042048                 ld      [%l0+0x48], %o0
F004C840: d0228000                 st      %o0, [%o2]
F004C844: d2066048                 ld      [%i1+0x48], %o1
F004C848: 9010000b                 mov     %o3, %o0
F004C84C: 7fff5fc7                 call    _bwrite
F004C850: d222a00c                 st      %o1, [%o2+0xC]
F004C854: d004a1dc                 ld      [%l2+0x1DC], %o0
F004C858: f04a2038                 ldsb    [%o0+0x38], %i0
F004C85C: 81c7e008                 ret
F004C860: 81e80000                 restore
