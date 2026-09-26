F00A1818: 9de3bf90                 save    %sp, -0x70, %sp
F00A181C: 153c04f79412a270         set     _pmap_info, %o2
F00A1824: d202a0d0                 ld      [%o2+0xD0], %o1
F00A1828: f0060000                 ld      [%i0], %i0
F00A182C: 113c0447                 sethi   %hi(_page_size), %o0
F00A1830: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F00A1834: f227a048                 st      %i1, [%fp+arg_48]
F00A1838: e407a05c                 ld      [%fp+arg_5C], %l2
F00A183C: 92026001                 inc     %o1
F00A1840: 90023fff                 inc     -1, %o0
F00A1844: 808e4008                 btst    %o0, %i1
F00A1848: 02800005                 be      loc_F00A185C
F00A184C: d222a0d0                 st      %o1, [%o2+0xD0]
F00A1850: 113c0463                 sethi   %hi(aSetPteVaNotAli), %o0! "set_pte: va not aligned\n"
F00A1854: 7ffdce47                 call    _panic
F00A1858: 90122258                 bset    %lo(aSetPteVaNotAli), %o0! "set_pte: va not aligned\n"
F00A185C: d00e200d                 ldub    [%i0+0xD], %o0
F00A1860: 80a22003                 cmp     %o0, 3
F00A1864: 12800007                 bne     loc_F00A1880
F00A1868: 80a22002                 cmp     %o0, 2
F00A186C: d007a048                 ld      [%fp+arg_48], %o0
F00A1870: d2060000                 ld      [%i0], %o1
F00A1874: 9132200a                 srl     %o0, 10, %o0
F00A1878: 1080000a                 ba      loc_F00A18A0
F00A187C: 900a20fc                 and     %o0, 0xFC, %o0
F00A1880: 32800006                 bne,a   loc_F00A1898
F00A1884: d00fa048                 ldub    [%fp+arg_48], %o0
F00A1888: d017a048                 lduh    [%fp+arg_48], %o0
F00A188C: d2060000                 ld      [%i0], %o1
F00A1890: 10800004                 ba      loc_F00A18A0
F00A1894: 900a20fc                 and     %o0, 0xFC, %o0
F00A1898: d2060000                 ld      [%i0], %o1
F00A189C: 912a2002                 sll     %o0, 2, %o0
F00A18A0: b2024008                 add     %o1, %o0, %i1
F00A18A4: d00e200d                 ldub    [%i0+0xD], %o0
F00A18A8: 80a22003                 cmp     %o0, 3
F00A18AC: 12800006                 bne     loc_F00A18C4
F00A18B0: a0066004                 add     %i1, 4, %l0
F00A18B4: 113c04f7                 sethi   %hi(_pmap_info), %o0
F00A18B8: d0122270                 lduh    [%o0+%lo(_pmap_info)], %o0
F00A18BC: 912a2002                 sll     %o0, 2, %o0
F00A18C0: a0064008                 add     %i1, %o0, %l0
F00A18C4: d20e200f                 ldub    [%i0+0xF], %o1
F00A18C8: d0062008                 ld      [%i0+8], %o0
F00A18CC: 92026001                 inc     %o1
F00A18D0: 7ffffe60                 call    _get_context
F00A18D4: d22e200f                 stb     %o1, [%i0+0xF]
F00A18D8: a2100008                 mov     %o0, %l1
F00A18DC: 7ffff0de                 call    _check_pmap
F00A18E0: 90100018                 mov     %i0, %o0
F00A18E4: 900ee007                 and     %i3, 7, %o0
F00A18E8: 912a2002                 sll     %o0, 2, %o0
F00A18EC: 972ea008                 sll     %i2, 8, %o3
F00A18F0: 920f2001                 and     %i4, 1, %o1
F00A18F4: 9612c008                 bset    %o0, %o3
F00A18F8: 932a6007                 sll     %o1, 7, %o1
F00A18FC: 940f6001                 and     %i5, 1, %o2
F00A1900: 952aa006                 sll     %o2, 6, %o2
F00A1904: 9212400b                 bset    %o3, %o1
F00A1908: 900ca001                 and     %l2, 1, %o0
F00A190C: 9212400a                 bset    %o2, %o1
F00A1910: 912a2005                 sll     %o0, 5, %o0
F00A1914: 90120009                 bset    %o1, %o0
F00A1918: 90122002                 bset    2, %o0
F00A191C: 80a64010                 cmp     %i1, %l0
F00A1920: 1a800018                 bcc     locret_F00A1980
F00A1924: d027bff4                 st      %o0, [%fp+var_C]
F00A1928: 35000004                 sethi   0x1000, %i2
F00A192C: d007bff4                 ld      [%fp+var_C], %o0
F00A1930: d407a048                 ld      [%fp+arg_48], %o2
F00A1934: 92100019                 mov     %i1, %o1
F00A1938: d60e200d                 ldub    [%i0+0xD], %o3
F00A193C: 7fffcf93                 call    _mmu_writepte
F00A1940: 98100011                 mov     %l1, %o4
F00A1944: d00e200d                 ldub    [%i0+0xD], %o0
F00A1948: 80a22003                 cmp     %o0, 3
F00A194C: 12800005                 bne     loc_F00A1960
F00A1950: b2066004                 inc     4, %i1
F00A1954: d007a048                 ld      [%fp+arg_48], %o0
F00A1958: 9002001a                 add     %o0, %i2, %o0
F00A195C: d027a048                 st      %o0, [%fp+arg_48]
F00A1960: d007bff4                 ld      [%fp+var_C], %o0
F00A1964: 80a64010                 cmp     %i1, %l0
F00A1968: 920a20ff                 and     %o0, 0xFF, %o1
F00A196C: 900a3f00                 and     %o0, -0x100, %o0
F00A1970: 90022100                 inc     0x100, %o0
F00A1974: 92124008                 bset    %o0, %o1
F00A1978: 0abfffed                 bcs     loc_F00A192C
F00A197C: d227bff4                 st      %o1, [%fp+var_C]
F00A1980: 81c7e008                 ret
F00A1984: 81e80000                 restore
