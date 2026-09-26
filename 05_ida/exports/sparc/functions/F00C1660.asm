F00C1660: 9de3bf98                 save    %sp, -0x68, %sp
F00C1664: 92100019                 mov     %i1, %o1
F00C1668: d0026034                 ld      [%o1+0x34], %o0
F00C166C: e0022034                 ld      [%o0+0x34], %l0
F00C1670: 80a42000                 cmp     %l0, 0
F00C1674: 0280004f                 be      locret_F00C17B0
F00C1678: e2022038                 ld      [%o0+0x38], %l1
F00C167C: 113c04cb                 sethi   %hi(unk_F0132FF4), %o0
F00C1680: d04a23f4                 ldsb    [%o0+%lo(unk_F0132FF4)], %o0
F00C1684: 80a22001                 cmp     %o0, 1
F00C1688: 0280004a                 be      locret_F00C17B0
F00C168C: b00e20ff                 and     %i0, 0xFF, %i0
F00C1690: 7ffffe7c                 call    sub_F00C1080
F00C1694: 90100018                 mov     %i0, %o0
F00C1698: 80a22000                 cmp     %o0, 0
F00C169C: 02800018                 be      loc_F00C16FC
F00C16A0: 113c04cb                 sethi   %hi(unk_F0132F88), %o0
F00C16A4: b2122388                 or      %o0, %lo(unk_F0132F88), %i1
F00C16A8: 900e3f7f                 and     %i0, -0x81, %o0
F00C16AC: d0266008                 st      %o0, [%i1+8]
F00C16B0: 4000128b                 call    _IOGetTimestamp
F00C16B4: 90100019                 mov     %i1, %o0
F00C16B8: 91362007                 srl     %i0, 7, %o0
F00C16BC: 901a2001                 btog    1, %o0
F00C16C0: 80a22000                 cmp     %o0, 0
F00C16C4: 02800012                 be      loc_F00C170C
F00C16C8: d02e600c                 stb     %o0, [%i1+0xC]
F00C16CC: 113c04cb981223f8         set     unk_F0132FF8, %o4
F00C16D4: d2066008                 ld      [%i1+8], %o1
F00C16D8: 90102001                 mov     1, %o0
F00C16DC: 95326005                 srl     %o1, 5, %o2
F00C16E0: 952aa002                 sll     %o2, 2, %o2
F00C16E4: 920a601f                 and     %o1, 0x1F, %o1
F00C16E8: d602800c                 ld      [%o2+%o4], %o3
F00C16EC: 912a0009                 sll     %o0, %o1, %o0
F00C16F0: 808ac008                 btst    %o0, %o3
F00C16F4: 02800004                 be      loc_F00C1704
F00C16F8: 9012c008                 bset    %o3, %o0
F00C16FC: 10800011                 ba      loc_F00C1740
F00C1700: b0102000                 mov     0, %i0
F00C1704: 1080000d                 ba      loc_F00C1738
F00C1708: d022800c                 st      %o0, [%o2+%o4]
F00C170C: 153c04cb9412a3f8         set     unk_F0132FF8, %o2
F00C1714: d2066008                 ld      [%i1+8], %o1
F00C1718: 90102001                 mov     1, %o0
F00C171C: 97326005                 srl     %o1, 5, %o3
F00C1720: 972ae002                 sll     %o3, 2, %o3
F00C1724: 920a601f                 and     %o1, 0x1F, %o1
F00C1728: d802c00a                 ld      [%o3+%o2], %o4
F00C172C: 912a0009                 sll     %o0, %o1, %o0
F00C1730: 902b0008                 andn    %o4, %o0, %o0
F00C1734: d022c00a                 st      %o0, [%o3+%o2]
F00C1738: 113c04cbb0122388         set     unk_F0132F88, %i0
F00C1740: 80a62000                 cmp     %i0, 0
F00C1744: 0280001b                 be      locret_F00C17B0
F00C1748: 90100018                 mov     %i0, %o0
F00C174C: 7ffffd39                 call    sub_F00C0C30
F00C1750: 92100011                 mov     %l1, %o1
F00C1754: 912a2018                 sll     %o0, 24, %o0
F00C1758: 80a22000                 cmp     %o0, 0
F00C175C: 32800011                 bne,a   loc_F00C17A0
F00C1760: 90100010                 mov     %l0, %o0
F00C1764: 133c04cb                 sethi   %hi(dword_F0132FF0), %o1
F00C1768: d80263f0                 ld      [%o1+%lo(dword_F0132FF0)], %o4
F00C176C: 80a32005                 cmp     %o4, 5
F00C1770: 02800010                 be      locret_F00C17B0
F00C1774: 90032001                 add     %o4, 1, %o0
F00C1778: d02263f0                 st      %o0, [%o1+%lo(dword_F0132FF0)]
F00C177C: 133c04cb921263a0         set     qword_F0132FA0, %o1
F00C1784: d41e0000                 ldd     [%i0], %o2
F00C1788: 912b2004                 sll     %o4, 4, %o0
F00C178C: d43a0009                 std     %o2, [%o0+%o1]
F00C1790: d41e2008                 ldd     [%i0+8], %o2
F00C1794: 90020009                 add     %o0, %o1, %o0
F00C1798: d43a2008                 std     %o2, [%o0+8]
F00C179C: 90100010                 mov     %l0, %o0
F00C17A0: 92100011                 mov     %l1, %o1
F00C17A4: 150008c8                 sethi   0x232000, %o2
F00C17A8: 7fff3551                 call    _IOSendInterrupt
F00C17AC: 9412a325                 bset    0x325, %o2
F00C17B0: 81c7e008                 ret
F00C17B4: 81e80000                 restore
