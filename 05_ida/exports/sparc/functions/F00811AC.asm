F00811AC: 9de3bf98                 save    %sp, -0x68, %sp
F00811B0: 90100018                 mov     %i0, %o0
F00811B4: 92100019                 mov     %i1, %o1
F00811B8: 9410001a                 mov     %i2, %o2
F00811BC: 9610001b                 mov     %i3, %o3
F00811C0: 4000a5d2                 call    _machine_exception
F00811C4: 9810001c                 mov     %i4, %o4
F00811C8: 80a22000                 cmp     %o0, 0
F00811CC: 1280002e                 bne     def_F00811EC! jumptable F00811EC default case
F00811D0: 92063fff                 add     %i0, -1, %o1
F00811D4: 80a26005                 cmp     %o1, 5! switch 6 cases
F00811D8: 1880002b                 bgu     def_F00811EC! jumptable F00811EC default case
F00811DC: 113c0204                 sethi   %hi(jpt_F00811EC), %o0
F00811E0: 901221f4                 bset    %lo(jpt_F00811EC), %o0
F00811E4: 932a6002                 sll     %o1, 2, %o1
F00811E8: d0024008                 ld      [%o1+%o0], %o0
F00811EC: 81c20000                 jmp     %o0! switch jump
F00811F0: 01000000                 nop
F008120C: 80a66001                 cmp     %i1, 1! jumptable F00811EC case 0
F0081210: 1280001c                 bne     loc_F0081280
F0081214: 9010200a                 mov     0xA, %o0
F0081218: 1080001a                 ba      loc_F0081280
F008121C: 9010200b                 mov     0xB, %o0
F0081220: 10800018                 ba      loc_F0081280! jumptable F00811EC case 1
F0081224: 90102004                 mov     4, %o0
F0081228: 10800016                 ba      loc_F0081280! jumptable F00811EC case 2
F008122C: 90102008                 mov     8, %o0
F0081230: 10800014                 ba      loc_F0081280! jumptable F00811EC case 3
F0081234: 90102007                 mov     7, %o0
F0081238: 1100004090122001         set     0x10001, %o0! jumptable F00811EC case 4
F0081240: 80a64008                 cmp     %i1, %o0
F0081244: 2280000f                 be,a    loc_F0081280
F0081248: 9010200d                 mov     0xD, %o0
F008124C: 14800007                 bg      loc_F0081268
F0081250: 11000040                 sethi   0x10000, %o0
F0081254: 11000040                 sethi   0x10000, %o0
F0081258: 80a64008                 cmp     %i1, %o0
F008125C: 02800009                 be      loc_F0081280
F0081260: 9010200c                 mov     0xC, %o0
F0081264: 30800008                 ba,a    def_F00811EC! jumptable F00811EC default case
F0081268: 90122002                 bset    2, %o0
F008126C: 80a64008                 cmp     %i1, %o0
F0081270: 02800004                 be      loc_F0081280
F0081274: 90102006                 mov     6, %o0
F0081278: 30800003                 ba,a    def_F00811EC! jumptable F00811EC default case
F008127C: 90102005                 mov     5, %o0! jumptable F00811EC case 5
F0081280: d026c000                 st      %o0, [%i3]
F0081284: 81c7e008                 ret! jumptable F00811EC default case
F0081288: 81e80000                 restore
