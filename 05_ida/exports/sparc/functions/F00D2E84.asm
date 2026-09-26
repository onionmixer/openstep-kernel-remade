F00D2E84: 9de3bf90                 save    %sp, -0x70, %sp
F00D2E88: 80a6a000                 cmp     %i2, 0
F00D2E8C: 32800004                 bne,a   loc_F00D2E9C
F00D2E90: d0062114                 ld      [%i0+0x114], %o0
F00D2E94: 1080000a                 ba      loc_F00D2EBC
F00D2E98: c0262144                 clr     [%i0+0x144]
F00D2E9C: 80a68008                 cmp     %i2, %o0
F00D2EA0: 22800008                 be,a    loc_F00D2EC0
F00D2EA4: d006214c                 ld      [%i0+0x14C], %o0
F00D2EA8: 7fffdcfb                 call    _IOGetKernPort
F00D2EAC: 9010001a                 mov     %i2, %o0
F00D2EB0: d2062140                 ld      [%i0+0x140], %o1
F00D2EB4: 7ffea100                 call    _port_request_notification
F00D2EB8: d0262144                 st      %o0, [%i0+0x144]
F00D2EBC: d006214c                 ld      [%i0+0x14C], %o0
F00D2EC0: 80a22000                 cmp     %o0, 0
F00D2EC4: 32800006                 bne,a   loc_F00D2EDC
F00D2EC8: f4262114                 st      %i2, [%i0+0x114]
F00D2ECC: 7fffcc19                 call    _IOMalloc
F00D2ED0: 9010201c                 mov     0x1C, %o0
F00D2ED4: d026214c                 st      %o0, [%i0+0x14C]
F00D2ED8: f4262114                 st      %i2, [%i0+0x114]
F00D2EDC: d406214c                 ld      [%i0+0x14C], %o2
F00D2EE0: 113c04bb                 sethi   %hi(dword_F012EEE0), %o0
F00D2EE4: d20222e0                 ld      [%o0+%lo(dword_F012EEE0)], %o1
F00D2EE8: d2228000                 st      %o1, [%o2]
F00D2EEC: 901222e0                 bset    %lo(dword_F012EEE0), %o0
F00D2EF0: d2022004                 ld      [%o0+4], %o1
F00D2EF4: d222a004                 st      %o1, [%o2+4]
F00D2EF8: d2022008                 ld      [%o0+8], %o1
F00D2EFC: d222a008                 st      %o1, [%o2+8]
F00D2F00: d202200c                 ld      [%o0+0xC], %o1
F00D2F04: d222a00c                 st      %o1, [%o2+0xC]
F00D2F08: d2022010                 ld      [%o0+0x10], %o1
F00D2F0C: d222a010                 st      %o1, [%o2+0x10]
F00D2F10: d2022014                 ld      [%o0+0x14], %o1
F00D2F14: d222a014                 st      %o1, [%o2+0x14]
F00D2F18: d0022018                 ld      [%o0+0x18], %o0
F00D2F1C: d022a018                 st      %o0, [%o2+0x18]
F00D2F20: d006214c                 ld      [%i0+0x14C], %o0
F00D2F24: f4222010                 st      %i2, [%o0+0x10]
F00D2F28: 81c7e008                 ret
F00D2F2C: 81e80000                 restore
