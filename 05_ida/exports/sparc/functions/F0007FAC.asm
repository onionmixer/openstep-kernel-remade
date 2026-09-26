F0007FAC: 80920000                 tst     %o0
F0007FB0: 02800006                 be      locret_F0007FC8
F0007FB4: 92100000                 clr     %o1
F0007FB8: 92026001                 inc     %o1
F0007FBC: 808a2001                 btst    1, %o0
F0007FC0: 02bffffe                 be      loc_F0007FB8
F0007FC4: 91322001                 srl     %o0, 1, %o0
F0007FC8: 81c3e008                 retl
F0007FCC: 90100009                 mov     %o1, %o0
