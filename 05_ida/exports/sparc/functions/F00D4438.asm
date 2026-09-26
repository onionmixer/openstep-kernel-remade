F00D4438: 9de3bf90                 save    %sp, -0x70, %sp
F00D443C: d0062170                 ld      [%i0+0x170], %o0! id
F00D4440: 213c0504                 sethi   %hi(paLock), %l0
F00D4444: 4000750b                 call    _objc_msgSend
F00D4448: d2042000                 ld      [%l0+%lo(paLock)], %o1
F00D444C: d0062174                 ld      [%i0+0x174], %o0
F00D4450: 92062174                 add     %i0, 0x174, %o1
F00D4454: 80a24008                 cmp     %o1, %o0
F00D4458: 22800026                 be,a    loc_F00D44F0
F00D445C: d0062170                 ld      [%i0+0x170], %o0
F00D4460: a2100009                 mov     %o1, %l1
F00D4464: 293c0504                 sethi   -0xFEBF000, %l4
F00D4468: 273c0504                 sethi   -0xFEBF000, %l3
F00D446C: a4100010                 mov     %l0, %l2
F00D4470: e0062174                 ld      [%i0+0x174], %l0
F00D4474: d2042004                 ld      [%l0+4], %o1! SEL
F00D4478: 80a44009                 cmp     %l1, %o1
F00D447C: 12800004                 bne     loc_F00D448C
F00D4480: d0042008                 ld      [%l0+8], %o0
F00D4484: 10800003                 ba      loc_F00D4490
F00D4488: d0262178                 st      %o0, [%i0+0x178]
F00D448C: d0226008                 st      %o0, [%o1+8]
F00D4490: 80a44008                 cmp     %l1, %o0
F00D4494: 32800003                 bne,a   loc_F00D44A0
F00D4498: d2222004                 st      %o1, [%o0+4]
F00D449C: d2262174                 st      %o1, [%i0+0x174]
F00D44A0: d0062170                 ld      [%i0+0x170], %o0! id
F00D44A4: 400074f3                 call    _objc_msgSend
F00D44A8: d2052244                 ld      [%l4+0x244], %o1
F00D44AC: d0040000                 ld      [%l0], %o0! id
F00D44B0: 80a22000                 cmp     %o0, 0
F00D44B4: 02800004                 be      loc_F00D44C4
F00D44B8: d204e2b8                 ld      [%l3+0x2B8], %o1! SEL
F00D44BC: 400074ed                 call    _objc_msgSend
F00D44C0: 94100018                 mov     %i0, %o2
F00D44C4: 90100010                 mov     %l0, %o0
F00D44C8: 7fffc69f                 call    _IOFree
F00D44CC: 9210200c                 mov     0xC, %o1! SEL
F00D44D0: d0062170                 ld      [%i0+0x170], %o0! id
F00D44D4: 400074e7                 call    _objc_msgSend
F00D44D8: d204a000                 ld      [%l2], %o1
F00D44DC: d0062174                 ld      [%i0+0x174], %o0
F00D44E0: 80a44008                 cmp     %l1, %o0
F00D44E4: 32bfffe4                 bne,a   loc_F00D4474
F00D44E8: e0062174                 ld      [%i0+0x174], %l0
F00D44EC: d0062170                 ld      [%i0+0x170], %o0! id
F00D44F0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D44F4: 400074df                 call    _objc_msgSend
F00D44F8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D44FC: 81c7e008                 ret
F00D4500: 81e80000                 restore
