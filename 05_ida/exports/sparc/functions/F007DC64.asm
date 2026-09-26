F007DC64: 9de3bf98                 save    %sp, -0x68, %sp! previous
F007DC68: d0062004                 ld      [%i0+4], %o0
F007DC6C: 80a22038                 cmp     %o0, 0x38 ! '8'
F007DC70: 12800020                 bne     loc_F007DCF0
F007DC74: 90103ed0                 mov     -0x130, %o0
F007DC78: d0060000                 ld      [%i0], %o0
F007DC7C: 23200000                 sethi   0x80000000, %l1
F007DC80: 808a0011                 btst    %l1, %o0
F007DC84: 0280001a                 be      loc_F007DCEC
F007DC88: 133c0444                 sethi   %hi(dword_F011126C), %o1
F007DC8C: d0062018                 ld      [%i0+0x18], %o0
F007DC90: d202626c                 ld      [%o1+%lo(dword_F011126C)], %o1
F007DC94: 80a20009                 cmp     %o0, %o1
F007DC98: 12800016                 bne     loc_F007DCF0
F007DC9C: 90103ed0                 mov     -0x130, %o0
F007DCA0: d0062020                 ld      [%i0+0x20], %o0
F007DCA4: 133c0444                 sethi   %hi(dword_F0111270), %o1
F007DCA8: d2026270                 ld      [%o1+%lo(dword_F0111270)], %o1
F007DCAC: 80a20009                 cmp     %o0, %o1
F007DCB0: 12800010                 bne     loc_F007DCF0
F007DCB4: 90103ed0                 mov     -0x130, %o0
F007DCB8: d0062028                 ld      [%i0+0x28], %o0
F007DCBC: 133c0444                 sethi   %hi(dword_F0111274), %o1
F007DCC0: d2026274                 ld      [%o1+%lo(dword_F0111274)], %o1
F007DCC4: 80a20009                 cmp     %o0, %o1
F007DCC8: 1280000a                 bne     loc_F007DCF0
F007DCCC: 90103ed0                 mov     -0x130, %o0
F007DCD0: d2062030                 ld      [%i0+0x30], %o1
F007DCD4: 1104880090122018         set     0x12200018, %o0
F007DCDC: 920a7ffc                 and     %o1, -4, %o1
F007DCE0: 80a24008                 cmp     %o1, %o0
F007DCE4: 02800005                 be      loc_F007DCF8
F007DCE8: 01000000                 nop
F007DCEC: 90103ed0                 mov     -0x130, %o0
F007DCF0: 10800019                 ba      locret_F007DD54
F007DCF4: d026601c                 st      %o0, [%i1+0x1C]
F007DCF8: 7fffa71f                 call    _convert_port_to_space
F007DCFC: d0062008                 ld      [%i0+8], %o0! task
F007DD00: d206201c                 ld      [%i0+0x1C], %o1! name
F007DD04: d4062024                 ld      [%i0+0x24], %o2! msgid
F007DD08: a0100008                 mov     %o0, %l0
F007DD0C: d606202c                 ld      [%i0+0x2C], %o3! sync
F007DD10: d8062034                 ld      [%i0+0x34], %o4! notify
F007DD14: 7fff9377                 call    _mach_port_request_notification
F007DD18: 9a066024                 add     %i1, 0x24, %o5 ! '$'
F007DD1C: d026601c                 st      %o0, [%i1+0x1C]
F007DD20: 7fffa7a5                 call    _space_deallocate
F007DD24: 90100010                 mov     %l0, %o0
F007DD28: d006601c                 ld      [%i1+0x1C], %o0
F007DD2C: 80a22000                 cmp     %o0, 0
F007DD30: 12800009                 bne     locret_F007DD54
F007DD34: 92102028                 mov     0x28, %o1 ! '('
F007DD38: d0064000                 ld      [%i1], %o0
F007DD3C: d2266004                 st      %o1, [%i1+4]
F007DD40: 90120011                 bset    %l1, %o0
F007DD44: d0264000                 st      %o0, [%i1]
F007DD48: 113c0444                 sethi   %hi(dword_F0111278), %o0
F007DD4C: d0022278                 ld      [%o0+%lo(dword_F0111278)], %o0
F007DD50: d0266020                 st      %o0, [%i1+0x20]
F007DD54: 81c7e008                 ret
F007DD58: 81e80000                 restore
