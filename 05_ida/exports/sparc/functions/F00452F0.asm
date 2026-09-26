F00452F0: 9de3bf98                 save    %sp, -0x68, %sp
F00452F4: d006201c                 ld      [%i0+0x1C], %o0
F00452F8: 173c04eb                 sethi   %hi(_dupchecks), %o3
F00452FC: d202e0f8                 ld      [%o3+%lo(_dupchecks)], %o1
F0045300: d0022030                 ld      [%o0+0x30], %o0
F0045304: e2022004                 ld      [%o0+4], %l1
F0045308: 92026001                 inc     %o1
F004530C: 940c601f                 and     %l1, 0x1F, %o2
F0045310: 113c04eb90122070         set     _drhashtbl, %o0
F0045318: 952aa002                 sll     %o2, 2, %o2
F004531C: e0028008                 ld      [%o2+%o0], %l0
F0045320: 80a42000                 cmp     %l0, 0
F0045324: 02800027                 be      loc_F00453C0
F0045328: d222e0f8                 st      %o1, [%o3+%lo(_dupchecks)]
F004532C: 253c04eb                 sethi   -0xFEC5400, %l2
F0045330: d0040000                 ld      [%l0], %o0
F0045334: 80a20011                 cmp     %o0, %l1
F0045338: 3280001f                 bne,a   loc_F00453B4
F004533C: e0042024                 ld      [%l0+0x24], %l0
F0045340: d204201c                 ld      [%l0+0x1C], %o1
F0045344: d0060000                 ld      [%i0], %o0
F0045348: 80a24008                 cmp     %o1, %o0
F004534C: 3280001a                 bne,a   loc_F00453B4
F0045350: e0042024                 ld      [%l0+0x24], %l0
F0045354: d2042018                 ld      [%l0+0x18], %o1
F0045358: d0062004                 ld      [%i0+4], %o0
F004535C: 80a24008                 cmp     %o1, %o0
F0045360: 32800015                 bne,a   loc_F00453B4
F0045364: e0042024                 ld      [%l0+0x24], %l0
F0045368: d2042014                 ld      [%l0+0x14], %o1
F004536C: d0062008                 ld      [%i0+8], %o0
F0045370: 80a24008                 cmp     %o1, %o0
F0045374: 32800010                 bne,a   loc_F00453B4
F0045378: e0042024                 ld      [%l0+0x24], %l0
F004537C: d206201c                 ld      [%i0+0x1C], %o1! void *
F0045380: 90042004                 add     %l0, 4, %o0! void *
F0045384: 94102010                 mov     0x10, %o2! size_t
F0045388: 7fff02f5                 call    _bcmp
F004538C: 92026010                 inc     0x10, %o1
F0045390: 80a22000                 cmp     %o0, 0
F0045394: 02800004                 be      loc_F00453A4
F0045398: d004a100                 ld      [%l2+0x100], %o0
F004539C: 10800006                 ba      loc_F00453B4
F00453A0: e0042024                 ld      [%l0+0x24], %l0
F00453A4: b0102001                 mov     1, %i0
F00453A8: 90022001                 inc     %o0
F00453AC: 10800006                 ba      locret_F00453C4
F00453B0: d024a100                 st      %o0, [%l2+0x100]
F00453B4: 80a42000                 cmp     %l0, 0
F00453B8: 32bfffdf                 bne,a   loc_F0045334
F00453BC: d0040000                 ld      [%l0], %o0
F00453C0: b0102000                 mov     0, %i0
F00453C4: 81c7e008                 ret
F00453C8: 81e80000                 restore
