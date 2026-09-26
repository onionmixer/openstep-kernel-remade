F000E6B4: 9de3bf98                 save    %sp, -0x68, %sp
F000E6B8: 7fffffea                 call    _pgfind
F000E6BC: 90100019                 mov     %i1, %o0
F000E6C0: a0100008                 mov     %o0, %l0
F000E6C4: 40000117                 call    _get_posix_proc
F000E6C8: d0562030                 ldsh    [%i0+0x30], %o0
F000E6CC: 80a42000                 cmp     %l0, 0
F000E6D0: 12800027                 bne     loc_F000E76C
F000E6D4: a2100008                 mov     %o0, %l1
F000E6D8: 40016666                 call    _kalloc
F000E6DC: 90102014                 mov     0x14, %o0
F000E6E0: 80a6a000                 cmp     %i2, 0
F000E6E4: 0280000f                 be      loc_F000E720
F000E6E8: a0100008                 mov     %o0, %l0
F000E6EC: 40016661                 call    _kalloc
F000E6F0: 90102010                 mov     0x10, %o0
F000E6F4: f0222004                 st      %i0, [%o0+4]
F000E6F8: 92102001                 mov     1, %o1
F000E6FC: d2220000                 st      %o1, [%o0]
F000E700: c0222008                 clr     [%o0+8]
F000E704: c032200c                 clrh    [%o0+0xC]
F000E708: d4062028                 ld      [%i0+0x28], %o2
F000E70C: 13100000                 sethi   0x40000000, %o1
F000E710: 922a8009                 andn    %o2, %o1, %o1
F000E714: d2262028                 st      %o1, [%i0+0x28]
F000E718: 10800008                 ba      loc_F000E738
F000E71C: d0242008                 st      %o0, [%l0+8]
F000E720: d0046010                 ld      [%l1+0x10], %o0
F000E724: d2022008                 ld      [%o0+8], %o1
F000E728: d2242008                 st      %o1, [%l0+8]
F000E72C: d0024000                 ld      [%o1], %o0
F000E730: 90022001                 inc     %o0
F000E734: d0224000                 st      %o0, [%o1]
F000E738: f224200c                 st      %i1, [%l0+0xC]
F000E73C: 900e603f                 and     %i1, 0x3F, %o0
F000E740: 133c04d1921263b0         set     _pgrphash, %o1
F000E748: 912a2002                 sll     %o0, 2, %o0
F000E74C: d4020009                 ld      [%o0+%o1], %o2
F000E750: d4240000                 st      %o2, [%l0]
F000E754: e0220009                 st      %l0, [%o0+%o1]
F000E758: c0242010                 clr     [%l0+0x10]
F000E75C: 1080000a                 ba      loc_F000E784
F000E760: c0242004                 clr     [%l0+4]
F000E764: 10800024                 ba      loc_F000E7F4
F000E768: d0224000                 st      %o0, [%o1]
F000E76C: d0046010                 ld      [%l1+0x10], %o0
F000E770: d204200c                 ld      [%l0+0xC], %o1
F000E774: d002200c                 ld      [%o0+0xC], %o0
F000E778: 80a24008                 cmp     %o1, %o0
F000E77C: 0280002c                 be      locret_F000E82C
F000E780: 01000000                 nop
F000E784: d2062014                 ld      [%i0+0x14], %o1
F000E788: 11000010                 sethi   0x4000, %o0
F000E78C: 808a4008                 btst    %o0, %o1
F000E790: 02800009                 be      loc_F000E7B4
F000E794: 90100018                 mov     %i0, %o0
F000E798: 92100010                 mov     %l0, %o1
F000E79C: 40000083                 call    _fixjobc
F000E7A0: 94102001                 mov     1, %o2
F000E7A4: 90100018                 mov     %i0, %o0
F000E7A8: d2046010                 ld      [%l1+0x10], %o1
F000E7AC: 4000007f                 call    _fixjobc
F000E7B0: 94102000                 mov     0, %o2
F000E7B4: d0046010                 ld      [%l1+0x10], %o0
F000E7B8: 92822004                 addcc   %o0, 4, %o1
F000E7BC: 0280000c                 be      loc_F000E7EC
F000E7C0: 113c042c                 sethi   -0xFEF5000, %o0
F000E7C4: d0024000                 ld      [%o1], %o0
F000E7C8: 80a20018                 cmp     %o0, %i0
F000E7CC: 22bfffe6                 be,a    loc_F000E764
F000E7D0: d004600c                 ld      [%l1+0xC], %o0
F000E7D4: 400000d3                 call    _get_posix_proc
F000E7D8: d0522030                 ldsh    [%o0+0x30], %o0
F000E7DC: 9282200c                 addcc   %o0, 0xC, %o1
F000E7E0: 32bffffa                 bne,a   loc_F000E7C8
F000E7E4: d0024000                 ld      [%o1], %o0
F000E7E8: 113c042c                 sethi   -0xFEF5000, %o0! char *
F000E7EC: 40001a61                 call    _panic
F000E7F0: 901220e0                 bset    0xE0, %o0
F000E7F4: d2046010                 ld      [%l1+0x10], %o1
F000E7F8: d0026004                 ld      [%o1+4], %o0
F000E7FC: 80a22000                 cmp     %o0, 0
F000E800: 32800005                 bne,a   loc_F000E814
F000E804: e0246010                 st      %l0, [%l1+0x10]
F000E808: 4000002f                 call    _pgdelete
F000E80C: 90100009                 mov     %o1, %o0
F000E810: e0246010                 st      %l0, [%l1+0x10]
F000E814: d0042004                 ld      [%l0+4], %o0
F000E818: d024600c                 st      %o0, [%l1+0xC]
F000E81C: f0242004                 st      %i0, [%l0+4]
F000E820: d0046010                 ld      [%l1+0x10], %o0
F000E824: d002200c                 ld      [%o0+0xC], %o0
F000E828: d036202e                 sth     %o0, [%i0+0x2E]
F000E82C: 81c7e008                 ret
F000E830: 81e80000                 restore
