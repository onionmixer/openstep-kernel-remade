F009E4AC: 9de3bf90                 save    %sp, -0x70, %sp
F009E4B0: f823a05c                 st      %i4, [%sp+0x70+var_14]
F009E4B4: 90100018                 mov     %i0, %o0
F009E4B8: 92100019                 mov     %i1, %o1
F009E4BC: 9410001a                 mov     %i2, %o2
F009E4C0: 96102000                 mov     0, %o3
F009E4C4: 9810001b                 mov     %i3, %o4
F009E4C8: 7ffffe9c                 call    _pmap_enter_dev
F009E4CC: 9a102001                 mov     1, %o5
F009E4D0: 81c7e008                 ret
F009E4D4: 81e80000                 restore
