F0091598: 9de3bf70                 save    %sp, -0x90, %sp
F009159C: d0062004                 ld      [%i0+4], %o0
F00915A0: 80a22018                 cmp     %o0, 0x18
F00915A4: 12800006                 bne     loc_F00915BC
F00915A8: 92100019                 mov     %i1, %o1
F00915AC: d0060000                 ld      [%i0], %o0
F00915B0: 80a22000                 cmp     %o0, 0
F00915B4: 16800005                 bge     loc_F00915C8
F00915B8: 90102007                 mov     7, %o0
F00915BC: 90103ed0                 mov     -0x130, %o0
F00915C0: 10800031                 ba      locret_F0091684
F00915C4: d022601c                 st      %o0, [%o1+0x1C]
F00915C8: d027bfd4                 st      %o0, [%fp+var_2C]
F00915CC: d0062008                 ld      [%i0+8], %o0
F00915D0: 92102004                 mov     4, %o1
F00915D4: 7ffffb31                 call    _convert_port_to_dev
F00915D8: d227bfd0                 st      %o1, [%fp+var_30]
F00915DC: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00915E0: 9407bfd4                 add     %fp, var_2C, %o2
F00915E4: a007bfd8                 add     %fp, var_28, %l0
F00915E8: 96100010                 mov     %l0, %o3
F00915EC: 7ffffe75                 call    _kern_IOGetDeviceConfig
F00915F0: 9807bfd0                 add     %fp, var_30, %o4
F00915F4: 80a22000                 cmp     %o0, 0
F00915F8: 12800023                 bne     locret_F0091684
F00915FC: d026601c                 st      %o0, [%i1+0x1C]
F0091600: 113c0448                 sethi   %hi(dword_F0112294), %o0
F0091604: 92100010                 mov     %l0, %o1! __src
F0091608: 233fffc0a214600f         set     -0xFFF1, %l1
F0091610: d4022294                 ld      [%o0+%lo(dword_F0112294)], %o2
F0091614: 173c0448                 sethi   %hi(dword_F0112298), %o3
F0091618: e007bfd4                 ld      [%fp+var_2C], %l0
F009161C: d4266020                 st      %o2, [%i1+0x20]
F0091620: 940a8011                 and     %o2, %l1, %o2
F0091624: 900c2fff                 and     %l0, 0xFFF, %o0
F0091628: 912a2004                 sll     %o0, 4, %o0
F009162C: 94128008                 bset    %o0, %o2
F0091630: d4266020                 st      %o2, [%i1+0x20]
F0091634: a12c2002                 sll     %l0, 2, %l0
F0091638: a4042028                 add     %l0, 0x28, %l2 ! '('
F009163C: a0064010                 add     %i1, %l0, %l0
F0091640: d407bfd0                 ld      [%fp+var_30], %o2
F0091644: 90042028                 add     %l0, 0x28, %o0 ! '('! __dst
F0091648: d602e298                 ld      [%o3+%lo(dword_F0112298)], %o3
F009164C: 952aa003                 sll     %o2, 3, %o2! __n
F0091650: 7ffdd714                 call    _memcpy
F0091654: d6242024                 st      %o3, [%l0+0x24]
F0091658: d2042024                 ld      [%l0+0x24], %o1
F009165C: d407bfd0                 ld      [%fp+var_30], %o2
F0091660: 920a4011                 and     %o1, %l1, %o1
F0091664: 912aa001                 sll     %o2, 1, %o0
F0091668: 900a2fff                 and     %o0, 0xFFF, %o0
F009166C: 912a2004                 sll     %o0, 4, %o0
F0091670: 92124008                 bset    %o0, %o1
F0091674: d2242024                 st      %o1, [%l0+0x24]
F0091678: 952aa003                 sll     %o2, 3, %o2
F009167C: a404800a                 add     %l2, %o2, %l2
F0091680: e4266004                 st      %l2, [%i1+4]
F0091684: 81c7e008                 ret
F0091688: 81e80000                 restore
