F00B2BAC: 9de3bf98                 save    %sp, -0x68, %sp
F00B2BB0: c02e8000                 clrb    [%i2]
F00B2BB4: 90100018                 mov     %i0, %o0
F00B2BB8: 133c047792126198         set     aName_2, %o1! "name"
F00B2BC0: 7ffff111                 call    _prom_getprop
F00B2BC4: 9410001a                 mov     %i2, %o2
F00B2BC8: 9010001a                 mov     %i2, %o0! __s1
F00B2BCC: 7ffd5578                 call    _strcmp
F00B2BD0: 92100019                 mov     %i1, %o1
F00B2BD4: 80a22000                 cmp     %o0, 0
F00B2BD8: 02800017                 be      locret_F00B2C34
F00B2BDC: 01000000                 nop
F00B2BE0: 7ffff226                 call    _prom_nextnode
F00B2BE4: 90100018                 mov     %i0, %o0
F00B2BE8: 80a22000                 cmp     %o0, 0
F00B2BEC: 02800007                 be      loc_F00B2C08
F00B2BF0: 92100019                 mov     %i1, %o1
F00B2BF4: 7fffffee                 call    _searchpromtree
F00B2BF8: 9410001a                 mov     %i2, %o2
F00B2BFC: 80a22000                 cmp     %o0, 0
F00B2C00: 3280000d                 bne,a   locret_F00B2C34
F00B2C04: b0100008                 mov     %o0, %i0
F00B2C08: 7ffff225                 call    _prom_childnode
F00B2C0C: 90100018                 mov     %i0, %o0
F00B2C10: 80a22000                 cmp     %o0, 0
F00B2C14: 02800007                 be      loc_F00B2C30
F00B2C18: 92100019                 mov     %i1, %o1
F00B2C1C: 7fffffe4                 call    _searchpromtree
F00B2C20: 9410001a                 mov     %i2, %o2
F00B2C24: 80a22000                 cmp     %o0, 0
F00B2C28: 12800003                 bne     locret_F00B2C34
F00B2C2C: b0100008                 mov     %o0, %i0
F00B2C30: b0102000                 mov     0, %i0
F00B2C34: 81c7e008                 ret
F00B2C38: 81e80000                 restore
