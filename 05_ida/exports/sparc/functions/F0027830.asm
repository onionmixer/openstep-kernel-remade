F0027830: 9de3bf50                 save    %sp, -0xB0, %sp
F0027834: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0027838: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F002783C: e0022024                 ld      [%o0+0x24], %l0
F0027840: 2300003c                 sethi   0xF000, %l1
F0027844: d4042004                 ld      [%l0+4], %o2
F0027848: 808a8011                 btst    %l1, %o2
F002784C: 12800005                 bne     loc_F0027860
F0027850: a41261dc                 or      %o1, %lo(dword_F0133DDC), %l2
F0027854: 1100002090128008         set     0x8000, %o0
F002785C: d0242004                 st      %o0, [%l0+4]
F0027860: d0042004                 ld      [%l0+4], %o0
F0027864: 13000004                 sethi   0x1000, %o1
F0027868: 900a0011                 and     %o0, %l1, %o0
F002786C: 80a20009                 cmp     %o0, %o1
F0027870: 02800007                 be      loc_F002788C
F0027874: 01000000                 nop
F0027878: 7fffa03d                 call    _suser
F002787C: 01000000                 nop
F0027880: 80a22000                 cmp     %o0, 0
F0027884: 02800042                 be      locret_F002798C
F0027888: 01000000                 nop
F002788C: 40000702                 call    _vattr_null
F0027890: 9007bfb8                 add     %fp, var_48, %o0
F0027894: 133c042f                 sethi   %hi(_mftovt_tab), %o1
F0027898: d0042004                 ld      [%l0+4], %o0
F002789C: 92126188                 bset    %lo(_mftovt_tab), %o1
F00278A0: 900a0011                 and     %o0, %l1, %o0
F00278A4: 913a200d                 sra     %o0, 13, %o0
F00278A8: 912a2002                 sll     %o0, 2, %o0
F00278AC: d4020009                 ld      [%o0+%o1], %o2
F00278B0: d427bfb8                 st      %o2, [%fp+var_48]
F00278B4: d2042004                 ld      [%l0+4], %o1
F00278B8: d004bffc                 ld      [%l2-4], %o0
F00278BC: 80a2a009                 cmp     %o2, 9! switch 10 cases
F00278C0: d012216a                 lduh    [%o0+0x16A], %o0
F00278C4: 920a6fff                 and     %o1, 0xFFF, %o1
F00278C8: 902a4008                 andn    %o1, %o0, %o0
F00278CC: 1880001f                 bgu     def_F00278E4! jumptable F00278E4 default case, cases 1,5,6,8
F00278D0: d037bfbc                 sth     %o0, [%fp+var_44]
F00278D4: 113c009e901220ec         set     jpt_F00278E4, %o0
F00278DC: 932aa002                 sll     %o2, 2, %o1
F00278E0: d0024008                 ld      [%o1+%o0], %o0
F00278E4: 81c20000                 jmp     %o0! switch jump
F00278E8: 01000000                 nop
F0027914: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0! jumptable F00278E4 case 2
F0027918: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F002791C: 90102015                 mov     0x15, %o0
F0027920: 1080001b                 ba      locret_F002798C
F0027924: d02a6038                 stb     %o0, [%o1+0x38]
F0027928: d0042008                 ld      [%l0+8], %o0! jumptable F00278E4 cases 3,4,7,9
F002792C: 10800007                 ba      def_F00278E4! jumptable F00278E4 default case, cases 1,5,6,8
F0027930: d037bff0                 sth     %o0, [%fp+var_10]
F0027934: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0! jumptable F00278E4 case 0
F0027938: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F002793C: 90102016                 mov     0x16, %o0
F0027940: 10800013                 ba      locret_F002798C
F0027944: d02a6038                 stb     %o0, [%o1+0x38]
F0027948: 92102000                 mov     0, %o1! jumptable F00278E4 default case, cases 1,5,6,8
F002794C: 9407bfb8                 add     %fp, var_48, %o2
F0027950: 96102001                 mov     1, %o3
F0027954: 98102000                 mov     0, %o4
F0027958: d0040000                 ld      [%l0], %o0
F002795C: 40000526                 call    _vn_create
F0027960: 9a07bfb4                 add     %fp, var_4C, %o5
F0027964: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F0027968: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F002796C: d02a6038                 stb     %o0, [%o1+0x38]
F0027970: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F0027974: d04a2038                 ldsb    [%o0+0x38], %o0
F0027978: 80a22000                 cmp     %o0, 0
F002797C: 12800004                 bne     locret_F002798C
F0027980: 01000000                 nop
F0027984: 40000478                 call    _vn_rele
F0027988: d007bfb4                 ld      [%fp+var_4C], %o0
F002798C: 81c7e008                 ret
F0027990: 81e80000                 restore
