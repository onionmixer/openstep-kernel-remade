F002E634: 9de3bf90                 save    %sp, -0x70, %sp
F002E638: d2062004                 ld      [%i0+4], %o1
F002E63C: 9007bff4                 add     %fp, var_C, %o0
F002E640: 40000045                 call    _in_netof
F002E644: d227bff4                 st      %o1, [%fp+var_C]
F002E648: 80a22000                 cmp     %o0, 0
F002E64C: 02800008                 be      loc_F002E66C
F002E650: 808a20ff                 btst    0xFF, %o0
F002E654: 32800007                 bne,a   loc_F002E670
F002E658: d0266004                 st      %o0, [%i1+4]
F002E65C: 91322008                 srl     %o0, 8, %o0
F002E660: 808a20ff                 btst    0xFF, %o0
F002E664: 22bfffff                 be,a    loc_F002E660
F002E668: 91322008                 srl     %o0, 8, %o0
F002E66C: d0266004                 st      %o0, [%i1+4]
F002E670: d0062004                 ld      [%i0+4], %o0
F002E674: d0264000                 st      %o0, [%i1]
F002E678: 81c7e008                 ret
F002E67C: 81e80000                 restore
