F00BDA90: 9de3bf90                 save    %sp, -0x70, %sp
F00BDA94: d0062114                 ld      [%i0+0x114], %o0
F00BDA98: 80a22002                 cmp     %o0, 2
F00BDA9C: 12800071                 bne     locret_F00BDC60
F00BDAA0: 113c04cb                 sethi   %hi(dword_F0132F38), %o0
F00BDAA4: c0222338                 clr     [%o0+%lo(dword_F0132F38)]
F00BDAA8: 133c04cb                 sethi   %hi(dword_F0132F20), %o1
F00BDAAC: 90102120                 mov     0x120, %o0
F00BDAB0: d0226320                 st      %o0, [%o1+%lo(dword_F0132F20)]
F00BDAB4: 133c04cb                 sethi   %hi(dword_F0132F24), %o1
F00BDAB8: 90102034                 mov     0x34, %o0 ! '4'
F00BDABC: 7fffff71                 call    sub_F00BD880
F00BDAC0: d0226324                 st      %o0, [%o1+%lo(dword_F0132F24)]
F00BDAC4: a4102000                 mov     0, %l2
F00BDAC8: a210001a                 mov     %i2, %l1
F00BDACC: d20c4000                 ldub    [%l1], %o1
F00BDAD0: 80a26000                 cmp     %o1, 0
F00BDAD4: 0280000b                 be      loc_F00BDB00
F00BDAD8: 90102000                 mov     0, %o0
F00BDADC: 90100009                 mov     %o1, %o0
F00BDAE0: 80a2200a                 cmp     %o0, 0xA
F00BDAE4: 22800002                 be,a    loc_F00BDAEC
F00BDAE8: a404a001                 inc     %l2
F00BDAEC: a2046001                 inc     %l1
F00BDAF0: d20c4000                 ldub    [%l1], %o1
F00BDAF4: 80a26000                 cmp     %o1, 0
F00BDAF8: 32bffffa                 bne,a   loc_F00BDAE0
F00BDAFC: 90100009                 mov     %o1, %o0
F00BDB00: 912a2018                 sll     %o0, 24, %o0
F00BDB04: 913a2018                 sra     %o0, 24, %o0
F00BDB08: 80a2200a                 cmp     %o0, 0xA
F00BDB0C: 32800002                 bne,a   loc_F00BDB14
F00BDB10: a404a001                 inc     %l2
F00BDB14: 9210200a                 mov     0xA, %o1! int
F00BDB18: 153c04cb                 sethi   %hi(dword_F0132F28), %o2
F00BDB1C: a210001a                 mov     %i2, %l1
F00BDB20: d002a328                 ld      [%o2+%lo(dword_F0132F28)], %o0
F00BDB24: 173c04cb                 sethi   %hi(dword_F0132F20), %o3
F00BDB28: 90022003                 inc     3, %o0
F00BDB2C: 900a3ffc                 and     %o0, -4, %o0
F00BDB30: d022a328                 st      %o0, [%o2+%lo(dword_F0132F28)]
F00BDB34: d002e320                 ld      [%o3+%lo(dword_F0132F20)], %o0
F00BDB38: 353c0481                 sethi   %hi(off_F012054C), %i2
F00BDB3C: d406a14c                 ld      [%i2+%lo(off_F012054C)], %o2
F00BDB40: 900a3ffc                 and     %o0, -4, %o0! int
F00BDB44: e052a008                 ldsh    [%o2+8], %l0
F00BDB48: d022e320                 st      %o0, [%o3+%lo(dword_F0132F20)]
F00BDB4C: 7ffd22af                 call    _div
F00BDB50: 90042009                 add     %l0, 9, %o0
F00BDB54: a0040008                 add     %l0, %o0, %l0
F00BDB58: 90100010                 mov     %l0, %o0
F00BDB5C: 7ffd2269                 call    _umul
F00BDB60: 9204bfff                 add     %l2, -1, %o1
F00BDB64: 133c04cb                 sethi   %hi(dword_F0132F24), %o1
F00BDB68: d2026324                 ld      [%o1+%lo(dword_F0132F24)], %o1
F00BDB6C: 153c04cb                 sethi   %hi(dword_F0132F34), %o2
F00BDB70: 92224008                 sub     %o1, %o0, %o1
F00BDB74: 9132601f                 srl     %o1, 31, %o0
F00BDB78: 92024008                 add     %o1, %o0, %o1
F00BDB7C: 933a6001                 sra     %o1, 1, %o1
F00BDB80: 92026002                 inc     2, %o1
F00BDB84: d222a334                 st      %o1, [%o2+%lo(dword_F0132F34)]
F00BDB88: d00c4000                 ldub    [%l1], %o0
F00BDB8C: 80a22000                 cmp     %o0, 0
F00BDB90: 02800032                 be      loc_F00BDC58
F00BDB94: 01000000                 nop
F00BDB98: a410001a                 mov     %i2, %l2
F00BDB9C: b410000a                 mov     %o2, %i2
F00BDBA0: 94100011                 mov     %l1, %o2
F00BDBA4: 0280000f                 be      loc_F00BDBE0
F00BDBA8: 96102000                 mov     0, %o3
F00BDBAC: d804a14c                 ld      [%l2+0x14C], %o4
F00BDBB0: d04a8000                 ldsb    [%o2], %o0
F00BDBB4: 80a2200a                 cmp     %o0, 0xA
F00BDBB8: 0280000a                 be      loc_F00BDBE0
F00BDBBC: 900a20ff                 and     %o0, 0xFF, %o0
F00BDBC0: 912a2004                 sll     %o0, 4, %o0
F00BDBC4: 9002000c                 add     %o0, %o4, %o0
F00BDBC8: d2523e18                 ldsh    [%o0-0x1E8], %o1
F00BDBCC: 9402a001                 inc     %o2
F00BDBD0: d04a8000                 ldsb    [%o2], %o0
F00BDBD4: 80a22000                 cmp     %o0, 0
F00BDBD8: 12bffff7                 bne     loc_F00BDBB4
F00BDBDC: 9602c009                 add     %o3, %o1, %o3
F00BDBE0: 113c04cb                 sethi   %hi(dword_F0132F20), %o0
F00BDBE4: d0022320                 ld      [%o0+%lo(dword_F0132F20)], %o0
F00BDBE8: 9022000b                 sub     %o0, %o3, %o0
F00BDBEC: 9332201f                 srl     %o0, 31, %o1
F00BDBF0: 90020009                 add     %o0, %o1, %o0
F00BDBF4: 913a2001                 sra     %o0, 1, %o0
F00BDBF8: 133c04cb                 sethi   %hi(dword_F0132F30), %o1
F00BDBFC: 1080000c                 ba      loc_F00BDC2C
F00BDC00: d0226330                 st      %o0, [%o1+%lo(dword_F0132F30)]
F00BDC04: 80a2200a                 cmp     %o0, 0xA
F00BDC08: 12800004                 bne     loc_F00BDC18
F00BDC0C: a2046001                 inc     %l1
F00BDC10: 1080000c                 ba      loc_F00BDC40
F00BDC14: d006a334                 ld      [%i2+0x334], %o0
F00BDC18: 912a2004                 sll     %o0, 4, %o0
F00BDC1C: d204a14c                 ld      [%l2+0x14C], %o1
F00BDC20: 90023e10                 inc     -0x1F0, %o0
F00BDC24: 7fffff23                 call    sub_F00BD8B0
F00BDC28: 90024008                 add     %o1, %o0, %o0
F00BDC2C: d00c4000                 ldub    [%l1], %o0
F00BDC30: 80a22000                 cmp     %o0, 0
F00BDC34: 12bffff4                 bne     loc_F00BDC04
F00BDC38: 900a20ff                 and     %o0, 0xFF, %o0
F00BDC3C: d006a334                 ld      [%i2+0x334], %o0
F00BDC40: 90020010                 add     %o0, %l0, %o0
F00BDC44: d026a334                 st      %o0, [%i2+0x334]
F00BDC48: d00c4000                 ldub    [%l1], %o0
F00BDC4C: 80a22000                 cmp     %o0, 0
F00BDC50: 12bfffd5                 bne     loc_F00BDBA4
F00BDC54: 94100011                 mov     %l1, %o2
F00BDC58: 7fffff76                 call    sub_F00BDA30
F00BDC5C: d006210c                 ld      [%i0+0x10C], %o0
F00BDC60: 81c7e008                 ret
F00BDC64: 81e80000                 restore
