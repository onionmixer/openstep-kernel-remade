F00A3844: 9de3bf90                 save    %sp, -0x70, %sp
F00A3848: 133c0485                 sethi   %hi(aMachKernel), %o1! "/mach_kernel"
F00A384C: 113c04d590122220         set     _boot_file, %o0! __dst
F00A3854: 92126104                 bset    %lo(aMachKernel), %o1! "/mach_kernel"
F00A3858: 7ffd9031                 call    _strncpy
F00A385C: 94102040                 mov     0x40, %o2 ! '@'! __n
F00A3860: d04e0000                 ldsb    [%i0], %o0
F00A3864: 80a22000                 cmp     %o0, 0
F00A3868: 12800004                 bne     loc_F00A3878
F00A386C: 01000000                 nop
F00A3870: 1080009f                 ba      locret_F00A3AEC
F00A3874: b0102001                 mov     1, %i0
F00A3878: 4000009f                 call    _isargsep
F00A387C: d04e0000                 ldsb    [%i0], %o0
F00A3880: 80a22000                 cmp     %o0, 0
F00A3884: 22800004                 be,a    loc_F00A3894
F00A3888: d04e0000                 ldsb    [%i0], %o0
F00A388C: 10bffffb                 ba      loc_F00A3878
F00A3890: b0062001                 inc     %i0
F00A3894: 80a22000                 cmp     %o0, 0
F00A3898: 02800094                 be      loc_F00A3AE8
F00A389C: d20e0000                 ldub    [%i0], %o1
F00A38A0: 113c028eac1220f8         set     jpt_F00A38F0, %l6
F00A38A8: 273c046c                 sethi   -0xFEE5000, %l3
F00A38AC: 2b000800                 sethi   0x200000, %l5
F00A38B0: 80a2602d                 cmp     %o1, 0x2D ! '-'
F00A38B4: 1280003d                 bne     loc_F00A39A8
F00A38B8: a0100018                 mov     %i0, %l0
F00A38BC: 113c042ba0122368         set     _init_args, %l0! "-xx"
F00A38C4: 90100018                 mov     %i0, %o0
F00A38C8: 4000009a                 call    _argstrcpy
F00A38CC: 92100010                 mov     %l0, %o1
F00A38D0: d00c0000                 ldub    [%l0], %o0
F00A38D4: 90023f9f                 inc     -0x61, %o0
F00A38D8: 912a2018                 sll     %o0, 24, %o0
F00A38DC: 913a2018                 sra     %o0, 24, %o0
F00A38E0: 80a22012                 cmp     %o0, 0x12! switch 19 cases
F00A38E4: 18800027                 bgu     def_F00A38F0! jumptable F00A38F0 default case, cases 1,2,4,6,8-17
F00A38E8: 912a2002                 sll     %o0, 2, %o0
F00A38EC: d0020016                 ld      [%o0+%l6], %o0
F00A38F0: 81c20000                 jmp     %o0! switch jump
F00A38F4: 01000000                 nop
F00A3944: d004e104                 ld      [%l3+0x104], %o0! jumptable F00A38F0 case 0
F00A3948: 1080000d                 ba      loc_F00A397C
F00A394C: 90122001                 bset    1, %o0
F00A3950: d004e104                 ld      [%l3+0x104], %o0! jumptable F00A38F0 case 18
F00A3954: 1080000a                 ba      loc_F00A397C
F00A3958: 90122002                 bset    2, %o0
F00A395C: d004e104                 ld      [%l3+0x104], %o0! jumptable F00A38F0 case 3
F00A3960: 10800007                 ba      loc_F00A397C
F00A3964: 90122004                 bset    4, %o0
F00A3968: d004e104                 ld      [%l3+0x104], %o0! jumptable F00A38F0 case 5
F00A396C: 10800004                 ba      loc_F00A397C
F00A3970: 90120015                 bset    %l5, %o0
F00A3974: d004e104                 ld      [%l3+0x104], %o0! jumptable F00A38F0 case 7
F00A3978: 90122008                 bset    8, %o0
F00A397C: d024e104                 st      %o0, [%l3+0x104]
F00A3980: d04c0000                 ldsb    [%l0], %o0! jumptable F00A38F0 default case, cases 1,2,4,6,8-17
F00A3984: 80a22000                 cmp     %o0, 0
F00A3988: 02800042                 be      loc_F00A3A90
F00A398C: 01000000                 nop
F00A3990: 40000059                 call    _isargsep
F00A3994: a0042001                 inc     %l0
F00A3998: 80a22000                 cmp     %o0, 0
F00A399C: 22bfffce                 be,a    loc_F00A38D4
F00A39A0: d00c0000                 ldub    [%l0], %o0
F00A39A4: 3080003b                 ba,a    loc_F00A3A90
F00A39A8: 40000053                 call    _isargsep
F00A39AC: d04c0000                 ldsb    [%l0], %o0
F00A39B0: 80a22000                 cmp     %o0, 0
F00A39B4: 12800007                 bne     loc_F00A39D0
F00A39B8: d04c0000                 ldsb    [%l0], %o0
F00A39BC: 80a2203d                 cmp     %o0, 0x3D ! '='
F00A39C0: 02800005                 be      loc_F00A39D4
F00A39C4: 01000000                 nop
F00A39C8: 10bffff8                 ba      loc_F00A39A8
F00A39CC: a0042001                 inc     %l0
F00A39D0: 80a2203d                 cmp     %o0, 0x3D ! '='
F00A39D4: 1280002f                 bne     loc_F00A3A90
F00A39D8: 113c0464                 sethi   %hi(_kernargs), %o0
F00A39DC: d2022268                 ld      [%o0+%lo(_kernargs)], %o1
F00A39E0: 80a26000                 cmp     %o1, 0
F00A39E4: 0280002b                 be      loc_F00A3A90
F00A39E8: a2122268                 or      %o0, %lo(_kernargs), %l1
F00A39EC: a810203d                 mov     0x3D, %l4 ! '='
F00A39F0: a4046004                 add     %l1, 4, %l2
F00A39F4: 90100018                 mov     %i0, %o0! __s1
F00A39F8: d2044000                 ld      [%l1], %o1! __s2
F00A39FC: 7ffd92bb                 call    _strncmp
F00A3A00: 94240018                 sub     %l0, %i0, %o2
F00A3A04: 80a22000                 cmp     %o0, 0
F00A3A08: 3280001e                 bne,a   loc_F00A3A80
F00A3A0C: a2046008                 inc     8, %l1
F00A3A10: 40000039                 call    _isargsep
F00A3A14: d04c0000                 ldsb    [%l0], %o0
F00A3A18: 80a22000                 cmp     %o0, 0
F00A3A1C: 22800004                 be,a    loc_F00A3A2C
F00A3A20: d04c0000                 ldsb    [%l0], %o0
F00A3A24: 10bffffb                 ba      loc_F00A3A10
F00A3A28: a0042001                 inc     %l0
F00A3A2C: 80a2203d                 cmp     %o0, 0x3D ! '='
F00A3A30: 12800005                 bne     loc_F00A3A44
F00A3A34: 90100010                 mov     %l0, %o0
F00A3A38: 80a5203d                 cmp     %l4, 0x3D ! '='
F00A3A3C: 32800015                 bne,a   loc_F00A3A90
F00A3A40: b0042001                 add     %l0, 1, %i0
F00A3A44: 4000004a                 call    _getval
F00A3A48: 9207bff4                 add     %fp, var_C, %o1
F00A3A4C: 80a22000                 cmp     %o0, 0
F00A3A50: 02800005                 be      loc_F00A3A64
F00A3A54: 80a22001                 cmp     %o0, 1
F00A3A58: 22800007                 be,a    loc_F00A3A74
F00A3A5C: d2048000                 ld      [%l2], %o1
F00A3A60: 3080000c                 ba,a    loc_F00A3A90
F00A3A64: d2048000                 ld      [%l2], %o1
F00A3A68: d007bff4                 ld      [%fp+var_C], %o0
F00A3A6C: 10800009                 ba      loc_F00A3A90
F00A3A70: d0224000                 st      %o0, [%o1]
F00A3A74: 4000002f                 call    _argstrcpy
F00A3A78: 90042001                 add     %l0, 1, %o0
F00A3A7C: 30800005                 ba,a    loc_F00A3A90
F00A3A80: d0044000                 ld      [%l1], %o0
F00A3A84: 80a22000                 cmp     %o0, 0
F00A3A88: 12bfffdb                 bne     loc_F00A39F4
F00A3A8C: a404a008                 inc     8, %l2
F00A3A90: 40000019                 call    _isargsep
F00A3A94: d04e0000                 ldsb    [%i0], %o0
F00A3A98: 80a22000                 cmp     %o0, 0
F00A3A9C: 3280000c                 bne,a   loc_F00A3ACC
F00A3AA0: d04e0000                 ldsb    [%i0], %o0
F00A3AA4: 10bffffb                 ba      loc_F00A3A90
F00A3AA8: b0062001                 inc     %i0
F00A3AAC: 912a6018                 sll     %o1, 24, %o0
F00A3AB0: 40000011                 call    _isargsep
F00A3AB4: 913a2018                 sra     %o0, 24, %o0
F00A3AB8: 80a22000                 cmp     %o0, 0
F00A3ABC: 22800008                 be,a    loc_F00A3ADC
F00A3AC0: d04e0000                 ldsb    [%i0], %o0
F00A3AC4: b0062001                 inc     %i0
F00A3AC8: d04e0000                 ldsb    [%i0], %o0
F00A3ACC: 80a22000                 cmp     %o0, 0
F00A3AD0: 12bffff7                 bne     loc_F00A3AAC
F00A3AD4: d20e0000                 ldub    [%i0], %o1
F00A3AD8: d04e0000                 ldsb    [%i0], %o0
F00A3ADC: 80a22000                 cmp     %o0, 0
F00A3AE0: 12bfff74                 bne     loc_F00A38B0
F00A3AE4: d20e0000                 ldub    [%i0], %o1
F00A3AE8: b0102000                 mov     0, %i0
F00A3AEC: 81c7e008                 ret
F00A3AF0: 81e80000                 restore
