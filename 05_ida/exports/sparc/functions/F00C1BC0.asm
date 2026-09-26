F00C1BC0: 9de3bf90                 save    %sp, -0x70, %sp
F00C1BC4: 90102016                 mov     0x16, %o0
F00C1BC8: 213c02eca01421bc         set     _zsintr, %l0
F00C1BD0: 7fff5d59                 call    _remintr
F00C1BD4: 92100010                 mov     %l0, %o1
F00C1BD8: e0268000                 st      %l0, [%i2]
F00C1BDC: 90102016                 mov     0x16, %o0
F00C1BE0: d026c000                 st      %o0, [%i3]
F00C1BE4: f0270000                 st      %i0, [%i4]
F00C1BE8: 81c7e008                 ret
F00C1BEC: 91e82001                 restore %g0, 1, %o0
