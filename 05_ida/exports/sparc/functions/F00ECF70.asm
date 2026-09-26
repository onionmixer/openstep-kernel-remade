F00ECF70: 9de3bf98                 save    %sp, -0x68, %sp
F00ECF74: 113c04bca012206c         set     dword_F012F06C, %l0
F00ECF7C: d0040000                 ld      [%l0], %o0
F00ECF80: 80a22000                 cmp     %o0, 0
F00ECF84: 12bffffe                 bne     loc_F00ECF7C
F00ECF88: 01000000                 nop
F00ECF8C: 7ffea7c7                 call    _simple_lock_try
F00ECF90: 90100010                 mov     %l0, %o0
F00ECF94: 80a22000                 cmp     %o0, 0
F00ECF98: 02bffff9                 be      loc_F00ECF7C
F00ECF9C: 113c04bc                 sethi   %hi(dword_F012F068), %o0
F00ECFA0: d0022068                 ld      [%o0+%lo(dword_F012F068)], %o0
F00ECFA4: b0060008                 add     %i0, %o0, %i0
F00ECFA8: b0062007                 inc     7, %i0
F00ECFAC: b00e3ff8                 and     %i0, -8, %i0
F00ECFB0: 233c04bb                 sethi   %hi(dword_F012EF80), %l1
F00ECFB4: d0046380                 ld      [%l1+%lo(dword_F012EF80)], %o0
F00ECFB8: 80a60008                 cmp     %i0, %o0
F00ECFBC: 04800007                 ble     loc_F00ECFD8
F00ECFC0: 213c04bc                 sethi   %hi(dword_F012F064), %l0
F00ECFC4: d0042064                 ld      [%l0+%lo(dword_F012F064)], %o0! __ptr
F00ECFC8: 7ffdecaf                 call    _realloc
F00ECFCC: 92100018                 mov     %i0, %o1
F00ECFD0: d0242064                 st      %o0, [%l0+%lo(dword_F012F064)]
F00ECFD4: f0246380                 st      %i0, [%l1+%lo(dword_F012EF80)]
F00ECFD8: 113c04bc                 sethi   %hi(dword_F012F064), %o0
F00ECFDC: 153c04bc                 sethi   %hi(dword_F012F068), %o2
F00ECFE0: d0022064                 ld      [%o0+%lo(dword_F012F064)], %o0
F00ECFE4: d202a068                 ld      [%o2+%lo(dword_F012F068)], %o1
F00ECFE8: 90020009                 add     %o0, %o1, %o0
F00ECFEC: d0264000                 st      %o0, [%i1]
F00ECFF0: f022a068                 st      %i0, [%o2+%lo(dword_F012F068)]
F00ECFF4: 113c04bc                 sethi   %hi(dword_F012F06C), %o0
F00ECFF8: c022206c                 clr     [%o0+%lo(dword_F012F06C)]
F00ECFFC: 81c7e008                 ret
F00ED000: 81e80000                 restore
