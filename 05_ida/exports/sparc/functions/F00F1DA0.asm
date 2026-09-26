F00F1DA0: 9de3bf98                 save    %sp, -0x68, %sp
F00F1DA4: d0062020                 ld      [%i0+0x20], %o0
F00F1DA8: 80a22000                 cmp     %o0, 0
F00F1DAC: 32800008                 bne,a   loc_F00F1DCC
F00F1DB0: d2060000                 ld      [%i0], %o1
F00F1DB4: 113c03e890122354         set     _emptyCache, %o0
F00F1DBC: d0262020                 st      %o0, [%i0+0x20]
F00F1DC0: 90102001                 mov     1, %o0
F00F1DC4: d0262010                 st      %o0, [%i0+0x10]
F00F1DC8: d2060000                 ld      [%i0], %o1
F00F1DCC: d0026020                 ld      [%o1+0x20], %o0
F00F1DD0: 80a22000                 cmp     %o0, 0
F00F1DD4: 12800009                 bne     loc_F00F1DF8
F00F1DD8: 113c04bc                 sethi   -0xFED1000, %o0
F00F1DDC: 113c03e890122354         set     _emptyCache, %o0
F00F1DE4: d0226020                 st      %o0, [%o1+0x20]
F00F1DE8: d2060000                 ld      [%i0], %o1! data
F00F1DEC: 90102002                 mov     2, %o0
F00F1DF0: d0226010                 st      %o0, [%o1+0x10]
F00F1DF4: 113c04bc                 sethi   -0xFED1000, %o0
F00F1DF8: d002212c                 ld      [%o0+0x12C], %o0! table
F00F1DFC: 7fffee9f                 call    _NXHashInsert
F00F1E00: 92100018                 mov     %i0, %o1
F00F1E04: 81c7e008                 ret
F00F1E08: 81e80000                 restore
