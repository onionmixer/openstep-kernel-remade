F00994C4: 9de3bf90                 save    %sp, -0x70, %sp
F00994C8: 90100019                 mov     %i1, %o0
F00994CC: 40000103                 call    _iom_ptefind
F00994D0: 9210001b                 mov     %i3, %o1
F00994D4: b2920000                 orcc    %o0, %g0, %i1
F00994D8: 32800006                 bne,a   loc_F00994F0
F00994DC: d0060000                 ld      [%i0], %o0
F00994E0: 113c045b                 sethi   %hi(aBpIomMapBadIop), %o0! "bp_iom_map: bad iopfn"
F00994E4: 7ffdef23                 call    _panic
F00994E8: 90122380                 bset    %lo(aBpIomMapBadIop), %o0! "bp_iom_map: bad iopfn"
F00994EC: d0060000                 ld      [%i0], %o0
F00994F0: 808a2010                 btst    0x10, %o0
F00994F4: 02800007                 be      loc_F0099510
F00994F8: 113c04f0                 sethi   -0xFEC4000, %o0
F00994FC: d006202c                 ld      [%i0+0x2C], %o0
F0099500: d0022068                 ld      [%o0+0x68], %o0
F0099504: d002200c                 ld      [%o0+0xC], %o0
F0099508: 10800003                 ba      loc_F0099514
F009950C: e2022024                 ld      [%o0+0x24], %l1
F0099510: e2022100                 ld      [%o0+0x100], %l1
F0099514: d0062020                 ld      [%i0+0x20], %o0
F0099518: b607bff4                 add     %fp, var_C, %i3
F009951C: d2062014                 ld      [%i0+0x14], %o1
F0099520: 940a2fff                 and     %o0, 0xFFF, %o2
F0099524: 9202400a                 add     %o1, %o2, %o1
F0099528: 92026fff                 inc     0xFFF, %o1
F009952C: b132600c                 srl     %o1, 12, %i0
F0099530: 80a62000                 cmp     %i0, 0
F0099534: 0480002d                 ble     loc_F00995E8
F0099538: a0100008                 mov     %o0, %l0
F009953C: 2d3c0464                 sethi   -0xFEE7000, %l6
F0099540: 2b3c0464                 sethi   -0xFEE7000, %l5
F0099544: 113c044aa8122264         set     _mod_info, %l4
F009954C: 273c045b                 sethi   -0xFEE9400, %l3
F0099550: 25000004                 sethi   0x1000, %l2
F0099554: 90100011                 mov     %l1, %o0
F0099558: 92100010                 mov     %l0, %o1
F009955C: 40000ecf                 call    _pmap_getpte
F0099560: 9410001b                 mov     %i3, %o2
F0099564: d206c000                 ld      [%i3], %o1
F0099568: d005a330                 ld      [%l6+0x330], %o0
F009956C: 80a22000                 cmp     %o0, 0
F0099570: 12800004                 bne     loc_F0099580
F0099574: d2264000                 st      %o1, [%i1]
F0099578: 900a7f7f                 and     %o1, -0x81, %o0
F009957C: d0264000                 st      %o0, [%i1]
F0099580: d0056334                 ld      [%l5+0x334], %o0
F0099584: 80a22000                 cmp     %o0, 0
F0099588: 22800014                 be,a    loc_F00995D8
F009958C: b0063fff                 inc     -1, %i0
F0099590: d0052034                 ld      [%l4+0x34], %o0
F0099594: 80a22000                 cmp     %o0, 0
F0099598: 02800005                 be      loc_F00995AC
F009959C: d004e378                 ld      [%l3+0x378], %o0
F00995A0: 80a22000                 cmp     %o0, 0
F00995A4: 2280000d                 be,a    loc_F00995D8
F00995A8: b0063fff                 inc     -1, %i0
F00995AC: d0064000                 ld      [%i1], %o0
F00995B0: 808a2080                 btst    0x80, %o0
F00995B4: 22800009                 be,a    loc_F00995D8
F00995B8: b0063fff                 inc     -1, %i0
F00995BC: d006c000                 ld      [%i3], %o0
F00995C0: 40001f3c                 call    _pmap_vacflush
F00995C4: 91322008                 srl     %o0, 8, %o0
F00995C8: d0064000                 ld      [%i1], %o0
F00995CC: 900a3f7f                 and     %o0, -0x81, %o0
F00995D0: d0264000                 st      %o0, [%i1]
F00995D4: b0063fff                 inc     -1, %i0
F00995D8: b2066004                 inc     4, %i1
F00995DC: 80a62000                 cmp     %i0, 0
F00995E0: 14bfffdd                 bg      loc_F0099554
F00995E4: a0040012                 add     %l0, %l2, %l0
F00995E8: c0264000                 clr     [%i1]
F00995EC: 81c7e008                 ret
F00995F0: 81e80000                 restore
