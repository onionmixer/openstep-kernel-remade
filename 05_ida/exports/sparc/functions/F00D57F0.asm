F00D57F0: 9de3bf90                 save    %sp, -0x70, %sp
F00D57F4: d0062110                 ld      [%i0+0x110], %o0! id
F00D57F8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D57FC: 4000701d                 call    _objc_msgSend
F00D5800: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D5804: d0062108                 ld      [%i0+0x108], %o0
F00D5808: 80a2001a                 cmp     %o0, %i2
F00D580C: 12800004                 bne     loc_F00D581C
F00D5810: a2103d2b                 mov     -0x2D5, %l1
F00D5814: a2102000                 mov     0, %l1
F00D5818: c0262108                 clr     [%i0+0x108]
F00D581C: d0062110                 ld      [%i0+0x110], %o0! id
F00D5820: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D5824: 40007013                 call    _objc_msgSend
F00D5828: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D582C: 80a46000                 cmp     %l1, 0
F00D5830: 1280001e                 bne     locret_F00D58A8
F00D5834: 01000000                 nop
F00D5838: d006210c                 ld      [%i0+0x10C], %o0! id
F00D583C: 80a22000                 cmp     %o0, 0
F00D5840: 0280001a                 be      locret_F00D58A8
F00D5844: 80a2001a                 cmp     %o0, %i2
F00D5848: 02800018                 be      locret_F00D58A8
F00D584C: 133c0504                 sethi   %hi(paCanbecomeowner), %o1
F00D5850: e0026320                 ld      [%o1+%lo(paCanbecomeowner)], %l0
F00D5854: 133c0504                 sethi   %hi(paRespondsto), %o1
F00D5858: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00D585C: 40007005                 call    _objc_msgSend
F00D5860: 94100010                 mov     %l0, %o2
F00D5864: 912a2018                 sll     %o0, 24, %o0
F00D5868: 80a22000                 cmp     %o0, 0
F00D586C: 02800006                 be      loc_F00D5884
F00D5870: 92100010                 mov     %l0, %o1! SEL
F00D5874: d006210c                 ld      [%i0+0x10C], %o0! id
F00D5878: 40006ffe                 call    _objc_msgSend
F00D587C: 94100018                 mov     %i0, %o2
F00D5880: 3080000a                 ba,a    locret_F00D58A8
F00D5884: 90100018                 mov     %i0, %o0! id
F00D5888: 133c0504                 sethi   %hi(paName), %o1
F00D588C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D5890: 213c03f0                 sethi   %hi(aSDesiredownerD), %l0! "%s: desiredOwner does not respond to ca"...
F00D5894: 40006ff7                 call    _objc_msgSend
F00D5898: a0142070                 bset    %lo(aSDesiredownerD), %l0! "%s: desiredOwner does not respond to ca"...
F00D589C: 92100008                 mov     %o0, %o1
F00D58A0: 7fffc215                 call    _IOLog
F00D58A4: 90100010                 mov     %l0, %o0
F00D58A8: 81c7e008                 ret
F00D58AC: 91e80011                 restore %g0, %l1, %o0
