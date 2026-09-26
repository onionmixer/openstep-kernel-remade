F0062610: 9de3bf70                 save    %sp, -0x90, %sp
F0062614: 90100018                 mov     %i0, %o0
F0062618: 92100019                 mov     %i1, %o1
F006261C: 400001b0                 call    _mach_port_get_receive_status
F0062620: 9407bfd0                 add     %fp, var_30, %o2
F0062624: 80a22000                 cmp     %o0, 0
F0062628: 12800013                 bne     locret_F0062674
F006262C: b0100008                 mov     %o0, %i0
F0062630: d007bfd0                 ld      [%fp+var_30], %o0
F0062634: d0268000                 st      %o0, [%i2]
F0062638: d007bfd8                 ld      [%fp+var_28], %o0
F006263C: d026a004                 st      %o0, [%i2+4]
F0062640: d007bfdc                 ld      [%fp+var_24], %o0
F0062644: d026a008                 st      %o0, [%i2+8]
F0062648: d007bfe0                 ld      [%fp+var_20], %o0
F006264C: d026a00c                 st      %o0, [%i2+0xC]
F0062650: d007bfe4                 ld      [%fp+var_1C], %o0
F0062654: d026a010                 st      %o0, [%i2+0x10]
F0062658: d007bfe8                 ld      [%fp+var_18], %o0
F006265C: d026a014                 st      %o0, [%i2+0x14]
F0062660: d007bfec                 ld      [%fp+var_14], %o0
F0062664: d026a018                 st      %o0, [%i2+0x18]
F0062668: d007bff0                 ld      [%fp+var_10], %o0
F006266C: b0102000                 mov     0, %i0
F0062670: d026a01c                 st      %o0, [%i2+0x1C]
F0062674: 81c7e008                 ret
F0062678: 81e80000                 restore
