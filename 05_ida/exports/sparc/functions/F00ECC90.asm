F00ECC90: 9de3bf98                 save    %sp, -0x68, %sp
F00ECC94: 113c04bc96122048         set     unk_F012F048, %o3
F00ECC9C: 80a2e000                 cmp     %o3, 0
F00ECCA0: 0280001e                 be      loc_F00ECD18
F00ECCA4: 90063fff                 add     %i0, -1, %o0
F00ECCA8: 9332201f                 srl     %o0, 31, %o1
F00ECCAC: 90020009                 add     %o0, %o1, %o0
F00ECCB0: 913a2001                 sra     %o0, 1, %o0
F00ECCB4: 932a2001                 sll     %o0, 1, %o1
F00ECCB8: 92024008                 add     %o1, %o0, %o1
F00ECCBC: 992a6002                 sll     %o1, 2, %o4
F00ECCC0: d002c000                 ld      [%o3], %o0
F00ECCC4: 80a20018                 cmp     %o0, %i0
F00ECCC8: 32800011                 bne,a   loc_F00ECD0C
F00ECCCC: d602e014                 ld      [%o3+0x14], %o3
F00ECCD0: d402e004                 ld      [%o3+4], %o2
F00ECCD4: 912b2002                 sll     %o4, 2, %o0
F00ECCD8: 9002000c                 add     %o0, %o4, %o0
F00ECCDC: 932a2004                 sll     %o0, 4, %o1
F00ECCE0: 90020009                 add     %o0, %o1, %o0
F00ECCE4: 932a2008                 sll     %o0, 8, %o1
F00ECCE8: 90020009                 add     %o0, %o1, %o0
F00ECCEC: 932a2010                 sll     %o0, 16, %o1
F00ECCF0: 90020009                 add     %o0, %o1, %o0
F00ECCF4: 90200008                 neg     %o0
F00ECCF8: 913a2002                 sra     %o0, 2, %o0
F00ECCFC: d022e00c                 st      %o0, [%o3+0xC]
F00ECD00: d003000a                 ld      [%o4+%o2], %o0
F00ECD04: 10800008                 ba      locret_F00ECD24
F00ECD08: d022c000                 st      %o0, [%o3]
F00ECD0C: 80a2e000                 cmp     %o3, 0
F00ECD10: 32bfffed                 bne,a   loc_F00ECCC4
F00ECD14: d002c000                 ld      [%o3], %o0
F00ECD18: 90100018                 mov     %i0, %o0
F00ECD1C: 7fffff14                 call    sub_F00EC96C
F00ECD20: 92102001                 mov     1, %o1
F00ECD24: 81c7e008                 ret
F00ECD28: 81e80000                 restore
