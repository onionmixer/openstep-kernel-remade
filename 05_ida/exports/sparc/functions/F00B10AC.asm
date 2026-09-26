F00B10AC: 9de3bf90                 save    %sp, -0x70, %sp
F00B10B0: 90100018                 mov     %i0, %o0
F00B10B4: 40000013                 call    _getproplen
F00B10B8: 92100019                 mov     %i1, %o1
F00B10BC: 80a22000                 cmp     %o0, 0
F00B10C0: 2280000e                 be,a    locret_F00B10F8
F00B10C4: b0102001                 mov     1, %i0
F00B10C8: 0480000b                 ble     loc_F00B10F4
F00B10CC: 80a22004                 cmp     %o0, 4
F00B10D0: 02800004                 be      loc_F00B10E0
F00B10D4: 90100018                 mov     %i0, %o0
F00B10D8: 10800008                 ba      locret_F00B10F8
F00B10DC: b010001a                 mov     %i2, %i0
F00B10E0: 92100019                 mov     %i1, %o1
F00B10E4: 7ffff7c8                 call    _prom_getprop
F00B10E8: 9407bff4                 add     %fp, var_C, %o2
F00B10EC: 10800003                 ba      locret_F00B10F8
F00B10F0: f007bff4                 ld      [%fp+var_C], %i0
F00B10F4: b010001a                 mov     %i2, %i0
F00B10F8: 81c7e008                 ret
F00B10FC: 81e80000                 restore
