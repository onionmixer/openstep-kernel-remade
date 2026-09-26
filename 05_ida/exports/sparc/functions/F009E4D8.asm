F009E4D8: 9de3bf90                 save    %sp, -0x70, %sp
F009E4DC: 9410001a                 mov     %i2, %o2
F009E4E0: 9810001b                 mov     %i3, %o4
F009E4E4: 133c04f792126270         set     _pmap_info, %o1
F009E4EC: d0026064                 ld      [%o1+0x64], %o0
F009E4F0: 80a76002                 cmp     %i5, 2
F009E4F4: 90022001                 inc     %o0
F009E4F8: 12800008                 bne     loc_F009E518
F009E4FC: d0226064                 st      %o0, [%o1+0x64]
F009E500: f823a05c                 st      %i4, [%sp+0x70+var_14]
F009E504: 90100018                 mov     %i0, %o0
F009E508: 92100019                 mov     %i1, %o1
F009E50C: 96102000                 mov     0, %o3
F009E510: 10800007                 ba      loc_F009E52C
F009E514: 9a102000                 mov     0, %o5
F009E518: f823a05c                 st      %i4, [%sp+0x70+var_14]
F009E51C: 90100018                 mov     %i0, %o0
F009E520: 92100019                 mov     %i1, %o1
F009E524: 96102000                 mov     0, %o3
F009E528: 9a102001                 mov     1, %o5
F009E52C: 7ffffe83                 call    _pmap_enter_dev
F009E530: 01000000                 nop
F009E534: 81c7e008                 ret
F009E538: 81e80000                 restore
