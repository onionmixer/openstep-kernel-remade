F002FEB4: 9de3bf78                 save    %sp, -0x88, %sp
F002FEB8: f227bff0                 st      %i1, [%fp+var_10]
F002FEBC: f427bff4                 st      %i2, [%fp+var_C]
F002FEC0: 9007bff0                 add     %fp, var_10, %o0
F002FEC4: d027bfd8                 st      %o0, [%fp+var_28]
F002FEC8: 90102001                 mov     1, %o0
F002FECC: d027bfdc                 st      %o0, [%fp+var_24]
F002FED0: d027bfe4                 st      %o0, [%fp+var_1C]
F002FED4: c027bfe0                 clr     [%fp+var_20]
F002FED8: f427bfec                 st      %i2, [%fp+var_14]
F002FEDC: 90100018                 mov     %i0, %o0
F002FEE0: 92102000                 mov     0, %o1
F002FEE4: 9407bfd8                 add     %fp, var_28, %o2
F002FEE8: 96102000                 mov     0, %o3
F002FEEC: 7fffbc76                 call    _soreceive
F002FEF0: 98102000                 mov     0, %o4
F002FEF4: 81c7e008                 ret
F002FEF8: 91e80008                 restore %g0, %o0, %o0
