F00091A0: 9de3bf88                 save    %sp, -0x78, %sp
F00091A4: 4000150d                 call    _pqinit
F00091A8: 213c0442                 sethi   %hi(_kernel_task), %l0
F00091AC: 113c04d1                 sethi   %hi(_kernel_proc), %o0
F00091B0: e4022348                 ld      [%o0+%lo(_kernel_proc)], %l2
F00091B4: d0042250                 ld      [%l0+%lo(_kernel_task)], %o0
F00091B8: e422203c                 st      %l2, [%o0+0x3C]
F00091BC: c034a030                 clrh    [%l2+0x30]
F00091C0: 400014d5                 call    _pidhash_enter
F00091C4: 90100012                 mov     %l2, %o0
F00091C8: d0042250                 ld      [%l0+%lo(_kernel_task)], %o0
F00091CC: 4002366f                 call    _splusclock
F00091D0: d024a068                 st      %o0, [%l2+0x68]
F00091D4: 400236d4                 call    _splx
F00091D8: 213c04cf                 sethi   %hi(_active_u), %l0
F00091DC: 4001b527                 call    _calloutInitialize
F00091E0: a2102000                 mov     0, %l1
F00091E4: 113c04d0                 sethi   %hi(_active_threads), %o0
F00091E8: 40001307                 call    _switch_unix_context
F00091EC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00091F0: 90102003                 mov     3, %o0
F00091F4: d02ca013                 stb     %o0, [%l2+0x13]
F00091F8: c02ca015                 clrb    [%l2+0x15]
F00091FC: c024a070                 clr     [%l2+0x70]
F0009200: c024a074                 clr     [%l2+0x74]
F0009204: c024a078                 clr     [%l2+0x78]
F0009208: d004a028                 ld      [%l2+0x28], %o0
F000920C: 90122003                 bset    3, %o0
F0009210: d024a028                 st      %o0, [%l2+0x28]
F0009214: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F0009218: 400019f1                 call    _crget
F000921C: e4220000                 st      %l2, [%o0]
F0009220: d20421d8                 ld      [%l0+0x1D8], %o1
F0009224: d022601c                 st      %o0, [%o1+0x1C]
F0009228: 133c0429                 sethi   %hi(_cmask), %o1
F000922C: d40421d8                 ld      [%l0+0x1D8], %o2
F0009230: 111fffff                 sethi   0x7FFFFC00, %o0
F0009234: d20263d4                 ld      [%o1+%lo(_cmask)], %o1
F0009238: 961223ff                 or      %o0, 0x3FF, %o3
F000923C: d232a16a                 sth     %o1, [%o2+0x16A]
F0009240: d20421d8                 ld      [%l0+0x1D8], %o1
F0009244: 90103fff                 mov     -1, %o0
F0009248: d0226154                 st      %o0, [%o1+0x154]
F000924C: 932c6003                 sll     %l1, 3, %o1
F0009250: a2046001                 inc     %l1
F0009254: d00421d8                 ld      [%l0+0x1D8], %o0
F0009258: 80a46005                 cmp     %l1, 5
F000925C: 90020009                 add     %o0, %o1, %o0
F0009260: d6222264                 st      %o3, [%o0+0x264]
F0009264: 08bffffa                 bleu    loc_F000924C
F0009268: d6222260                 st      %o3, [%o0+0x260]
F000926C: 173c04cf                 sethi   %hi(_active_u), %o3
F0009270: d402e1d8                 ld      [%o3+%lo(_active_u)], %o2
F0009274: 113c0429                 sethi   %hi(_vm_initial_limit_stack), %o0
F0009278: d20223d8                 ld      [%o0+%lo(_vm_initial_limit_stack)], %o1
F000927C: d222a278                 st      %o1, [%o2+0x278]
F0009280: 901223d8                 bset    %lo(_vm_initial_limit_stack), %o0
F0009284: d0022004                 ld      [%o0+4], %o0
F0009288: d022a27c                 st      %o0, [%o2+0x27C]
F000928C: d402e1d8                 ld      [%o3+%lo(_active_u)], %o2
F0009290: 113c0429                 sethi   %hi(_vm_initial_limit_data), %o0
F0009294: d20223e0                 ld      [%o0+%lo(_vm_initial_limit_data)], %o1
F0009298: a2102000                 mov     0, %l1
F000929C: d222a270                 st      %o1, [%o2+0x270]
F00092A0: 901223e0                 bset    %lo(_vm_initial_limit_data), %o0
F00092A4: 133c04d2981260b0         set     _posix_proc_hash, %o4
F00092AC: d0022004                 ld      [%o0+4], %o0
F00092B0: 133c04d1                 sethi   %hi(_pgrphash), %o1
F00092B4: d022a274                 st      %o0, [%o2+0x274]
F00092B8: d602e1d8                 ld      [%o3+0x1D8], %o3
F00092BC: 113c0429                 sethi   %hi(_vm_initial_limit_core), %o0
F00092C0: d40223e8                 ld      [%o0+%lo(_vm_initial_limit_core)], %o2
F00092C4: 921263b0                 bset    %lo(_pgrphash), %o1
F00092C8: d422e280                 st      %o2, [%o3+0x280]
F00092CC: 901223e8                 bset    %lo(_vm_initial_limit_core), %o0
F00092D0: d0022004                 ld      [%o0+4], %o0
F00092D4: 94102000                 mov     0, %o2
F00092D8: d022e284                 st      %o0, [%o3+0x284]
F00092DC: c0228009                 clr     [%o2+%o1]
F00092E0: c022800c                 clr     [%o2+%o4]
F00092E4: a2046001                 inc     %l1
F00092E8: 80a4603f                 cmp     %l1, 0x3F ! '?'
F00092EC: 04bffffc                 ble     loc_F00092DC
F00092F0: 9402a004                 inc     4, %o2
F00092F4: 40001653                 call    _new_posix_proc
F00092F8: 90102000                 mov     0, %o0
F00092FC: 193c04d196132390         set     _pgrp0, %o3
F0009304: d6222010                 st      %o3, [%o0+0x10]
F0009308: c022200c                 clr     [%o0+0xC]
F000930C: 213c04cf                 sethi   %hi(_active_u), %l0
F0009310: d20421d8                 ld      [%l0+%lo(_active_u)], %o1
F0009314: d202601c                 ld      [%o1+0x1C], %o1
F0009318: d2126006                 lduh    [%o1+6], %o1
F000931C: d2322004                 sth     %o1, [%o0+4]
F0009320: d20421d8                 ld      [%l0+%lo(_active_u)], %o1
F0009324: d202601c                 ld      [%o1+0x1C], %o1
F0009328: d2126002                 lduh    [%o1+2], %o1
F000932C: d2322006                 sth     %o1, [%o0+6]
F0009330: d20421d8                 ld      [%l0+%lo(_active_u)], %o1
F0009334: 153c04d2                 sethi   %hi(_px), %o2
F0009338: d202601c                 ld      [%o1+0x1C], %o1
F000933C: d022a1b8                 st      %o0, [%o2+%lo(_px)]
F0009340: d2126004                 lduh    [%o1+4], %o1
F0009344: 15200000                 sethi   0x80000000, %o2
F0009348: d2322008                 sth     %o1, [%o0+8]
F000934C: d2022018                 ld      [%o0+0x18], %o1
F0009350: c0222014                 clr     [%o0+0x14]
F0009354: 942a400a                 andn    %o1, %o2, %o2
F0009358: 13100000                 sethi   0x40000000, %o1
F000935C: 922a8009                 andn    %o2, %o1, %o1
F0009360: d2222018                 st      %o1, [%o0+0x18]
F0009364: 113c04d1                 sethi   %hi(_pgrphash), %o0
F0009368: d62223b0                 st      %o3, [%o0+%lo(_pgrphash)]
F000936C: e422e004                 st      %l2, [%o3+4]
F0009370: 153c04d29212a1d0         set     _session0, %o1
F0009378: d222e008                 st      %o1, [%o3+8]
F000937C: c0232390                 clr     [%o4+0x390]
F0009380: c022e010                 clr     [%o3+0x10]
F0009384: 90102001                 mov     1, %o0
F0009388: d022a1d0                 st      %o0, [%o2+0x1D0]
F000938C: e4226004                 st      %l2, [%o1+4]
F0009390: c0226008                 clr     [%o1+8]
F0009394: 40020495                 call    _gc_init
F0009398: c032600c                 clrh    [%o1+0xC]
F000939C: 9207bff4                 add     %fp, var_C, %o1
F00093A0: 9407bff0                 add     %fp, var_10, %o2
F00093A4: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00093A8: 17000200                 sethi   0x80000, %o3
F00093AC: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00093B0: 4001e988                 call    _kmem_suballoc
F00093B4: 98102001                 mov     1, %o4
F00093B8: 133c04d0                 sethi   %hi(_kernel_pageable_map), %o1
F00093BC: 4001934a                 call    _ns_hardclock_init
F00093C0: d02260c0                 st      %o0, [%o1+%lo(_kernel_pageable_map)]
F00093C4: 40018b32                 call    _mfs_init
F00093C8: a2102001                 mov     1, %l1
F00093CC: d00421d8                 ld      [%l0+0x1D8], %o0
F00093D0: 92102001                 mov     1, %o1
F00093D4: 40017e4d                 call    _lock_init
F00093D8: 90022020                 inc     0x20, %o0 ! ' '
F00093DC: d00421d8                 ld      [%l0+0x1D8], %o0
F00093E0: d202201c                 ld      [%o0+0x1C], %o1
F00093E4: d0124000                 lduh    [%o1], %o0
F00093E8: 90022001                 inc     %o0
F00093EC: d0324000                 sth     %o0, [%o1]
F00093F0: d00421d8                 ld      [%l0+0x1D8], %o0
F00093F4: d202201c                 ld      [%o0+0x1C], %o1
F00093F8: 94103fff                 mov     -1, %o2
F00093FC: 113c04d2                 sethi   %hi(_rootcred), %o0
F0009400: d22221c0                 st      %o1, [%o0+%lo(_rootcred)]
F0009404: 912c6001                 sll     %l1, 1, %o0
F0009408: d20421d8                 ld      [%l0+0x1D8], %o1
F000940C: a2046001                 inc     %l1
F0009410: d202601c                 ld      [%o1+0x1C], %o1
F0009414: 80a4600f                 cmp     %l1, 0xF
F0009418: 90020009                 add     %o0, %o1, %o0
F000941C: 04bffffa                 ble     loc_F0009404
F0009420: d432200a                 sth     %o2, [%o0+0xA]
F0009424: 4000509b                 call    _mbinit
F0009428: a2102000                 mov     0, %l1
F000942C: 40000125                 call    _cinit
F0009430: 2b3c0442                 sethi   -0xFEEF800, %l5
F0009434: 40023618                 call    _splnet
F0009438: 273c01c8                 sethi   -0xFF8E000, %l3
F000943C: 40008120                 call    _ifinit
F0009440: a0100008                 mov     %o0, %l0
F0009444: 40004fa5                 call    _domaininit
F0009448: a4102000                 mov     0, %l2
F000944C: 40023636                 call    _splx
F0009450: 90100010                 mov     %l0, %o0
F0009454: 400000b2                 call    _bhinit
F0009458: a0102000                 mov     0, %l0
F000945C: 40007096                 call    _dnlc_init
F0009460: 01000000                 nop
F0009464: 113c04d1ac122360         set     _machine_slot, %l6
F000946C: 113c04d2a81221b0         set     _processor_ptr, %l4
F0009474: 133c04cf                 sethi   %hi(_active_u), %o1! child_act
F0009478: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F000947C: c0222160                 clr     [%o0+0x160]
F0009480: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F0009484: c022215c                 clr     [%o0+0x15C]
F0009488: d0040016                 ld      [%l0+%l6], %o0
F000948C: 80a22000                 cmp     %o0, 0
F0009490: 22800010                 be,a    loc_F00094D0
F0009494: a404a004                 inc     4, %l2
F0009498: d0056250                 ld      [%l5+0x250], %o0! parent_task
F000949C: 4001ab1a                 call    _thread_create
F00094A0: 9207bfec                 add     %fp, target_act, %o1
F00094A4: d007bfec                 ld      [%fp+target_act], %o0
F00094A8: 40019f4e                 call    _thread_bind
F00094AC: d2048014                 ld      [%l2+%l4], %o1
F00094B0: d007bfec                 ld      [%fp+target_act], %o0
F00094B4: 4001b15c                 call    _thread_start
F00094B8: 9214e350                 or      %l3, 0x350, %o1
F00094BC: 4001b40e                 call    _thread_doswapin
F00094C0: d007bfec                 ld      [%fp+target_act], %o0! target_act
F00094C4: 4001b035                 call    _thread_resume
F00094C8: d007bfec                 ld      [%fp+target_act], %o0
F00094CC: a404a004                 inc     4, %l2
F00094D0: a2046001                 inc     %l1
F00094D4: 80a46000                 cmp     %l1, 0
F00094D8: 04bfffec                 ble     loc_F0009488
F00094DC: a0042020                 inc     0x20, %l0 ! ' '
F00094E0: 4000009d                 call    _binit
F00094E4: 253c0442                 sethi   %hi(_kernel_task), %l2
F00094E8: 4001a138                 call    _recompute_priorities
F00094EC: 233c04cf                 sethi   -0xFECC400, %l1
F00094F0: 90102000                 mov     0, %o0
F00094F4: 4000006f                 call    _lightning_bolt
F00094F8: 92102000                 mov     0, %o1
F00094FC: 133c01d692126384         set     _reaper_thread, %o1
F0009504: d004a250                 ld      [%l2+%lo(_kernel_task)], %o0
F0009508: 4001b14b                 call    _kernel_thread
F000950C: 94102000                 mov     0, %o2
F0009510: 133c01d992126258         set     _swapin_thread, %o1
F0009518: d004a250                 ld      [%l2+%lo(_kernel_task)], %o0
F000951C: 4001b146                 call    _kernel_thread
F0009520: 94102000                 mov     0, %o2
F0009524: 133c01c992126028         set     _sched_thread, %o1
F000952C: d004a250                 ld      [%l2+%lo(_kernel_task)], %o0
F0009530: 4001b141                 call    _kernel_thread
F0009534: 94102000                 mov     0, %o2
F0009538: 133c00b192126018         set     _netisr_thread, %o1
F0009540: d004a250                 ld      [%l2+0x250], %o0
F0009544: 4001b13c                 call    _kernel_thread
F0009548: 94102000                 mov     0, %o2
F000954C: 4003a76a                 call    __objcInit
F0009550: 213c04d2                 sethi   -0xFECB800, %l0
F0009554: 113c0024                 sethi   %hi(sub_F0009194), %o0! int (__cdecl *)(const char *)
F0009558: 4003a1e8                 call    _objc_setClassHandler
F000955C: 90122194                 bset    %lo(sub_F0009194), %o0
F0009560: 4002cdc9                 call    _kmEnableAnimation
F0009564: 01000000                 nop
F0009568: 40020b88                 call    _autoconf
F000956C: 01000000                 nop
F0009570: 40027674                 call    _setconf
F0009574: 01000000                 nop
F0009578: 4000830c                 call    _loattach
F000957C: 01000000                 nop
F0009580: d00461dc                 ld      [%l1+0x1DC], %o0
F0009584: c02a2038                 clrb    [%o0+0x38]
F0009588: 400069f0                 call    _vfs_mountroot
F000958C: a21461dc                 bset    0x1DC, %l1
F0009590: d2047ffc                 ld      [%l1-4], %o1
F0009594: 9010200f                 mov     0xF, %o0
F0009598: 4000077f                 call    _file_init
F000959C: d02a625c                 stb     %o0, [%o1+0x25C]
F00095A0: 400010c1                 call    _newproc
F00095A4: 90102000                 mov     0, %o0
F00095A8: d202200c                 ld      [%o0+0xC], %o1
F00095AC: d027bfec                 st      %o0, [%fp+target_act]
F00095B0: 90102001                 mov     1, %o0
F00095B4: 400013c3                 call    _pfind
F00095B8: c022604c                 clr     [%o1+0x4C]
F00095BC: 133c04d1                 sethi   %hi(_init_proc), %o1! which_port
F00095C0: 4002cdde                 call    _kmDisableAnimation
F00095C4: d0226338                 st      %o0, [%o1+%lo(_init_proc)]
F00095C8: 4001dea4                 call    _ux_handler_init
F00095CC: 01000000                 nop
F00095D0: 40017a31                 call    _port_reference
F00095D4: d00421e0                 ld      [%l0+0x1E0], %o0
F00095D8: d007bfec                 ld      [%fp+target_act], %o0
F00095DC: d40421e0                 ld      [%l0+0x1E0], %o2! special_port
F00095E0: d002200c                 ld      [%o0+0xC], %o0! task
F00095E4: 4001779e                 call    _task_set_special_port
F00095E8: 92102003                 mov     3, %o1
F00095EC: 133c0025                 sethi   %hi(_init_task), %o1
F00095F0: d007bfec                 ld      [%fp+target_act], %o0! target_act
F00095F4: 4001b10c                 call    _thread_start
F00095F8: 92126270                 bset    %lo(_init_task), %o1
F00095FC: 4001afe7                 call    _thread_resume
F0009600: d007bfec                 ld      [%fp+target_act], %o0
F0009604: 400194a2                 call    _power_init
F0009608: 01000000                 nop
F000960C: 133c021f92126390         set     _vm_pageout, %o1
F0009614: d004a250                 ld      [%l2+0x250], %o0
F0009618: 4001b107                 call    _kernel_thread
F000961C: 94102000                 mov     0, %o2
F0009620: 133c04d1                 sethi   %hi(_pageoutThread), %o1
F0009624: 40022ade                 call    _vol_start_thread
F0009628: d0226388                 st      %o0, [%o1+%lo(_pageoutThread)]
F000962C: 4001c74d                 call    _pnotify_start
F0009630: 01000000                 nop
F0009634: d0047ffc                 ld      [%l1-4], %o0
F0009638: d4020000                 ld      [%o0], %o2
F000963C: 113c0429                 sethi   %hi(aKernelIdle), %o0! "kernel idle"
F0009640: d202a028                 ld      [%o2+0x28], %o1
F0009644: 901223f0                 bset    %lo(aKernelIdle), %o0! "kernel idle"
F0009648: 92126003                 bset    3, %o1
F000964C: 7ffffec4                 call    _task_name
F0009650: d222a028                 st      %o1, [%o2+0x28]
F0009654: 113c04d0                 sethi   %hi(_active_threads), %o0! target_act
F0009658: 4001ac8f                 call    _thread_terminate
F000965C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0009660: 4001aeab                 call    _thread_halt_self
F0009664: 01000000                 nop
F0009668: 81c7e008                 ret
F000966C: 81e80000                 restore
