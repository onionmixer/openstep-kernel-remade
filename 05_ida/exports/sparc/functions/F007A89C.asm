F007A89C: 9de3bf98                 save    %sp, -0x68, %sp
F007A8A0: f0060000                 ld      [%i0], %i0
F007A8A4: d00624d0                 ld      [%i0+0x4D0], %o0
F007A8A8: 80a22000                 cmp     %o0, 0
F007A8AC: 22800005                 be,a    loc_F007A8C0
F007A8B0: d0062030                 ld      [%i0+0x30], %o0
F007A8B4: 4001db47                 call    _objc_unregisterModule
F007A8B8: 92102000                 mov     0, %o1
F007A8BC: d0062030                 ld      [%i0+0x30], %o0
F007A8C0: 80a22000                 cmp     %o0, 0
F007A8C4: 02800006                 be      loc_F007A8DC
F007A8C8: a2102000                 mov     0, %l1
F007A8CC: 40000108                 call    sub_F007ACEC
F007A8D0: 90062024                 add     %i0, 0x24, %o0 ! '$'
F007A8D4: c0262030                 clr     [%i0+0x30]
F007A8D8: a2102000                 mov     0, %l1
F007A8DC: a0100018                 mov     %i0, %l0
F007A8E0: d204218c                 ld      [%l0+0x18C], %o1
F007A8E4: 80a26000                 cmp     %o1, 0
F007A8E8: 22800007                 be,a    loc_F007A904
F007A8EC: a2046001                 inc     %l1
F007A8F0: 4001e4df                 call    _port_deallocate_EXTERNAL
F007A8F4: d0062008                 ld      [%i0+8], %o0
F007A8F8: c024218c                 clr     [%l0+0x18C]
F007A8FC: c0242190                 clr     [%l0+0x190]
F007A900: a2046001                 inc     %l1
F007A904: 80a46031                 cmp     %l1, 0x31 ! '1'
F007A908: 04bffff6                 ble     loc_F007A8E0
F007A90C: a0042010                 inc     0x10, %l0
F007A910: d0062008                 ld      [%i0+8], %o0
F007A914: 4001e4d6                 call    _port_deallocate_EXTERNAL
F007A918: d2062014                 ld      [%i0+0x14], %o1
F007A91C: d0062008                 ld      [%i0+8], %o0
F007A920: 4001e4d3                 call    _port_deallocate_EXTERNAL
F007A924: d206201c                 ld      [%i0+0x1C], %o1
F007A928: d0062008                 ld      [%i0+8], %o0
F007A92C: 4001e595                 call    _port_set_deallocate_EXTERNAL
F007A930: d2062020                 ld      [%i0+0x20], %o1
F007A934: d0062044                 ld      [%i0+0x44], %o0
F007A938: 7fffb61a                 call    _kfree
F007A93C: d2062048                 ld      [%i0+0x48], %o1
F007A940: 90100018                 mov     %i0, %o0
F007A944: 7fffb617                 call    _kfree
F007A948: 921024d4                 mov     0x4D4, %o1
F007A94C: 113c04d0                 sethi   %hi(_active_threads), %o0! target_act
F007A950: 7fffe7d1                 call    _thread_terminate
F007A954: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F007A958: 7fffe9ed                 call    _thread_halt_self
F007A95C: 9e03fff8                 inc     -8, %o7
F007A960: 81c7e008                 ret
F007A964: 81e80000                 restore
