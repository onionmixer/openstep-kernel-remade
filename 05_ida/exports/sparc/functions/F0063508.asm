F0063508: 9de3bf90                 save    %sp, -0x70, %sp
F006350C: 80a62000                 cmp     %i0, 0
F0063510: 02800014                 be      loc_F0063560
F0063514: 90100018                 mov     %i0, %o0
F0063518: 92100019                 mov     %i1, %o1
F006351C: 7fffe158                 call    _ipc_right_lookup_write
F0063520: 9407bff4                 add     %fp, var_C, %o2
F0063524: 80a22000                 cmp     %o0, 0
F0063528: 02800004                 be      loc_F0063538
F006352C: d407bff4                 ld      [%fp+var_C], %o2
F0063530: 1080000d                 ba      locret_F0063564
F0063534: b0100008                 mov     %o0, %i0
F0063538: d2028000                 ld      [%o2], %o1
F006353C: 11000200                 sethi   0x80000, %o0
F0063540: 808a4008                 btst    %o0, %o1
F0063544: 02800006                 be      loc_F006355C
F0063548: 90100018                 mov     %i0, %o0
F006354C: 7fffe31b                 call    _ipc_right_destroy
F0063550: 92100019                 mov     %i1, %o1
F0063554: 10800004                 ba      locret_F0063564
F0063558: b0100008                 mov     %o0, %i0
F006355C: c0262008                 clr     [%i0+8]
F0063560: b0102004                 mov     4, %i0
F0063564: 81c7e008                 ret
F0063568: 81e80000                 restore
