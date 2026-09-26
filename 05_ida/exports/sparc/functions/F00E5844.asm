F00E5844: 9de3bf98                 save    %sp, -0x68, %sp
F00E5848: 80a6200f                 cmp     %i0, 0xF
F00E584C: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E5850: 912e2004                 sll     %i0, 4, %o0
F00E5854: 90020018                 add     %o0, %i0, %o0
F00E5858: 912a2002                 sll     %o0, 2, %o0
F00E585C: d2026364                 ld      [%o1+%lo(_sparcfbs)], %o1
F00E5860: 90022008                 inc     8, %o0
F00E5864: 18800006                 bgu     loc_F00E587C
F00E5868: a2024008                 add     %o1, %o0, %l1
F00E586C: d0024008                 ld      [%o1+%o0], %o0
F00E5870: 80a22000                 cmp     %o0, 0
F00E5874: 32800004                 bne,a   loc_F00E5884
F00E5878: e6166002                 lduh    [%i1+2], %l3
F00E587C: 1080005d                 ba      locret_F00E59F0
F00E5880: b0103d40                 mov     -0x2C0, %i0
F00E5884: ea164000                 lduh    [%i1], %l5
F00E5888: e8166004                 lduh    [%i1+4], %l4
F00E588C: d0046034                 ld      [%l1+0x34], %o0
F00E5890: 80a22001                 cmp     %o0, 1
F00E5894: 02800007                 be      loc_F00E58B0
F00E5898: f2166006                 lduh    [%i1+6], %i1
F00E589C: 80a22004                 cmp     %o0, 4
F00E58A0: 0280002d                 be      loc_F00E5954
F00E58A4: a4102000                 mov     0, %l2
F00E58A8: 10800052                 ba      locret_F00E59F0
F00E58AC: b0103d39                 mov     -0x2C7, %i0
F00E58B0: a4102000                 mov     0, %l2
F00E58B4: 80a48019                 cmp     %l2, %i1
F00E58B8: 1a80004e                 bcc     locret_F00E59F0
F00E58BC: b0102000                 mov     0, %i0
F00E58C0: d2046038                 ld      [%l1+0x38], %o1
F00E58C4: 7ffc830f                 call    _umul
F00E58C8: 90100013                 mov     %l3, %o0
F00E58CC: 94100008                 mov     %o0, %o2
F00E58D0: e0046014                 ld      [%l1+0x14], %l0
F00E58D4: 90100015                 mov     %l5, %o0
F00E58D8: d2046034                 ld      [%l1+0x34], %o1
F00E58DC: 7ffc8309                 call    _umul
F00E58E0: a004000a                 add     %l0, %o2, %l0
F00E58E4: b0040008                 add     %l0, %o0, %i0
F00E58E8: d2046038                 ld      [%l1+0x38], %o1
F00E58EC: 7ffc8305                 call    _umul
F00E58F0: 9010001b                 mov     %i3, %o0
F00E58F4: 94100008                 mov     %o0, %o2
F00E58F8: e0046014                 ld      [%l1+0x14], %l0
F00E58FC: 9010001a                 mov     %i2, %o0
F00E5900: d2046034                 ld      [%l1+0x34], %o1
F00E5904: 7ffc82ff                 call    _umul
F00E5908: a004000a                 add     %l0, %o2, %l0
F00E590C: 92102000                 mov     0, %o1
F00E5910: 80a24014                 cmp     %o1, %l4
F00E5914: 1a800009                 bcc     loc_F00E5938
F00E5918: a0040008                 add     %l0, %o0, %l0
F00E591C: 92026001                 inc     %o1
F00E5920: d00e0000                 ldub    [%i0], %o0
F00E5924: 80a24014                 cmp     %o1, %l4
F00E5928: d02c0000                 stb     %o0, [%l0]
F00E592C: b0062001                 inc     %i0
F00E5930: 0abffffb                 bcs     loc_F00E591C
F00E5934: a0042001                 inc     %l0
F00E5938: a604e001                 inc     %l3
F00E593C: a404a001                 inc     %l2
F00E5940: 80a48019                 cmp     %l2, %i1
F00E5944: 0abfffdf                 bcs     loc_F00E58C0
F00E5948: b606e001                 inc     %i3
F00E594C: 10800029                 ba      locret_F00E59F0
F00E5950: b0102000                 mov     0, %i0
F00E5954: 80a48019                 cmp     %l2, %i1
F00E5958: 1a800026                 bcc     locret_F00E59F0
F00E595C: b0102000                 mov     0, %i0
F00E5960: d2046038                 ld      [%l1+0x38], %o1
F00E5964: 7ffc82e7                 call    _umul
F00E5968: 90100013                 mov     %l3, %o0
F00E596C: 94100008                 mov     %o0, %o2
F00E5970: e0046018                 ld      [%l1+0x18], %l0
F00E5974: 90100015                 mov     %l5, %o0
F00E5978: d2046034                 ld      [%l1+0x34], %o1
F00E597C: 7ffc82e1                 call    _umul
F00E5980: a004000a                 add     %l0, %o2, %l0
F00E5984: b0040008                 add     %l0, %o0, %i0
F00E5988: d2046038                 ld      [%l1+0x38], %o1
F00E598C: 7ffc82dd                 call    _umul
F00E5990: 9010001b                 mov     %i3, %o0
F00E5994: 94100008                 mov     %o0, %o2
F00E5998: e0046018                 ld      [%l1+0x18], %l0
F00E599C: 9010001a                 mov     %i2, %o0
F00E59A0: d2046034                 ld      [%l1+0x34], %o1
F00E59A4: 7ffc82d7                 call    _umul
F00E59A8: a004000a                 add     %l0, %o2, %l0
F00E59AC: 92102000                 mov     0, %o1
F00E59B0: 80a24014                 cmp     %o1, %l4
F00E59B4: 1a800009                 bcc     loc_F00E59D8
F00E59B8: a0040008                 add     %l0, %o0, %l0
F00E59BC: 92026001                 inc     %o1
F00E59C0: d0060000                 ld      [%i0], %o0
F00E59C4: 80a24014                 cmp     %o1, %l4
F00E59C8: d0240000                 st      %o0, [%l0]
F00E59CC: b0062004                 inc     4, %i0
F00E59D0: 0abffffb                 bcs     loc_F00E59BC
F00E59D4: a0042004                 inc     4, %l0
F00E59D8: a604e001                 inc     %l3
F00E59DC: a404a001                 inc     %l2
F00E59E0: 80a48019                 cmp     %l2, %i1
F00E59E4: 0abfffdf                 bcs     loc_F00E5960
F00E59E8: b606e001                 inc     %i3
F00E59EC: b0102000                 mov     0, %i0
F00E59F0: 81c7e008                 ret
F00E59F4: 81e80000                 restore
