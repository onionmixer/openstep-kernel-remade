F000A860: 9de3bf98                 save    %sp, -0x68, %sp
F000A864: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F000A868: d604e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o3
F000A86C: a414e1dc                 or      %l3, %lo(dword_F0133DDC), %l2
F000A870: d204bffc                 ld      [%l2-4], %o1
F000A874: e002e024                 ld      [%o3+0x24], %l0
F000A878: d0026158                 ld      [%o1+0x158], %o0
F000A87C: d4040000                 ld      [%l0], %o2
F000A880: 80a28008                 cmp     %o2, %o0
F000A884: 1a80000a                 bcc     loc_F000A8AC
F000A888: 912aa002                 sll     %o2, 2, %o0
F000A88C: d202614c                 ld      [%o1+0x14C], %o1
F000A890: e2024008                 ld      [%o1+%o0], %l1
F000A894: 80a46000                 cmp     %l1, 0
F000A898: 02800005                 be      loc_F000A8AC
F000A89C: 293fffc0                 sethi   -0x10000, %l4
F000A8A0: 80a44014                 cmp     %l1, %l4
F000A8A4: 32800005                 bne,a   loc_F000A8B8
F000A8A8: d0042004                 ld      [%l0+4], %o0
F000A8AC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000A8B0: 10800040                 ba      loc_F000A9B0
F000A8B4: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000A8B8: 80a220ff                 cmp     %o0, 0xFF
F000A8BC: 28800005                 bleu,a  loc_F000A8D0
F000A8C0: d022e030                 st      %o0, [%o3+0x30]
F000A8C4: 90102009                 mov     9, %o0
F000A8C8: 10800042                 ba      locret_F000A9D0
F000A8CC: d02ae038                 stb     %o0, [%o3+0x38]
F000A8D0: d0040000                 ld      [%l0], %o0
F000A8D4: d2042004                 ld      [%l0+4], %o1
F000A8D8: 80a20009                 cmp     %o0, %o1
F000A8DC: 0280003d                 be      locret_F000A9D0
F000A8E0: 113c04d0                 sethi   %hi(_active_threads), %o0
F000A8E4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000A8E8: d002200c                 ld      [%o0+0xC], %o0
F000A8EC: 400003a3                 call    _expand_fdlist
F000A8F0: d0022038                 ld      [%o0+0x38], %o0
F000A8F4: d204bffc                 ld      [%l2-4], %o1
F000A8F8: d0040000                 ld      [%l0], %o0
F000A8FC: d202614c                 ld      [%o1+0x14C], %o1
F000A900: 912a2002                 sll     %o0, 2, %o0
F000A904: d0024008                 ld      [%o1+%o0], %o0
F000A908: 80a44008                 cmp     %l1, %o0
F000A90C: 32800029                 bne,a   loc_F000A9B0
F000A910: d204e1dc                 ld      [%l3+0x1DC], %o1
F000A914: d0042004                 ld      [%l0+4], %o0
F000A918: 912a2002                 sll     %o0, 2, %o0
F000A91C: d0024008                 ld      [%o1+%o0], %o0
F000A920: 80a20014                 cmp     %o0, %l4
F000A924: 12800004                 bne     loc_F000A934
F000A928: 80a22000                 cmp     %o0, 0
F000A92C: 10800021                 ba      loc_F000A9B0
F000A930: d204e1dc                 ld      [%l3+0x1DC], %o1
F000A934: 02800016                 be      loc_F000A98C
F000A938: 153c04cf                 sethi   -0xFECC400, %o2
F000A93C: 40006f0e                 call    _vno_lockrelease
F000A940: 01000000                 nop
F000A944: d004bffc                 ld      [%l2-4], %o0
F000A948: d2042004                 ld      [%l0+4], %o1
F000A94C: d0022150                 ld      [%o0+0x150], %o0
F000A950: d00a0009                 ldub    [%o0+%o1], %o0
F000A954: 808a2002                 btst    2, %o0
F000A958: 22800005                 be,a    loc_F000A96C
F000A95C: d204bffc                 ld      [%l2-4], %o1
F000A960: 40000e60                 call    _munmapfd
F000A964: 90100009                 mov     %o1, %o0
F000A968: d204bffc                 ld      [%l2-4], %o1
F000A96C: d0042004                 ld      [%l0+4], %o0
F000A970: d202614c                 ld      [%o1+0x14C], %o1
F000A974: 912a2002                 sll     %o0, 2, %o0
F000A978: 400002da                 call    _closef
F000A97C: d0024008                 ld      [%o1+%o0], %o0
F000A980: d004e1dc                 ld      [%l3+0x1DC], %o0
F000A984: c02a2038                 clrb    [%o0+0x38]
F000A988: 153c04cf                 sethi   -0xFECC400, %o2
F000A98C: d602a1d8                 ld      [%o2+0x1D8], %o3
F000A990: d8040000                 ld      [%l0], %o4
F000A994: d202e14c                 ld      [%o3+0x14C], %o1
F000A998: 912b2002                 sll     %o4, 2, %o0
F000A99C: d0024008                 ld      [%o1+%o0], %o0
F000A9A0: 80a44008                 cmp     %l1, %o0
F000A9A4: 02800006                 be      loc_F000A9BC
F000A9A8: 9412a1d8                 bset    0x1D8, %o2
F000A9AC: d202a004                 ld      [%o2+4], %o1
F000A9B0: 90102009                 mov     9, %o0
F000A9B4: 10800007                 ba      locret_F000A9D0
F000A9B8: d02a6038                 stb     %o0, [%o1+0x38]
F000A9BC: d202e150                 ld      [%o3+0x150], %o1
F000A9C0: d44a400c                 ldsb    [%o1+%o4], %o2
F000A9C4: d0042004                 ld      [%l0+4], %o0
F000A9C8: 40000004                 call    _dupit
F000A9CC: 92100011                 mov     %l1, %o1
F000A9D0: 81c7e008                 ret
F000A9D4: 81e80000                 restore
