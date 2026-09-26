F002A1A8: 9de3bf80                 save    %sp, -0x80, %sp
F002A1AC: c023a05c                 clr     [%sp+0x80+var_24]
F002A1B0: 113c03d390122068         set     aInternetProtoc, %o0! "Internet Protocol"
F002A1B8: d023a060                 st      %o0, [%sp+0x80+var_20]
F002A1BC: 90102600                 mov     0x600, %o0
F002A1C0: d023a064                 st      %o0, [%sp+0x80+var_1C]
F002A1C4: 90102808                 mov     0x808, %o0
F002A1C8: d023a068                 st      %o0, [%sp+0x80+var_18]
F002A1CC: 11000004                 sethi   0x1000, %o0
F002A1D0: d023a06c                 st      %o0, [%sp+0x80+var_14]
F002A1D4: c023a070                 clr     [%sp+0x80+var_10]
F002A1D8: 90102000                 mov     0, %o0
F002A1DC: 153c00a8                 sethi   %hi(_looutput), %o2
F002A1E0: 173c00a8                 sethi   %hi(_logetbuf), %o3
F002A1E4: 193c00a8                 sethi   %hi(_locontrol), %o4
F002A1E8: 1b3c0430                 sethi   %hi(unk_F010C1E0), %o5
F002A1EC: 92102000                 mov     0, %o1
F002A1F0: 9412a0c4                 bset    %lo(_looutput), %o2
F002A1F4: 9612e0b0                 bset    %lo(_logetbuf), %o3
F002A1F8: 98132124                 bset    %lo(_locontrol), %o4
F002A1FC: 40000776                 call    _if_attach
F002A200: 9a1361e0                 bset    %lo(unk_F010C1E0), %o5
F002A204: 133c04d5                 sethi   %hi(_loifp), %o1
F002A208: d0226268                 st      %o0, [%o1+%lo(_loifp)]
F002A20C: 81c7e008                 ret
F002A210: 81e80000                 restore
