F000C3F0: 9de3bf80                 save    %sp, -0x80, %sp! int
F000C3F4: a2102000                 mov     0, %l1
F000C3F8: 273c046c                 sethi   %hi(_boothowto), %l3
F000C3FC: 2d3c042ba415a2e8         set     _init_program_name, %l2! "/etc/mach_init"
F000C404: 2b3c042b                 sethi   -0xFEF5400, %l5
F000C408: 113c042cb0122000         set     aEtcInit, %i0! "/etc/init"
F000C410: 113c04d2a8122240         set     _init_exec_args, %l4
F000C418: 2f3c04cf                 sethi   -0xFECC400, %l7
F000C41C: d004e104                 ld      [%l3+%lo(_boothowto)], %o0
F000C420: 808a2010                 btst    0x10, %o0
F000C424: 02800007                 be      loc_F000C440
F000C428: 113c042b                 sethi   %hi(aInitProgram), %o0! "init program? "
F000C42C: 4000208b                 call    _printf
F000C430: 901223f0                 bset    %lo(aInitProgram), %o0! "init program? "
F000C434: 90100012                 mov     %l2, %o0! char *
F000C438: 40026b8c                 call    _gets
F000C43C: 92100012                 mov     %l2, %o1
F000C440: 80a46000                 cmp     %l1, 0
F000C444: 02800013                 be      loc_F000C490
F000C448: d004e104                 ld      [%l3+0x104], %o0
F000C44C: 808a2010                 btst    0x10, %o0
F000C450: 12800011                 bne     loc_F000C494
F000C454: d00563e8                 ld      [%l5+0x3E8], %o0
F000C458: 80a22001                 cmp     %o0, 1
F000C45C: 1280000f                 bne     loc_F000C498
F000C460: 80a46000                 cmp     %l1, 0
F000C464: 113c042c90122010         set     aLoadOfSErrnoDT, %o0! "Load of %s, errno %d, trying %s\n"
F000C46C: 92100012                 mov     %l2, %o1
F000C470: 94100011                 mov     %l1, %o2! size_t
F000C474: 40002079                 call    _printf
F000C478: 96100018                 mov     %i0, %o3! flags
F000C47C: a2102000                 mov     0, %l1
F000C480: 90100018                 mov     %i0, %o0! void *
F000C484: 92100012                 mov     %l2, %o1! void *
F000C488: 400221a2                 call    _bcopy
F000C48C: 9410200a                 mov     0xA, %o2
F000C490: d00563e8                 ld      [%l5+0x3E8], %o0
F000C494: 80a46000                 cmp     %l1, 0
F000C498: 90022001                 inc     %o0
F000C49C: 0280000c                 be      loc_F000C4CC
F000C4A0: d02563e8                 st      %o0, [%l5+0x3E8]
F000C4A4: 113c042c90122038         set     aLoadOfSFailedE, %o0! "Load of %s failed, errno %d\n"
F000C4AC: 9215a2e8                 or      %l6, 0x2E8, %o1
F000C4B0: 4000206a                 call    _printf
F000C4B4: 94100011                 mov     %l1, %o2
F000C4B8: d004e104                 ld      [%l3+0x104], %o0
F000C4BC: a2102000                 mov     0, %l1
F000C4C0: 90122010                 bset    0x10, %o0
F000C4C4: 10800035                 ba      loc_F000C598
F000C4C8: d024e104                 st      %o0, [%l3+0x104]
F000C4CC: 113c0447                 sethi   %hi(_page_size), %o0
F000C4D0: d402213c                 ld      [%o0+%lo(_page_size)], %o2! int
F000C4D4: 113c04d0                 sethi   %hi(_active_threads), %o0
F000C4D8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000C4DC: c027bfe4                 clr     [%fp+__envp]
F000C4E0: d002200c                 ld      [%o0+0xC], %o0
F000C4E4: 9207bfe4                 add     %fp, __envp, %o1! address
F000C4E8: d002200c                 ld      [%o0+0xC], %o0! target_task
F000C4EC: 4001f8cd                 call    _vm_allocate
F000C4F0: 96102001                 mov     1, %o3! int
F000C4F4: d007bfe4                 ld      [%fp+__envp], %o0
F000C4F8: 80a22000                 cmp     %o0, 0
F000C4FC: 12800005                 bne     loc_F000C510
F000C500: 9015a2e8                 or      %l6, 0x2E8, %o0
F000C504: 90102001                 mov     1, %o0
F000C508: d027bfe4                 st      %o0, [%fp+__envp]
F000C50C: 9015a2e8                 or      %l6, 0x2E8, %o0! int
F000C510: d207bfe4                 ld      [%fp+__envp], %o1! int
F000C514: 40022eee                 call    _copyout
F000C518: 94102081                 mov     0x81, %o2
F000C51C: 113c042b90122368         set     _init_args, %o0! "-xx"
F000C524: d207bfe4                 ld      [%fp+__envp], %o1
F000C528: 94102080                 mov     0x80, %o2! int
F000C52C: d227bfe8                 st      %o1, [%fp+__argv]
F000C530: 9202608f                 inc     0x8F, %o1
F000C534: 920a7ff0                 and     %o1, -0x10, %o1! int
F000C538: 40022ee5                 call    _copyout
F000C53C: d227bfe4                 st      %o1, [%fp+__envp]
F000C540: c027bff0                 clr     [%fp+var_10]
F000C544: 9007bfe8                 add     %fp, __argv, %o0! int
F000C548: d207bfe4                 ld      [%fp+__envp], %o1
F000C54C: 9410200c                 mov     0xC, %o2! int
F000C550: d227bfec                 st      %o1, [%fp+var_14]
F000C554: 9202608f                 inc     0x8F, %o1
F000C558: 920a7ff0                 and     %o1, -0x10, %o1! int
F000C55C: 40022edc                 call    _copyout
F000C560: d227bfe4                 st      %o1, [%fp+__envp]
F000C564: c0252008                 clr     [%l4+8]
F000C568: d207bfe8                 ld      [%fp+__argv], %o1! __argv
F000C56C: 113c04d2                 sethi   %hi(_init_exec_args), %o0
F000C570: d407bfe4                 ld      [%fp+__envp], %o2! __envp
F000C574: d2222240                 st      %o1, [%o0+%lo(_init_exec_args)]
F000C578: d005e1dc                 ld      [%l7+0x1DC], %o0! __file
F000C57C: d4252004                 st      %o2, [%l4+4]
F000C580: e0022024                 ld      [%o0+0x24], %l0
F000C584: 7ffffcbb                 call    _execve
F000C588: e8222024                 st      %l4, [%o0+0x24]
F000C58C: d205e1dc                 ld      [%l7+0x1DC], %o1
F000C590: a2100008                 mov     %o0, %l1
F000C594: e0226024                 st      %l0, [%o1+0x24]
F000C598: 80a46000                 cmp     %l1, 0
F000C59C: 12bfffa1                 bne     loc_F000C420
F000C5A0: d004e104                 ld      [%l3+0x104], %o0
F000C5A4: 81c7e008                 ret
F000C5A8: 81e80000                 restore
