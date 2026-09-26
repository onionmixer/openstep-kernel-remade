F001569C: 9de3bf78                 save    %sp, -0x88, %sp
F00156A0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00156A4: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00156A8: d2026024                 ld      [%o1+0x24], %o1
F00156AC: 901221dc                 bset    %lo(dword_F0133DDC), %o0
F00156B0: d4023ffc                 ld      [%o0-4], %o2
F00156B4: f027bfe4                 st      %i0, [%fp+var_1C]
F00156B8: d6024000                 ld      [%o1], %o3
F00156BC: f227a048                 st      %i1, [%fp+arg_48]
F00156C0: d002a158                 ld      [%o2+0x158], %o0
F00156C4: c027bff4                 clr     [%fp+var_C]
F00156C8: 80a2c008                 cmp     %o3, %o0
F00156CC: 1a800013                 bcc     loc_F0015718
F00156D0: 912ae002                 sll     %o3, 2, %o0
F00156D4: d202a14c                 ld      [%o2+0x14C], %o1
F00156D8: d2024008                 ld      [%o1+%o0], %o1
F00156DC: 80a26000                 cmp     %o1, 0
F00156E0: 0280000e                 be      loc_F0015718
F00156E4: d227bfdc                 st      %o1, [%fp+var_24]
F00156E8: 113fffc0                 sethi   -0x10000, %o0
F00156EC: 80a24008                 cmp     %o1, %o0
F00156F0: 0280000a                 be      loc_F0015718
F00156F4: d807bfdc                 ld      [%fp+var_24], %o4
F00156F8: 80a66000                 cmp     %i1, 0
F00156FC: 12800004                 bne     loc_F001570C
F0015700: d0032008                 ld      [%o4+8], %o0
F0015704: 10800003                 ba      loc_F0015710
F0015708: 808a2001                 btst    1, %o0
F001570C: 808a2002                 btst    2, %o0
F0015710: 12800007                 bne     loc_F001572C
F0015714: d807bfe4                 ld      [%fp+var_1C], %o4
F0015718: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F001571C: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0015720: 90102009                 mov     9, %o0
F0015724: 1080006b                 ba      locret_F00158D0
F0015728: d02a6038                 stb     %o0, [%o1+0x38]
F001572C: c027bff0                 clr     [%fp+var_10]
F0015730: c0232014                 clr     [%o4+0x14]
F0015734: d0032004                 ld      [%o4+4], %o0
F0015738: c023200c                 clr     [%o4+0xC]
F001573C: 80a22000                 cmp     %o0, 0
F0015740: 04800012                 ble     loc_F0015788
F0015744: d4030000                 ld      [%o4], %o2
F0015748: 96100008                 mov     %o0, %o3
F001574C: d202a004                 ld      [%o2+4], %o1
F0015750: 80a26000                 cmp     %o1, 0
F0015754: 06800033                 bl      loc_F0015820
F0015758: d807bfe4                 ld      [%fp+var_1C], %o4
F001575C: d0032014                 ld      [%o4+0x14], %o0
F0015760: 90020009                 add     %o0, %o1, %o0
F0015764: 80a22000                 cmp     %o0, 0
F0015768: 0680002e                 bl      loc_F0015820
F001576C: d0232014                 st      %o0, [%o4+0x14]
F0015770: d007bff0                 ld      [%fp+var_10], %o0
F0015774: 9402a008                 inc     8, %o2
F0015778: 90022001                 inc     %o0
F001577C: 80a2000b                 cmp     %o0, %o3
F0015780: 06bffff3                 bl      loc_F001574C
F0015784: d027bff0                 st      %o0, [%fp+var_10]
F0015788: d807bfe4                 ld      [%fp+var_1C], %o4
F001578C: d0032014                 ld      [%o4+0x14], %o0
F0015790: d027bfec                 st      %o0, [%fp+var_14]
F0015794: d807bfdc                 ld      [%fp+var_24], %o4
F0015798: d003201c                 ld      [%o4+0x1C], %o0
F001579C: d807bfe4                 ld      [%fp+var_1C], %o4
F00157A0: d0232008                 st      %o0, [%o4+8]
F00157A4: d2032014                 ld      [%o4+0x14], %o1
F00157A8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00157AC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F00157B0: d227bfe8                 st      %o1, [%fp+var_18]
F00157B4: 40020568                 call    _setjmp
F00157B8: 90022028                 inc     0x28, %o0 ! '('
F00157BC: 80a22000                 cmp     %o0, 0
F00157C0: 0280001d                 be      loc_F0015834
F00157C4: d807bfe4                 ld      [%fp+var_1C], %o4
F00157C8: d2032014                 ld      [%o4+0x14], %o1
F00157CC: d007bfec                 ld      [%fp+var_14], %o0
F00157D0: 80a24008                 cmp     %o1, %o0
F00157D4: 32800029                 bne,a   loc_F0015878
F00157D8: d4032014                 ld      [%o4+0x14], %o2
F00157DC: 153c04cf                 sethi   %hi(_active_u), %o2
F00157E0: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F00157E4: d0024000                 ld      [%o1], %o0
F00157E8: d04a2017                 ldsb    [%o0+0x17], %o0
F00157EC: d202613c                 ld      [%o1+0x13C], %o1
F00157F0: 90023fff                 inc     -1, %o0
F00157F4: 933a4008                 sra     %o1, %o0, %o1
F00157F8: 808a6001                 btst    1, %o1
F00157FC: 02800005                 be      loc_F0015810
F0015800: 9412a1d8                 bset    %lo(_active_u), %o2
F0015804: d202a004                 ld      [%o2+4], %o1
F0015808: 10800018                 ba      loc_F0015868
F001580C: 90102004                 mov     4, %o0
F0015810: d202a004                 ld      [%o2+4], %o1
F0015814: 90102002                 mov     2, %o0
F0015818: 10800015                 ba      loc_F001586C
F001581C: d02a6039                 stb     %o0, [%o1+0x39]
F0015820: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0015824: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0015828: 90102016                 mov     0x16, %o0
F001582C: 10800029                 ba      locret_F00158D0
F0015830: d02a6038                 stb     %o0, [%o1+0x38]
F0015834: d007bff4                 ld      [%fp+var_C], %o0
F0015838: d807bfdc                 ld      [%fp+var_24], %o4
F001583C: d207a048                 ld      [%fp+arg_48], %o1
F0015840: d407bfe4                 ld      [%fp+var_1C], %o2
F0015844: 90022001                 inc     %o0
F0015848: d027bff4                 st      %o0, [%fp+var_C]
F001584C: d007bff4                 ld      [%fp+var_C], %o0
F0015850: d0032014                 ld      [%o4+0x14], %o0
F0015854: d6020000                 ld      [%o0], %o3
F0015858: 9fc2c000                 call    %o3
F001585C: d007bfdc                 ld      [%fp+var_24], %o0
F0015860: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0015864: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0015868: d02a6038                 stb     %o0, [%o1+0x38]
F001586C: d807bfe4                 ld      [%fp+var_1C], %o4
F0015870: d007bfec                 ld      [%fp+var_14], %o0
F0015874: d4032014                 ld      [%o4+0x14], %o2
F0015878: 173c04cf                 sethi   %hi(dword_F0133DDC), %o3
F001587C: d202e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o1
F0015880: 9022000a                 sub     %o0, %o2, %o0
F0015884: d0226030                 st      %o0, [%o1+0x30]
F0015888: d4032014                 ld      [%o4+0x14], %o2
F001588C: d007bfe8                 ld      [%fp+var_18], %o0
F0015890: d807bfdc                 ld      [%fp+var_24], %o4
F0015894: d203201c                 ld      [%o4+0x1C], %o1
F0015898: 9022000a                 sub     %o0, %o2, %o0
F001589C: 92024008                 add     %o1, %o0, %o1
F00158A0: d223201c                 st      %o1, [%o4+0x1C]
F00158A4: d002e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o0
F00158A8: d04a2038                 ldsb    [%o0+0x38], %o0
F00158AC: 80a22000                 cmp     %o0, 0
F00158B0: 02800008                 be      locret_F00158D0
F00158B4: 11000004                 sethi   0x1000, %o0
F00158B8: d2032008                 ld      [%o4+8], %o1
F00158BC: 4000cc87                 call    _fspause
F00158C0: 900a4008                 and     %o1, %o0, %o0
F00158C4: 80a22000                 cmp     %o0, 0
F00158C8: 12bfffb4                 bne     loc_F0015798
F00158CC: d807bfdc                 ld      [%fp+var_24], %o4
F00158D0: 81c7e008                 ret
F00158D4: 81e80000                 restore
