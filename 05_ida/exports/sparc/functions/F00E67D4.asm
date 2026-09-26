F00E67D4: 9de3bf98                 save    %sp, -0x68, %sp
F00E67D8: 80a6200f                 cmp     %i0, 0xF
F00E67DC: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E67E0: 912e2004                 sll     %i0, 4, %o0
F00E67E4: 90020018                 add     %o0, %i0, %o0
F00E67E8: d4026364                 ld      [%o1+%lo(_sparcfbs)], %o2
F00E67EC: 912a2002                 sll     %o0, 2, %o0
F00E67F0: 92022008                 add     %o0, 8, %o1
F00E67F4: 18800006                 bgu     loc_F00E680C
F00E67F8: a0028009                 add     %o2, %o1, %l0
F00E67FC: d0028009                 ld      [%o2+%o1], %o0
F00E6800: 80a22000                 cmp     %o0, 0
F00E6804: 12800004                 bne     loc_F00E6814
F00E6808: 01000000                 nop
F00E680C: 10800085                 ba      locret_F00E6A20
F00E6810: b0103d40                 mov     -0x2C0, %i0
F00E6814: d0028009                 ld      [%o2+%o1], %o0
F00E6818: 80a22002                 cmp     %o0, 2
F00E681C: 0280000d                 be      loc_F00E6850
F00E6820: 01000000                 nop
F00E6824: 18800006                 bgu     loc_F00E683C
F00E6828: 80a22001                 cmp     %o0, 1
F00E682C: 0280001e                 be      loc_F00E68A4
F00E6830: 01000000                 nop
F00E6834: 1080007b                 ba      locret_F00E6A20
F00E6838: b0103fff                 mov     -1, %i0
F00E683C: 80a22003                 cmp     %o0, 3
F00E6840: 02800022                 be      loc_F00E68C8
F00E6844: 01000000                 nop
F00E6848: 10800076                 ba      locret_F00E6A20
F00E684C: b0103fff                 mov     -1, %i0
F00E6850: d0042040                 ld      [%l0+0x40], %o0
F00E6854: 80a22000                 cmp     %o0, 0
F00E6858: 02800005                 be      loc_F00E686C
F00E685C: 01000000                 nop
F00E6860: d2042040                 ld      [%l0+0x40], %o1
F00E6864: 9fc24000                 call    %o1
F00E6868: 90100018                 mov     %i0, %o0
F00E686C: d0042030                 ld      [%l0+0x30], %o0
F00E6870: 80a22008                 cmp     %o0, 8
F00E6874: 0280006a                 be      loc_F00E6A1C
F00E6878: 90102008                 mov     8, %o0
F00E687C: d0242030                 st      %o0, [%l0+0x30]
F00E6880: 90102001                 mov     1, %o0
F00E6884: d0242034                 st      %o0, [%l0+0x34]
F00E6888: d0042020                 ld      [%l0+0x20], %o0
F00E688C: d2042034                 ld      [%l0+0x34], %o1
F00E6890: 7ffc7f1c                 call    _umul
F00E6894: 01000000                 nop
F00E6898: d0242038                 st      %o0, [%l0+0x38]
F00E689C: 10800061                 ba      locret_F00E6A20
F00E68A0: b0102000                 mov     0, %i0
F00E68A4: d0042040                 ld      [%l0+0x40], %o0
F00E68A8: 80a22000                 cmp     %o0, 0
F00E68AC: 2280005d                 be,a    locret_F00E6A20
F00E68B0: b0102000                 mov     0, %i0
F00E68B4: d2042040                 ld      [%l0+0x40], %o1
F00E68B8: 9fc24000                 call    %o1
F00E68BC: 90100018                 mov     %i0, %o0
F00E68C0: 10800058                 ba      locret_F00E6A20
F00E68C4: b0102000                 mov     0, %i0
F00E68C8: d0042004                 ld      [%l0+4], %o0
F00E68CC: 80a22000                 cmp     %o0, 0
F00E68D0: 0280000c                 be      loc_F00E6900
F00E68D4: 90102008                 mov     8, %o0
F00E68D8: d2042008                 ld      [%l0+8], %o1
F00E68DC: 17000400                 sethi   0x100000, %o3
F00E68E0: 90102000                 mov     0, %o0
F00E68E4: 94102066                 mov     0x66, %o2 ! 'f'
F00E68E8: d4224000                 st      %o2, [%o1]
F00E68EC: 90022001                 inc     %o0
F00E68F0: 80a2000b                 cmp     %o0, %o3
F00E68F4: 06bffffd                 bl      loc_F00E68E8
F00E68F8: 92026004                 inc     4, %o1
F00E68FC: 90102008                 mov     8, %o0
F00E6900: d0242030                 st      %o0, [%l0+0x30]
F00E6904: 90102001                 mov     1, %o0
F00E6908: d0242034                 st      %o0, [%l0+0x34]
F00E690C: d0042020                 ld      [%l0+0x20], %o0
F00E6910: d2042034                 ld      [%l0+0x34], %o1
F00E6914: 7ffc7efb                 call    _umul
F00E6918: 01000000                 nop
F00E691C: d0242038                 st      %o0, [%l0+0x38]
F00E6920: 80a6200f                 cmp     %i0, 0xF
F00E6924: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E6928: 912e2004                 sll     %i0, 4, %o0
F00E692C: 90020018                 add     %o0, %i0, %o0
F00E6930: d4026364                 ld      [%o1+%lo(_sparcfbs)], %o2
F00E6934: 912a2002                 sll     %o0, 2, %o0
F00E6938: 92022008                 add     %o0, 8, %o1
F00E693C: 18800038                 bgu     loc_F00E6A1C
F00E6940: 96028009                 add     %o2, %o1, %o3
F00E6944: d0028009                 ld      [%o2+%o1], %o0
F00E6948: 80a22000                 cmp     %o0, 0
F00E694C: 22800035                 be,a    locret_F00E6A20
F00E6950: b0102000                 mov     0, %i0
F00E6954: d0028009                 ld      [%o2+%o1], %o0
F00E6958: 80a22002                 cmp     %o0, 2
F00E695C: 0280000b                 be      loc_F00E6988
F00E6960: 01000000                 nop
F00E6964: 18800005                 bgu     loc_F00E6978
F00E6968: 80a22001                 cmp     %o0, 1
F00E696C: 02800015                 be      loc_F00E69C0
F00E6970: b0102000                 mov     0, %i0
F00E6974: 3080002b                 ba,a    locret_F00E6A20
F00E6978: 80a22003                 cmp     %o0, 3
F00E697C: 02800011                 be      loc_F00E69C0
F00E6980: b0102000                 mov     0, %i0
F00E6984: 30800027                 ba,a    locret_F00E6A20
F00E6988: d202e00c                 ld      [%o3+0xC], %o1
F00E698C: 11000010                 sethi   0x4000, %o0
F00E6990: c0224008                 clr     [%o1+%o0]
F00E6994: 92024008                 add     %o1, %o0, %o1
F00E6998: 1100266690122199         set     0x999999, %o0
F00E69A0: d0226264                 st      %o0, [%o1+0x264]
F00E69A4: 1100199990122266         set     0x666666, %o0
F00E69AC: d0226198                 st      %o0, [%o1+0x198]
F00E69B0: 11003fff901223ff         set     0xFFFFFF, %o0
F00E69B8: 10800019                 ba      loc_F00E6A1C
F00E69BC: d02263fc                 st      %o0, [%o1+0x3FC]
F00E69C0: d002e00c                 ld      [%o3+0xC], %o0
F00E69C4: 133fc000                 sethi   -0x1000000, %o1
F00E69C8: c0220000                 clr     [%o0]
F00E69CC: c0222004                 clr     [%o0+4]
F00E69D0: c0222004                 clr     [%o0+4]
F00E69D4: c0222004                 clr     [%o0+4]
F00E69D8: d2220000                 st      %o1, [%o0]
F00E69DC: d2222004                 st      %o1, [%o0+4]
F00E69E0: d2222004                 st      %o1, [%o0+4]
F00E69E4: d2222004                 st      %o1, [%o0+4]
F00E69E8: 13264000                 sethi   -0x67000000, %o1
F00E69EC: d2220000                 st      %o1, [%o0]
F00E69F0: d2222004                 st      %o1, [%o0+4]
F00E69F4: d2222004                 st      %o1, [%o0+4]
F00E69F8: d2222004                 st      %o1, [%o0+4]
F00E69FC: 13198000                 sethi   0x66000000, %o1
F00E6A00: d2220000                 st      %o1, [%o0]
F00E6A04: d2222004                 st      %o1, [%o0+4]
F00E6A08: d2222004                 st      %o1, [%o0+4]
F00E6A0C: d2222004                 st      %o1, [%o0+4]
F00E6A10: c0220000                 clr     [%o0]
F00E6A14: 10800003                 ba      locret_F00E6A20
F00E6A18: b0102000                 mov     0, %i0
F00E6A1C: b0102000                 mov     0, %i0
F00E6A20: 81c7e008                 ret
F00E6A24: 81e80000                 restore
