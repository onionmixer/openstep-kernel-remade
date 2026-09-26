F004A674: 9de3bf90                 save    %sp, -0x70, %sp
F004A678: e2062050                 ld      [%i0+0x50], %l1
F004A67C: d00460b8                 ld      [%l1+0xB8], %o0
F004A680: 7ffeefa0                 call    _umul
F004A684: d204602c                 ld      [%l1+0x2C], %o1
F004A688: 80a64008                 cmp     %i1, %o0
F004A68C: 0a80000a                 bcs     loc_F004A6B4
F004A690: 113c043a                 sethi   %hi(aDev0xXInoDFsS), %o0! "dev = 0x%x, ino = %d, fs = %s\n"
F004A694: 90122108                 bset    %lo(aDev0xXInoDFsS), %o0! "dev = 0x%x, ino = %d, fs = %s\n"
F004A698: d2562046                 ldsh    [%i0+0x46], %o1
F004A69C: 94100019                 mov     %i1, %o2
F004A6A0: 7fff27ee                 call    _printf
F004A6A4: 960460d4                 add     %l1, 0xD4, %o3
F004A6A8: 113c043a                 sethi   %hi(aIfreeRange), %o0! "ifree: range"
F004A6AC: 7fff2ab1                 call    _panic
F004A6B0: 90122128                 bset    %lo(aIfreeRange), %o0! "ifree: range"
F004A6B4: d20460b8                 ld      [%l1+0xB8], %o1
F004A6B8: 7ffeefd2                 call    _udiv
F004A6BC: 90100019                 mov     %i1, %o0
F004A6C0: a8100008                 mov     %o0, %l4
F004A6C4: d00460bc                 ld      [%l1+0xBC], %o0
F004A6C8: 7ffeef8e                 call    _umul
F004A6CC: 92100014                 mov     %l4, %o1
F004A6D0: d4046018                 ld      [%l1+0x18], %o2
F004A6D4: a0100008                 mov     %o0, %l0
F004A6D8: d204601c                 ld      [%l1+0x1C], %o1
F004A6DC: 9010000a                 mov     %o2, %o0
F004A6E0: 7ffeef88                 call    _umul
F004A6E4: 922d0009                 andn    %l4, %o1, %o1
F004A6E8: d40460a0                 ld      [%l1+0xA0], %o2
F004A6EC: 96100008                 mov     %o0, %o3
F004A6F0: d2062040                 ld      [%i0+0x40], %o1
F004A6F4: a004000b                 add     %l0, %o3, %l0
F004A6F8: d804600c                 ld      [%l1+0xC], %o4
F004A6FC: 90100009                 mov     %o1, %o0
F004A700: d2046064                 ld      [%l1+0x64], %o1
F004A704: a004000c                 add     %l0, %o4, %l0
F004A708: 7fff6786                 call    _bread
F004A70C: 932c0009                 sll     %l0, %o1, %o1
F004A710: aa100008                 mov     %o0, %l5
F004A714: d0054000                 ld      [%l5], %o0
F004A718: 808a2004                 btst    4, %o0
F004A71C: 12800008                 bne     loc_F004A73C
F004A720: e0056020                 ld      [%l5+0x20], %l0
F004A724: d20423d4                 ld      [%l0+0x3D4], %o1
F004A728: 1100024090122255         set     0x90255, %o0
F004A730: 80a24008                 cmp     %o1, %o0
F004A734: 02800005                 be      loc_F004A748
F004A738: 01000000                 nop
F004A73C: 7fff684b                 call    _brelse
F004A740: 90100015                 mov     %l5, %o0
F004A744: 3080005e                 ba,a    locret_F004A8BC
F004A748: 7fff2211                 call    _getthetime
F004A74C: 9007bff0                 add     %fp, var_10, %o0
F004A750: d007bff0                 ld      [%fp+var_10], %o0
F004A754: d0242008                 st      %o0, [%l0+8]
F004A758: d20460b8                 ld      [%l1+0xB8], %o1
F004A75C: 7ffef051                 call    _urem
F004A760: 90100019                 mov     %i1, %o0
F004A764: b2100008                 mov     %o0, %i1
F004A768: 91366003                 srl     %i1, 3, %o0
F004A76C: a4020010                 add     %o0, %l0, %l2
F004A770: d04ca2d4                 ldsb    [%l2+0x2D4], %o0
F004A774: a60e6007                 and     %i1, 7, %l3
F004A778: 913a0013                 sra     %o0, %l3, %o0
F004A77C: 808a2001                 btst    1, %o0
F004A780: 3280000c                 bne,a   loc_F004A7B0
F004A784: 90102001                 mov     1, %o0
F004A788: 113c043a90122138         set     aDev0xXInoDFsS_0, %o0! "dev = 0x%x, ino = %d, fs = %s\n"
F004A790: d2562046                 ldsh    [%i0+0x46], %o1
F004A794: 94100019                 mov     %i1, %o2
F004A798: 7fff27b0                 call    _printf
F004A79C: 960460d4                 add     %l1, 0xD4, %o3
F004A7A0: 113c043a                 sethi   %hi(aIfreeFreeingFr), %o0! "ifree: freeing free inode"
F004A7A4: 7fff2a73                 call    _panic
F004A7A8: 90122158                 bset    %lo(aIfreeFreeingFr), %o0! "ifree: freeing free inode"
F004A7AC: 90102001                 mov     1, %o0
F004A7B0: d20ca2d4                 ldub    [%l2+0x2D4], %o1
F004A7B4: 912a0013                 sll     %o0, %l3, %o0
F004A7B8: 902a4008                 andn    %o1, %o0, %o0
F004A7BC: d02ca2d4                 stb     %o0, [%l2+0x2D4]
F004A7C0: d0042030                 ld      [%l0+0x30], %o0
F004A7C4: 80a64008                 cmp     %i1, %o0
F004A7C8: 2a800002                 bcs,a   loc_F004A7D0
F004A7CC: f2242030                 st      %i1, [%l0+0x30]
F004A7D0: d0042020                 ld      [%l0+0x20], %o0
F004A7D4: 90022001                 inc     %o0
F004A7D8: d0242020                 st      %o0, [%l0+0x20]
F004A7DC: d20460c8                 ld      [%l1+0xC8], %o1
F004A7E0: 17000010                 sethi   0x4000, %o3
F004A7E4: d0046070                 ld      [%l1+0x70], %o0
F004A7E8: 92026001                 inc     %o1
F004A7EC: d22460c8                 st      %o1, [%l1+0xC8]
F004A7F0: 913d0008                 sra     %l4, %o0, %o0
F004A7F4: 912a2002                 sll     %o0, 2, %o0
F004A7F8: d204606c                 ld      [%l1+0x6C], %o1
F004A7FC: 90020011                 add     %o0, %l1, %o0
F004A800: d40222d8                 ld      [%o0+0x2D8], %o2
F004A804: 922d0009                 andn    %l4, %o1, %o1
F004A808: 932a6004                 sll     %o1, 4, %o1
F004A80C: 94028009                 add     %o2, %o1, %o2
F004A810: 1300003c                 sethi   0xF000, %o1
F004A814: 920e8009                 and     %i2, %o1, %o1
F004A818: d002a008                 ld      [%o2+8], %o0
F004A81C: 80a2400b                 cmp     %o1, %o3
F004A820: 90022001                 inc     %o0
F004A824: 12800013                 bne     loc_F004A870
F004A828: d022a008                 st      %o0, [%o2+8]
F004A82C: d0042018                 ld      [%l0+0x18], %o0
F004A830: 90023fff                 inc     -1, %o0
F004A834: d0242018                 st      %o0, [%l0+0x18]
F004A838: d20460c0                 ld      [%l1+0xC0], %o1
F004A83C: d0046070                 ld      [%l1+0x70], %o0
F004A840: 92027fff                 inc     -1, %o1
F004A844: d22460c0                 st      %o1, [%l1+0xC0]
F004A848: 913d0008                 sra     %l4, %o0, %o0
F004A84C: 912a2002                 sll     %o0, 2, %o0
F004A850: d204606c                 ld      [%l1+0x6C], %o1
F004A854: 90020011                 add     %o0, %l1, %o0
F004A858: d40222d8                 ld      [%o0+0x2D8], %o2
F004A85C: 922d0009                 andn    %l4, %o1, %o1
F004A860: 932a6004                 sll     %o1, 4, %o1
F004A864: d0028009                 ld      [%o2+%o1], %o0
F004A868: 90023fff                 inc     -1, %o0
F004A86C: d0228009                 st      %o0, [%o2+%o1]
F004A870: d20c60d0                 ldub    [%l1+0xD0], %o1
F004A874: 90100015                 mov     %l5, %o0
F004A878: 92026001                 inc     %o1
F004A87C: 7fff67e2                 call    _bdwrite
F004A880: d22c60d0                 stb     %o1, [%l1+0xD0]
F004A884: d00c60d3                 ldub    [%l1+0xD3], %o0
F004A888: 808a2002                 btst    2, %o0
F004A88C: 0280000c                 be      locret_F004A8BC
F004A890: 01000000                 nop
F004A894: d20460c8                 ld      [%l1+0xC8], %o1
F004A898: d0046090                 ld      [%l1+0x90], %o0
F004A89C: 80a24008                 cmp     %o1, %o0
F004A8A0: 04800007                 ble     locret_F004A8BC
F004A8A4: 01000000                 nop
F004A8A8: 7fff2150                 call    _wakeup
F004A8AC: 900460c8                 add     %l1, 0xC8, %o0
F004A8B0: d00c60d3                 ldub    [%l1+0xD3], %o0
F004A8B4: 900a3ffd                 and     %o0, -3, %o0
F004A8B8: d02c60d3                 stb     %o0, [%l1+0xD3]
F004A8BC: 81c7e008                 ret
F004A8C0: 81e80000                 restore
