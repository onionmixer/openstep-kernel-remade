F00F25F4: 9de3bf98                 save    %sp, -0x68, %sp
F00F25F8: ea066004                 ld      [%i1+4], %l5
F00F25FC: 10800037                 ba      loc_F00F26D8
F00F2600: a8102000                 mov     0, %l4
F00F2604: 92100008                 mov     %o0, %o1
F00F2608: 90054008                 add     %l5, %o0, %o0
F00F260C: d002200c                 ld      [%o0+0xC], %o0
F00F2610: 80a22000                 cmp     %o0, 0
F00F2614: 22800031                 be,a    loc_F00F26D8
F00F2618: a8052001                 inc     %l4
F00F261C: a6102000                 mov     0, %l3
F00F2620: d0122008                 lduh    [%o0+8], %o0
F00F2624: 80a4c008                 cmp     %l3, %o0
F00F2628: 3a80002c                 bcc,a   loc_F00F26D8
F00F262C: a8052001                 inc     %l4
F00F2630: ad2d2004                 sll     %l4, 4, %l6
F00F2634: ae054016                 add     %l5, %l6, %l7
F00F2638: a4054009                 add     %l5, %o1, %l2
F00F263C: d204a00c                 ld      [%l2+0xC], %o1
F00F2640: a12ce002                 sll     %l3, 2, %l0
F00F2644: 92040009                 add     %l0, %o1, %o1! data
F00F2648: 90100018                 mov     %i0, %o0! table
F00F264C: 7fffec8b                 call    _NXHashInsert
F00F2650: d202600c                 ld      [%o1+0xC], %o1
F00F2654: a2920000                 orcc    %o0, %g0, %l1
F00F2658: 0280000b                 be      loc_F00F2684
F00F265C: 90100018                 mov     %i0, %o0! name
F00F2660: d404a00c                 ld      [%l2+0xC], %o2
F00F2664: 9404000a                 add     %l0, %o2, %o2
F00F2668: 92100011                 mov     %l1, %o1
F00F266C: 7fffffa9                 call    sub_F00F2510
F00F2670: d402a00c                 ld      [%o2+0xC], %o2
F00F2674: 7ffffdba                 call    _objc_lookUpClass
F00F2678: d0046008                 ld      [%l1+8], %o0
F00F267C: 10800006                 ba      loc_F00F2694
F00F2680: 94100008                 mov     %o0, %o2
F00F2684: d205e00c                 ld      [%l7+0xC], %o1
F00F2688: 912ce002                 sll     %l3, 2, %o0
F00F268C: 90020009                 add     %o0, %o1, %o0
F00F2690: d402200c                 ld      [%o0+0xC], %o2
F00F2694: 80a28011                 cmp     %o2, %l1
F00F2698: 02800005                 be      loc_F00F26AC
F00F269C: 01000000                 nop
F00F26A0: d2028000                 ld      [%o2], %o1
F00F26A4: d0054016                 ld      [%l5+%l6], %o0
F00F26A8: d022600c                 st      %o0, [%o1+0xC]
F00F26AC: 7ffffece                 call    sub_F00F21E4
F00F26B0: 9010000a                 mov     %o2, %o0
F00F26B4: a604e001                 inc     %l3
F00F26B8: 932d2004                 sll     %l4, 4, %o1
F00F26BC: 90054009                 add     %l5, %o1, %o0
F00F26C0: d002200c                 ld      [%o0+0xC], %o0
F00F26C4: d0122008                 lduh    [%o0+8], %o0
F00F26C8: 80a4c008                 cmp     %l3, %o0
F00F26CC: 0abfffdc                 bcs     loc_F00F263C
F00F26D0: a4054009                 add     %l5, %o1, %l2
F00F26D4: a8052001                 inc     %l4
F00F26D8: d0066008                 ld      [%i1+8], %o0
F00F26DC: 80a50008                 cmp     %l4, %o0
F00F26E0: 0abfffc9                 bcs     loc_F00F2604
F00F26E4: 912d2004                 sll     %l4, 4, %o0
F00F26E8: 81c7e008                 ret
F00F26EC: 81e80000                 restore
