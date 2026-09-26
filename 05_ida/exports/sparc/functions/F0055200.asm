F0055200: 9de3bf98                 save    %sp, -0x68, %sp
F0055204: 90100018                 mov     %i0, %o0
F0055208: d2022008                 ld      [%o0+8], %o1
F005520C: 80a27ffe                 cmp     %o1, -2
F0055210: 02800007                 be      loc_F005522C
F0055214: 01000000                 nop
F0055218: 1880000b                 bgu     locret_F0055244
F005521C: 80a27ffd                 cmp     %o1, -3
F0055220: 02800005                 be      loc_F0055234
F0055224: 01000000                 nop
F0055228: 30800005                 ba,a    loc_F005523C
F005522C: 4000e669                 call    _KernDeviceInterruptMsgRelease
F0055230: 9e03e010                 inc     0x10, %o7
F0055234: 40005a95                 call    _netipc_msg_release
F0055238: 9e03e008                 inc     8, %o7
F005523C: 40004bd9                 call    _kfree
F0055240: 01000000                 nop
F0055244: 81c7e008                 ret
F0055248: 81e80000                 restore
