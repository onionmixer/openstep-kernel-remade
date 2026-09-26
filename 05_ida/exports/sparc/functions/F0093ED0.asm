F0093ED0: 9de3bf80                 save    %sp, -0x80, %sp
F0093ED4: d407a05c                 ld      [%fp+arg_5C], %o2
F0093ED8: 90100018                 mov     %i0, %o0
F0093EDC: 133c0449921263e0         set     unk_F01127E0, %o1
F0093EE4: 80a0001d                 cmp     %g0, %i5
F0093EE8: 96100019                 mov     %i1, %o3
F0093EEC: 9810001a                 mov     %i2, %o4
F0093EF0: 9a10001b                 mov     %i3, %o5
F0093EF4: c023a05c                 clr     [%sp+0x80+var_24]
F0093EF8: d223a060                 st      %o1, [%sp+0x80+var_20]
F0093EFC: 133c0449921263e8         set     unk_F01127E8, %o1
F0093F04: d223a064                 st      %o1, [%sp+0x80+var_1C]
F0093F08: f823a068                 st      %i4, [%sp+0x80+var_18]
F0093F0C: d423a06c                 st      %o2, [%sp+0x80+var_14]
F0093F10: 92602000                 subc    %g0, 0, %o1
F0093F14: 920a6002                 and     %o1, 2, %o1
F0093F18: 7fffff15                 call    _vol_panel_request
F0093F1C: 94102002                 mov     2, %o2
F0093F20: 81c7e008                 ret
F0093F24: 91e80008                 restore %g0, %o0, %o0
