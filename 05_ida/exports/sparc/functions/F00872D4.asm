F00872D4: 9de3bf98                 save    %sp, -0x68, %sp
F00872D8: e0060000                 ld      [%i0], %l0
F00872DC: 7ffffd31                 call    _vm_object_allocate
F00872E0: 9010001a                 mov     %i2, %o0
F00872E4: b4920000                 orcc    %o0, %g0, %i2
F00872E8: 32800006                 bne,a   loc_F0087300
F00872EC: e026a020                 st      %l0, [%i2+0x20]
F00872F0: 113c0447                 sethi   %hi(aVmObjectShadow), %o0! "vm_object_shadow: no object for shadowi"...
F00872F4: 7ffe379f                 call    _panic
F00872F8: 90122020                 bset    %lo(aVmObjectShadow), %o0! "vm_object_shadow: no object for shadowi"...
F00872FC: e026a020                 st      %l0, [%i2+0x20]
F0087300: d0064000                 ld      [%i1], %o0
F0087304: d026a024                 st      %o0, [%i2+0x24]
F0087308: c0264000                 clr     [%i1]
F008730C: f4260000                 st      %i2, [%i0]
F0087310: 81c7e008                 ret
F0087314: 81e80000                 restore
