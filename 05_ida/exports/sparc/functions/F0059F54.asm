F0059F54: 9de3bf98                 save    %sp, -0x68, %sp
F0059F58: a0102000                 mov     0, %l0
F0059F5C: d4066004                 ld      [%i1+4], %o2
F0059F60: 9002bfff                 add     %o2, -1, %o0
F0059F64: 80a6a011                 cmp     %i2, 0x11
F0059F68: 02800007                 be      loc_F0059F84
F0059F6C: d0266004                 st      %o0, [%i1+4]
F0059F70: 80a6a012                 cmp     %i2, 0x12
F0059F74: 0280001f                 be      loc_F0059FF0
F0059F78: 92100019                 mov     %i1, %o1
F0059F7C: 1080002c                 ba      loc_F005A02C
F0059F80: 113c043d                 sethi   -0xFEF0C00, %o0
F0059F84: 96102000                 mov     0, %o3
F0059F88: d006601c                 ld      [%i1+0x1C], %o0
F0059F8C: 92102000                 mov     0, %o1
F0059F90: 94100019                 mov     %i1, %o2
F0059F94: 90023fff                 inc     -1, %o0
F0059F98: 80a22000                 cmp     %o0, 0
F0059F9C: 12800008                 bne     loc_F0059FBC
F0059FA0: d026601c                 st      %o0, [%i1+0x1C]
F0059FA4: d6066024                 ld      [%i1+0x24], %o3
F0059FA8: 80a2e000                 cmp     %o3, 0
F0059FAC: 22800005                 be,a    loc_F0059FC0
F0059FB0: d002a00c                 ld      [%o2+0xC], %o0
F0059FB4: c0266024                 clr     [%i1+0x24]
F0059FB8: d2066018                 ld      [%i1+0x18], %o1
F0059FBC: d002a00c                 ld      [%o2+0xC], %o0
F0059FC0: 80a20018                 cmp     %o0, %i0
F0059FC4: 12800003                 bne     loc_F0059FD0
F0059FC8: a0102000                 mov     0, %l0
F0059FCC: e002a010                 ld      [%o2+0x10], %l0
F0059FD0: c0228000                 clr     [%o2]
F0059FD4: 80a2e000                 cmp     %o3, 0
F0059FD8: 22800018                 be,a    locret_F005A038
F0059FDC: e026c000                 st      %l0, [%i3]
F0059FE0: 7ffffc89                 call    _ipc_notify_no_senders
F0059FE4: 9010000b                 mov     %o3, %o0
F0059FE8: 10800014                 ba      locret_F005A038
F0059FEC: e026c000                 st      %l0, [%i3]
F0059FF0: d002600c                 ld      [%o1+0xC], %o0
F0059FF4: 80a20018                 cmp     %o0, %i0
F0059FF8: 32800008                 bne,a   loc_F005A018
F0059FFC: d4266004                 st      %o2, [%i1+4]
F005A000: d0026020                 ld      [%o1+0x20], %o0
F005A004: c0224000                 clr     [%o1]
F005A008: e0026010                 ld      [%o1+0x10], %l0
F005A00C: 90023fff                 inc     -1, %o0
F005A010: 10800009                 ba      loc_F005A034
F005A014: d0226020                 st      %o0, [%o1+0x20]
F005A018: c0264000                 clr     [%i1]
F005A01C: 7ffffca6                 call    _ipc_notify_send_once
F005A020: 90100019                 mov     %i1, %o0! char *
F005A024: 10800005                 ba      locret_F005A038
F005A028: e026c000                 st      %l0, [%i3]
F005A02C: 7ffeec51                 call    _panic
F005A030: 90122240                 bset    0x240, %o0
F005A034: e026c000                 st      %l0, [%i3]
F005A038: 81c7e008                 ret
F005A03C: 81e80000                 restore
