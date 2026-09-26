F009EBC4: 9de3bf98                 save    %sp, -0x68, %sp
F009EBC8: 133c04f792126270         set     _pmap_info, %o1
F009EBD0: d0026078                 ld      [%o1+0x78], %o0
F009EBD4: 80a66005                 cmp     %i1, 5
F009EBD8: 90022001                 inc     %o0
F009EBDC: 0280000c                 be      loc_F009EC0C
F009EBE0: d0226078                 st      %o0, [%o1+0x78]
F009EBE4: 80a66005                 cmp     %i1, 5
F009EBE8: 14800006                 bg      loc_F009EC00
F009EBEC: 80a66007                 cmp     %i1, 7
F009EBF0: 80a66001                 cmp     %i1, 1
F009EBF4: 02800006                 be      loc_F009EC0C
F009EBF8: 01000000                 nop
F009EBFC: 30800007                 ba,a    loc_F009EC18
F009EC00: 02800008                 be      locret_F009EC20
F009EC04: 01000000                 nop
F009EC08: 30800004                 ba,a    loc_F009EC18
F009EC0C: 7ffffe6b                 call    _pmap_copy_on_write
F009EC10: 90100018                 mov     %i0, %o0
F009EC14: 30800003                 ba,a    locret_F009EC20
F009EC18: 7ffffaf8                 call    _pmap_remove_all
F009EC1C: 90100018                 mov     %i0, %o0
F009EC20: 81c7e008                 ret
F009EC24: 81e80000                 restore
