F00CC758: 9de3bf88                 save    %sp, -0x78, %sp
F00CC75C: f027bff0                 st      %i0, [%fp+var_10]
F00CC760: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CC764: 133c0508                 sethi   %hi(stru_F01420EC.super_class), %o1
F00CC768: d60260f0                 ld      [%o1+%lo(stru_F01420EC.super_class)], %o3
F00CC76C: 9410001a                 mov     %i2, %o2
F00CC770: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00CC774: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00CC778: 40009481                 call    _objc_msgSendSuper
F00CC77C: d627bff4                 st      %o3, [%fp+var_C]
F00CC780: 80a22000                 cmp     %o0, 0
F00CC784: 22800047                 be,a    locret_F00CC8A0
F00CC788: b0102000                 mov     0, %i0
F00CC78C: 113c0506                 sethi   %hi(paStartiothread), %o0! id
F00CC790: d202206c                 ld      [%o0+%lo(paStartiothread)], %o1! SEL
F00CC794: 40009437                 call    _objc_msgSend
F00CC798: 90100018                 mov     %i0, %o0
F00CC79C: 80a22000                 cmp     %o0, 0
F00CC7A0: 1280003c                 bne     loc_F00CC890
F00CC7A4: 113c0503                 sethi   -0xFEBF400, %o0
F00CC7A8: a207bfe8                 add     %fp, var_18, %l1
F00CC7AC: 90100011                 mov     %l1, %o0! char *
F00CC7B0: 133c03ec921260a8         set     aSD, %o1! "%s%d"
F00CC7B8: 193c04bb                 sethi   %hi(dword_F012ECE4), %o4
F00CC7BC: 153c04bb                 sethi   %hi(aTr), %o2! "tr"
F00CC7C0: e00320e4                 ld      [%o4+%lo(dword_F012ECE4)], %l0
F00CC7C4: 9412a0d0                 bset    %lo(aTr), %o2! "tr"
F00CC7C8: 96042001                 add     %l0, 1, %o3
F00CC7CC: d62320e4                 st      %o3, [%o4+%lo(dword_F012ECE4)]
F00CC7D0: 7ffd1fe6                 call    _sprintf
F00CC7D4: 96100010                 mov     %l0, %o3
F00CC7D8: 90100018                 mov     %i0, %o0! id
F00CC7DC: 133c0504                 sethi   %hi(paSetname), %o1
F00CC7E0: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00CC7E4: 40009423                 call    _objc_msgSend
F00CC7E8: 94100011                 mov     %l1, %o2
F00CC7EC: 90100018                 mov     %i0, %o0! id
F00CC7F0: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00CC7F4: 153c04bb                 sethi   %hi(aTokenring), %o2! "TokenRing"
F00CC7F8: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00CC7FC: 4000941d                 call    _objc_msgSend
F00CC800: 9412a0d8                 bset    %lo(aTokenring), %o2! "TokenRing"
F00CC804: 90100018                 mov     %i0, %o0! id
F00CC808: 133c0504                 sethi   %hi(paSetunit), %o1
F00CC80C: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00CC810: 40009418                 call    _objc_msgSend
F00CC814: 94100010                 mov     %l0, %o2
F00CC818: 90100018                 mov     %i0, %o0! id
F00CC81C: 133c0506                 sethi   %hi(paGetinstancetab), %o1
F00CC820: d2026010                 ld      [%o1+%lo(paGetinstancetab)], %o1! SEL
F00CC824: 40009413                 call    _objc_msgSend
F00CC828: 9410001a                 mov     %i2, %o2
F00CC82C: 80a22000                 cmp     %o0, 0
F00CC830: 12800018                 bne     loc_F00CC890
F00CC834: 113c0503                 sethi   -0xFEBF400, %o0
F00CC838: 113c0506                 sethi   %hi(paDrivercmdtr), %o0
F00CC83C: d00222e4                 ld      [%o0+%lo(paDrivercmdtr)], %o0! id
F00CC840: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00CC844: 4000940b                 call    _objc_msgSend
F00CC848: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00CC84C: a2100008                 mov     %o0, %l1
F00CC850: 113c0506                 sethi   %hi(paInitport), %o0! id
F00CC854: e0022068                 ld      [%o0+%lo(paInitport)], %l0
F00CC858: 133c0504                 sethi   %hi(paInterruptport_0), %o1
F00CC85C: d2026308                 ld      [%o1+%lo(paInterruptport_0)], %o1! SEL
F00CC860: 40009404                 call    _objc_msgSend
F00CC864: 90100018                 mov     %i0, %o0
F00CC868: 94100008                 mov     %o0, %o2
F00CC86C: 90100011                 mov     %l1, %o0! id
F00CC870: 40009400                 call    _objc_msgSend
F00CC874: 92100010                 mov     %l0, %o1
F00CC878: d0262154                 st      %o0, [%i0+0x154]
F00CC87C: 113c0506                 sethi   %hi(paSet8025framesi), %o0! id
F00CC880: d202200c                 ld      [%o0+%lo(paSet8025framesi)], %o1! SEL
F00CC884: 400093fb                 call    _objc_msgSend
F00CC888: 90100018                 mov     %i0, %o0! id
F00CC88C: 30800005                 ba,a    locret_F00CC8A0
F00CC890: d20223fc                 ld      [%o0+0x3FC], %o1! SEL
F00CC894: 400093f7                 call    _objc_msgSend
F00CC898: 90100018                 mov     %i0, %o0
F00CC89C: b0102000                 mov     0, %i0
F00CC8A0: 81c7e008                 ret
F00CC8A4: 81e80000                 restore
