F00A93F8: 9de3bf80                 save    %sp, -0x80, %sp
F00A93FC: 113c04cf                 sethi   %hi(_active_u), %o0
F00A9400: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00A9404: d0020000                 ld      [%o0], %o0
F00A9408: 80a22000                 cmp     %o0, 0
F00A940C: 02800003                 be      loc_F00A9418
F00A9410: a0103fff                 mov     -1, %l0
F00A9414: e0522030                 ldsh    [%o0+0x30], %l0
F00A9418: 7fffb5c9                 call    _splaudio
F00A941C: 01000000                 nop
F00A9420: 13000040                 sethi   0x10000, %o1
F00A9424: b02e0009                 bclr    %o1, %i0
F00A9428: 80a43fff                 cmp     %l0, -1
F00A942C: 12800007                 bne     loc_F00A9448
F00A9430: a8100008                 mov     %o0, %l4
F00A9434: 113c046f                 sethi   %hi(aUnknown_1), %o0! "(unknown): "
F00A9438: 7ffdac88                 call    _printf
F00A943C: 90122118                 bset    %lo(aUnknown_1), %o0! "(unknown): "
F00A9440: 1080000a                 ba      loc_F00A9468
F00A9444: 80a6202b                 cmp     %i0, 0x2B ! '+'
F00A9448: 113c046f                 sethi   %hi(aPidDS), %o0! "pid %d, `%s': "
F00A944C: 133c04cf                 sethi   %hi(_active_u), %o1
F00A9450: d40261d8                 ld      [%o1+%lo(_active_u)], %o2
F00A9454: 90122128                 bset    %lo(aPidDS), %o0! "pid %d, `%s': "
F00A9458: 92100010                 mov     %l0, %o1
F00A945C: 7ffdac7f                 call    _printf
F00A9460: 9402a008                 inc     8, %o2
F00A9464: 80a6202b                 cmp     %i0, 0x2B ! '+'
F00A9468: 18800008                 bgu     loc_F00A9488
F00A946C: 113c046c                 sethi   %hi(_trap_type), %o0
F00A9470: 9012237c                 bset    %lo(_trap_type), %o0
F00A9474: 932e2002                 sll     %i0, 2, %o1
F00A9478: d2024008                 ld      [%o1+%o0], %o1
F00A947C: 113c046f                 sethi   %hi(aS_4), %o0! "%s\n"
F00A9480: 1080003c                 ba      loc_F00A9570
F00A9484: 90122138                 bset    %lo(aS_4), %o0! "%s\n"
F00A9488: 80a62082                 cmp     %i0, 0x82
F00A948C: 02800021                 be      loc_F00A9510
F00A9490: 113c046f                 sethi   -0xFEE4400, %o0
F00A9494: 18800008                 bgu     loc_F00A94B4
F00A9498: 80a62080                 cmp     %i0, 0x80
F00A949C: 02800014                 be      loc_F00A94EC
F00A94A0: 80a62081                 cmp     %i0, 0x81
F00A94A4: 02800017                 be      loc_F00A9500
F00A94A8: 113c046f                 sethi   -0xFEE4400, %o0
F00A94AC: 10800029                 ba      loc_F00A9550
F00A94B0: 92063f80                 add     %i0, -0x80, %o1
F00A94B4: 80a62110                 cmp     %i0, 0x110
F00A94B8: 0280001e                 be      loc_F00A9530
F00A94BC: 113c046f                 sethi   -0xFEE4400, %o0
F00A94C0: 18800006                 bgu     loc_F00A94D8
F00A94C4: 80a62083                 cmp     %i0, 0x83
F00A94C8: 02800016                 be      loc_F00A9520
F00A94CC: 113c046f                 sethi   -0xFEE4400, %o0
F00A94D0: 10800020                 ba      loc_F00A9550
F00A94D4: 92063f80                 add     %i0, -0x80, %o1
F00A94D8: 80a62400                 cmp     %i0, 0x400
F00A94DC: 02800019                 be      loc_F00A9540
F00A94E0: 113c046f                 sethi   -0xFEE4400, %o0
F00A94E4: 1080001b                 ba      loc_F00A9550
F00A94E8: 92063f80                 add     %i0, -0x80, %o1
F00A94EC: 113c046f                 sethi   %hi(aSyscallTrap), %o0! "syscall trap:\n"
F00A94F0: 7ffdac5a                 call    _printf
F00A94F4: 90122140                 bset    %lo(aSyscallTrap), %o0! "syscall trap:\n"
F00A94F8: 10800021                 ba      loc_F00A957C
F00A94FC: 80a62009                 cmp     %i0, 9
F00A9500: 7ffdac56                 call    _printf
F00A9504: 90122150                 bset    0x150, %o0! char *
F00A9508: 1080001d                 ba      loc_F00A957C
F00A950C: 80a62009                 cmp     %i0, 9
F00A9510: 7ffdac52                 call    _printf
F00A9514: 90122168                 bset    0x168, %o0! char *
F00A9518: 10800019                 ba      loc_F00A957C
F00A951C: 80a62009                 cmp     %i0, 9
F00A9520: 7ffdac4e                 call    _printf
F00A9524: 90122180                 bset    0x180, %o0! char *
F00A9528: 10800015                 ba      loc_F00A957C
F00A952C: 80a62009                 cmp     %i0, 9
F00A9530: 7ffdac4a                 call    _printf
F00A9534: 90122198                 bset    0x198, %o0! char *
F00A9538: 10800011                 ba      loc_F00A957C
F00A953C: 80a62009                 cmp     %i0, 9
F00A9540: 7ffdac46                 call    _printf
F00A9544: 901221b0                 bset    0x1B0, %o0
F00A9548: 1080000d                 ba      loc_F00A957C
F00A954C: 80a62009                 cmp     %i0, 9
F00A9550: 80a2607f                 cmp     %o1, 0x7F
F00A9554: 18800004                 bgu     loc_F00A9564
F00A9558: 113c046f                 sethi   %hi(aSoftwareTrap0x), %o0! "software trap 0x%x\n"
F00A955C: 10800005                 ba      loc_F00A9570
F00A9560: 901221b8                 bset    %lo(aSoftwareTrap0x), %o0! "software trap 0x%x\n"
F00A9564: 113c046f901221d0         set     aBadTrapD, %o0! "bad trap = %d\n"
F00A956C: 92100018                 mov     %i0, %o1
F00A9570: 7ffdac3a                 call    _printf
F00A9574: 01000000                 nop
F00A9578: 80a62009                 cmp     %i0, 9
F00A957C: 02800004                 be      loc_F00A958C
F00A9580: 80a62001                 cmp     %i0, 1
F00A9584: 12800023                 bne     loc_F00A9610
F00A9588: 80a6a000                 cmp     %i2, 0
F00A958C: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A9590: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00A9594: d002200c                 ld      [%o0+0xC], %o0
F00A9598: d002200c                 ld      [%o0+0xC], %o0
F00A959C: 9210001a                 mov     %i2, %o1
F00A95A0: d0022024                 ld      [%o0+0x24], %o0
F00A95A4: 7fffcebd                 call    _pmap_getpte
F00A95A8: 9407bff4                 add     %fp, var_C, %o2
F00A95AC: d0064000                 ld      [%i1], %o0
F00A95B0: 808a2040                 btst    0x40, %o0 ! '@'
F00A95B4: 113c046f                 sethi   %hi(aSSFaultAtAddr0), %o0! "%s %s fault at addr=0x%x, pme=0x%x\n"
F00A95B8: 12800005                 bne     loc_F00A95CC
F00A95BC: 961221e0                 or      %o0, %lo(aSSFaultAtAddr0), %o3! "%s %s fault at addr=0x%x, pme=0x%x\n"
F00A95C0: 113c046f                 sethi   %hi(aUser_5), %o0! "user"
F00A95C4: 10800004                 ba      loc_F00A95D4
F00A95C8: 92122208                 or      %o0, %lo(aUser_5), %o1! "user"
F00A95CC: 113c046f92122210         set     aKernel, %o1! "kernel"
F00A95D4: 80a72002                 cmp     %i4, 2
F00A95D8: 12800005                 bne     loc_F00A95EC
F00A95DC: 113c046f                 sethi   -0xFEE4400, %o0
F00A95E0: 113c046f                 sethi   %hi(aWrite_1), %o0! "write"
F00A95E4: 10800003                 ba      loc_F00A95F0
F00A95E8: 94122218                 or      %o0, %lo(aWrite_1), %o2! "write"
F00A95EC: 94122220                 or      %o0, 0x220, %o2
F00A95F0: 9010000b                 mov     %o3, %o0! char *
F00A95F4: d807bff4                 ld      [%fp+var_C], %o4
F00A95F8: 7ffdac18                 call    _printf
F00A95FC: 9610001a                 mov     %i2, %o3
F00A9600: 7fffb04e                 call    _mmu_print_sfsr
F00A9604: 9010001b                 mov     %i3, %o0
F00A9608: 10800008                 ba      loc_F00A9628
F00A960C: e4066004                 ld      [%i1+4], %l2
F00A9610: 02800005                 be      loc_F00A9624
F00A9614: 113c046f                 sethi   %hi(aAddr0xX), %o0! "addr=0x%x\n"
F00A9618: 90122228                 bset    %lo(aAddr0xX), %o0! "addr=0x%x\n"
F00A961C: 7ffdac0f                 call    _printf
F00A9620: 9210001a                 mov     %i2, %o1
F00A9624: e4066004                 ld      [%i1+4], %l2
F00A9628: e6066044                 ld      [%i1+0x44], %l3
F00A962C: 213c046f                 sethi   %hi(aRp0xXPc0xXSp0x), %l0! "rp=0x%x, pc=0x%x, sp=0x%x, psr=0x%x, co"...
F00A9630: e2064000                 ld      [%i1], %l1
F00A9634: 7fffaff2                 call    _mmu_getctx
F00A9638: a0142238                 bset    %lo(aRp0xXPc0xXSp0x), %l0! "rp=0x%x, pc=0x%x, sp=0x%x, psr=0x%x, co"...
F00A963C: 9a100008                 mov     %o0, %o5
F00A9640: 90100010                 mov     %l0, %o0! char *
F00A9644: 92100019                 mov     %i1, %o1
F00A9648: 94100012                 mov     %l2, %o2
F00A964C: 96100013                 mov     %l3, %o3
F00A9650: 7ffdac02                 call    _printf
F00A9654: 98100011                 mov     %l1, %o4
F00A9658: d0064000                 ld      [%i1], %o0
F00A965C: 808a2040                 btst    0x40, %o0 ! '@'
F00A9660: 32800011                 bne,a   loc_F00A96A4
F00A9664: d2066010                 ld      [%i1+0x10], %o1
F00A9668: d206602c                 ld      [%i1+0x2C], %o1
F00A966C: d4066030                 ld      [%i1+0x30], %o2
F00A9670: d6066034                 ld      [%i1+0x34], %o3
F00A9674: d8066038                 ld      [%i1+0x38], %o4
F00A9678: c4066040                 ld      [%i1+0x40], %g2
F00A967C: da06603c                 ld      [%i1+0x3C], %o5
F00A9680: c423a05c                 st      %g2, [%sp+0x80+var_24]
F00A9684: c4066044                 ld      [%i1+0x44], %g2
F00A9688: 113c046f                 sethi   %hi(aO0O7XXXXXXXX), %o0! "o0-o7: %x, %x, %x, %x, %x, %x, %x, %x\n"
F00A968C: c423a060                 st      %g2, [%sp+0x80+var_20]
F00A9690: c4066048                 ld      [%i1+0x48], %g2
F00A9694: 90122270                 bset    %lo(aO0O7XXXXXXXX), %o0! "o0-o7: %x, %x, %x, %x, %x, %x, %x, %x\n"
F00A9698: 7ffdabf0                 call    _printf
F00A969C: c423a064                 st      %g2, [%sp+0x80+var_1C]
F00A96A0: d2066010                 ld      [%i1+0x10], %o1
F00A96A4: d4066014                 ld      [%i1+0x14], %o2
F00A96A8: d6066018                 ld      [%i1+0x18], %o3
F00A96AC: d806601c                 ld      [%i1+0x1C], %o4
F00A96B0: da066020                 ld      [%i1+0x20], %o5
F00A96B4: c4066024                 ld      [%i1+0x24], %g2
F00A96B8: 113c046f                 sethi   %hi(aG1G7XXXXXXX), %o0! "g1-g7: %x, %x, %x, %x, %x, %x, %x\n"
F00A96BC: c423a05c                 st      %g2, [%sp+0x80+var_24]
F00A96C0: c4066028                 ld      [%i1+0x28], %g2
F00A96C4: 90122298                 bset    %lo(aG1G7XXXXXXX), %o0! "g1-g7: %x, %x, %x, %x, %x, %x, %x\n"
F00A96C8: 7ffdabe4                 call    _printf
F00A96CC: c423a060                 st      %g2, [%sp+0x80+var_20]
F00A96D0: 113c042d                 sethi   %hi(_pmsgbuf), %o0
F00A96D4: d002208c                 ld      [%o0+%lo(_pmsgbuf)], %o0
F00A96D8: 7fffb0b4                 call    _vac_flush
F00A96DC: 13000004                 sethi   0x1000, %o1
F00A96E0: 7fffb591                 call    _splx
F00A96E4: 90100014                 mov     %l4, %o0
F00A96E8: 81c7e008                 ret
F00A96EC: 81e80000                 restore
