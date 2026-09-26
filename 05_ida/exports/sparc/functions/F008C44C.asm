F008C44C: 9de3bf98                 save    %sp, -0x68, %sp
F008C450: 113c0442                 sethi   %hi(_kernel_task), %o0
F008C454: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0! target_task
F008C458: 92102000                 mov     0, %o1! ledgers
F008C45C: 233c04f6                 sethi   %hi(_IOTask_kern), %l1
F008C460: 7fff9a9e                 call    _task_create
F008C464: 941461b8                 or      %l1, %lo(_IOTask_kern), %o2
F008C468: 92920000                 orcc    %o0, %g0, %o1
F008C46C: 02800006                 be      loc_F008C484
F008C470: 01000000                 nop
F008C474: 113c0447                 sethi   %hi(aIolibioinitTas), %o0! "IOLibIOInit task_create returned %d\n"
F008C478: 4000e71f                 call    _IOLog
F008C47C: 901223b0                 bset    %lo(aIolibioinitTas), %o0! "IOLibIOInit task_create returned %d\n"
F008C480: 30800024                 ba,a    locret_F008C510
F008C484: 7fff9b09                 call    _task_deallocate
F008C488: d00461b8                 ld      [%l1+0x1B8], %o0
F008C48C: d00461b8                 ld      [%l1+0x1B8], %o0
F008C490: 7fffdf5f                 call    _vm_map_deallocate
F008C494: d002200c                 ld      [%o0+0xC], %o0
F008C498: 92102001                 mov     1, %o1
F008C49C: d40461b8                 ld      [%l1+0x1B8], %o2
F008C4A0: 113c04d1                 sethi   %hi(_kernel_map), %o0
F008C4A4: d6022340                 ld      [%o0+%lo(_kernel_map)], %o3
F008C4A8: 213c04d1                 sethi   %hi(_kernel_proc), %l0
F008C4AC: d622a00c                 st      %o3, [%o2+0xC]
F008C4B0: d0042348                 ld      [%l0+%lo(_kernel_proc)], %o0
F008C4B4: 96102001                 mov     1, %o3
F008C4B8: d022a03c                 st      %o0, [%o2+0x3C]
F008C4BC: d002a038                 ld      [%o2+0x38], %o0
F008C4C0: d622a050                 st      %o3, [%o2+0x50]
F008C4C4: 7fff7211                 call    _lock_init
F008C4C8: 90022020                 inc     0x20, %o0 ! ' '
F008C4CC: d40461b8                 ld      [%l1+0x1B8], %o2
F008C4D0: 113c04d2                 sethi   %hi(_rootcred), %o0
F008C4D4: d00221c0                 ld      [%o0+%lo(_rootcred)], %o0
F008C4D8: d202a038                 ld      [%o2+0x38], %o1
F008C4DC: d022601c                 st      %o0, [%o1+0x1C]
F008C4E0: 113c04d3                 sethi   %hi(_default_pset), %o0
F008C4E4: d602a038                 ld      [%o2+0x38], %o3
F008C4E8: 901223c0                 bset    %lo(_default_pset), %o0! processor_set
F008C4EC: d4042348                 ld      [%l0+0x348], %o2
F008C4F0: 92102002                 mov     2, %o1! policy
F008C4F4: 7fff8c02                 call    _processor_set_policy_enable
F008C4F8: d422c000                 st      %o2, [%o3]
F008C4FC: d00461b8                 ld      [%l1+0x1B8], %o0
F008C500: 4000f760                 call    _IOTaskGetPort
F008C504: d002206c                 ld      [%o0+0x6C], %o0
F008C508: 133c04f6                 sethi   %hi(_IOTask), %o1
F008C50C: d02261b0                 st      %o0, [%o1+%lo(_IOTask)]
F008C510: 81c7e008                 ret
F008C514: 81e80000                 restore
