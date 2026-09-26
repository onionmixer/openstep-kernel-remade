F00AEFBC: 9de3bf98                 save    %sp, -0x68, %sp
F00AEFC0: 400000f0                 call    _prom_mayget
F00AEFC4: 01000000                 nop
F00AEFC8: 80a23fff                 cmp     %o0, -1
F00AEFCC: 02bffffd                 be      loc_F00AEFC0
F00AEFD0: b00a20ff                 and     %o0, 0xFF, %i0
F00AEFD4: 81c7e008                 ret
F00AEFD8: 81e80000                 restore
