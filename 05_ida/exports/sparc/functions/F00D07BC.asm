F00D07BC: 9de3bf90                 save    %sp, -0x70, %sp
F00D07C0: a4100018                 mov     %i0, %l2
F00D07C4: 9610001b                 mov     %i3, %o3
F00D07C8: d004a124                 ld      [%l2+0x124], %o0
F00D07CC: 21200000                 sethi   0x80000000, %l0
F00D07D0: 808a0010                 btst    %l0, %o0
F00D07D4: 02800014                 be      loc_F00D0824
F00D07D8: 9810001c                 mov     %i4, %o4
F00D07DC: d004a108                 ld      [%l2+0x108], %o0
F00D07E0: 84102000                 mov     0, %g2
F00D07E4: 80a08008                 cmp     %g2, %o0
F00D07E8: 1280000f                 bne     loc_F00D0824
F00D07EC: c60e8000                 ldub    [%i2], %g3
F00D07F0: d004a10c                 ld      [%l2+0x10C], %o0
F00D07F4: 80a0c008                 cmp     %g3, %o0
F00D07F8: 32800046                 bne,a   locret_F00D0910
F00D07FC: b0102007                 mov     7, %i0
F00D0800: d004a110                 ld      [%l2+0x110], %o0
F00D0804: 84102000                 mov     0, %g2
F00D0808: 80a08008                 cmp     %g2, %o0
F00D080C: 12800006                 bne     loc_F00D0824
F00D0810: c60ea001                 ldub    [%i2+1], %g3
F00D0814: d004a114                 ld      [%l2+0x114], %o0
F00D0818: 80a0c008                 cmp     %g3, %o0
F00D081C: 22800004                 be,a    loc_F00D082C
F00D0820: d004a128                 ld      [%l2+0x128], %o0! id
F00D0824: 1080003b                 ba      locret_F00D0910
F00D0828: b0102007                 mov     7, %i0
F00D082C: 133c0505                 sethi   %hi(paExecuterequest_0), %o1
F00D0830: d20263b0                 ld      [%o1+%lo(paExecuterequest_0)], %o1! SEL
F00D0834: 4000840f                 call    _objc_msgSend
F00D0838: 9410001a                 mov     %i2, %o2
F00D083C: b0100008                 mov     %o0, %i0
F00D0840: 80a62002                 cmp     %i0, 2
F00D0844: 12800011                 bne     loc_F00D0888
F00D0848: 80a62003                 cmp     %i0, 3
F00D084C: d006a040                 ld      [%i2+0x40], %o0
F00D0850: d0274000                 st      %o0, [%i5]
F00D0854: d006a044                 ld      [%i2+0x44], %o0
F00D0858: d0276004                 st      %o0, [%i5+4]
F00D085C: d006a048                 ld      [%i2+0x48], %o0
F00D0860: d0276008                 st      %o0, [%i5+8]
F00D0864: d006a04c                 ld      [%i2+0x4C], %o0
F00D0868: d027600c                 st      %o0, [%i5+0xC]
F00D086C: d006a050                 ld      [%i2+0x50], %o0
F00D0870: d0276010                 st      %o0, [%i5+0x10]
F00D0874: d006a054                 ld      [%i2+0x54], %o0
F00D0878: d0276014                 st      %o0, [%i5+0x14]
F00D087C: d006a058                 ld      [%i2+0x58], %o0
F00D0880: 10800024                 ba      locret_F00D0910
F00D0884: d0276018                 st      %o0, [%i5+0x18]
F00D0888: 12800022                 bne     locret_F00D0910
F00D088C: 01000000                 nop
F00D0890: d004a11c                 ld      [%l2+0x11C], %o0
F00D0894: 808a0010                 btst    %l0, %o0
F00D0898: 0280001e                 be      locret_F00D0910
F00D089C: 90100012                 mov     %l2, %o0! id
F00D08A0: 133c0505                 sethi   %hi(paGetsense), %o1
F00D08A4: d2026364                 ld      [%o1+%lo(paGetsense)], %o1! SEL
F00D08A8: 400083f2                 call    _objc_msgSend
F00D08AC: 9410001d                 mov     %i5, %o2
F00D08B0: b0920000                 orcc    %o0, %g0, %i0
F00D08B4: 12800004                 bne     loc_F00D08C4
F00D08B8: 90100012                 mov     %l2, %o0! id
F00D08BC: 10800015                 ba      locret_F00D0910
F00D08C0: b0102002                 mov     2, %i0
F00D08C4: 133c0504                 sethi   %hi(paName), %o1
F00D08C8: 213c03ed                 sethi   %hi(aSRequestSenseO), %l0! "%s: Request Sense on target %d lun %d f"...
F00D08CC: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D08D0: 400083e8                 call    _objc_msgSend
F00D08D4: a01422a8                 bset    %lo(aSRequestSenseO), %l0! "%s: Request Sense on target %d lun %d f"...
F00D08D8: a2100008                 mov     %o0, %l1
F00D08DC: 90100018                 mov     %i0, %o0
F00D08E0: 133c04bb                 sethi   %hi(_IOScStatusStrings), %o1
F00D08E4: e81ca108                 ldd     [%l2+0x108], %l4
F00D08E8: 92126100                 bset    %lo(_IOScStatusStrings), %o1
F00D08EC: e41ca110                 ldd     [%l2+0x110], %l2
F00D08F0: 7fffd612                 call    _IOFindNameForValue
F00D08F4: b0102003                 mov     3, %i0
F00D08F8: 98100008                 mov     %o0, %o4
F00D08FC: 90100010                 mov     %l0, %o0
F00D0900: 92100011                 mov     %l1, %o1
F00D0904: 94100015                 mov     %l5, %o2
F00D0908: 7fffd5fb                 call    _IOLog
F00D090C: 96100013                 mov     %l3, %o3
F00D0910: 81c7e008                 ret
F00D0914: 81e80000                 restore
