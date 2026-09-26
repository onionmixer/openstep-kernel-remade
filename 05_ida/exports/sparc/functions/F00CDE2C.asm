F00CDE2C: 9de3bf40                 save    %sp, -0xC0, %sp
F00CDE30: 113c0506                 sethi   %hi(paUpdatereadysta), %o0! id
F00CDE34: d20221c8                 ld      [%o0+%lo(paUpdatereadysta)], %o1! SEL
F00CDE38: a6102000                 mov     0, %l3
F00CDE3C: 40008e8d                 call    _objc_msgSend
F00CDE40: 90100018                 mov     %i0, %o0
F00CDE44: 80a22000                 cmp     %o0, 0
F00CDE48: 02800004                 be      loc_F00CDE58
F00CDE4C: 90100018                 mov     %i0, %o0! id
F00CDE50: 10800059                 ba      locret_F00CDFB4
F00CDE54: b0103d28                 mov     -0x2D8, %i0
F00CDE58: 133c0505                 sethi   %hi(paSdreadcapacity), %o1
F00CDE5C: d20263c4                 ld      [%o1+%lo(paSdreadcapacity)], %o1! SEL
F00CDE60: 40008e84                 call    _objc_msgSend
F00CDE64: 9407bfe8                 add     %fp, var_18, %o2
F00CDE68: 80a22000                 cmp     %o0, 0
F00CDE6C: 02800004                 be      loc_F00CDE7C
F00CDE70: 90100018                 mov     %i0, %o0! id
F00CDE74: 10800050                 ba      locret_F00CDFB4
F00CDE78: b0103d36                 mov     -0x2CA, %i0
F00CDE7C: a210200a                 mov     0xA, %l1
F00CDE80: d407bfe8                 ld      [%fp+var_18], %o2
F00CDE84: 133c0506                 sethi   %hi(paSetdisksize), %o1
F00CDE88: d202616c                 ld      [%o1+%lo(paSetdisksize)], %o1! SEL
F00CDE8C: 40008e79                 call    _objc_msgSend
F00CDE90: 9402a001                 inc     %o2
F00CDE94: 113c0506                 sethi   %hi(paSetblocksize), %o0! id
F00CDE98: d2022170                 ld      [%o0+%lo(paSetblocksize)], %o1! SEL
F00CDE9C: a0102000                 mov     0, %l0
F00CDEA0: d407bfec                 ld      [%fp+var_14], %o2
F00CDEA4: 40008e73                 call    _objc_msgSend
F00CDEA8: 90100018                 mov     %i0, %o0
F00CDEAC: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F00CDEB0: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F00CDEB4: 293c0505                 sethi   -0xFEBEC00, %l4
F00CDEB8: 40008e6e                 call    _objc_msgSend
F00CDEBC: 90100018                 mov     %i0, %o0
F00CDEC0: 94100008                 mov     %o0, %o2
F00CDEC4: 9607bfa4                 add     %fp, var_5C, %o3
F00CDEC8: d0062184                 ld      [%i0+0x184], %o0! id
F00CDECC: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F00CDED0: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F00CDED4: 40008e67                 call    _objc_msgSend
F00CDED8: 9807bfa0                 add     %fp, var_60, %o4
F00CDEDC: a4100008                 mov     %o0, %l2
F00CDEE0: 90100018                 mov     %i0, %o0! id
F00CDEE4: d20523c0                 ld      [%l4+0x3C0], %o1! SEL
F00CDEE8: 94100011                 mov     %l1, %o2
F00CDEEC: 96102001                 mov     1, %o3
F00CDEF0: 40008e60                 call    _objc_msgSend
F00CDEF4: 98100012                 mov     %l2, %o4
F00CDEF8: 80a22000                 cmp     %o0, 0
F00CDEFC: 02800007                 be      loc_F00CDF18
F00CDF00: 01000000                 nop
F00CDF04: a0042001                 inc     %l0
F00CDF08: 80a42004                 cmp     %l0, 4
F00CDF0C: 04bffff5                 ble     loc_F00CDEE0
F00CDF10: a204600a                 inc     0xA, %l1
F00CDF14: 80a22000                 cmp     %o0, 0
F00CDF18: 12800006                 bne     loc_F00CDF30
F00CDF1C: 90100018                 mov     %i0, %o0! id
F00CDF20: 133c0506                 sethi   %hi(paSetformattedin), %o1
F00CDF24: d20261ac                 ld      [%o1+%lo(paSetformattedin)], %o1
F00CDF28: 10800005                 ba      loc_F00CDF3C
F00CDF2C: 94102001                 mov     1, %o2
F00CDF30: 133c0506                 sethi   %hi(paSetformattedin), %o1
F00CDF34: d20261ac                 ld      [%o1+%lo(paSetformattedin)], %o1! SEL
F00CDF38: 94102000                 mov     0, %o2
F00CDF3C: 40008e4d                 call    _objc_msgSend
F00CDF40: 01000000                 nop
F00CDF44: d007bfa4                 ld      [%fp+var_5C], %o0
F00CDF48: 7fffdfff                 call    _IOFree
F00CDF4C: d207bfa0                 ld      [%fp+var_60], %o1! size_t
F00CDF50: d00e21bc                 ldub    [%i0+0x1BC], %o0
F00CDF54: 80a22005                 cmp     %o0, 5
F00CDF58: 22800011                 be,a    loc_F00CDF9C
F00CDF5C: a6102001                 mov     1, %l3
F00CDF60: a007bfa8                 add     %fp, var_58, %l0
F00CDF64: 90100010                 mov     %l0, %o0! void *
F00CDF68: 7fff1bbc                 call    _bzero
F00CDF6C: 9210203c                 mov     0x3C, %o1 ! '<'
F00CDF70: 90100018                 mov     %i0, %o0! id
F00CDF74: 133c0505                 sethi   %hi(paSdmodesense), %o1
F00CDF78: d20263bc                 ld      [%o1+%lo(paSdmodesense)], %o1! SEL
F00CDF7C: 40008e3d                 call    _objc_msgSend
F00CDF80: 94100010                 mov     %l0, %o2
F00CDF84: d207bfa8                 ld      [%fp+var_58], %o1
F00CDF88: 11000020                 sethi   0x8000, %o0
F00CDF8C: 808a4008                 btst    %o0, %o1
F00CDF90: 02800004                 be      loc_F00CDFA0
F00CDF94: 90100018                 mov     %i0, %o0
F00CDF98: a6102001                 mov     1, %l3
F00CDF9C: 90100018                 mov     %i0, %o0! id
F00CDFA0: 133c0506                 sethi   %hi(paSetwriteprotec), %o1
F00CDFA4: d20261a8                 ld      [%o1+%lo(paSetwriteprotec)], %o1! SEL
F00CDFA8: 40008e32                 call    _objc_msgSend
F00CDFAC: 94100013                 mov     %l3, %o2
F00CDFB0: b0102000                 mov     0, %i0
F00CDFB4: 81c7e008                 ret
F00CDFB8: 81e80000                 restore
