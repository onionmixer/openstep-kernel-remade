F0016040: 9de3bf98                 save    %sp, -0x68, %sp
F0016044: 400202d1                 call    _splusclock
F0016048: 01000000                 nop
F001604C: e0060000                 ld      [%i0], %l0
F0016050: 80a42000                 cmp     %l0, 0
F0016054: 02800016                 be      loc_F00160AC
F0016058: 94100008                 mov     %o0, %o2
F001605C: d0042188                 ld      [%l0+0x188], %o0
F0016060: 80a22000                 cmp     %o0, 0
F0016064: 2280000c                 be,a    loc_F0016094
F0016068: c0260000                 clr     [%i0]
F001606C: d204203c                 ld      [%l0+0x3C], %o1
F0016070: 113c04d490122238         set     _selwait, %o0
F0016078: 80a24008                 cmp     %o1, %o0
F001607C: 32800006                 bne,a   loc_F0016094
F0016080: c0260000                 clr     [%i0]
F0016084: 40020328                 call    _splx
F0016088: 9010000a                 mov     %o2, %o0
F001608C: 10800010                 ba      locret_F00160CC
F0016090: b0102001                 mov     1, %i0
F0016094: 40020324                 call    _splx
F0016098: 9010000a                 mov     %o2, %o0
F001609C: 400178c4                 call    _thread_deallocate
F00160A0: 90100010                 mov     %l0, %o0
F00160A4: 10800005                 ba      loc_F00160B8
F00160A8: 113c04d0                 sethi   -0xFECC000, %o0
F00160AC: 4002031e                 call    _splx
F00160B0: 9010000a                 mov     %o2, %o0
F00160B4: 113c04d0                 sethi   -0xFECC000, %o0
F00160B8: e0022260                 ld      [%o0+0x260], %l0
F00160BC: 400179de                 call    _thread_reference
F00160C0: 90100010                 mov     %l0, %o0
F00160C4: e0260000                 st      %l0, [%i0]
F00160C8: b0102000                 mov     0, %i0
F00160CC: 81c7e008                 ret
F00160D0: 81e80000                 restore
