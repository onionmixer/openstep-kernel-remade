F009F5B0: 9de3bf98                 save    %sp, -0x68, %sp
F009F5B4: 113c04f790122270         set     _pmap_info, %o0
F009F5BC: d2022090                 ld      [%o0+0x90], %o1
F009F5C0: 153c04f7                 sethi   %hi(_garbage), %o2
F009F5C4: e002a218                 ld      [%o2+%lo(_garbage)], %l0
F009F5C8: 92026001                 inc     %o1
F009F5CC: 9412a218                 bset    %lo(_garbage), %o2
F009F5D0: 80a4000a                 cmp     %l0, %o2
F009F5D4: 02800009                 be      locret_F009F5F8
F009F5D8: d2222090                 st      %o1, [%o0+0x90]
F009F5DC: a210000a                 mov     %o2, %l1
F009F5E0: 40000ee8                 call    _garbage_collect
F009F5E4: 90100010                 mov     %l0, %o0
F009F5E8: e0040000                 ld      [%l0], %l0
F009F5EC: 80a40011                 cmp     %l0, %l1
F009F5F0: 12bffffc                 bne     loc_F009F5E0
F009F5F4: 01000000                 nop
F009F5F8: 81c7e008                 ret
F009F5FC: 81e80000                 restore
