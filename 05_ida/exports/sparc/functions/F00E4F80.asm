F00E4F80: 9de3bf90                 save    %sp, -0x70, %sp
F00E4F84: 90100018                 mov     %i0, %o0
F00E4F88: 7fff2815                 call    _prom_getproplen
F00E4F8C: 92100019                 mov     %i1, %o1
F00E4F90: 80a22000                 cmp     %o0, 0
F00E4F94: 2280000e                 be,a    locret_F00E4FCC
F00E4F98: b0102001                 mov     1, %i0
F00E4F9C: 0480000b                 ble     loc_F00E4FC8
F00E4FA0: 80a22004                 cmp     %o0, 4
F00E4FA4: 02800004                 be      loc_F00E4FB4
F00E4FA8: 90100018                 mov     %i0, %o0
F00E4FAC: 10800008                 ba      locret_F00E4FCC
F00E4FB0: b010001a                 mov     %i2, %i0
F00E4FB4: 92100019                 mov     %i1, %o1
F00E4FB8: 7fff2813                 call    _prom_getprop
F00E4FBC: 9407bff4                 add     %fp, var_C, %o2
F00E4FC0: 10800003                 ba      locret_F00E4FCC
F00E4FC4: f007bff4                 ld      [%fp+var_C], %i0
F00E4FC8: b010001a                 mov     %i2, %i0
F00E4FCC: 81c7e008                 ret
F00E4FD0: 81e80000                 restore
