F00306F0: 9de3bf90                 save    %sp, -0x70, %sp
F00306F4: e406201c                 ld      [%i0+0x1C], %l2
F00306F8: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F00306FC: d0022070                 ld      [%o0+%lo(_in_ifaddr)], %o0
F0030700: a0102000                 mov     0, %l0
F0030704: 80a22000                 cmp     %o0, 0
F0030708: 0280001e                 be      loc_F0030780
F003070C: e2062008                 ld      [%i0+8], %l1
F0030710: d0162018                 lduh    [%i0+0x18], %o0
F0030714: 80a22000                 cmp     %o0, 0
F0030718: 32800071                 bne,a   locret_F00308DC
F003071C: b0102016                 mov     0x16, %i0
F0030720: d0062014                 ld      [%i0+0x14], %o0
F0030724: 80a22000                 cmp     %o0, 0
F0030728: 3280006d                 bne,a   locret_F00308DC
F003072C: b0102016                 mov     0x16, %i0
F0030730: 80a66000                 cmp     %i1, 0
F0030734: 02800048                 be      loc_F0030854
F0030738: 80a42000                 cmp     %l0, 0
F003073C: d0166008                 lduh    [%i1+8], %o0
F0030740: d2066004                 ld      [%i1+4], %o1
F0030744: 80a22010                 cmp     %o0, 0x10
F0030748: 02800004                 be      loc_F0030758
F003074C: b2064009                 add     %i1, %o1, %i1
F0030750: 10800063                 ba      locret_F00308DC
F0030754: b0102016                 mov     0x16, %i0
F0030758: d0066004                 ld      [%i1+4], %o0
F003075C: 80a22000                 cmp     %o0, 0
F0030760: 0280000a                 be      loc_F0030788
F0030764: 90100019                 mov     %i1, %o0
F0030768: e0166002                 lduh    [%i1+2], %l0
F003076C: 7fffe457                 call    _ifa_ifwithaddr
F0030770: c0366002                 clrh    [%i1+2]
F0030774: 80a22000                 cmp     %o0, 0
F0030778: 32800004                 bne,a   loc_F0030788
F003077C: e0366002                 sth     %l0, [%i1+2]
F0030780: 10800057                 ba      locret_F00308DC
F0030784: b0102031                 mov     0x31, %i0 ! '1'
F0030788: e0166002                 lduh    [%i1+2], %l0
F003078C: 90940000                 orcc    %l0, %g0, %o0
F0030790: 0280002e                 be      loc_F0030848
F0030794: 80a223ff                 cmp     %o0, 0x3FF
F0030798: 1880000f                 bgu     loc_F00307D4
F003079C: 86102000                 mov     0, %g3
F00307A0: 113c04cf                 sethi   %hi(_active_u), %o0
F00307A4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00307A8: d002201c                 ld      [%o0+0x1C], %o0
F00307AC: d0522002                 ldsh    [%o0+2], %o0
F00307B0: 80a22000                 cmp     %o0, 0
F00307B4: 22800009                 be,a    loc_F00307D8
F00307B8: d214a002                 lduh    [%l2+2], %o1
F00307BC: d014a006                 lduh    [%l2+6], %o0
F00307C0: 808a2080                 btst    0x80, %o0
F00307C4: 32800005                 bne,a   loc_F00307D8
F00307C8: d214a002                 lduh    [%l2+2], %o1
F00307CC: 10800044                 ba      locret_F00308DC
F00307D0: b010200d                 mov     0xD, %i0
F00307D4: d214a002                 lduh    [%l2+2], %o1
F00307D8: 808a6004                 btst    4, %o1
F00307DC: 1280000b                 bne     loc_F0030808
F00307E0: 90100011                 mov     %l1, %o0
F00307E4: d004a00c                 ld      [%l2+0xC], %o0
F00307E8: d012200a                 lduh    [%o0+0xA], %o0
F00307EC: 808a2004                 btst    4, %o0
F00307F0: 02800004                 be      loc_F0030800
F00307F4: 808a6002                 btst    2, %o1
F00307F8: 12800004                 bne     loc_F0030808
F00307FC: 90100011                 mov     %l1, %o0
F0030800: 86102001                 mov     1, %g3
F0030804: 90100011                 mov     %l1, %o0
F0030808: 9207bff4                 add     %fp, var_C, %o1
F003080C: 94102000                 mov     0, %o2
F0030810: 193c04d9                 sethi   %hi(_zeroin_addr), %o4
F0030814: da032150                 ld      [%o4+%lo(_zeroin_addr)], %o5
F0030818: 9607bff0                 add     %fp, var_10, %o3
F003081C: 98100010                 mov     %l0, %o4
F0030820: da27bff4                 st      %o5, [%fp+var_C]
F0030824: c4066004                 ld      [%i1+4], %g2
F0030828: 9a100003                 mov     %g3, %o5
F003082C: 400001c7                 call    _in_pcblookup
F0030830: c427bff0                 st      %g2, [%fp+var_10]
F0030834: 80a22000                 cmp     %o0, 0
F0030838: 22800005                 be,a    loc_F003084C
F003083C: d0066004                 ld      [%i1+4], %o0
F0030840: 10800027                 ba      locret_F00308DC
F0030844: b0102030                 mov     0x30, %i0 ! '0'
F0030848: d0066004                 ld      [%i1+4], %o0
F003084C: d0262014                 st      %o0, [%i0+0x14]
F0030850: 80a42000                 cmp     %l0, 0
F0030854: 32800021                 bne,a   loc_F00308D8
F0030858: e0362018                 sth     %l0, [%i0+0x18]
F003085C: 11000004a6122388         set     0x1388, %l3
F0030864: b2102a00                 mov     0xA00, %i1
F0030868: 253c04d9                 sethi   -0xFEC9C00, %l2
F003086C: d0146018                 lduh    [%l1+0x18], %o0
F0030870: 92022001                 add     %o0, 1, %o1
F0030874: 80a229ff                 cmp     %o0, 0x9FF
F0030878: 08800007                 bleu    loc_F0030894
F003087C: d2346018                 sth     %o1, [%l1+0x18]
F0030880: 912a6010                 sll     %o1, 16, %o0
F0030884: 91322010                 srl     %o0, 16, %o0
F0030888: 80a20013                 cmp     %o0, %l3
F003088C: 08800004                 bleu    loc_F003089C
F0030890: 90100011                 mov     %l1, %o0
F0030894: f2346018                 sth     %i1, [%l1+0x18]
F0030898: 90100011                 mov     %l1, %o0
F003089C: 9207bff0                 add     %fp, var_10, %o1
F00308A0: 94102000                 mov     0, %o2
F00308A4: e0146018                 lduh    [%l1+0x18], %l0
F00308A8: 9607bff4                 add     %fp, var_C, %o3
F00308AC: d804a150                 ld      [%l2+0x150], %o4
F00308B0: 9a102000                 mov     0, %o5
F00308B4: d827bff0                 st      %o4, [%fp+var_10]
F00308B8: c4062014                 ld      [%i0+0x14], %g2
F00308BC: 98100010                 mov     %l0, %o4
F00308C0: 400001a2                 call    _in_pcblookup
F00308C4: c427bff4                 st      %g2, [%fp+var_C]
F00308C8: 80a22000                 cmp     %o0, 0
F00308CC: 32bfffe9                 bne,a   loc_F0030870
F00308D0: d0146018                 lduh    [%l1+0x18], %o0
F00308D4: e0362018                 sth     %l0, [%i0+0x18]
F00308D8: b0102000                 mov     0, %i0
F00308DC: 81c7e008                 ret
F00308E0: 81e80000                 restore
