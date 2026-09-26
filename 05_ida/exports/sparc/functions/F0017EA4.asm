F0017EA4: 9de3bf98                 save    %sp, -0x68, %sp
F0017EA8: 40000c90                 call    _ttynty
F0017EAC: 90100018                 mov     %i0, %o0
F0017EB0: d4062040                 ld      [%i0+0x40], %o2
F0017EB4: 808aa002                 btst    2, %o2
F0017EB8: 12800023                 bne     loc_F0017F44
F0017EBC: 96100008                 mov     %o0, %o3
F0017EC0: d206203c                 ld      [%i0+0x3C], %o1
F0017EC4: 11000400                 sethi   0x100000, %o0
F0017EC8: 808a4008                 btst    %o0, %o1
F0017ECC: 0280001e                 be      loc_F0017F44
F0017ED0: 80a66000                 cmp     %i1, 0
F0017ED4: 02800007                 be      loc_F0017EF0
F0017ED8: 900abeff                 and     %o2, -0x101, %o0
F0017EDC: d0262040                 st      %o0, [%i0+0x40]
F0017EE0: 7ffffb26                 call    _ttstart
F0017EE4: 90100018                 mov     %i0, %o0
F0017EE8: 1080003a                 ba      locret_F0017FD0
F0017EEC: b0102001                 mov     1, %i0
F0017EF0: 808aa100                 btst    0x100, %o2
F0017EF4: 32800037                 bne,a   locret_F0017FD0
F0017EF8: b0102001                 mov     1, %i0
F0017EFC: 9012a100                 or      %o2, 0x100, %o0
F0017F00: d4162038                 lduh    [%i0+0x38], %o2
F0017F04: d0262040                 st      %o0, [%i0+0x40]
F0017F08: 9532a008                 srl     %o2, 8, %o2
F0017F0C: 932aa001                 sll     %o2, 1, %o1
F0017F10: 9202400a                 add     %o1, %o2, %o1
F0017F14: 932a6002                 sll     %o1, 2, %o1
F0017F18: 9222400a                 sub     %o1, %o2, %o1
F0017F1C: 932a6002                 sll     %o1, 2, %o1
F0017F20: 153c04729412a1f0         set     _cdevsw, %o2
F0017F28: 9202400a                 add     %o1, %o2, %o1
F0017F2C: d4026014                 ld      [%o1+0x14], %o2
F0017F30: 90100018                 mov     %i0, %o0
F0017F34: 9fc28000                 call    %o2
F0017F38: 92102000                 mov     0, %o1
F0017F3C: 10800025                 ba      locret_F0017FD0
F0017F40: b0102001                 mov     1, %i0
F0017F44: 80a66000                 cmp     %i1, 0
F0017F48: 1280001d                 bne     loc_F0017FBC
F0017F4C: d2062040                 ld      [%i0+0x40], %o1
F0017F50: 900a7fef                 and     %o1, -0x11, %o0
F0017F54: 808a6004                 btst    4, %o1
F0017F58: 0280001d                 be      loc_F0017FCC
F0017F5C: d0262040                 st      %o0, [%i0+0x40]
F0017F60: d202e010                 ld      [%o3+0x10], %o1
F0017F64: 11000020                 sethi   0x8000, %o0
F0017F68: 808a4008                 btst    %o0, %o1
F0017F6C: 32800019                 bne,a   locret_F0017FD0
F0017F70: b0102001                 mov     1, %i0
F0017F74: 4000098c                 call    _ttwakeup
F0017F78: 90100018                 mov     %i0, %o0
F0017F7C: d206203c                 ld      [%i0+0x3C], %o1
F0017F80: 11004000                 sethi   0x1000000, %o0
F0017F84: 808a4008                 btst    %o0, %o1
F0017F88: 32800012                 bne,a   locret_F0017FD0
F0017F8C: b0102001                 mov     1, %i0
F0017F90: d0562044                 ldsh    [%i0+0x44], %o0
F0017F94: 7fffe552                 call    _gsignal
F0017F98: 92102001                 mov     1, %o1
F0017F9C: d0562044                 ldsh    [%i0+0x44], %o0
F0017FA0: 7fffe54f                 call    _gsignal
F0017FA4: 92102013                 mov     0x13, %o1
F0017FA8: 90100018                 mov     %i0, %o0
F0017FAC: 7ffffaa1                 call    _ttyflush
F0017FB0: 92102003                 mov     3, %o1
F0017FB4: 10800007                 ba      locret_F0017FD0
F0017FB8: b0102000                 mov     0, %i0
F0017FBC: 90100018                 mov     %i0, %o0
F0017FC0: 92126010                 bset    0x10, %o1
F0017FC4: 7fffeb89                 call    _wakeup
F0017FC8: d2222040                 st      %o1, [%o0+0x40]
F0017FCC: b0102001                 mov     1, %i0
F0017FD0: 81c7e008                 ret
F0017FD4: 81e80000                 restore
