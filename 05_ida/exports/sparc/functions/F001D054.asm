F001D054: 9de3bf98                 save    %sp, -0x68, %sp
F001D058: 113c04cf                 sethi   %hi(_active_u), %o0
F001D05C: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F001D060: d0026164                 ld      [%o1+0x164], %o0
F001D064: 80a22000                 cmp     %o0, 0
F001D068: 02800011                 be      locret_F001D0AC
F001D06C: b0102006                 mov     6, %i0
F001D070: d4126168                 lduh    [%o1+0x168], %o2
F001D074: 952aa010                 sll     %o2, 16, %o2
F001D078: 913aa010                 sra     %o2, 16, %o0
F001D07C: 9532a018                 srl     %o2, 24, %o2
F001D080: 932aa001                 sll     %o2, 1, %o1
F001D084: 9202400a                 add     %o1, %o2, %o1
F001D088: 932a6002                 sll     %o1, 2, %o1
F001D08C: 9222400a                 sub     %o1, %o2, %o1
F001D090: 932a6002                 sll     %o1, 2, %o1
F001D094: 153c04729412a1f0         set     _cdevsw, %o2
F001D09C: d402400a                 ld      [%o1+%o2], %o2
F001D0A0: 9fc28000                 call    %o2
F001D0A4: 92100019                 mov     %i1, %o1
F001D0A8: b0100008                 mov     %o0, %i0
F001D0AC: 81c7e008                 ret
F001D0B0: 81e80000                 restore
