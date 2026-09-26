F0003170: 2d3c000c                 sethi   %hi(_nwindows), %l6
F0003174: ec05a03c                 ld      [%l6+%lo(_nwindows)], %l6
F0003178: ac25a001                 dec     %l6
F000317C: aa102001                 mov     1, %l5
F0003180: ab2d4010                 sll     %l5, %l0, %l5
F0003184: a7500000                 rdpr    %tpc, %l3
F0003188: 808c2040                 btst    0x40, %l0 ! '@'
F000318C: 0280002b                 be      loc_F0003238
F0003190: 808d4013                 btst    %l3, %l5
F0003194: ae27a0a8                 sub     %fp, 0xA8, %l7
F0003198: c225e06c                 st      %g1, [%l7+0x6C]
F000319C: c43de070                 std     %g2, [%l7+0x70]
F00031A0: c83de078                 std     %g4, [%l7+0x78]
F00031A4: cc3de080                 std     %g6, [%l7+0x80]
F00031A8: 83400000                 mov     %y, %g1
F00031AC: c225e068                 st      %g1, [%l7+0x68]
F00031B0: 808d2200                 btst    0x200, %l4
F00031B4: 2280001a                 be,a    loc_F000321C
F00031B8: 8c100000                 clr     %g6
F00031BC: 8610000f                 mov     %o7, %g3
F00031C0: 4002494e                 call    _mmu_getsyncflt
F00031C4: 8c100014                 mov     %l4, %g6
F00031C8: 9e100003                 mov     %g3, %o7
F00031CC: 033c045d821062dc         set     _do_work_arounds, %g1
F00031D4: c2004000                 ld      [%g1], %g1
F00031D8: 80a04000                 cmp     %g1, %g0
F00031DC: 02800010                 be      loc_F000321C
F00031E0: 01000000                 nop
F00031E4: 8089a002                 btst    2, %g6
F00031E8: 0280000d                 be      loc_F000321C
F00031EC: 8331a002                 srl     %g6, 2, %g1
F00031F0: 8208601c                 and     %g1, 0x1C, %g1
F00031F4: 80a06008                 cmp     %g1, 8
F00031F8: 02800005                 be      loc_F000320C
F00031FC: 01000000                 nop
F0003200: 80a0600c                 cmp     %g1, 0xC
F0003204: 12800006                 bne     loc_F000321C
F0003208: 01000000                 nop
F000320C: f03de088                 std     %i0, [%l7+0x88]
F0003210: f43de090                 std     %i2, [%l7+0x90]
F0003214: f83de098                 std     %i4, [%l7+0x98]
F0003218: fc3de0a0                 std     %fp, [%l7+0xA0]
F000321C: fc25e0a0                 st      %fp, [%l7+0xA0]
F0003220: e025e05c                 st      %l0, [%l7+0x5C]
F0003224: e225e060                 st      %l1, [%l7+0x60]
F0003228: 808d4013                 btst    %l3, %l5
F000322C: 02800033                 be      loc_F00032F8
F0003230: e425e064                 st      %l2, [%l7+0x64]
F0003234: 30800059                 ba,a    loc_F0003398
F0003238: 2f3c0428ae15e024         set     _active_pcb, %l7
F0003240: ee05c000                 ld      [%l7], %l7
F0003244: c225e244                 st      %g1, [%l7+0x244]
F0003248: c43de248                 std     %g2, [%l7+0x248]
F000324C: c83de250                 std     %g4, [%l7+0x250]
F0003250: cc3de258                 std     %g6, [%l7+0x258]
F0003254: 83400000                 mov     %y, %g1
F0003258: c225e240                 st      %g1, [%l7+0x240]
F000325C: f03de260                 std     %i0, [%l7+0x260]
F0003260: f43de268                 std     %i2, [%l7+0x268]
F0003264: f83de270                 std     %i4, [%l7+0x270]
F0003268: fc3de278                 std     %fp, [%l7+0x278]
F000326C: e025e234                 st      %l0, [%l7+0x234]
F0003270: e225e238                 st      %l1, [%l7+0x238]
F0003274: e425e23c                 st      %l2, [%l7+0x23C]
F0003278: 808d2200                 btst    0x200, %l4
F000327C: 22800006                 be,a    loc_F0003294
F0003280: 8c100000                 clr     %g6
F0003284: 8610000f                 mov     %o7, %g3
F0003288: 4002491c                 call    _mmu_getsyncflt
F000328C: 8c100014                 mov     %l4, %g6
F0003290: 9e100003                 mov     %g3, %o7
F0003294: ee05e2a0                 ld      [%l7+0x2A0], %l7
F0003298: e025e05c                 st      %l0, [%l7+0x5C]
F000329C: 0b3c04288a116024         set     _active_pcb, %g5
F00032A4: ca014000                 ld      [%g5], %g5
F00032A8: 808d4013                 btst    %l3, %l5
F00032AC: 02800008                 be      loc_F00032CC
F00032B0: c0216230                 clr     [%g5+0x230]
F00032B4: 843d4000                 not     %l5, %g2
F00032B8: 86103ffe                 mov     -2, %g3
F00032BC: 8728c016                 sll     %g3, %l6, %g3
F00032C0: 84288003                 bclr    %g3, %g2
F00032C4: 1080004a                 ba      loc_F00033EC
F00032C8: 8334e001                 srl     %l3, 1, %g1
F00032CC: 82a4c015                 subcc   %l3, %l5, %g1
F00032D0: 2c800002                 bneg,a  loc_F00032D8
F00032D4: 82206001                 dec     %g1
F00032D8: 82284015                 bclr    %l5, %g1
F00032DC: 86103ffe                 mov     -2, %g3
F00032E0: 8728c016                 sll     %g3, %l6, %g3
F00032E4: 82284003                 bclr    %g3, %g1
F00032E8: 0b3c04288a116024         set     _active_pcb, %g5
F00032F0: ca014000                 ld      [%g5], %g5
F00032F4: c221600c                 st      %g1, [%g5+0xC]
F00032F8: 9c100017                 mov     %l7, %sp
F00032FC: 808d2100                 btst    0x100, %l4
F0003300: 128001af                 bne     interrupt
F0003304: 80a52080                 cmp     %l4, 0x80
F0003308: 0280016f                 be      syscall
F000330C: 80a52090                 cmp     %l4, 0x90
F0003310: 02800177                 be      machcall
F0003314: 808d2200                 btst    0x200, %l4
F0003318: 3280017f                 bne,a   fault
F000331C: a82d2200                 bclr    0x200, %l4
F0003320: 80a52008                 cmp     %l4, 8
F0003324: 0282479a                 be      _fp_exception
F0003328: 80a52004                 cmp     %l4, 4
F000332C: 02824895                 be      _fp_disabled
F0003330: 80a52083                 cmp     %l4, 0x83
F0003334: 1280000c                 bne     loc_F0003364
F0003338: 818c2020                 saved
F000333C: 01000000                 nop
F0003340: 01000000                 nop
F0003344: 01000000                 nop
F0003348: 400006ed                 call    _flush_user_windows
F000334C: 01000000                 nop
F0003350: c201623c                 ld      [%g5+0x23C], %g1
F0003354: c2216238                 st      %g1, [%g5+0x238]
F0003358: 82006004                 inc     4, %g1
F000335C: 10800051                 ba      sys_rtt
F0003360: c221623c                 st      %g1, [%g5+0x23C]
F0003364: 90100014                 mov     %l4, %o0
F0003368: 94100000                 clr     %o2
F000336C: 96100000                 clr     %o3
F0003370: 808c2040                 btst    0x40, %l0 ! '@'
F0003374: 32800006                 bne,a   loc_F000338C
F0003378: 9203a05c                 add     %sp, arg_5C, %o1
F000337C: 0b3c04288a116024         set     _active_pcb, %g5
F0003384: ca014000                 ld      [%g5], %g5
F0003388: 92016234                 add     %g5, 0x234, %o1
F000338C: 40029561                 call    _trap
F0003390: 98102000                 mov     0, %o4
F0003394: 30800043                 ba,a    sys_rtt
F0003398: 0b3c04288a116024         set     _active_pcb, %g5
F00033A0: ca014000                 ld      [%g5], %g5
F00033A4: c401600c                 ld      [%g5+0xC], %g2
F00033A8: 80908000                 tst     %g2
F00033AC: 12800010                 bne     loc_F00033EC
F00033B0: 8334e001                 srl     %l3, 1, %g1
F00033B4: a72cc016                 sll     %l3, %l6, %l3
F00033B8: 8214c001                 bset    %l3, %g1
F00033BC: 81e00000                 save
F00033C0: 81904000                 wrpr    %g1, %g0, %tpc
F00033C4: e03ba000                 std     %l0, [%sp+arg_0]
F00033C8: e43ba008                 std     %l2, [%sp+arg_8]
F00033CC: e83ba010                 std     %l4, [%sp+arg_10]
F00033D0: ec3ba018                 std     %l6, [%sp+arg_18]
F00033D4: f03ba020                 std     %i0, [%sp+arg_20]
F00033D8: f43ba028                 std     %i2, [%sp+arg_28]
F00033DC: f83ba030                 std     %i4, [%sp+arg_30]
F00033E0: fc3ba038                 std     %fp, [%sp+arg_38]
F00033E4: 10bfffc5                 ba      loc_F00032F8
F00033E8: 81e80000                 restore
F00033EC: a72cc016                 sll     %l3, %l6, %l3
F00033F0: 8214c001                 bset    %l3, %g1
F00033F4: 84288001                 bclr    %g1, %g2
F00033F8: 0b3c04288a116024         set     _active_pcb, %g5
F0003400: ca014000                 ld      [%g5], %g5
F0003404: c421600c                 st      %g2, [%g5+0xC]
F0003408: 81e00000                 save
F000340C: 81904000                 wrpr    %g1, %g0, %tpc
F0003410: 808ba007                 btst    7, %sp
F0003414: 1280000b                 bne     loc_F0003440
F0003418: 033c0000                 sethi   -0x10000000, %g1
F000341C: 80a0400e                 cmp     %g1, %sp
F0003420: 188248ca                 bgu     _mmu_sys_ovf
F0003424: 01000000                 nop
F0003428: 8210208e                 mov     0x8E, %g1
F000342C: 10800005                 ba      loc_F0003440
F0003430: 8410000e                 mov     %sp, %g2
