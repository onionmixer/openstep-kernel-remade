F002BC50: 9de3bf90                 save    %sp, -0x70, %sp
F002BC54: 9410001a                 mov     %i2, %o2
F002BC58: d6062038                 ld      [%i0+0x38], %o3
F002BC5C: 80a2e000                 cmp     %o3, 0
F002BC60: 12800004                 bne     loc_F002BC70
F002BC64: 98100018                 mov     %i0, %o4
F002BC68: 10800047                 ba      locret_F002BD84
F002BC6C: b0102006                 mov     6, %i0
F002BC70: 1120081a90122131         set     -0x7FDF96CF, %o0
F002BC78: 80a64008                 cmp     %i1, %o0
F002BC7C: 22800031                 be,a    loc_F002BD40
F002BC80: 90100018                 mov     %i0, %o0
F002BC84: 1880000c                 bgu     loc_F002BCB4
F002BC88: 1120081a                 sethi   -0x7FDF9800, %o0
F002BC8C: 9012210c                 bset    0x10C, %o0
F002BC90: 80a64008                 cmp     %i1, %o0
F002BC94: 0280001f                 be      loc_F002BD10
F002BC98: 1120081a                 sethi   -0x7FDF9800, %o0
F002BC9C: 90122110                 bset    0x110, %o0
F002BCA0: 80a64008                 cmp     %i1, %o0
F002BCA4: 02800023                 be      loc_F002BD30
F002BCA8: 90100018                 mov     %i0, %o0
F002BCAC: 1080002d                 ba      loc_F002BD60
F002BCB0: f227bff0                 st      %i1, [%fp+var_10]
F002BCB4: 1130081a9012210d         set     -0x3FDF96F3, %o0
F002BCBC: 80a64008                 cmp     %i1, %o0
F002BCC0: 22800018                 be,a    loc_F002BD20
F002BCC4: 90100018                 mov     %i0, %o0
F002BCC8: 18800008                 bgu     loc_F002BCE8
F002BCCC: 1120081a                 sethi   -0x7FDF9800, %o0
F002BCD0: 90122132                 bset    0x132, %o0
F002BCD4: 80a64008                 cmp     %i1, %o0
F002BCD8: 0280001f                 be      loc_F002BD54
F002BCDC: 90100018                 mov     %i0, %o0
F002BCE0: 10800020                 ba      loc_F002BD60
F002BCE4: f227bff0                 st      %i1, [%fp+var_10]
F002BCE8: 1130081a90122121         set     -0x3FDF96DF, %o0
F002BCF0: 80a64008                 cmp     %i1, %o0
F002BCF4: 3280001b                 bne,a   loc_F002BD60
F002BCF8: f227bff0                 st      %i1, [%fp+var_10]
F002BCFC: 90100018                 mov     %i0, %o0
F002BD00: 133c03d3921260f0         set     _IFCONTROL_AUTOADDR, %o1! "autoaddr"
F002BD08: 1080001c                 ba      loc_F002BD78
F002BD0C: 9402a010                 inc     0x10, %o2
F002BD10: 90100018                 mov     %i0, %o0
F002BD14: 133c03d3                 sethi   %hi(_IFCONTROL_SETADDR), %o1! "setaddr"
F002BD18: 10800018                 ba      loc_F002BD78
F002BD1C: 921260e0                 bset    %lo(_IFCONTROL_SETADDR), %o1! "setaddr"
F002BD20: 133c03d3921260e8         set     _IFCONTROL_GETADDR, %o1! "getaddr"
F002BD28: 10800014                 ba      loc_F002BD78
F002BD2C: 9402a010                 inc     0x10, %o2
F002BD30: 133c03d3921260d0         set     _IFCONTROL_SETFLAGS, %o1! "setflags"
F002BD38: 10800010                 ba      loc_F002BD78
F002BD3C: 9402a010                 inc     0x10, %o2
F002BD40: 133c03d3                 sethi   %hi(_IFCONTROL_ADDMULTICAST), %o1! "add-multicast"
F002BD44: 7fffffb5                 call    _if_control
F002BD48: 92126130                 bset    %lo(_IFCONTROL_ADDMULTICAST), %o1! "add-multicast"
F002BD4C: 1080000e                 ba      locret_F002BD84
F002BD50: b0100008                 mov     %o0, %i0
F002BD54: 133c03d3                 sethi   %hi(_IFCONTROL_RMVMULTICAST), %o1! "rmv-multicast"
F002BD58: 10800008                 ba      loc_F002BD78
F002BD5C: 92126140                 bset    %lo(_IFCONTROL_RMVMULTICAST), %o1! "rmv-multicast"
F002BD60: d427bff4                 st      %o2, [%fp+var_C]
F002BD64: 90100018                 mov     %i0, %o0
F002BD68: 133c03d392126100         set     _IFCONTROL_UNIXIOCTL, %o1! "unix-ioctl"
F002BD70: d6032038                 ld      [%o4+0x38], %o3
F002BD74: 9407bff0                 add     %fp, var_10, %o2
F002BD78: 9fc2c000                 call    %o3
F002BD7C: 01000000                 nop
F002BD80: b0100008                 mov     %o0, %i0
F002BD84: 81c7e008                 ret
F002BD88: 81e80000                 restore
