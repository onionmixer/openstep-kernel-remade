F00280FC: 9de3bf90                 save    %sp, -0x70, %sp
F0028100: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0028104: 92102000                 mov     0, %o1
F0028108: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F002810C: 94102001                 mov     1, %o2
F0028110: e2022024                 ld      [%o0+0x24], %l1
F0028114: 96102000                 mov     0, %o3
F0028118: d0044000                 ld      [%l1], %o0
F002811C: 7ffffa2a                 call    _lookupname
F0028120: 9807bff4                 add     %fp, var_C, %o4
F0028124: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0028128: d02a6038                 stb     %o0, [%o1+0x38]
F002812C: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0028130: d04a2038                 ldsb    [%o0+0x38], %o0
F0028134: 80a22000                 cmp     %o0, 0
F0028138: 12800035                 bne     locret_F002820C
F002813C: a014a1dc                 or      %l2, %lo(dword_F0133DDC), %l0
F0028140: d0043ffc                 ld      [%l0-4], %o0
F0028144: d202201c                 ld      [%o0+0x1C], %o1
F0028148: d0126006                 lduh    [%o1+6], %o0
F002814C: e8526002                 ldsh    [%o1+2], %l4
F0028150: e6526004                 ldsh    [%o1+4], %l3
F0028154: d0326002                 sth     %o0, [%o1+2]
F0028158: d0043ffc                 ld      [%l0-4], %o0
F002815C: d002201c                 ld      [%o0+0x1C], %o0
F0028160: d4122008                 lduh    [%o0+8], %o2
F0028164: d4322004                 sth     %o2, [%o0+4]
F0028168: d2046004                 ld      [%l1+4], %o1
F002816C: 80a26000                 cmp     %o1, 0
F0028170: 0280001e                 be      loc_F00281E8
F0028174: 912a6006                 sll     %o1, 6, %o0
F0028178: a00a2100                 and     %o0, 0x100, %l0
F002817C: 808a6002                 btst    2, %o1
F0028180: 0280000a                 be      loc_F00281A8
F0028184: 96100010                 mov     %l0, %o3
F0028188: 400004b5                 call    _isrofile
F002818C: d007bff4                 ld      [%fp+var_C], %o0
F0028190: 80a22000                 cmp     %o0, 0
F0028194: 02800004                 be      loc_F00281A4
F0028198: d204a1dc                 ld      [%l2+0x1DC], %o1
F002819C: 10800012                 ba      loc_F00281E4
F00281A0: 9010201e                 mov     0x1E, %o0
F00281A4: 96142080                 or      %l0, 0x80, %o3
F00281A8: d0046004                 ld      [%l1+4], %o0
F00281AC: 808a2001                 btst    1, %o0
F00281B0: 32800002                 bne,a   loc_F00281B8
F00281B4: 9612e040                 bset    0x40, %o3 ! '@'
F00281B8: 213c04cf                 sethi   %hi(_active_u), %l0
F00281BC: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F00281C0: d402201c                 ld      [%o0+0x1C], %o2
F00281C4: d007bff4                 ld      [%fp+var_C], %o0
F00281C8: 932ae010                 sll     %o3, 16, %o1
F00281CC: d602201c                 ld      [%o0+0x1C], %o3
F00281D0: 93326010                 srl     %o1, 16, %o1
F00281D4: d602e01c                 ld      [%o3+0x1C], %o3
F00281D8: 9fc2c000                 call    %o3
F00281DC: a01421d8                 bset    %lo(_active_u), %l0
F00281E0: d2042004                 ld      [%l0+4], %o1
F00281E4: d02a6038                 stb     %o0, [%o1+0x38]
F00281E8: 4000025f                 call    _vn_rele
F00281EC: d007bff4                 ld      [%fp+var_C], %o0
F00281F0: 133c04cf                 sethi   %hi(_active_u), %o1
F00281F4: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F00281F8: d002201c                 ld      [%o0+0x1C], %o0
F00281FC: e8322002                 sth     %l4, [%o0+2]
F0028200: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F0028204: d002201c                 ld      [%o0+0x1C], %o0
F0028208: e6322004                 sth     %l3, [%o0+4]
F002820C: 81c7e008                 ret
F0028210: 81e80000                 restore
