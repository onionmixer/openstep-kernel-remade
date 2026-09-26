F00752BC: 9de3bf98                 save    %sp, -0x68, %sp
F00752C0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00752C4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00752C8: 80a60008                 cmp     %i0, %o0
F00752CC: 12800005                 bne     loc_F00752E0
F00752D0: a6102000                 mov     0, %l3
F00752D4: 113c0442                 sethi   %hi(aThreadDowait), %o0! "thread_dowait"
F00752D8: 7ffe7fa6                 call    _panic
F00752DC: 90122350                 bset    %lo(aThreadDowait), %o0! "thread_dowait"
F00752E0: 4000862a                 call    _splusclock
F00752E4: a4102000                 mov     0, %l2
F00752E8: ac100008                 mov     %o0, %l6
F00752EC: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00752F0: d0040000                 ld      [%l0], %o0
F00752F4: 80a22000                 cmp     %o0, 0
F00752F8: 12bffffe                 bne     loc_F00752F0
F00752FC: 01000000                 nop
F0075300: 400086ea                 call    _simple_lock_try
F0075304: 90100010                 mov     %l0, %o0
F0075308: 80a22000                 cmp     %o0, 0
F007530C: 02bffff9                 be      loc_F00752F0
F0075310: 113c01d4                 sethi   %hi(jpt_F007533C), %o0
F0075314: aa122344                 or      %o0, %lo(jpt_F007533C), %l5
F0075318: a8102001                 mov     1, %l4
F007531C: a2062020                 add     %i0, 0x20, %l1 ! ' '
F0075320: d006204c                 ld      [%i0+0x4C], %o0
F0075324: 900a200f                 and     %o0, 0xF, %o0
F0075328: 90023ffe                 inc     -2, %o0
F007532C: 80a2200d                 cmp     %o0, 0xD! switch 14 cases
F0075330: 18800036                 bgu     def_F007533C! jumptable F007533C default case, cases 0-3,6-8,10,11
F0075334: 912a2002                 sll     %o0, 2, %o0
F0075338: d0020015                 ld      [%o0+%l5], %o0
F007533C: 81c20000                 jmp     %o0! switch jump
F0075340: 01000000                 nop
F007537C: 7ffff2a1                 call    _rem_runq! jumptable F007533C case 4
F0075380: 90100018                 mov     %i0, %o0
F0075384: 80a22000                 cmp     %o0, 0
F0075388: 22800009                 be,a    loc_F00753AC
F007538C: e8262048                 st      %l4, [%i0+0x48]
F0075390: d006204c                 ld      [%i0+0x4C], %o0
F0075394: e4062048                 ld      [%i0+0x48], %l2
F0075398: 900a3ffb                 and     %o0, -5, %o0
F007539C: d026204c                 st      %o0, [%i0+0x4C]
F00753A0: 1080001a                 ba      def_F007533C! jumptable F007533C default case, cases 0-3,6-8,10,11
F00753A4: c0262048                 clr     [%i0+0x48]
F00753A8: e8262048                 st      %l4, [%i0+0x48]! jumptable F007533C cases 5,9,12,13
F00753AC: 90062048                 add     %i0, 0x48, %o0 ! 'H'
F00753B0: 92100011                 mov     %l1, %o1
F00753B4: 7fffef82                 call    _thread_sleep
F00753B8: 94102001                 mov     1, %o2
F00753BC: a0100011                 mov     %l1, %l0
F00753C0: d0040000                 ld      [%l0], %o0
F00753C4: 80a22000                 cmp     %o0, 0
F00753C8: 12bffffe                 bne     loc_F00753C0
F00753CC: 01000000                 nop
F00753D0: 400086b6                 call    _simple_lock_try
F00753D4: 90100010                 mov     %l0, %o0
F00753D8: 80a22000                 cmp     %o0, 0
F00753DC: 02bffff9                 be      loc_F00753C0
F00753E0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00753E4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00753E8: d0022044                 ld      [%o0+0x44], %o0
F00753EC: 80a22000                 cmp     %o0, 0
F00753F0: 22bfffcd                 be,a    loc_F0075324
F00753F4: d006204c                 ld      [%i0+0x4C], %o0
F00753F8: 80a66000                 cmp     %i1, 0
F00753FC: 32bfffca                 bne,a   loc_F0075324
F0075400: d006204c                 ld      [%i0+0x4C], %o0
F0075404: a6102005                 mov     5, %l3
F0075408: c0262020                 clr     [%i0+0x20]! jumptable F007533C default case, cases 0-3,6-8,10,11
F007540C: 40008646                 call    _splx
F0075410: 90100016                 mov     %l6, %o0
F0075414: 80a4a000                 cmp     %l2, 0
F0075418: 02800005                 be      locret_F007542C
F007541C: 90062048                 add     %i0, 0x48, %o0 ! 'H'
F0075420: 92102000                 mov     0, %o1
F0075424: 7fffeef6                 call    _thread_wakeup_prim
F0075428: 94102000                 mov     0, %o2
F007542C: 81c7e008                 ret
F0075430: 91e80013                 restore %g0, %l3, %o0
