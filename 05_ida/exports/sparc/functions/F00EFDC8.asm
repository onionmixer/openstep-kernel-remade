F00EFDC8: 9de3bf98                 save    %sp, -0x68, %sp
F00EFDCC: a2100018                 mov     %i0, %l1
F00EFDD0: 4000035f                 call    _NXDefaultMallocZone
F00EFDD4: a4102004                 mov     4, %l2
F00EFDD8: 4000035d                 call    _NXDefaultMallocZone
F00EFDDC: a0100008                 mov     %o0, %l0
F00EFDE0: d4042004                 ld      [%l0+4], %o2
F00EFDE4: 9fc28000                 call    %o2
F00EFDE8: 92102018                 mov     0x18, %o1
F00EFDEC: b0100008                 mov     %o0, %i0
F00EFDF0: 92102000                 mov     0, %o1
F00EFDF4: 912a6002                 sll     %o1, 2, %o0
F00EFDF8: 90020018                 add     %o0, %i0, %o0
F00EFDFC: 92026001                 inc     %o1
F00EFE00: 80a24012                 cmp     %o1, %l2
F00EFE04: 06bffffc                 bl      loc_F00EFDF4
F00EFE08: c0222008                 clr     [%o0+8]
F00EFE0C: c0262004                 clr     [%i0+4]
F00EFE10: 9004bfff                 add     %l2, -1, %o0
F00EFE14: d0260000                 st      %o0, [%i0]
F00EFE18: f0246020                 st      %i0, [%l1+0x20]
F00EFE1C: d2046010                 ld      [%l1+0x10], %o1
F00EFE20: 900a7fdf                 and     %o1, -0x21, %o0
F00EFE24: d0246010                 st      %o0, [%l1+0x10]
F00EFE28: 113c04bc                 sethi   %hi(dword_F012F0D4), %o0
F00EFE2C: d00220d4                 ld      [%o0+%lo(dword_F012F0D4)], %o0
F00EFE30: 80a22000                 cmp     %o0, 0
F00EFE34: 02800003                 be      locret_F00EFE40
F00EFE38: 900a7f9f                 and     %o1, -0x61, %o0
F00EFE3C: d0246010                 st      %o0, [%l1+0x10]
F00EFE40: 81c7e008                 ret
F00EFE44: 81e80000                 restore
