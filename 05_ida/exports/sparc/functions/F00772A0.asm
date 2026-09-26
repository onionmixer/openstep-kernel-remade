F00772A0: 9de3bf98                 save    %sp, -0x68, %sp
F00772A4: 40007e39                 call    _splusclock
F00772A8: 01000000                 nop
F00772AC: a2100008                 mov     %o0, %l1
F00772B0: 113c04c3a0122320         set     dword_F0130F20, %l0
F00772B8: d0040000                 ld      [%l0], %o0
F00772BC: 80a22000                 cmp     %o0, 0
F00772C0: 12bffffe                 bne     loc_F00772B8
F00772C4: 01000000                 nop
F00772C8: 40007ef8                 call    _simple_lock_try
F00772CC: 90100010                 mov     %l0, %o0
F00772D0: 80a22000                 cmp     %o0, 0
F00772D4: 02bffff9                 be      loc_F00772B8
F00772D8: 01000000                 nop
F00772DC: d0062020                 ld      [%i0+0x20], %o0
F00772E0: 80a22001                 cmp     %o0, 1
F00772E4: 12800013                 bne     loc_F0077330
F00772E8: 80a22002                 cmp     %o0, 2
F00772EC: 113c04c198122120         set     unk_F0130520, %o4
F00772F4: d6060000                 ld      [%i0], %o3
F00772F8: 80a6000c                 cmp     %i0, %o4
F00772FC: d2062004                 ld      [%i0+4], %o1
F0077300: 153c04c3                 sethi   %hi(dword_F0130F3C), %o2
F0077304: d002a33c                 ld      [%o2+%lo(dword_F0130F3C)], %o0
F0077308: d222e004                 st      %o1, [%o3+4]
F007730C: d6062004                 ld      [%i0+4], %o3
F0077310: 90023fff                 inc     -1, %o0
F0077314: d2060000                 ld      [%i0], %o1
F0077318: d022a33c                 st      %o0, [%o2+%lo(dword_F0130F3C)]
F007731C: d222c000                 st      %o1, [%o3]
F0077320: 0a80001c                 bcs     loc_F0077390
F0077324: c0262020                 clr     [%i0+0x20]
F0077328: 10800010                 ba      loc_F0077368
F007732C: 90032a00                 add     %o4, 0xA00, %o0
F0077330: 12800019                 bne     loc_F0077394
F0077334: 113c04c3                 sethi   -0xFECF400, %o0
F0077338: d2060000                 ld      [%i0], %o1
F007733C: d0062004                 ld      [%i0+4], %o0
F0077340: d0226004                 st      %o0, [%o1+4]
F0077344: 113c04c1                 sethi   %hi(unk_F0130520), %o0
F0077348: d2062004                 ld      [%i0+4], %o1
F007734C: 94122120                 or      %o0, %lo(unk_F0130520), %o2
F0077350: d0060000                 ld      [%i0], %o0
F0077354: 80a6000a                 cmp     %i0, %o2
F0077358: d0224000                 st      %o0, [%o1]
F007735C: 0a80000d                 bcs     loc_F0077390
F0077360: c0262020                 clr     [%i0+0x20]
F0077364: 9002aa00                 add     %o2, 0xA00, %o0
F0077368: 80a60008                 cmp     %i0, %o0
F007736C: 3a80000a                 bcc,a   loc_F0077394
F0077370: 113c04c3                 sethi   -0xFECF400, %o0
F0077374: 113c04c390122324         set     dword_F0130F24, %o0
F007737C: d0260000                 st      %o0, [%i0]
F0077380: d2022004                 ld      [%o0+4], %o1
F0077384: d2262004                 st      %o1, [%i0+4]
F0077388: f0224000                 st      %i0, [%o1]
F007738C: f0222004                 st      %i0, [%o0+4]
F0077390: 113c04c3                 sethi   -0xFECF400, %o0
F0077394: c0222320                 clr     [%o0+0x320]
F0077398: 40007e63                 call    _splx
F007739C: 90100011                 mov     %l1, %o0
F00773A0: 81c7e008                 ret
F00773A4: 81e80000                 restore
