F0027F2C: 9de3bf50                 save    %sp, -0xB0, %sp
F0027F30: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0027F34: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0027F38: e0022024                 ld      [%o0+0x24], %l0
F0027F3C: d0040000                 ld      [%l0], %o0
F0027F40: 400002b6                 call    _getvnodefp
F0027F44: 9207bff4                 add     %fp, var_C, %o1
F0027F48: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0027F4C: d02a6038                 stb     %o0, [%o1+0x38]
F0027F50: d60461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o3
F0027F54: d04ae038                 ldsb    [%o3+0x38], %o0
F0027F58: 80a22000                 cmp     %o0, 0
F0027F5C: 02800006                 be      loc_F0027F74
F0027F60: a41461dc                 or      %l1, %lo(dword_F0133DDC), %l2
F0027F64: 80a22016                 cmp     %o0, 0x16
F0027F68: 12800063                 bne     locret_F00280F4
F0027F6C: 9010201d                 mov     0x1D, %o0
F0027F70: 30800008                 ba,a    loc_F0027F90
F0027F74: d807bff4                 ld      [%fp+var_C], %o4
F0027F78: d4032018                 ld      [%o4+0x18], %o2
F0027F7C: d002a028                 ld      [%o2+0x28], %o0
F0027F80: 80a22008                 cmp     %o0, 8
F0027F84: 32800005                 bne,a   loc_F0027F98
F0027F88: d0042008                 ld      [%l0+8], %o0
F0027F8C: 9010201d                 mov     0x1D, %o0
F0027F90: 10800059                 ba      locret_F00280F4
F0027F94: d02ae038                 stb     %o0, [%o3+0x38]
F0027F98: 80a22001                 cmp     %o0, 1
F0027F9C: 2280000d                 be,a    loc_F0027FD0
F0027FA0: d004bffc                 ld      [%l2-4], %o0
F0027FA4: 14800007                 bg      loc_F0027FC0
F0027FA8: 80a22002                 cmp     %o0, 2
F0027FAC: 80a22000                 cmp     %o0, 0
F0027FB0: 22800039                 be,a    loc_F0028094
F0027FB4: d004bffc                 ld      [%l2-4], %o0
F0027FB8: 10800047                 ba      loc_F00280D4
F0027FBC: 113c04cf                 sethi   -0xFECC400, %o0
F0027FC0: 22800014                 be,a    loc_F0028010
F0027FC4: d002a01c                 ld      [%o2+0x1C], %o0
F0027FC8: 10800043                 ba      loc_F00280D4
F0027FCC: 113c04cf                 sethi   -0xFECC400, %o0
F0027FD0: d0020000                 ld      [%o0], %o0
F0027FD4: d2022014                 ld      [%o0+0x14], %o1
F0027FD8: 11000010                 sethi   0x4000, %o0
F0027FDC: 808a4008                 btst    %o0, %o1
F0027FE0: 02800007                 be      loc_F0027FFC
F0027FE4: d007bff4                 ld      [%fp+var_C], %o0
F0027FE8: d203201c                 ld      [%o4+0x1C], %o1
F0027FEC: d0042004                 ld      [%l0+4], %o0
F0027FF0: 80824008                 addcc   %o1, %o0, %g0
F0027FF4: 0c800032                 bneg    loc_F00280BC
F0027FF8: d007bff4                 ld      [%fp+var_C], %o0
F0027FFC: d4042004                 ld      [%l0+4], %o2
F0028000: d202201c                 ld      [%o0+0x1C], %o1
F0028004: 9202400a                 add     %o1, %o2, %o1
F0028008: 10800036                 ba      loc_F00280E0
F002800C: d222201c                 st      %o1, [%o0+0x1C]
F0028010: d6022014                 ld      [%o0+0x14], %o3
F0028014: d204bffc                 ld      [%l2-4], %o1
F0028018: 9010000a                 mov     %o2, %o0
F002801C: d402601c                 ld      [%o1+0x1C], %o2
F0028020: 9fc2c000                 call    %o3
F0028024: 9207bfb0                 add     %fp, var_50, %o1
F0028028: d20461dc                 ld      [%l1+0x1DC], %o1
F002802C: d02a6038                 stb     %o0, [%o1+0x38]
F0028030: d40461dc                 ld      [%l1+0x1DC], %o2
F0028034: d04aa038                 ldsb    [%o2+0x38], %o0
F0028038: 80a22000                 cmp     %o0, 0
F002803C: 1280002e                 bne     locret_F00280F4
F0028040: 01000000                 nop
F0028044: d004bffc                 ld      [%l2-4], %o0
F0028048: d0020000                 ld      [%o0], %o0
F002804C: d2022014                 ld      [%o0+0x14], %o1
F0028050: 11000010                 sethi   0x4000, %o0
F0028054: 808a4008                 btst    %o0, %o1
F0028058: 02800009                 be      loc_F002807C
F002805C: d007bfc8                 ld      [%fp+var_38], %o0
F0028060: d2042004                 ld      [%l0+4], %o1
F0028064: 80824008                 addcc   %o1, %o0, %g0
F0028068: 3c800006                 bpos,a  loc_F0028080
F002806C: d0042004                 ld      [%l0+4], %o0
F0028070: 90102016                 mov     0x16, %o0
F0028074: 10800020                 ba      locret_F00280F4
F0028078: d02aa038                 stb     %o0, [%o2+0x38]
F002807C: d0042004                 ld      [%l0+4], %o0
F0028080: d207bfc8                 ld      [%fp+var_38], %o1
F0028084: d407bff4                 ld      [%fp+var_C], %o2
F0028088: 90020009                 add     %o0, %o1, %o0
F002808C: 10800015                 ba      loc_F00280E0
F0028090: d022a01c                 st      %o0, [%o2+0x1C]
F0028094: d0020000                 ld      [%o0], %o0
F0028098: d2022014                 ld      [%o0+0x14], %o1
F002809C: 11000010                 sethi   0x4000, %o0
F00280A0: 808a4008                 btst    %o0, %o1
F00280A4: 02800009                 be      loc_F00280C8
F00280A8: d207bff4                 ld      [%fp+var_C], %o1
F00280AC: d0042004                 ld      [%l0+4], %o0
F00280B0: 80a22000                 cmp     %o0, 0
F00280B4: 3680000b                 bge,a   loc_F00280E0
F00280B8: d022601c                 st      %o0, [%o1+0x1C]
F00280BC: 90102016                 mov     0x16, %o0
F00280C0: 1080000d                 ba      locret_F00280F4
F00280C4: d02ae038                 stb     %o0, [%o3+0x38]
F00280C8: d0042004                 ld      [%l0+4], %o0
F00280CC: 10800005                 ba      loc_F00280E0
F00280D0: d022601c                 st      %o0, [%o1+0x1C]
F00280D4: d20221dc                 ld      [%o0+0x1DC], %o1
F00280D8: 90102016                 mov     0x16, %o0
F00280DC: d02a6038                 stb     %o0, [%o1+0x38]
F00280E0: d407bff4                 ld      [%fp+var_C], %o2
F00280E4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00280E8: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00280EC: d002a01c                 ld      [%o2+0x1C], %o0
F00280F0: d0226030                 st      %o0, [%o1+0x30]
F00280F4: 81c7e008                 ret
F00280F8: 81e80000                 restore
