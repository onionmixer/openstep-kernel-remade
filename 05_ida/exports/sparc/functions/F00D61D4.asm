F00D61D4: 9de3bf90                 save    %sp, -0x70, %sp
F00D61D8: d00624f4                 ld      [%i0+0x4F4], %o0! id
F00D61DC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D61E0: 40006da4                 call    _objc_msgSend
F00D61E4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D61E8: d00624ec                 ld      [%i0+0x4EC], %o0
F00D61EC: 80a22000                 cmp     %o0, 0
F00D61F0: 02800037                 be      loc_F00D62CC
F00D61F4: 9006001a                 add     %i0, %i2, %o0
F00D61F8: e00a2006                 ldub    [%o0+6], %l0
F00D61FC: 912ee018                 sll     %i3, 24, %o0
F00D6200: 993a2018                 sra     %o0, 24, %o4
F00D6204: 80a32001                 cmp     %o4, 1
F00D6208: 12800019                 bne     loc_F00D626C
F00D620C: 808c2020                 btst    0x20, %l0 ! ' '
F00D6210: 808c2010                 btst    0x10, %l0
F00D6214: 9136a005                 srl     %i2, 5, %o0
F00D6218: 912a2002                 sll     %o0, 2, %o0
F00D621C: 920ea01f                 and     %i2, 0x1F, %o1
F00D6220: d4070008                 ld      [%i4+%o0], %o2
F00D6224: 932b0009                 sll     %o4, %o1, %o1
F00D6228: 94128009                 bset    %o1, %o2
F00D622C: 02800008                 be      loc_F00D624C
F00D6230: d4270008                 st      %o2, [%i4+%o0]
F00D6234: 90100018                 mov     %i0, %o0! id
F00D6238: 133c0505                 sethi   %hi(paDomodcalcKeybi), %o1
F00D623C: d202625c                 ld      [%o1+%lo(paDomodcalcKeybi)], %o1! SEL
F00D6240: 9410001a                 mov     %i2, %o2
F00D6244: 40006d8b                 call    _objc_msgSend
F00D6248: 9610001c                 mov     %i4, %o3
F00D624C: 808c2020                 btst    0x20, %l0 ! ' '
F00D6250: 0280001f                 be      loc_F00D62CC
F00D6254: 90100018                 mov     %i0, %o0
F00D6258: 133c0505                 sethi   %hi(paDochargenDirec), %o1
F00D625C: d2026258                 ld      [%o1+%lo(paDochargenDirec)], %o1
F00D6260: 9410001a                 mov     %i2, %o2
F00D6264: 10800018                 ba      loc_F00D62C4
F00D6268: 96102001                 mov     1, %o3
F00D626C: 9336a005                 srl     %i2, 5, %o1
F00D6270: 932a6002                 sll     %o1, 2, %o1
F00D6274: 960ea01f                 and     %i2, 0x1F, %o3
F00D6278: 90102001                 mov     1, %o0
F00D627C: d4070009                 ld      [%i4+%o1], %o2
F00D6280: 912a000b                 sll     %o0, %o3, %o0
F00D6284: 902a8008                 andn    %o2, %o0, %o0
F00D6288: 02800008                 be      loc_F00D62A8
F00D628C: d0270009                 st      %o0, [%i4+%o1]
F00D6290: 90100018                 mov     %i0, %o0! id
F00D6294: 133c0505                 sethi   %hi(paDochargenDirec), %o1
F00D6298: d2026258                 ld      [%o1+%lo(paDochargenDirec)], %o1! SEL
F00D629C: 9410001a                 mov     %i2, %o2
F00D62A0: 40006d74                 call    _objc_msgSend
F00D62A4: 9610000c                 mov     %o4, %o3
F00D62A8: 808c2010                 btst    0x10, %l0
F00D62AC: 02800008                 be      loc_F00D62CC
F00D62B0: 90100018                 mov     %i0, %o0! id
F00D62B4: 133c0505                 sethi   %hi(paDomodcalcKeybi), %o1
F00D62B8: d202625c                 ld      [%o1+%lo(paDomodcalcKeybi)], %o1! SEL
F00D62BC: 9410001a                 mov     %i2, %o2
F00D62C0: 9610001c                 mov     %i4, %o3
F00D62C4: 40006d6b                 call    _objc_msgSend
F00D62C8: 01000000                 nop
F00D62CC: d00624f4                 ld      [%i0+0x4F4], %o0! id
F00D62D0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D62D4: 40006d67                 call    _objc_msgSend
F00D62D8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D62DC: 81c7e008                 ret
F00D62E0: 81e80000                 restore
