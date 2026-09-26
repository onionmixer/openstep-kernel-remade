F009A260: 9de3bf98                 save    %sp, -0x68, %sp
F009A264: 7ffff2a6                 call    _splvm
F009A268: 01000000                 nop
F009A26C: e2064000                 ld      [%i1], %l1
F009A270: 80a46000                 cmp     %l1, 0
F009A274: 12800006                 bne     loc_F009A28C
F009A278: a0100008                 mov     %o0, %l0
F009A27C: 113c045c                 sethi   %hi(aMbMapfreeMr0), %o0! "mb_mapfree: MR == 0!!!\n"
F009A280: 7ffde8f6                 call    _printf
F009A284: 90122220                 bset    %lo(aMbMapfreeMr0), %o0! "mb_mapfree: MR == 0!!!\n"
F009A288: 3080003c                 ba,a    loc_F009A378
F009A28C: c0264000                 clr     [%i1]
F009A290: 7ffff2a5                 call    _splx
F009A294: 90100010                 mov     %l0, %o0
F009A298: a334600c                 srl     %l1, 12, %l1
F009A29C: 90100011                 mov     %l1, %o0
F009A2A0: 7ffffdbb                 call    _map_addr_to_map
F009A2A4: 92100018                 mov     %i0, %o1
F009A2A8: a4920000                 orcc    %o0, %g0, %l2
F009A2AC: 02800029                 be      loc_F009A350
F009A2B0: 90100011                 mov     %l1, %o0
F009A2B4: 7ffffd89                 call    _iom_ptefind
F009A2B8: 92100012                 mov     %l2, %o1
F009A2BC: b0920000                 orcc    %o0, %g0, %i0
F009A2C0: 12800006                 bne     loc_F009A2D8
F009A2C4: b2102000                 mov     0, %i1
F009A2C8: 113c045c                 sethi   %hi(aMbMapfreeNoIop), %o0! "mb_mapfree: no iopte"
F009A2CC: 7ffdeba9                 call    _panic
F009A2D0: 90122238                 bset    %lo(aMbMapfreeNoIop), %o0! "mb_mapfree: no iopte"
F009A2D4: b2102000                 mov     0, %i1
F009A2D8: 273c044a                 sethi   -0xFEED800, %l3
F009A2DC: 213c0464                 sethi   -0xFEE7000, %l0
F009A2E0: 7ffdabd8                 call    _get_iommu_entry
F009A2E4: 90100018                 mov     %i0, %o0
F009A2E8: 808a2002                 btst    2, %o0
F009A2EC: 02800010                 be      loc_F009A32C
F009A2F0: 01000000                 nop
F009A2F4: d2060000                 ld      [%i0], %o1
F009A2F8: 808a6004                 btst    4, %o1
F009A2FC: 02800007                 be      loc_F009A318
F009A300: d004e24c                 ld      [%l3+0x24C], %o0
F009A304: 80a22000                 cmp     %o0, 0
F009A308: 12800004                 bne     loc_F009A318
F009A30C: 01000000                 nop
F009A310: 40001be8                 call    _pmap_vacflush
F009A314: 91326008                 srl     %o1, 8, %o0
F009A318: 7ffffd64                 call    _iom_pteunload
F009A31C: 90100018                 mov     %i0, %o0
F009A320: b0062004                 inc     4, %i0
F009A324: 10bfffef                 ba      loc_F009A2E0
F009A328: b2066001                 inc     %i1
F009A32C: 7ffff274                 call    _splvm
F009A330: 01000000                 nop
F009A334: a0100008                 mov     %o0, %l0
F009A338: 90100012                 mov     %l2, %o0
F009A33C: 92066001                 add     %i1, 1, %o1
F009A340: 40002af5                 call    _rmfree
F009A344: 94100011                 mov     %l1, %o2
F009A348: 7ffff277                 call    _splx
F009A34C: 90100010                 mov     %l0, %o0
F009A350: 7ffff26b                 call    _splvm
F009A354: 01000000                 nop
F009A358: 133c04c5                 sethi   %hi(dword_F0131558), %o1
F009A35C: d2026158                 ld      [%o1+%lo(dword_F0131558)], %o1
F009A360: 80a26000                 cmp     %o1, 0
F009A364: 02800005                 be      loc_F009A378
F009A368: a0100008                 mov     %o0, %l0
F009A36C: 913c2008                 sra     %l0, 8, %o0
F009A370: 40000059                 call    sub_F009A4D4
F009A374: 900a200f                 and     %o0, 0xF, %o0
F009A378: 7ffff26b                 call    _splx
F009A37C: 90100010                 mov     %l0, %o0
F009A380: 81c7e008                 ret
F009A384: 81e80000                 restore
