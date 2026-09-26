F00BE080: 9de3bf98                 save    %sp, -0x68, %sp
F00BE084: d0062024                 ld      [%i0+0x24], %o0
F00BE088: d606200c                 ld      [%i0+0xC], %o3
F00BE08C: d4062010                 ld      [%i0+0x10], %o2
F00BE090: d8062030                 ld      [%i0+0x30], %o4
F00BE094: 932a2001                 sll     %o0, 1, %o1
F00BE098: 92024008                 add     %o1, %o0, %o1
F00BE09C: 932a6002                 sll     %o1, 2, %o1
F00BE0A0: 92028009                 add     %o2, %o1, %o1
F00BE0A4: d0062028                 ld      [%i0+0x28], %o0
F00BE0A8: 94102008                 mov     8, %o2
F00BE0AC: 912a2003                 sll     %o0, 3, %o0
F00BE0B0: 9002c008                 add     %o3, %o0, %o0
F00BE0B4: 7fffff8f                 call    sub_F00BDEF0
F00BE0B8: 9610200c                 mov     0xC, %o3
F00BE0BC: 81c7e008                 ret
F00BE0C0: 81e80000                 restore
