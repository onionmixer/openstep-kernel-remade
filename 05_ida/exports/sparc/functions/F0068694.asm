F0068694: 9de3bf98                 save    %sp, -0x68, %sp
F0068698: b2102001                 mov     1, %i1
F006869C: a2102000                 mov     0, %l1
F00686A0: a0102000                 mov     0, %l0
F00686A4: 293c043e                 sethi   -0xFEF0800, %l4
F00686A8: 273c04bd                 sethi   -0xFED0C00, %l3
F00686AC: 113c04f0a41220c0         set     _stackStats, %l2
F00686B4: 2f3c043e                 sethi   -0xFEF0800, %l7
F00686B8: 2d3c04f0aa15a0e0         set     _stack_queue_lock, %l5
F00686C0: 400001c1                 call    _lock_write
F00686C4: 9015a0e0                 or      %l6, 0xE0, %o0
F00686C8: d0052300                 ld      [%l4+0x300], %o0
F00686CC: 80a22000                 cmp     %o0, 0
F00686D0: 02800019                 be      loc_F0068734
F00686D4: d204e270                 ld      [%l3+0x270], %o1
F00686D8: 9414e270                 or      %l3, 0x270, %o2
F00686DC: 80a2400a                 cmp     %o1, %o2
F00686E0: 32800004                 bne,a   loc_F00686F0
F00686E4: d0024000                 ld      [%o1], %o0
F00686E8: 10800006                 ba      loc_F0068700
F00686EC: b0102000                 mov     0, %i0
F00686F0: d4222004                 st      %o2, [%o0+4]
F00686F4: d0024000                 ld      [%o1], %o0
F00686F8: b0100009                 mov     %o1, %i0
F00686FC: d024e270                 st      %o0, [%l3+0x270]
F0068700: 90102002                 mov     2, %o0
F0068704: d0262008                 st      %o0, [%i0+8]
F0068708: d0052300                 ld      [%l4+0x300], %o0
F006870C: b006200c                 inc     0xC, %i0
F0068710: d204a008                 ld      [%l2+8], %o1
F0068714: 90023fff                 inc     -1, %o0
F0068718: d0252300                 st      %o0, [%l4+0x300]
F006871C: 92027fff                 inc     -1, %o1
F0068720: d004a004                 ld      [%l2+4], %o0
F0068724: d224a008                 st      %o1, [%l2+8]
F0068728: 90022001                 inc     %o0
F006872C: 10800003                 ba      loc_F0068738
F0068730: d024a004                 st      %o0, [%l2+4]
F0068734: b0102000                 mov     0, %i0
F0068738: 4000023f                 call    _lock_done
F006873C: 9015a0e0                 or      %l6, 0xE0, %o0
F0068740: 80a66000                 cmp     %i1, 0
F0068744: 02800036                 be      loc_F006881C
F0068748: 80a62000                 cmp     %i0, 0
F006874C: 1280002c                 bne     loc_F00687FC
F0068750: 80a46000                 cmp     %l1, 0
F0068754: 7fffff99                 call    _newStack
F0068758: 01000000                 nop
F006875C: b0920000                 orcc    %o0, %g0, %i0
F0068760: 12800027                 bne     loc_F00687FC
F0068764: 80a46000                 cmp     %l1, 0
F0068768: 02800005                 be      loc_F006877C
F006876C: 80a42000                 cmp     %l0, 0
F0068770: 0280000d                 be      loc_F00687A4
F0068774: 90102000                 mov     0, %o0
F0068778: 3080002a                 ba,a    locret_F0068820
F006877C: 113c043e                 sethi   %hi(aMachOutOfKerne), %o0! "MACH: Out of kernel stacks, pausing..."
F0068780: 7ffeafc8                 call    _uprintf
F0068784: 90122310                 bset    %lo(aMachOutOfKerne), %o0! "MACH: Out of kernel stacks, pausing..."
F0068788: d005e308                 ld      [%l7+0x308], %o0
F006878C: 80a22000                 cmp     %o0, 0
F0068790: 12800005                 bne     loc_F00687A4
F0068794: a2102001                 mov     1, %l1
F0068798: 113c043e                 sethi   %hi(aStackAllocKern), %o0! "stack_alloc: Kernel stacks exhausted\n"
F006879C: 7ffeafaf                 call    _printf
F00687A0: 90122338                 bset    %lo(aStackAllocKern), %o0! "stack_alloc: Kernel stacks exhausted\n"
F00687A4: 40000188                 call    _lock_write
F00687A8: 90100015                 mov     %l5, %o0
F00687AC: d0052300                 ld      [%l4+0x300], %o0
F00687B0: 80a22000                 cmp     %o0, 0
F00687B4: 02800006                 be      loc_F00687CC
F00687B8: 9014e270                 or      %l3, 0x270, %o0
F00687BC: 4000021e                 call    _lock_done
F00687C0: 90100015                 mov     %l5, %o0
F00687C4: 10800013                 ba      loc_F0068810
F00687C8: a0102000                 mov     0, %l0
F00687CC: 40002142                 call    _assert_wait
F00687D0: 92102000                 mov     0, %o1
F00687D4: 90102001                 mov     1, %o0
F00687D8: d025e308                 st      %o0, [%l7+0x308]
F00687DC: 40000216                 call    _lock_done
F00687E0: 90100015                 mov     %l5, %o0
F00687E4: 400027b7                 call    _thread_block
F00687E8: 01000000                 nop
F00687EC: 113c04d0                 sethi   %hi(_active_threads), %o0
F00687F0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00687F4: 10800007                 ba      loc_F0068810
F00687F8: e0022044                 ld      [%o0+0x44], %l0
F00687FC: 02800006                 be      loc_F0068814
F0068800: 80a62000                 cmp     %i0, 0
F0068804: 113c043e                 sethi   %hi(aContinuing_0), %o0! "continuing\n"
F0068808: 7ffeafa6                 call    _uprintf
F006880C: 90122360                 bset    %lo(aContinuing_0), %o0! "continuing\n"
F0068810: 80a62000                 cmp     %i0, 0
F0068814: 02bfffab                 be      loc_F00686C0
F0068818: 01000000                 nop
F006881C: 90100018                 mov     %i0, %o0
F0068820: 81c7e008                 ret
F0068824: 91e80008                 restore %g0, %o0, %o0
