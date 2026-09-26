F00B4218: 9de3bf98                 save    %sp, -0x68, %sp
F00B421C: a6100018                 mov     %i0, %l3
F00B4220: b0102000                 mov     0, %i0
F00B4224: 80a6e001                 cmp     %i3, 1
F00B4228: d214e004                 lduh    [%l3+4], %o1
F00B422C: 90102001                 mov     1, %o0
F00B4230: e404c000                 ld      [%l3], %l2
F00B4234: 912a0009                 sll     %o0, %o1, %o0
F00B4238: a8380008                 xnor    %g0, %o0, %l4
F00B423C: 1880009a                 bgu     locret_F00B44A4
F00B4240: aa100008                 mov     %o0, %l5
F00B4244: 80a66000                 cmp     %i1, 0
F00B4248: 02800097                 be      locret_F00B44A4
F00B424C: 133c047c                 sethi   %hi(_scsi_capstrings), %o1
F00B4250: d00263b4                 ld      [%o1+%lo(_scsi_capstrings)], %o0! __s1
F00B4254: 80a22000                 cmp     %o0, 0
F00B4258: 0280000e                 be      loc_F00B4290
F00B425C: a2102000                 mov     0, %l1
F00B4260: a01263b4                 or      %o1, %lo(_scsi_capstrings), %l0
F00B4264: d2040000                 ld      [%l0], %o1! __s2
F00B4268: 7ffd4fd1                 call    _strcmp
F00B426C: 90100019                 mov     %i1, %o0
F00B4270: 80a22000                 cmp     %o0, 0
F00B4274: 02800008                 be      loc_F00B4294
F00B4278: 113c047c                 sethi   -0xFEE1000, %o0
F00B427C: a0042004                 inc     4, %l0
F00B4280: d0040000                 ld      [%l0], %o0
F00B4284: 80a22000                 cmp     %o0, 0
F00B4288: 12bffff7                 bne     loc_F00B4264
F00B428C: a2046001                 inc     %l1
F00B4290: 113c047c                 sethi   -0xFEE1000, %o0
F00B4294: 901223b4                 bset    0x3B4, %o0
F00B4298: 932c6002                 sll     %l1, 2, %o1
F00B429C: d0024008                 ld      [%o1+%o0], %o0
F00B42A0: 80a22000                 cmp     %o0, 0
F00B42A4: 0280007f                 be      def_F00B43C8! jumptable F00B43C8 default case, case 4
F00B42A8: 80a72000                 cmp     %i4, 0
F00B42AC: 0280003f                 be      loc_F00B43A8
F00B42B0: 80a6a001                 cmp     %i2, 1
F00B42B4: 1880003d                 bgu     loc_F00B43A8
F00B42B8: 80a46008                 cmp     %l1, 8
F00B42BC: 18800079                 bgu     def_F00B43C8! jumptable F00B43C8 default case, case 4
F00B42C0: 113c02d0                 sethi   %hi(loc_F00B42D4), %o0
F00B42C4: 901222d4                 bset    %lo(loc_F00B42D4), %o0
F00B42C8: d0024008                 ld      [%o1+%o0], %o0
F00B42CC: 81c20000                 jmp     %o0
F00B42D0: 01000000                 nop
F00B42D4: f00b44a4                 ldub    [%o5+%g4], %i0
F00B42D8: f00b44a4                 ldub    [%o5+%g4], %i0
F00B42DC: f00b42f8                 ldub    [%o5+%i0], %i0
F00B42E0: f00b4348                 ldub    [%o5+%o0], %i0
F00B42E4: f00b44a0                 ldub    [%o5], %i0
F00B42E8: f00b44a4                 ldub    [%o5+%g4], %i0
F00B42EC: f00b44a4                 ldub    [%o5+%g4], %i0
F00B42F0: f00b44a0                 ldub    [%o5], %i0
F00B42F4: f00b44a0                 ldub    [%o5], %i0
F00B42F8: 113c047c                 sethi   %hi(_scsi_options), %o0
F00B42FC: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B4300: 808a2008                 btst    8, %o0
F00B4304: 02800068                 be      locret_F00B44A4
F00B4308: 80a6e000                 cmp     %i3, 0
F00B430C: 0280000a                 be      loc_F00B4334
F00B4310: 80a6a000                 cmp     %i2, 0
F00B4314: 02800005                 be      loc_F00B4328
F00B4318: d00ca079                 ldub    [%l2+0x79], %o0
F00B431C: 900a0014                 and     %o0, %l4, %o0
F00B4320: 1080005b                 ba      loc_F00B448C! jumptable F00B43C8 case 1
F00B4324: d02ca079                 stb     %o0, [%l2+0x79]
F00B4328: 90120015                 bset    %l5, %o0
F00B432C: 10800058                 ba      loc_F00B448C! jumptable F00B43C8 case 1
F00B4330: d02ca079                 stb     %o0, [%l2+0x79]
F00B4334: 32800056                 bne,a   loc_F00B448C! jumptable F00B43C8 case 1
F00B4338: c02ca079                 clrb    [%l2+0x79]
F00B433C: 901020ff                 mov     0xFF, %o0
F00B4340: 10800053                 ba      loc_F00B448C! jumptable F00B43C8 case 1
F00B4344: d02ca079                 stb     %o0, [%l2+0x79]
F00B4348: 113c047c                 sethi   %hi(_scsi_options), %o0
F00B434C: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B4350: 808a2020                 btst    0x20, %o0 ! ' '
F00B4354: 02800054                 be      locret_F00B44A4
F00B4358: 80a6e000                 cmp     %i3, 0
F00B435C: 0280000c                 be      loc_F00B438C
F00B4360: 80a6a000                 cmp     %i2, 0
F00B4364: 02800004                 be      loc_F00B4374
F00B4368: d00ca07a                 ldub    [%l2+0x7A], %o0
F00B436C: 10800003                 ba      loc_F00B4378
F00B4370: 900a0014                 and     %o0, %l4, %o0
F00B4374: 90120015                 bset    %l5, %o0
F00B4378: d02ca07a                 stb     %o0, [%l2+0x7A]
F00B437C: d00ca078                 ldub    [%l2+0x78], %o0
F00B4380: 900a0014                 and     %o0, %l4, %o0
F00B4384: 10800042                 ba      loc_F00B448C! jumptable F00B43C8 case 1
F00B4388: d02ca078                 stb     %o0, [%l2+0x78]
F00B438C: 02800004                 be      loc_F00B439C
F00B4390: 901020ff                 mov     0xFF, %o0
F00B4394: 10800003                 ba      loc_F00B43A0
F00B4398: c02ca07a                 clrb    [%l2+0x7A]
F00B439C: d02ca07a                 stb     %o0, [%l2+0x7A]
F00B43A0: 1080003b                 ba      loc_F00B448C! jumptable F00B43C8 case 1
F00B43A4: c02ca078                 clrb    [%l2+0x78]
F00B43A8: 80a72000                 cmp     %i4, 0
F00B43AC: 1280003e                 bne     locret_F00B44A4
F00B43B0: 80a46006                 cmp     %l1, 6! switch 7 cases
F00B43B4: 1880003b                 bgu     def_F00B43C8! jumptable F00B43C8 default case, case 4
F00B43B8: 113c02d0                 sethi   %hi(jpt_F00B43C8), %o0
F00B43BC: 901223d0                 bset    %lo(jpt_F00B43C8), %o0
F00B43C0: 932c6002                 sll     %l1, 2, %o1
F00B43C4: d0024008                 ld      [%o1+%o0], %o0
F00B43C8: 81c20000                 jmp     %o0! switch jump
F00B43CC: 01000000                 nop
F00B43EC: d004a0a0                 ld      [%l2+0xA0], %o0! jumptable F00B43C8 case 0
F00B43F0: d0020000                 ld      [%o0], %o0
F00B43F4: 9132201c                 srl     %o0, 28, %o0
F00B43F8: 80a22009                 cmp     %o0, 9
F00B43FC: 08800004                 bleu    loc_F00B440C
F00B4400: 80a2200a                 cmp     %o0, 0xA
F00B4404: 02800028                 be      locret_F00B44A4
F00B4408: 31100000                 sethi   0x40000000, %i0
F00B440C: 10800026                 ba      locret_F00B44A4
F00B4410: 31004000                 sethi   0x1000000, %i0
F00B4414: 113c047c                 sethi   %hi(_scsi_options), %o0! jumptable F00B43C8 case 2
F00B4418: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B441C: 808a2008                 btst    8, %o0
F00B4420: 02800021                 be      locret_F00B44A4
F00B4424: 80a6e000                 cmp     %i3, 0
F00B4428: 2280001f                 be,a    locret_F00B44A4
F00B442C: b0102001                 mov     1, %i0
F00B4430: d00ca079                 ldub    [%l2+0x79], %o0
F00B4434: 808a0015                 btst    %l5, %o0
F00B4438: 1280001b                 bne     locret_F00B44A4
F00B443C: 01000000                 nop
F00B4440: 10800019                 ba      locret_F00B44A4
F00B4444: b0102001                 mov     1, %i0
F00B4448: 113c047c                 sethi   %hi(_scsi_options), %o0! jumptable F00B43C8 case 3
F00B444C: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B4450: 808a2020                 btst    0x20, %o0 ! ' '
F00B4454: 02800014                 be      locret_F00B44A4
F00B4458: 80a6e000                 cmp     %i3, 0
F00B445C: 22800012                 be,a    locret_F00B44A4
F00B4460: b0102001                 mov     1, %i0
F00B4464: d014e004                 lduh    [%l3+4], %o0
F00B4468: 90048008                 add     %l2, %o0, %o0
F00B446C: d00a205e                 ldub    [%o0+0x5E], %o0
F00B4470: 10800005                 ba      loc_F00B4484
F00B4474: 80a22000                 cmp     %o0, 0
F00B4478: 113c047c                 sethi   %hi(_scsi_options), %o0! jumptable F00B43C8 case 5
F00B447C: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B4480: 808a2040                 btst    0x40, %o0 ! '@'
F00B4484: 02800008                 be      locret_F00B44A4
F00B4488: 01000000                 nop
F00B448C: 10800006                 ba      locret_F00B44A4! jumptable F00B43C8 case 1
F00B4490: b0102001                 mov     1, %i0
F00B4494: d00ca032                 ldub    [%l2+0x32], %o0! jumptable F00B43C8 case 6
F00B4498: 10800003                 ba      locret_F00B44A4
F00B449C: b00a2007                 and     %o0, 7, %i0
F00B44A0: b0103fff                 mov     -1, %i0! jumptable F00B43C8 default case, case 4
F00B44A4: 81c7e008                 ret
F00B44A8: 81e80000                 restore
