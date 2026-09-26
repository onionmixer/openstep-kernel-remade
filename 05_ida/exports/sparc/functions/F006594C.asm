F006594C: 9de3bf90                 save    %sp, -0x70, %sp
F0065950: 90100018                 mov     %i0, %o0
F0065954: d4022008                 ld      [%o0+8], %o2
F0065958: 80a2a000                 cmp     %o2, 0
F006595C: 02800005                 be      loc_F0065970
F0065960: 92100019                 mov     %i1, %o1
F0065964: 80a2bfff                 cmp     %o2, -1
F0065968: 12800005                 bne     loc_F006597C
F006596C: 94102000                 mov     0, %o2
F0065970: 31040000                 sethi   0x10000000, %i0
F0065974: 10800011                 ba      locret_F00659B8
F0065978: b0162003                 bset    3, %i0
F006597C: 7fffbe73                 call    _ipc_kmsg_get_from_kernel
F0065980: 9607bff4                 add     %fp, var_C, %o3
F0065984: 80a22000                 cmp     %o0, 0
F0065988: 02800004                 be      loc_F0065998
F006598C: 113c043e                 sethi   %hi(aMachMsgSendFro), %o0! "mach_msg_send_from_kernel"
F0065990: 7ffebdf8                 call    _panic
F0065994: 901221c0                 bset    %lo(aMachMsgSendFro), %o0! "mach_msg_send_from_kernel"
F0065998: 7fffc21b                 call    _ipc_kmsg_copyin_from_kernel
F006599C: d007bff4                 ld      [%fp+var_C], %o0
F00659A0: d007bff4                 ld      [%fp+var_C], %o0
F00659A4: 13000040                 sethi   0x10000, %o1
F00659A8: 94102000                 mov     0, %o2
F00659AC: 7fffcab4                 call    _ipc_mqueue_send
F00659B0: 96102000                 mov     0, %o3
F00659B4: b0102000                 mov     0, %i0
F00659B8: 81c7e008                 ret
F00659BC: 81e80000                 restore
