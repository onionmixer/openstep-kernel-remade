F0063294: 9de3bf90                 save    %sp, -0x70, %sp
F0063298: 90960000                 orcc    %i0, %g0, %o0
F006329C: 12800004                 bne     loc_F00632AC
F00632A0: 92100019                 mov     %i1, %o1
F00632A4: 10800021                 ba      locret_F0063328
F00632A8: b0102004                 mov     4, %i0
F00632AC: 80a6bfff                 cmp     %i2, -1
F00632B0: 12800004                 bne     loc_F00632C0
F00632B4: 80a6a000                 cmp     %i2, 0
F00632B8: 10800004                 ba      loc_F00632C8
F00632BC: b4102000                 mov     0, %i2
F00632C0: 32800002                 bne,a   loc_F00632C8
F00632C4: b416a001                 bset    1, %i2
F00632C8: 7ffffeee                 call    _port_translate_compat
F00632CC: 9407bff4                 add     %fp, var_C, %o2
F00632D0: 80a22000                 cmp     %o0, 0
F00632D4: 12800015                 bne     locret_F0063328
F00632D8: b0100008                 mov     %o0, %i0
F00632DC: 9210001a                 mov     %i2, %o1
F00632E0: d007bff4                 ld      [%fp+var_C], %o0
F00632E4: 7fffdd17                 call    _ipc_port_pdrequest
F00632E8: 9407bff0                 add     %fp, var_10, %o2
F00632EC: d007bff0                 ld      [%fp+var_10], %o0
F00632F0: 80a22000                 cmp     %o0, 0
F00632F4: 0280000b                 be      loc_F0063320
F00632F8: 808a2001                 btst    1, %o0
F00632FC: 02800005                 be      loc_F0063310
F0063300: 01000000                 nop
F0063304: 900a3ffe                 and     %o0, -2, %o0
F0063308: 10800005                 ba      loc_F006331C
F006330C: d027bff0                 st      %o0, [%fp+var_10]
F0063310: 7fffd7e9                 call    _ipc_notify_send_once
F0063314: 01000000                 nop
F0063318: c027bff0                 clr     [%fp+var_10]
F006331C: d007bff0                 ld      [%fp+var_10], %o0
F0063320: b0102000                 mov     0, %i0
F0063324: d026c000                 st      %o0, [%i3]
F0063328: 81c7e008                 ret
F006332C: 81e80000                 restore
