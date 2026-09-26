F00699D0: 9de3bf98                 save    %sp, -0x68, %sp
F00699D4: 4000b46d                 call    _splusclock
F00699D8: 01000000                 nop
F00699DC: a2100008                 mov     %o0, %l1
F00699E0: 113c04bda0122280         set     dword_F012F680, %l0
F00699E8: d0040000                 ld      [%l0], %o0
F00699EC: 80a22000                 cmp     %o0, 0
F00699F0: 12bffffe                 bne     loc_F00699E8
F00699F4: 01000000                 nop
F00699F8: 4000b52c                 call    _simple_lock_try
F00699FC: 90100010                 mov     %l0, %o0
F0069A00: 80a22000                 cmp     %o0, 0
F0069A04: 02bffff9                 be      loc_F00699E8
F0069A08: 01000000                 nop
F0069A0C: 40001254                 call    _ticks_to_ns_time
F0069A10: 90100019                 mov     %i1, %o0
F0069A14: 400033d5                 call    _calloutDeadlineFromInterval
F0069A18: 01000000                 nop
F0069A1C: 94100008                 mov     %o0, %o2
F0069A20: 96100009                 mov     %o1, %o3
F0069A24: 9210000a                 mov     %o2, %o1
F0069A28: 9410000b                 mov     %o3, %o2
F0069A2C: 40003588                 call    _calloutEntryDispatchDelayed
F0069A30: 90100018                 mov     %i0, %o0
F0069A34: 90102001                 mov     1, %o0
F0069A38: d0262034                 st      %o0, [%i0+0x34]
F0069A3C: 113c04bd                 sethi   %hi(dword_F012F680), %o0
F0069A40: c0222280                 clr     [%o0+%lo(dword_F012F680)]
F0069A44: 4000b4b8                 call    _splx
F0069A48: 90100011                 mov     %l1, %o0
F0069A4C: 81c7e008                 ret
F0069A50: 81e80000                 restore
