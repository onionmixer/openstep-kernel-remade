F0011574: 9de3bf98                 save    %sp, -0x68, %sp
F0011578: 80a66020                 cmp     %i1, 0x20 ! ' '
F001157C: 1880010b                 bgu     locret_F00119A8
F0011580: 92067fff                 add     %i1, -1, %o1
F0011584: e2062068                 ld      [%i0+0x68], %l1
F0011588: 90102001                 mov     1, %o0
F001158C: 80a46000                 cmp     %l1, 0
F0011590: 02800106                 be      locret_F00119A8
F0011594: a52a0009                 sll     %o0, %o1, %l2
F0011598: d0046050                 ld      [%l1+0x50], %o0
F001159C: 80a22000                 cmp     %o0, 0
F00115A0: 12800102                 bne     locret_F00119A8
F00115A4: 01000000                 nop
F00115A8: d0062028                 ld      [%i0+0x28], %o0
F00115AC: 808a2010                 btst    0x10, %o0
F00115B0: 1280001e                 bne     loc_F0011628
F00115B4: a6102000                 mov     0, %l3
F00115B8: d2062014                 ld      [%i0+0x14], %o1
F00115BC: 11000010                 sethi   0x4000, %o0
F00115C0: 808a4008                 btst    %o0, %o1
F00115C4: 02800005                 be      loc_F00115D8
F00115C8: 11000100                 sethi   0x40000, %o0
F00115CC: 80a48008                 cmp     %l2, %o0
F00115D0: 02800007                 be      loc_F00115EC
F00115D4: 11000010                 sethi   0x4000, %o0
F00115D8: d0062020                 ld      [%i0+0x20], %o0
F00115DC: 808a0012                 btst    %l2, %o0
F00115E0: 128000f2                 bne     locret_F00119A8
F00115E4: 11000010                 sethi   0x4000, %o0
F00115E8: d2062014                 ld      [%i0+0x14], %o1
F00115EC: 808a4008                 btst    %o0, %o1
F00115F0: 02800005                 be      loc_F0011604
F00115F4: 11000100                 sethi   0x40000, %o0
F00115F8: 80a48008                 cmp     %l2, %o0
F00115FC: 22800007                 be,a    loc_F0011618
F0011600: d0062024                 ld      [%i0+0x24], %o0
F0011604: d006201c                 ld      [%i0+0x1C], %o0
F0011608: 808a0012                 btst    %l2, %o0
F001160C: 12800007                 bne     loc_F0011628
F0011610: a6102003                 mov     3, %l3
F0011614: d0062024                 ld      [%i0+0x24], %o0
F0011618: 900a0012                 and     %o0, %l2, %o0
F001161C: 80a00008                 cmp     %g0, %o0
F0011620: 90602000                 subc    %g0, 0, %o0
F0011624: a60a2002                 and     %o0, 2, %l3
F0011628: 80a66000                 cmp     %i1, 0
F001162C: 02800023                 be      def_F0011658! jumptable F0011658 default case, cases 1,5
F0011630: 92067ff1                 add     %i1, -0xF, %o1
F0011634: d0062018                 ld      [%i0+0x18], %o0
F0011638: 80a26007                 cmp     %o1, 7! switch 8 cases
F001163C: 90120012                 bset    %l2, %o0
F0011640: 1880001e                 bgu     def_F0011658! jumptable F0011658 default case, cases 1,5
F0011644: d0262018                 st      %o0, [%i0+0x18]
F0011648: 113c004590122260         set     jpt_F0011658, %o0
F0011650: 932a6002                 sll     %o1, 2, %o1
F0011654: d0024008                 ld      [%o1+%o0], %o0
F0011658: 81c20000                 jmp     %o0! switch jump
F001165C: 01000000                 nop
F0011680: d0062028                 ld      [%i0+0x28], %o0! jumptable F0011658 case 0
F0011684: 808a2010                 btst    0x10, %o0
F0011688: 1280000d                 bne     loc_F00116BC
F001168C: 80a4e003                 cmp     %l3, 3
F0011690: 80a4e000                 cmp     %l3, 0
F0011694: 1280000a                 bne     loc_F00116BC
F0011698: 80a4e003                 cmp     %l3, 3
F001169C: d2062018                 ld      [%i0+0x18], %o1! jumptable F0011658 case 4
F00116A0: 10800004                 ba      loc_F00116B0
F00116A4: 11000cc0                 sethi   0x330000, %o0
F00116A8: d2062018                 ld      [%i0+0x18], %o1! jumptable F0011658 cases 2,3,6,7
F00116AC: 11000100                 sethi   0x40000, %o0
F00116B0: 902a4008                 andn    %o1, %o0, %o0
F00116B4: d0262018                 st      %o0, [%i0+0x18]
F00116B8: 80a4e003                 cmp     %l3, 3! jumptable F0011658 default case, cases 1,5
F00116BC: 028000bb                 be      locret_F00119A8
F00116C0: 01000000                 nop
F00116C4: 40021531                 call    _splusclock
F00116C8: 01000000                 nop
F00116CC: 133c04d0                 sethi   %hi(_active_threads), %o1
F00116D0: e8026260                 ld      [%o1+%lo(_active_threads)], %l4
F00116D4: d205200c                 ld      [%l4+0xC], %o1
F00116D8: 80a44009                 cmp     %l1, %o1
F00116DC: 12800004                 bne     loc_F00116EC
F00116E0: aa100008                 mov     %o0, %l5
F00116E4: 10800017                 ba      loc_F0011740
F00116E8: a0100014                 mov     %l4, %l0
F00116EC: a0046028                 add     %l1, 0x28, %l0 ! '('
F00116F0: d0040000                 ld      [%l0], %o0
F00116F4: 80a22000                 cmp     %o0, 0
F00116F8: 12bffffe                 bne     loc_F00116F0
F00116FC: 01000000                 nop
F0011700: 400215ea                 call    _simple_lock_try
F0011704: 90100010                 mov     %l0, %o0
F0011708: 80a22000                 cmp     %o0, 0
F001170C: 02bffff9                 be      loc_F00116F0
F0011710: 9004601c                 add     %l1, 0x1C, %o0
F0011714: d204601c                 ld      [%l1+0x1C], %o1
F0011718: 80a20009                 cmp     %o0, %o1
F001171C: 12800006                 bne     loc_F0011734
F0011720: a0100009                 mov     %o1, %l0
F0011724: c0246028                 clr     [%l1+0x28]
F0011728: 4002157f                 call    _splx
F001172C: 90100015                 mov     %l5, %o0
F0011730: 3080009e                 ba,a    locret_F00119A8
F0011734: 40018c40                 call    _thread_reference
F0011738: 90100010                 mov     %l0, %o0
F001173C: c0246028                 clr     [%l1+0x28]
F0011740: 80a66009                 cmp     %i1, 9
F0011744: 3280000f                 bne,a   loc_F0011780
F0011748: d0062028                 ld      [%i0+0x28], %o0
F001174C: d04e2015                 ldsb    [%i0+0x15], %o0
F0011750: 80a22000                 cmp     %o0, 0
F0011754: 0480000a                 ble     loc_F001177C
F0011758: 90100010                 mov     %l0, %o0
F001175C: c02e2015                 clrb    [%i0+0x15]
F0011760: d2042190                 ld      [%l0+0x190], %o1
F0011764: 40019165                 call    _thread_max_priority
F0011768: 9410200a                 mov     0xA, %o2
F001176C: 90100010                 mov     %l0, %o0
F0011770: 9210200a                 mov     0xA, %o1
F0011774: 40019119                 call    _thread_priority
F0011778: 94102000                 mov     0, %o2
F001177C: d0062028                 ld      [%i0+0x28], %o0
F0011780: 808a2010                 btst    0x10, %o0
F0011784: 02800007                 be      loc_F00117A0
F0011788: 80a4e000                 cmp     %l3, 0
F001178C: d04e2013                 ldsb    [%i0+0x13], %o0
F0011790: 80a22006                 cmp     %o0, 6
F0011794: 1280007b                 bne     loc_F0011980
F0011798: 90100010                 mov     %l0, %o0
F001179C: 3080007c                 ba,a    loc_F001198C
F00117A0: 02800009                 be      loc_F00117C4
F00117A4: 80a66013                 cmp     %i1, 0x13
F00117A8: 32800076                 bne,a   loc_F0011980
F00117AC: 90100010                 mov     %l0, %o0! target_task
F00117B0: 400188da                 call    _task_resume
F00117B4: 90100011                 mov     %l1, %o0
F00117B8: 90102003                 mov     3, %o0
F00117BC: 10800070                 ba      def_F00117E0! jumptable F00117E0 default case, cases 1-6,15-18
F00117C0: d02e2013                 stb     %o0, [%i0+0x13]
F00117C4: 92067ff7                 add     %i1, -9, %o1
F00117C8: 80a26013                 cmp     %o1, 0x13! switch 20 cases
F00117CC: 1880006c                 bgu     def_F00117E0! jumptable F00117E0 default case, cases 1-6,15-18
F00117D0: 932a6002                 sll     %o1, 2, %o1
F00117D4: 113c0045901223e8         set     jpt_F00117E0, %o0
F00117DC: d0024008                 ld      [%o1+%o0], %o0
F00117E0: 81c20000                 jmp     %o0! switch jump
F00117E4: 01000000                 nop
F0011838: 80a66011                 cmp     %i1, 0x11! jumptable F00117E0 cases 8,9,12,13
F001183C: 0280000c                 be      loc_F001186C
F0011840: 133c04d1                 sethi   %hi(_init_proc), %o1
F0011844: d0062044                 ld      [%i0+0x44], %o0
F0011848: d2026338                 ld      [%o1+%lo(_init_proc)], %o1! char *
F001184C: 80a20009                 cmp     %o0, %o1
F0011850: 32800008                 bne,a   loc_F0011870
F0011854: d004204c                 ld      [%l0+0x4C], %o0
F0011858: 90100018                 mov     %i0, %o0! unsigned int
F001185C: 7fffff46                 call    _psignal
F0011860: 92102009                 mov     9, %o1! char *
F0011864: 10800023                 ba      loc_F00118F0
F0011868: d0062018                 ld      [%i0+0x18], %o0
F001186C: d004204c                 ld      [%l0+0x4C], %o0
F0011870: 808a2004                 btst    4, %o0
F0011874: 12800010                 bne     loc_F00118B4
F0011878: 113c04cf                 sethi   -0xFECC400, %o0
F001187C: d0062018                 ld      [%i0+0x18], %o0
F0011880: 902a0012                 bclr    %l2, %o0
F0011884: d0262018                 st      %o0, [%i0+0x18]
F0011888: d0046044                 ld      [%l1+0x44], %o0
F001188C: 80a22000                 cmp     %o0, 0
F0011890: 1280003f                 bne     loc_F001198C
F0011894: 01000000                 nop
F0011898: f226203c                 st      %i1, [%i0+0x3C]
F001189C: d0062044                 ld      [%i0+0x44], %o0! unsigned int
F00118A0: 7fffff35                 call    _psignal
F00118A4: 92102014                 mov     0x14, %o1
F00118A8: 4000019d                 call    _stop
F00118AC: 90100018                 mov     %i0, %o0
F00118B0: 30800037                 ba,a    loc_F001198C
F00118B4: d00221d8                 ld      [%o0+0x1D8], %o0
F00118B8: d0020000                 ld      [%o0], %o0
F00118BC: 80a60008                 cmp     %i0, %o0
F00118C0: 12800033                 bne     loc_F001198C
F00118C4: 01000000                 nop
F00118C8: d04e2013                 ldsb    [%i0+0x13], %o0
F00118CC: 80a22005                 cmp     %o0, 5
F00118D0: 0280002f                 be      loc_F001198C
F00118D4: 113c04cf                 sethi   %hi(_need_ast), %o0
F00118D8: d2022160                 ld      [%o0+%lo(_need_ast)], %o1
F00118DC: 92126020                 bset    0x20, %o1 ! ' '
F00118E0: d2222160                 st      %o1, [%o0+%lo(_need_ast)]
F00118E4: d0022160                 ld      [%o0+%lo(_need_ast)], %o0
F00118E8: 30800029                 ba,a    loc_F001198C
F00118EC: d0062018                 ld      [%i0+0x18], %o0! jumptable F00117E0 cases 7,11,14,19
F00118F0: 902a0012                 bclr    %l2, %o0! target_task
F00118F4: 10800026                 ba      loc_F001198C
F00118F8: d0262018                 st      %o0, [%i0+0x18]
F00118FC: 40018887                 call    _task_resume
F0011900: 90100011                 mov     %l1, %o0
F0011904: d0046044                 ld      [%l1+0x44], %o0! jumptable F00117E0 case 0
F0011908: 80a22000                 cmp     %o0, 0
F001190C: 14bffffc                 bg      loc_F00118FC
F0011910: 90102003                 mov     3, %o0! target_act
F0011914: 10800004                 ba      loc_F0011924
F0011918: d02e2013                 stb     %o0, [%i0+0x13]
F001191C: 40018f1f                 call    _thread_resume
F0011920: 90100010                 mov     %l0, %o0
F0011924: d004208c                 ld      [%l0+0x8C], %o0
F0011928: 80a22000                 cmp     %o0, 0
F001192C: 14bffffc                 bg      loc_F001191C
F0011930: 90100010                 mov     %l0, %o0
F0011934: 92102003                 mov     3, %o1
F0011938: 40017d3e                 call    _clear_wait
F001193C: 94102000                 mov     0, %o2
F0011940: 400214f9                 call    _splx
F0011944: 90100015                 mov     %l5, %o0
F0011948: 80a40014                 cmp     %l0, %l4
F001194C: 02800017                 be      locret_F00119A8
F0011950: 01000000                 nop
F0011954: 4001501b                 call    _mach_msg_abort_rpc
F0011958: 90100010                 mov     %l0, %o0
F001195C: 40018a94                 call    _thread_deallocate
F0011960: 90100010                 mov     %l0, %o0! target_task
F0011964: 30800011                 ba,a    locret_F00119A8
F0011968: 4001886c                 call    _task_resume! jumptable F00117E0 case 10
F001196C: 90100011                 mov     %l1, %o0
F0011970: 90102003                 mov     3, %o0
F0011974: 10800006                 ba      loc_F001198C
F0011978: d02e2013                 stb     %o0, [%i0+0x13]
F001197C: 90100010                 mov     %l0, %o0! jumptable F00117E0 default case, cases 1-6,15-18
F0011980: 92102002                 mov     2, %o1
F0011984: 40017d2b                 call    _clear_wait
F0011988: 94102001                 mov     1, %o2
F001198C: 400214e6                 call    _splx
F0011990: 90100015                 mov     %l5, %o0
F0011994: 80a40014                 cmp     %l0, %l4
F0011998: 02800004                 be      locret_F00119A8
F001199C: 01000000                 nop
F00119A0: 40018b6d                 call    _thread_deallocate_interrupt
F00119A4: 90100010                 mov     %l0, %o0
F00119A8: 81c7e008                 ret
F00119AC: 81e80000                 restore
