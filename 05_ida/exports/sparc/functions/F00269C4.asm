F00269C4: 9de3bf88                 save    %sp, -0x78, %sp
F00269C8: 90100018                 mov     %i0, %o0
F00269CC: 92100019                 mov     %i1, %o1
F00269D0: b207bfe8                 add     %fp, var_18, %i1
F00269D4: 40000239                 call    _pn_get
F00269D8: 94100019                 mov     %i1, %o2
F00269DC: b0920000                 orcc    %o0, %g0, %i0
F00269E0: 12800009                 bne     locret_F0026A04
F00269E4: 90100019                 mov     %i1, %o0
F00269E8: 9210001a                 mov     %i2, %o1
F00269EC: 9410001b                 mov     %i3, %o2
F00269F0: 40000007                 call    _lookuppn
F00269F4: 9610001c                 mov     %i4, %o3
F00269F8: b0100008                 mov     %o0, %i0
F00269FC: 400002bb                 call    _pn_free
F0026A00: 90100019                 mov     %i1, %o0
F0026A04: 81c7e008                 ret
F0026A08: 81e80000                 restore
