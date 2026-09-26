F006161C: 9de3bf78                 save    %sp, -0x88, %sp! int
F0061620: 213c04d0                 sethi   %hi(_active_threads), %l0
F0061624: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F0061628: d002200c                 ld      [%o0+0xC], %o0
F006162C: 9210001b                 mov     %i3, %o1
F0061630: e2022088                 ld      [%o0+0x88], %l1
F0061634: 9407bff4                 add     %fp, var_C, %o2
F0061638: e402200c                 ld      [%o0+0xC], %l2
F006163C: 9607bff0                 add     %fp, var_10, %o3
F0061640: 7fffdcaf                 call    _ipc_mqueue_copyin
F0061644: 90100011                 mov     %l1, %o0
F0061648: b6920000                 orcc    %o0, %g0, %i3
F006164C: 1280003b                 bne     loc_F0061738
F0061650: d207bff0                 ld      [%fp+var_10], %o1
F0061654: 11000004                 sethi   0x1000, %o0
F0061658: 808e4008                 btst    %o0, %i1
F006165C: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F0061660: 94103fff                 mov     -1, %o2
F0061664: d607bff4                 ld      [%fp+var_C], %o3
F0061668: f02220c4                 st      %i0, [%o0+0xC4]
F006166C: f22220c8                 st      %i1, [%o0+0xC8]
F0061670: f42220cc                 st      %i2, [%o0+0xCC]
F0061674: f82220d0                 st      %i4, [%o0+0xD0]
F0061678: d22220d8                 st      %o1, [%o0+0xD8]
F006167C: d62220dc                 st      %o3, [%o0+0xDC]
F0061680: 02800003                 be      loc_F006168C
F0061684: 920e6100                 and     %i1, 0x100, %o1
F0061688: 9410001a                 mov     %i2, %o2
F006168C: 9007bfec                 add     %fp, var_14, %o0
F0061690: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0061694: 9007bfe8                 add     %fp, var_18, %o0
F0061698: d023a060                 st      %o0, [%sp+0x88+var_28]
F006169C: 9010000b                 mov     %o3, %o0
F00616A0: 9610001c                 mov     %i4, %o3
F00616A4: 1b3c0187                 sethi   %hi(_msg_receive_continue), %o5
F00616A8: 98102000                 mov     0, %o4! int
F00616AC: 7fffdd03                 call    _ipc_mqueue_receive
F00616B0: 9a1360f0                 bset    %lo(_msg_receive_continue), %o5! int
F00616B4: b6100008                 mov     %o0, %i3
F00616B8: 7fffdfee                 call    _ipc_object_release
F00616BC: d007bff0                 ld      [%fp+var_10], %o0
F00616C0: 80a6e000                 cmp     %i3, 0
F00616C4: 0280000e                 be      loc_F00616FC
F00616C8: 11040010                 sethi   0x10004000, %o0
F00616CC: 90122004                 bset    4, %o0
F00616D0: 80a6c008                 cmp     %i3, %o0
F00616D4: 32800019                 bne,a   loc_F0061738
F00616D8: 9010001b                 mov     %i3, %o0
F00616DC: 9007bfe4                 add     %fp, var_1C, %o0! int
F00616E0: 92062004                 add     %i0, 4, %o1! int
F00616E4: d607bfec                 ld      [%fp+var_14], %o3! int
F00616E8: 94102004                 mov     4, %o2! int
F00616EC: 4000da78                 call    _copyout
F00616F0: d627bfe4                 st      %o3, [%fp+var_1C]
F00616F4: 10800011                 ba      loc_F0061738
F00616F8: 9010001b                 mov     %i3, %o0
F00616FC: d207bfec                 ld      [%fp+var_14], %o1
F0061700: d0026018                 ld      [%o1+0x18], %o0
F0061704: 80a2001a                 cmp     %o0, %i2
F0061708: 18800010                 bgu     loc_F0061748
F006170C: 90100009                 mov     %o1, %o0
F0061710: 92100011                 mov     %l1, %o1
F0061714: 7fffd87e                 call    _ipc_kmsg_copyout_compat
F0061718: 94100012                 mov     %l2, %o2
F006171C: d207bfec                 ld      [%fp+var_14], %o1
F0061720: d4026018                 ld      [%o1+0x18], %o2
F0061724: d6026010                 ld      [%o1+0x10], %o3
F0061728: 90100018                 mov     %i0, %o0
F006172C: 9402800b                 add     %o2, %o3, %o2
F0061730: 7fffcf1c                 call    _ipc_kmsg_put
F0061734: d4226018                 st      %o2, [%o1+0x18]
F0061738: 7ffffeca                 call    _msg_return_translate
F006173C: 01000000                 nop
F0061740: 10800005                 ba      locret_F0061754
F0061744: b0100008                 mov     %o0, %i0
F0061748: 7fffcdb8                 call    _ipc_kmsg_destroy
F006174C: 90100009                 mov     %o1, %o0
F0061750: b0103f34                 mov     -0xCC, %i0
F0061754: 81c7e008                 ret
F0061758: 81e80000                 restore
