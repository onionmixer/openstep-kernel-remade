F00D5738: 9de3bf90                 save    %sp, -0x70, %sp
F00D573C: d0062110                 ld      [%i0+0x110], %o0! id
F00D5740: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D5744: 4000704b                 call    _objc_msgSend
F00D5748: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D574C: d0062108                 ld      [%i0+0x108], %o0! id
F00D5750: 80a22000                 cmp     %o0, 0
F00D5754: 22800020                 be,a    loc_F00D57D4
F00D5758: f4262108                 st      %i2, [%i0+0x108]
F00D575C: 133c0504                 sethi   %hi(paRelinquishowne_0), %o1
F00D5760: e00262b8                 ld      [%o1+%lo(paRelinquishowne_0)], %l0
F00D5764: 133c0504                 sethi   %hi(paRespondsto), %o1
F00D5768: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00D576C: 40007041                 call    _objc_msgSend
F00D5770: 94100010                 mov     %l0, %o2
F00D5774: 912a2018                 sll     %o0, 24, %o0
F00D5778: 80a22000                 cmp     %o0, 0
F00D577C: 02800007                 be      loc_F00D5798
F00D5780: 92100010                 mov     %l0, %o1! SEL
F00D5784: d0062108                 ld      [%i0+0x108], %o0! id
F00D5788: 4000703a                 call    _objc_msgSend
F00D578C: 94100018                 mov     %i0, %o2
F00D5790: 1080000c                 ba      loc_F00D57C0
F00D5794: a2100008                 mov     %o0, %l1
F00D5798: 90100018                 mov     %i0, %o0! id
F00D579C: 133c0504                 sethi   %hi(paName), %o1
F00D57A0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D57A4: a2103d2b                 mov     -0x2D5, %l1
F00D57A8: 213c03f0                 sethi   %hi(aSOwnerDoesNotR), %l0! "%s: owner does not respond to relinquis"...
F00D57AC: 40007031                 call    _objc_msgSend
F00D57B0: a0142038                 bset    %lo(aSOwnerDoesNotR), %l0! "%s: owner does not respond to relinquis"...
F00D57B4: 92100008                 mov     %o0, %o1
F00D57B8: 7fffc24f                 call    _IOLog
F00D57BC: 90100010                 mov     %l0, %o0
F00D57C0: 80a46000                 cmp     %l1, 0
F00D57C4: 22800005                 be,a    loc_F00D57D8
F00D57C8: f4262108                 st      %i2, [%i0+0x108]
F00D57CC: 10800004                 ba      loc_F00D57DC
F00D57D0: d0062110                 ld      [%i0+0x110], %o0
F00D57D4: a2102000                 mov     0, %l1
F00D57D8: d0062110                 ld      [%i0+0x110], %o0! id
F00D57DC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D57E0: 40007024                 call    _objc_msgSend
F00D57E4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D57E8: 81c7e008                 ret
F00D57EC: 91e80011                 restore %g0, %l1, %o0
