F0015170: 9de3bf98                 save    %sp, -0x68, %sp
F0015174: a2102000                 mov     0, %l1
F0015178: 113c04d4a0122218         set     _panic_lock, %l0
F0015180: d0040000                 ld      [%l0], %o0
F0015184: 80a22000                 cmp     %o0, 0
F0015188: 12bffffe                 bne     loc_F0015180
F001518C: 01000000                 nop
F0015190: 40020746                 call    _simple_lock_try
F0015194: 90100010                 mov     %l0, %o0
F0015198: 80a22000                 cmp     %o0, 0
F001519C: 02bffff9                 be      loc_F0015180
F00151A0: 133c04d4                 sethi   %hi(_panicstr), %o1
F00151A4: d0026228                 ld      [%o1+%lo(_panicstr)], %o0
F00151A8: 80a22000                 cmp     %o0, 0
F00151AC: 0280000d                 be      loc_F00151E0
F00151B0: 113c04d4                 sethi   %hi(_paniccpu), %o0
F00151B4: d0022220                 ld      [%o0+%lo(_paniccpu)], %o0
F00151B8: 80a22000                 cmp     %o0, 0
F00151BC: 12800004                 bne     loc_F00151CC
F00151C0: 113c04d4                 sethi   -0xFECB000, %o0
F00151C4: 1080000a                 ba      loc_F00151EC
F00151C8: a2146004                 bset    4, %l1
F00151CC: c0222218                 clr     [%o0+0x218]
F00151D0: 40021373                 call    _halt_cpu
F00151D4: 01000000                 nop
F00151D8: 10800005                 ba      loc_F00151EC
F00151DC: 113c04d4                 sethi   -0xFECB000, %o0
F00151E0: f0226228                 st      %i0, [%o1+0x228]
F00151E4: c0222220                 clr     [%o0+0x220]
F00151E8: 113c04d4                 sethi   -0xFECB000, %o0
F00151EC: c0222218                 clr     [%o0+0x218]
F00151F0: 113c042d901220c0         set     aPanicCpuDS, %o0! "panic: (Cpu %d) %s\n"
F00151F8: 133c04d4                 sethi   %hi(_paniccpu), %o1
F00151FC: d2026220                 ld      [%o1+%lo(_paniccpu)], %o1
F0015200: 7ffffd16                 call    _printf
F0015204: 94100018                 mov     %i0, %o2
F0015208: 113c042d901220d8         set     aPanicS, %o0! "panic: %s\n"
F0015210: 133c04bc                 sethi   %hi(_version), %o1! "NeXT Mach 4.2: Sun Apr 27 14:33:09 PDT "...
F0015214: 7ffffd11                 call    _printf
F0015218: 92126190                 bset    %lo(_version), %o1! "NeXT Mach 4.2: Sun Apr 27 14:33:09 PDT "...
F001521C: 113c042d                 sethi   %hi(aPanic), %o0! "panic"
F0015220: 133c046c                 sethi   %hi(_boothowto), %o1
F0015224: d4026104                 ld      [%o1+%lo(_boothowto)], %o2
F0015228: 901220e8                 bset    %lo(aPanic), %o0! "panic"
F001522C: 133c042d                 sethi   %hi(aSystemPanic), %o1! "System Panic"
F0015230: 40021293                 call    _mini_mon
F0015234: 921260f0                 bset    %lo(aSystemPanic), %o1! "System Panic"
F0015238: 90102000                 mov     0, %o0
F001523C: 92100011                 mov     %l1, %o1
F0015240: 153c042d                 sethi   %hi(unk_F010B500), %o2
F0015244: 7fffec90                 call    _boot
F0015248: 9412a100                 bset    %lo(unk_F010B500), %o2
F001524C: 81c7e008                 ret
F0015250: 81e80000                 restore
