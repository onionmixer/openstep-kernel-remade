F00BCDA4: 9de3bf90                 save    %sp, -0x70, %sp
F00BCDA8: a2102000                 mov     0, %l1
F00BCDAC: d0062114                 ld      [%i0+0x114], %o0
F00BCDB0: 80a22002                 cmp     %o0, 2
F00BCDB4: 02800004                 be      loc_F00BCDC4
F00BCDB8: a4102000                 mov     0, %l2
F00BCDBC: 1080002e                 ba      locret_F00BCE74
F00BCDC0: b0102000                 mov     0, %i0
F00BCDC4: 113c04c8a0122070         set     dword_F0132070, %l0
F00BCDCC: d0040000                 ld      [%l0], %o0
F00BCDD0: 80a22000                 cmp     %o0, 0
F00BCDD4: 12bffffe                 bne     loc_F00BCDCC
F00BCDD8: 01000000                 nop
F00BCDDC: 7fff6833                 call    _simple_lock_try
F00BCDE0: 90100010                 mov     %l0, %o0
F00BCDE4: 80a22000                 cmp     %o0, 0
F00BCDE8: 02bffff9                 be      loc_F00BCDCC
F00BCDEC: 80a6a001                 cmp     %i2, 1
F00BCDF0: 08800006                 bleu    loc_F00BCE08
F00BCDF4: 80a6a002                 cmp     %i2, 2
F00BCDF8: 02800011                 be      loc_F00BCE3C
F00BCDFC: 133c047f                 sethi   -0xFEE0400, %o1
F00BCE00: 10800016                 ba      loc_F00BCE58
F00BCE04: a4102016                 mov     0x16, %l2
F00BCE08: 153c047f                 sethi   %hi(dword_F011FEBC), %o2
F00BCE0C: d202a2bc                 ld      [%o2+%lo(dword_F011FEBC)], %o1
F00BCE10: 80a26000                 cmp     %o1, 0
F00BCE14: 04800011                 ble     loc_F00BCE58
F00BCE18: 92200009                 neg     %o1
F00BCE1C: d222a2bc                 st      %o1, [%o2+%lo(dword_F011FEBC)]
F00BCE20: d006210c                 ld      [%i0+0x10C], %o0
F00BCE24: 133c047f                 sethi   %hi(unk_F011FE4C), %o1
F00BCE28: d4022010                 ld      [%o0+0x10], %o2
F00BCE2C: 9fc28000                 call    %o2
F00BCE30: 9212624c                 bset    %lo(unk_F011FE4C), %o1
F00BCE34: 1080000a                 ba      loc_F00BCE5C
F00BCE38: 113c04c8                 sethi   -0xFECE000, %o0
F00BCE3C: d00262bc                 ld      [%o1+0x2BC], %o0
F00BCE40: 80a22000                 cmp     %o0, 0
F00BCE44: 36800006                 bge,a   loc_F00BCE5C
F00BCE48: 113c04c8                 sethi   -0xFECE000, %o0
F00BCE4C: 90200008                 neg     %o0
F00BCE50: d02262bc                 st      %o0, [%o1+0x2BC]
F00BCE54: a2102001                 mov     1, %l1
F00BCE58: 113c04c8                 sethi   -0xFECE000, %o0
F00BCE5C: c0222070                 clr     [%o0+0x70]
F00BCE60: 80a46000                 cmp     %l1, 0
F00BCE64: 02800004                 be      locret_F00BCE74
F00BCE68: b0100012                 mov     %l2, %i0
F00BCE6C: 7fffff47                 call    sub_F00BCB88
F00BCE70: 01000000                 nop
F00BCE74: 81c7e008                 ret
F00BCE78: 81e80000                 restore
