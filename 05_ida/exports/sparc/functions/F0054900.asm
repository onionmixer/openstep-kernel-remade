F0054900: 9de3bf98                 save    %sp, -0x68, %sp
F0054904: e2062018                 ld      [%i0+0x18], %l1
F0054908: 91366006                 srl     %i1, 6, %o0
F005490C: e0062014                 ld      [%i0+0x14], %l0
F0054910: 7ffec7e4                 call    _urem
F0054914: 92100011                 mov     %l1, %o1
F0054918: 10800005                 ba      loc_F005492C
F005491C: b2100008                 mov     %o0, %i1
F0054920: 80a64011                 cmp     %i1, %l1
F0054924: 22800002                 be,a    loc_F005492C
F0054928: b2102000                 mov     0, %i1
F005492C: 912e6004                 sll     %i1, 4, %o0
F0054930: 90040008                 add     %l0, %o0, %o0
F0054934: d002200c                 ld      [%o0+0xC], %o0
F0054938: 80a2001a                 cmp     %o0, %i2
F005493C: 32bffff9                 bne,a   loc_F0054920
F0054940: b2066001                 inc     %i1
F0054944: 80a6a000                 cmp     %i2, 0
F0054948: 02800025                 be      locret_F00549DC
F005494C: b0100019                 mov     %i1, %i0
F0054950: b0062001                 inc     %i0
F0054954: 80a60011                 cmp     %i0, %l1
F0054958: 22800002                 be,a    loc_F0054960
F005495C: b0102000                 mov     0, %i0
F0054960: 912e2004                 sll     %i0, 4, %o0
F0054964: 90040008                 add     %l0, %o0, %o0
F0054968: f402200c                 ld      [%o0+0xC], %i2
F005496C: 80a6a000                 cmp     %i2, 0
F0054970: 02800015                 be      loc_F00549C4
F0054974: 912ea004                 sll     %i2, 4, %o0
F0054978: 90040008                 add     %l0, %o0, %o0
F005497C: d0022004                 ld      [%o0+4], %o0
F0054980: 92100011                 mov     %l1, %o1
F0054984: 7ffec7c7                 call    _urem
F0054988: 91322006                 srl     %o0, 6, %o0
F005498C: 80a60019                 cmp     %i0, %i1
F0054990: 1a800009                 bcc     loc_F00549B4
F0054994: 80a60008                 cmp     %i0, %o0
F0054998: 3abfffef                 bcc,a   loc_F0054954
F005499C: b0062001                 inc     %i0
F00549A0: 80a20019                 cmp     %o0, %i1
F00549A4: 08800009                 bleu    loc_F00549C8
F00549A8: 912e6004                 sll     %i1, 4, %o0
F00549AC: 10bfffea                 ba      loc_F0054954
F00549B0: b0062001                 inc     %i0
F00549B4: 0a800004                 bcs     loc_F00549C4
F00549B8: 80a20019                 cmp     %o0, %i1
F00549BC: 38bfffe6                 bgu,a   loc_F0054954
F00549C0: b0062001                 inc     %i0
F00549C4: 912e6004                 sll     %i1, 4, %o0
F00549C8: 90040008                 add     %l0, %o0, %o0
F00549CC: f422200c                 st      %i2, [%o0+0xC]
F00549D0: 80a6a000                 cmp     %i2, 0
F00549D4: 12bfffdf                 bne     loc_F0054950
F00549D8: b2100018                 mov     %i0, %i1
F00549DC: 81c7e008                 ret
F00549E0: 81e80000                 restore
