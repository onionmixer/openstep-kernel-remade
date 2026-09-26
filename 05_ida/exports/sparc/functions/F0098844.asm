F0098844: 9de3bf70                 save    %sp, -0x90, %sp
F0098848: 9807bfd0                 add     %fp, var_30, %o4
F009884C: 153c044a                 sethi   %hi(dword_F0112A40), %o2
F0098850: d202a240                 ld      [%o2+%lo(dword_F0112A40)], %o1
F0098854: 96102027                 mov     0x27, %o3 ! '''
F0098858: 90026001                 add     %o1, 1, %o0
F009885C: d022a240                 st      %o0, [%o2+%lo(dword_F0112A40)]
F0098860: 912a6003                 sll     %o1, 3, %o0
F0098864: 90220009                 sub     %o0, %o1, %o0
F0098868: 912a2002                 sll     %o0, 2, %o0
F009886C: 90020009                 add     %o0, %o1, %o0
F0098870: 912a2002                 sll     %o0, 2, %o0
F0098874: 133c044a92126264         set     _mod_info, %o1
F009887C: a0020009                 add     %o0, %o1, %l0
F0098880: c02b0000                 clrb    [%o4]
F0098884: 98032001                 inc     %o4
F0098888: 9092c000                 orcc    %o3, %g0, %o0
F009888C: 14bffffd                 bg      loc_F0098880
F0098890: 9602ffff                 inc     -1, %o3
F0098894: 90100018                 mov     %i0, %o0
F0098898: 133c044b92126148         set     _psname, %o1! "name"
F00988A0: a207bfd0                 add     %fp, var_30, %l1
F00988A4: 400059d8                 call    _prom_getprop
F00988A8: 94100011                 mov     %l1, %o2
F00988AC: 80a23fff                 cmp     %o0, -1
F00988B0: 02800063                 be      locret_F0098A3C
F00988B4: 01000000                 nop
F00988B8: d0042004                 ld      [%l0+4], %o0! __dst
F00988BC: 7ffdbb1b                 call    _strcpy
F00988C0: 92100011                 mov     %l1, %o1
F00988C4: 90100018                 mov     %i0, %o0
F00988C8: 7fffffb3                 call    _fill_nodeinfo
F00988CC: 92100019                 mov     %i1, %o1
F00988D0: 113c044b                 sethi   %hi(dword_F0112F5C), %o0
F00988D4: d002235c                 ld      [%o0+%lo(dword_F0112F5C)], %o0
F00988D8: d0242040                 st      %o0, [%l0+0x40]
F00988DC: 113c044b                 sethi   %hi(dword_F0112F2C), %o0
F00988E0: d202232c                 ld      [%o0+%lo(dword_F0112F2C)], %o1
F00988E4: 113c044b                 sethi   %hi(dword_F0112F60), %o0
F00988E8: d0022360                 ld      [%o0+%lo(dword_F0112F60)], %o0
F00988EC: d2242008                 st      %o1, [%l0+8]
F00988F0: d0242044                 st      %o0, [%l0+0x44]
F00988F4: 113c044b                 sethi   %hi(dword_F0112F64), %o0
F00988F8: d2022364                 ld      [%o0+%lo(dword_F0112F64)], %o1
F00988FC: 113c044b                 sethi   %hi(dword_F0112F30), %o0
F0098900: d0022330                 ld      [%o0+%lo(dword_F0112F30)], %o0
F0098904: d2242048                 st      %o1, [%l0+0x48]
F0098908: d0242010                 st      %o0, [%l0+0x10]
F009890C: 113c044b                 sethi   %hi(dword_F0112F34), %o0
F0098910: d2022334                 ld      [%o0+%lo(dword_F0112F34)], %o1
F0098914: 113c044b                 sethi   %hi(dword_F0112F58), %o0
F0098918: d0022358                 ld      [%o0+%lo(dword_F0112F58)], %o0
F009891C: d2242014                 st      %o1, [%l0+0x14]
F0098920: d0242038                 st      %o0, [%l0+0x38]
F0098924: 113c044b                 sethi   %hi(dword_F0112F38), %o0
F0098928: d2022338                 ld      [%o0+%lo(dword_F0112F38)], %o1
F009892C: 113c044b                 sethi   %hi(dword_F0112F3C), %o0
F0098930: d002233c                 ld      [%o0+%lo(dword_F0112F3C)], %o0
F0098934: d2242018                 st      %o1, [%l0+0x18]
F0098938: d024201c                 st      %o0, [%l0+0x1C]
F009893C: 113c044b                 sethi   %hi(dword_F0112F40), %o0
F0098940: d2022340                 ld      [%o0+%lo(dword_F0112F40)], %o1
F0098944: 113c044b                 sethi   %hi(dword_F0112F44), %o0
F0098948: d0022344                 ld      [%o0+%lo(dword_F0112F44)], %o0
F009894C: d2242020                 st      %o1, [%l0+0x20]
F0098950: d0242024                 st      %o0, [%l0+0x24]
F0098954: 113c044b                 sethi   %hi(dword_F0112F54), %o0
F0098958: d2022354                 ld      [%o0+%lo(dword_F0112F54)], %o1
F009895C: 113c044b                 sethi   %hi(dword_F0112F50), %o0
F0098960: d0022350                 ld      [%o0+%lo(dword_F0112F50)], %o0
F0098964: d2242034                 st      %o1, [%l0+0x34]
F0098968: d0242030                 st      %o0, [%l0+0x30]
F009896C: 113c044b                 sethi   %hi(dword_F0112F4C), %o0
F0098970: d202234c                 ld      [%o0+%lo(dword_F0112F4C)], %o1
F0098974: 113c044b                 sethi   %hi(dword_F0112F48), %o0
F0098978: d0022348                 ld      [%o0+%lo(dword_F0112F48)], %o0
F009897C: d224202c                 st      %o1, [%l0+0x2C]
F0098980: d0242028                 st      %o0, [%l0+0x28]
F0098984: 113c044b                 sethi   %hi(dword_F0112F68), %o0
F0098988: d2022368                 ld      [%o0+%lo(dword_F0112F68)], %o1
F009898C: 113c044b                 sethi   %hi(dword_F0112F6C), %o0
F0098990: d002236c                 ld      [%o0+%lo(dword_F0112F6C)], %o0
F0098994: d224204c                 st      %o1, [%l0+0x4C]
F0098998: d0242050                 st      %o0, [%l0+0x50]
F009899C: 113c044b                 sethi   %hi(dword_F0112F70), %o0
F00989A0: d0022370                 ld      [%o0+%lo(dword_F0112F70)], %o0
F00989A4: d0242054                 st      %o0, [%l0+0x54]
F00989A8: 113c044b                 sethi   %hi(dword_F0112F74), %o0
F00989AC: d2022374                 ld      [%o0+%lo(dword_F0112F74)], %o1
F00989B0: 113c044b                 sethi   %hi(dword_F0112F78), %o0
F00989B4: d0022378                 ld      [%o0+%lo(dword_F0112F78)], %o0
F00989B8: d2242058                 st      %o1, [%l0+0x58]
F00989BC: d024205c                 st      %o0, [%l0+0x5C]
F00989C0: 113c044b                 sethi   %hi(dword_F0112F7C), %o0
F00989C4: d202237c                 ld      [%o0+%lo(dword_F0112F7C)], %o1
F00989C8: 233c044b                 sethi   %hi(dword_F0112F84), %l1
F00989CC: 113c044b                 sethi   %hi(dword_F0112F80), %o0
F00989D0: d0022380                 ld      [%o0+%lo(dword_F0112F80)], %o0
F00989D4: d2242060                 st      %o1, [%l0+0x60]
F00989D8: d2046384                 ld      [%l1+%lo(dword_F0112F84)], %o1
F00989DC: d0242064                 st      %o0, [%l0+0x64]
F00989E0: 113c044b                 sethi   %hi(dword_F0112F88), %o0
F00989E4: d0022388                 ld      [%o0+%lo(dword_F0112F88)], %o0
F00989E8: d2242068                 st      %o1, [%l0+0x68]
F00989EC: d024206c                 st      %o0, [%l0+0x6C]
F00989F0: 113c044b                 sethi   %hi(dword_F0112F8C), %o0
F00989F4: d202238c                 ld      [%o0+%lo(dword_F0112F8C)], %o1
F00989F8: 113c044b                 sethi   %hi(dword_F0112F90), %o0
F00989FC: d0022390                 ld      [%o0+%lo(dword_F0112F90)], %o0
F0098A00: 80a22000                 cmp     %o0, 0
F0098A04: 1280000e                 bne     locret_F0098A3C
F0098A08: d2242070                 st      %o1, [%l0+0x70]
F0098A0C: 7ffff8fd                 call    _getpsr
F0098A10: 01000000                 nop
F0098A14: 91322018                 srl     %o0, 24, %o0
F0098A18: 80a22004                 cmp     %o0, 4
F0098A1C: 22800008                 be,a    locret_F0098A3C
F0098A20: d0240000                 st      %o0, [%l0]
F0098A24: d0046384                 ld      [%l1+0x384], %o0
F0098A28: 80a22000                 cmp     %o0, 0
F0098A2C: 12800003                 bne     loc_F0098A38
F0098A30: 90102041                 mov     0x41, %o0 ! 'A'
F0098A34: 90102040                 mov     0x40, %o0 ! '@'
F0098A38: d0240000                 st      %o0, [%l0]
F0098A3C: 81c7e008                 ret
F0098A40: 81e80000                 restore
