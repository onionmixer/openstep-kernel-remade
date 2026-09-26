F00D4350: 9de3bf90                 save    %sp, -0x70, %sp
F00D4354: a2100018                 mov     %i0, %l1
F00D4358: 4000766b                 call    _objc_getClass
F00D435C: 9010001a                 mov     %i2, %o0
F00D4360: a0920000                 orcc    %o0, %g0, %l0
F00D4364: 12800008                 bne     loc_F00D4384
F00D4368: 133c0505                 sethi   -0xFEBEC00, %o1
F00D436C: 90100011                 mov     %l1, %o0
F00D4370: 133c0504                 sethi   %hi(paName), %o1
F00D4374: d2026008                 ld      [%o1+%lo(paName)], %o1
F00D4378: 213c03ef                 sethi   %hi(aSSNoSuchClass), %l0! "%s: %s: no such class.\n"
F00D437C: 10800027                 ba      loc_F00D4418
F00D4380: a0142390                 bset    %lo(aSSNoSuchClass), %l0! "%s: %s: no such class.\n"
F00D4384: f0026340                 ld      [%o1+0x340], %i0
F00D4388: 90100010                 mov     %l0, %o0! id
F00D438C: 133c0504                 sethi   %hi(paRespondsto), %o1
F00D4390: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00D4394: 40007537                 call    _objc_msgSend
F00D4398: 94100018                 mov     %i0, %o2
F00D439C: 912a2018                 sll     %o0, 24, %o0
F00D43A0: 80a22000                 cmp     %o0, 0
F00D43A4: 12800008                 bne     loc_F00D43C4
F00D43A8: 90100010                 mov     %l0, %o0
F00D43AC: 90100011                 mov     %l1, %o0! id
F00D43B0: 133c0504                 sethi   %hi(paName), %o1
F00D43B4: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D43B8: 213c03ef                 sethi   %hi(aSSDoesNotRespo), %l0! "%s: %s does not respond to probe.\n"
F00D43BC: 10800017                 ba      loc_F00D4418
F00D43C0: a01423a8                 bset    %lo(aSSDoesNotRespo), %l0! "%s: %s does not respond to probe.\n"
F00D43C4: 4000752b                 call    _objc_msgSend
F00D43C8: 92100018                 mov     %i0, %o1
F00D43CC: b0920000                 orcc    %o0, %g0, %i0
F00D43D0: 12800007                 bne     loc_F00D43EC
F00D43D4: 90100011                 mov     %l1, %o0! id
F00D43D8: 133c0504                 sethi   %hi(paName), %o1
F00D43DC: d2026008                 ld      [%o1+%lo(paName)], %o1
F00D43E0: 213c03ef                 sethi   %hi(aSProbeOfSFaile), %l0! "%s: probe of %s failed\n"
F00D43E4: 1080000d                 ba      loc_F00D4418
F00D43E8: a01423d0                 bset    %lo(aSProbeOfSFaile), %l0! "%s: probe of %s failed\n"
F00D43EC: 133c0505                 sethi   %hi(paRegisterevents), %o1
F00D43F0: d2026288                 ld      [%o1+%lo(paRegisterevents)], %o1! SEL
F00D43F4: 4000751f                 call    _objc_msgSend
F00D43F8: 94100018                 mov     %i0, %o2
F00D43FC: 80a22000                 cmp     %o0, 0
F00D4400: 1280000c                 bne     locret_F00D4430
F00D4404: 90100011                 mov     %l1, %o0! id
F00D4408: 133c0504                 sethi   %hi(paName), %o1
F00D440C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D4410: 213c03efa01423e8         set     aSBecomeownerOf, %l0! "%s: becomeOwner of %s failed\n"
F00D4418: 40007516                 call    _objc_msgSend
F00D441C: b0102000                 mov     0, %i0
F00D4420: 92100008                 mov     %o0, %o1
F00D4424: 90100010                 mov     %l0, %o0
F00D4428: 7fffc733                 call    _IOLog
F00D442C: 9410001a                 mov     %i2, %o2
F00D4430: 81c7e008                 ret
F00D4434: 81e80000                 restore
