F00E56E4: 9de3bf98                 save    %sp, -0x68, %sp
F00E56E8: 80a6200f                 cmp     %i0, 0xF
F00E56EC: 133c04bb                 sethi   %hi(_sparcfbs), %o1
F00E56F0: 912e2004                 sll     %i0, 4, %o0
F00E56F4: 90020018                 add     %o0, %i0, %o0
F00E56F8: 912a2002                 sll     %o0, 2, %o0
F00E56FC: d2026364                 ld      [%o1+%lo(_sparcfbs)], %o1
F00E5700: 90022008                 inc     8, %o0
F00E5704: 18800006                 bgu     loc_F00E571C
F00E5708: a4024008                 add     %o1, %o0, %l2
F00E570C: d0024008                 ld      [%o1+%o0], %o0
F00E5710: 80a22000                 cmp     %o0, 0
F00E5714: 32800004                 bne,a   loc_F00E5724
F00E5718: e2166002                 lduh    [%i1+2], %l1
F00E571C: 10800048                 ba      locret_F00E583C
F00E5720: b0103d40                 mov     -0x2C0, %i0
F00E5724: e8164000                 lduh    [%i1], %l4
F00E5728: e6166004                 lduh    [%i1+4], %l3
F00E572C: d004a034                 ld      [%l2+0x34], %o0
F00E5730: 80a22001                 cmp     %o0, 1
F00E5734: 02800007                 be      loc_F00E5750
F00E5738: f2166006                 lduh    [%i1+6], %i1
F00E573C: 80a22004                 cmp     %o0, 4
F00E5740: 02800021                 be      loc_F00E57C4
F00E5744: b0102000                 mov     0, %i0
F00E5748: 1080003d                 ba      locret_F00E583C
F00E574C: b0103d39                 mov     -0x2C7, %i0
F00E5750: b0102000                 mov     0, %i0
F00E5754: 80a60019                 cmp     %i0, %i1
F00E5758: 1a800039                 bcc     locret_F00E583C
F00E575C: 01000000                 nop
F00E5760: d204a038                 ld      [%l2+0x38], %o1
F00E5764: 7ffc8367                 call    _umul
F00E5768: 90100011                 mov     %l1, %o0
F00E576C: 94100008                 mov     %o0, %o2
F00E5770: e004a014                 ld      [%l2+0x14], %l0
F00E5774: 90100014                 mov     %l4, %o0
F00E5778: d204a034                 ld      [%l2+0x34], %o1
F00E577C: 7ffc8361                 call    _umul
F00E5780: a004000a                 add     %l0, %o2, %l0
F00E5784: a0040008                 add     %l0, %o0, %l0
F00E5788: 90102000                 mov     0, %o0
F00E578C: 80a20013                 cmp     %o0, %l3
F00E5790: 3a800008                 bcc,a   loc_F00E57B0
F00E5794: b0062001                 inc     %i0
F00E5798: f42c0000                 stb     %i2, [%l0]
F00E579C: 90022001                 inc     %o0
F00E57A0: 80a20013                 cmp     %o0, %l3
F00E57A4: 0abffffd                 bcs     loc_F00E5798
F00E57A8: a0042001                 inc     %l0
F00E57AC: b0062001                 inc     %i0
F00E57B0: 80a60019                 cmp     %i0, %i1
F00E57B4: 0abfffeb                 bcs     loc_F00E5760
F00E57B8: a2046001                 inc     %l1
F00E57BC: 10800020                 ba      locret_F00E583C
F00E57C0: b0102000                 mov     0, %i0
F00E57C4: 80a60019                 cmp     %i0, %i1
F00E57C8: 912ea018                 sll     %i2, 24, %o0
F00E57CC: 1a80001b                 bcc     loc_F00E5838
F00E57D0: b412001a                 bset    %o0, %i2
F00E57D4: d204a038                 ld      [%l2+0x38], %o1
F00E57D8: 7ffc834a                 call    _umul
F00E57DC: 90100011                 mov     %l1, %o0
F00E57E0: 94100008                 mov     %o0, %o2
F00E57E4: e004a018                 ld      [%l2+0x18], %l0
F00E57E8: 90100014                 mov     %l4, %o0
F00E57EC: d204a034                 ld      [%l2+0x34], %o1
F00E57F0: 7ffc8344                 call    _umul
F00E57F4: a004000a                 add     %l0, %o2, %l0
F00E57F8: a0040008                 add     %l0, %o0, %l0
F00E57FC: 90102000                 mov     0, %o0
F00E5800: 80a20013                 cmp     %o0, %l3
F00E5804: 3a800008                 bcc,a   loc_F00E5824
F00E5808: b0062001                 inc     %i0
F00E580C: f4240000                 st      %i2, [%l0]
F00E5810: 90022001                 inc     %o0
F00E5814: 80a20013                 cmp     %o0, %l3
F00E5818: 0abffffd                 bcs     loc_F00E580C
F00E581C: a0042004                 inc     4, %l0
F00E5820: b0062001                 inc     %i0
F00E5824: 80a60019                 cmp     %i0, %i1
F00E5828: 0abfffeb                 bcs     loc_F00E57D4
F00E582C: a2046001                 inc     %l1
F00E5830: 10800003                 ba      locret_F00E583C
F00E5834: b0102000                 mov     0, %i0
F00E5838: b0102000                 mov     0, %i0
F00E583C: 81c7e008                 ret
F00E5840: 81e80000                 restore
