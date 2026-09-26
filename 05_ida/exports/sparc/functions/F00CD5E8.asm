F00CD5E8: 9de3bf80                 save    %sp, -0x80, %sp
F00CD5EC: e2070000                 ld      [%i4], %l1
F00CD5F0: 80a46000                 cmp     %l1, 0
F00CD5F4: 12800003                 bne     loc_F00CD600
F00CD5F8: a010001c                 mov     %i4, %l0
F00CD5FC: a2102200                 mov     0x200, %l1
F00CD600: 9010001b                 mov     %i3, %o0! __s1
F00CD604: 133c03ec                 sethi   %hi(aIoscsicontroll_2), %o1! "IOSCSIControllerStatistics"
F00CD608: 7ffceae9                 call    _strcmp
F00CD60C: 921262c8                 bset    %lo(aIoscsicontroll_2), %o1! "IOSCSIControllerStatistics"
F00CD610: 80a22000                 cmp     %o0, 0
F00CD614: 32800024                 bne,a   loc_F00CD6A4
F00CD618: 9010001b                 mov     %i3, %o0
F00CD61C: 113c0505                 sethi   %hi(paMaxqueuelength), %o0! id
F00CD620: d20223fc                 ld      [%o0+%lo(paMaxqueuelength)], %o1! SEL
F00CD624: 40009093                 call    _objc_msgSend
F00CD628: 90100018                 mov     %i0, %o0
F00CD62C: d027bfe0                 st      %o0, [%fp+var_20]
F00CD630: 113c0505                 sethi   %hi(paNumqueuesample), %o0! id
F00CD634: d20223f8                 ld      [%o0+%lo(paNumqueuesample)], %o1! SEL
F00CD638: 4000908e                 call    _objc_msgSend
F00CD63C: 90100018                 mov     %i0, %o0
F00CD640: d027bfe4                 st      %o0, [%fp+var_1C]
F00CD644: 113c0505                 sethi   %hi(paSumqueuelength), %o0! id
F00CD648: d20223f4                 ld      [%o0+%lo(paSumqueuelength)], %o1! SEL
F00CD64C: 40009089                 call    _objc_msgSend
F00CD650: 90100018                 mov     %i0, %o0
F00CD654: d027bfe8                 st      %o0, [%fp+var_18]
F00CD658: c0270000                 clr     [%i4]
F00CD65C: 96102000                 mov     0, %o3
F00CD660: 9407bff8                 add     %fp, var_8, %o2
F00CD664: 92102000                 mov     0, %o1
F00CD668: d0040000                 ld      [%l0], %o0
F00CD66C: 80a20011                 cmp     %o0, %l1
F00CD670: 02800020                 be      loc_F00CD6F0
F00CD674: 9602e001                 inc     %o3
F00CD678: d002bfe8                 ld      [%o2-0x18], %o0
F00CD67C: 80a2e002                 cmp     %o3, 2
F00CD680: d022401a                 st      %o0, [%o1+%i2]
F00CD684: 9402a004                 inc     4, %o2
F00CD688: d0040000                 ld      [%l0], %o0! __s1
F00CD68C: 92026004                 inc     4, %o1
F00CD690: 90022001                 inc     %o0
F00CD694: 04bffff5                 ble     loc_F00CD668
F00CD698: d0240000                 st      %o0, [%l0]
F00CD69C: 10800016                 ba      locret_F00CD6F4
F00CD6A0: b0102000                 mov     0, %i0
F00CD6A4: 133c03ec                 sethi   %hi(aIoisascsicontr), %o1! "IOIsASCSIController"
F00CD6A8: 7ffceac1                 call    _strcmp
F00CD6AC: 921262e8                 bset    %lo(aIoisascsicontr), %o1! "IOIsASCSIController"
F00CD6B0: 80a22000                 cmp     %o0, 0
F00CD6B4: 0280000e                 be      loc_F00CD6EC
F00CD6B8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CD6BC: f027bff0                 st      %i0, [%fp+var_10]
F00CD6C0: 133c0508                 sethi   %hi(stru_F014213C.super_class), %o1
F00CD6C4: 9610001b                 mov     %i3, %o3
F00CD6C8: d4026140                 ld      [%o1+%lo(stru_F014213C.super_class)], %o2
F00CD6CC: 9810001c                 mov     %i4, %o4
F00CD6D0: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00CD6D4: d427bff4                 st      %o2, [%fp+var_C]
F00CD6D8: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00CD6DC: 400090a8                 call    _objc_msgSendSuper
F00CD6E0: 9410001a                 mov     %i2, %o2
F00CD6E4: 10800004                 ba      locret_F00CD6F4
F00CD6E8: b0100008                 mov     %o0, %i0
F00CD6EC: c0270000                 clr     [%i4]
F00CD6F0: b0102000                 mov     0, %i0
F00CD6F4: 81c7e008                 ret
F00CD6F8: 81e80000                 restore
