F0093F28: 9de3bf80                 save    %sp, -0x80, %sp
F0093F2C: 9810001a                 mov     %i2, %o4
F0093F30: 9a10001b                 mov     %i3, %o5
F0093F34: 92102001                 mov     1, %o1
F0093F38: 80a76000                 cmp     %i5, 0
F0093F3C: 02800003                 be      loc_F0093F48
F0093F40: d407a05c                 ld      [%fp+arg_5C], %o2
F0093F44: 92102003                 mov     3, %o1
F0093F48: c023a05c                 clr     [%sp+0x80+var_24]
F0093F4C: f223a060                 st      %i1, [%sp+0x80+var_20]
F0093F50: 113c0449901223f0         set     unk_F01127F0, %o0
F0093F58: d023a064                 st      %o0, [%sp+0x80+var_1C]
F0093F5C: f823a068                 st      %i4, [%sp+0x80+var_18]
F0093F60: d423a06c                 st      %o2, [%sp+0x80+var_14]
F0093F64: 90100018                 mov     %i0, %o0
F0093F68: 94102002                 mov     2, %o2
F0093F6C: 7fffff00                 call    _vol_panel_request
F0093F70: 96102000                 mov     0, %o3
F0093F74: 81c7e008                 ret
F0093F78: 91e80008                 restore %g0, %o0, %o0
