F00BDEF0: 9de3bf90                 save    %sp, -0x70, %sp
F00BDEF4: f037bff0                 sth     %i0, [%fp+var_10]
F00BDEF8: f237bff2                 sth     %i1, [%fp+var_E]
F00BDEFC: f437bff4                 sth     %i2, [%fp+var_C]
F00BDF00: f637bff6                 sth     %i3, [%fp+var_A]
F00BDF04: 90102000                 mov     0, %o0
F00BDF08: 9207bff0                 add     %fp, var_10, %o1
F00BDF0C: 40009df6                 call    _sparcfbFillRect
F00BDF10: 9410001c                 mov     %i4, %o2
F00BDF14: 81c7e008                 ret
F00BDF18: 81e80000                 restore
