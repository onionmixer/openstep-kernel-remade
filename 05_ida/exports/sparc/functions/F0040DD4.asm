F0040DD4: 9de3bf98                 save    %sp, -0x68, %sp
F0040DD8: 90100018                 mov     %i0, %o0
F0040DDC: 92103fff                 mov     -1, %o1
F0040DE0: e4062030                 ld      [%i0+0x30], %l2
F0040DE4: 7fff913c                 call    _bflush
F0040DE8: 94103fff                 mov     -1, %o2
F0040DEC: d0062024                 ld      [%i0+0x24], %o0
F0040DF0: d204a098                 ld      [%l2+0x98], %o1
F0040DF4: d0022128                 ld      [%o0+0x128], %o0
F0040DF8: a0102000                 mov     0, %l0
F0040DFC: 80a40009                 cmp     %l0, %o1
F0040E00: 1a80000b                 bcc     loc_F0040E2C
F0040E04: e2022024                 ld      [%o0+0x24], %l1
F0040E08: 90100018                 mov     %i0, %o0
F0040E0C: 9334200a                 srl     %l0, 10, %o1
F0040E10: 7fff90ce                 call    _blkflush
F0040E14: 94100011                 mov     %l1, %o2
F0040E18: d004a098                 ld      [%l2+0x98], %o0
F0040E1C: a0040011                 add     %l0, %l1, %l0
F0040E20: 80a40008                 cmp     %l0, %o0
F0040E24: 0abffffa                 bcs     loc_F0040E0C
F0040E28: 90100018                 mov     %i0, %o0
F0040E2C: d214a060                 lduh    [%l2+0x60], %o1
F0040E30: 1100003f901223ef         set     0xFFEF, %o0
F0040E38: 920a4008                 and     %o1, %o0, %o1
F0040E3C: d234a060                 sth     %o1, [%l2+0x60]
F0040E40: 81c7e008                 ret
F0040E44: 81e80000                 restore
