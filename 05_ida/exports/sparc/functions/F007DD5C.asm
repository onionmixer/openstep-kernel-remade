F007DD5C: 9de3bf98                 save    %sp, -0x68, %sp
F007DD60: d0060000                 ld      [%i0], %o0
F007DD64: 98100019                 mov     %i1, %o4
F007DD68: 9532201f                 srl     %o0, 31, %o2
F007DD6C: d0062004                 ld      [%i0+4], %o0
F007DD70: 80a22028                 cmp     %o0, 0x28 ! '('
F007DD74: 12800008                 bne     loc_F007DD94
F007DD78: 941aa001                 btog    1, %o2
F007DD7C: d0062018                 ld      [%i0+0x18], %o0
F007DD80: 133c0444                 sethi   %hi(dword_F011127C), %o1
F007DD84: d202627c                 ld      [%o1+%lo(dword_F011127C)], %o1
F007DD88: 80a20009                 cmp     %o0, %o1
F007DD8C: 22800005                 be,a    loc_F007DDA0
F007DD90: d6062020                 ld      [%i0+0x20], %o3! polyPoly
F007DD94: 90103ed0                 mov     -0x130, %o0
F007DD98: 10800023                 ba      locret_F007DE24
F007DD9C: d026601c                 st      %o0, [%i1+0x1C]
F007DDA0: 900ae00c                 and     %o3, 0xC, %o0
F007DDA4: 80a22008                 cmp     %o0, 8
F007DDA8: 12800013                 bne     loc_F007DDF4
F007DDAC: 90103ed0                 mov     -0x130, %o0
F007DDB0: d00e2020                 ldub    [%i0+0x20], %o0
F007DDB4: 90023ff0                 inc     -0x10, %o0
F007DDB8: 900a20ff                 and     %o0, 0xFF, %o0
F007DDBC: 80a22005                 cmp     %o0, 5
F007DDC0: 18800004                 bgu     loc_F007DDD0
F007DDC4: 80a2a000                 cmp     %o2, 0
F007DDC8: 1280000b                 bne     loc_F007DDF4
F007DDCC: 90103ed0                 mov     -0x130, %o0
F007DDD0: 13003fff921263f0         set     0xFFFFF0, %o1
F007DDD8: 920ac009                 and     %o3, %o1, %o1
F007DDDC: 1100080090122010         set     0x200010, %o0
F007DDE4: 80a24008                 cmp     %o1, %o0
F007DDE8: 02800005                 be      loc_F007DDFC
F007DDEC: 01000000                 nop
F007DDF0: 90103ed0                 mov     -0x130, %o0
F007DDF4: 1080000c                 ba      locret_F007DE24
F007DDF8: d023201c                 st      %o0, [%o4+0x1C]
F007DDFC: 7fffa6de                 call    _convert_port_to_space
F007DE00: d0062008                 ld      [%i0+8], %o0! task
F007DE04: d206201c                 ld      [%i0+0x1C], %o1! name
F007DE08: d4062024                 ld      [%i0+0x24], %o2! poly
F007DE0C: a0100008                 mov     %o0, %l0
F007DE10: 7fff937f                 call    _mach_port_insert_right
F007DE14: d60e2020                 ldub    [%i0+0x20], %o3
F007DE18: d026601c                 st      %o0, [%i1+0x1C]
F007DE1C: 7fffa766                 call    _space_deallocate
F007DE20: 90100010                 mov     %l0, %o0
F007DE24: 81c7e008                 ret
F007DE28: 81e80000                 restore
