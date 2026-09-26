F008E4F4: 9de3bf88                 save    %sp, -0x78, %sp
F008E4F8: d0062004                 ld      [%i0+4], %o0
F008E4FC: 80a22000                 cmp     %o0, 0
F008E500: 12800023                 bne     loc_F008E58C
F008E504: 9210001a                 mov     %i2, %o1
F008E508: 113c04d0                 sethi   %hi(_active_threads), %o0
F008E50C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F008E510: d002200c                 ld      [%o0+0xC], %o0
F008E514: 94102014                 mov     0x14, %o2
F008E518: d0022088                 ld      [%o0+0x88], %o0
F008E51C: 7fff2d53                 call    _ipc_object_copyin
F008E520: 9607bfec                 add     %fp, var_14, %o3
F008E524: 80a22000                 cmp     %o0, 0
F008E528: 3280003e                 bne,a   locret_F008E620
F008E52C: b0102000                 mov     0, %i0
F008E530: d006200c                 ld      [%i0+0xC], %o0! id
F008E534: 133c0504                 sethi   %hi(paInterrupts_0), %o1! SEL
F008E538: 40018cce                 call    _objc_msgSend
F008E53C: d20260b4                 ld      [%o1+%lo(paInterrupts_0)], %o1
F008E540: 94920000                 orcc    %o0, %g0, %o2
F008E544: 02800008                 be      loc_F008E564
F008E548: 113c0504                 sethi   %hi(paCount_0), %o0! id
F008E54C: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F008E550: 40018cc8                 call    _objc_msgSend
F008E554: 9010000a                 mov     %o2, %o0
F008E558: a2920000                 orcc    %o0, %g0, %l1
F008E55C: 1280000e                 bne     loc_F008E594
F008E560: 113c0506                 sethi   -0xFEBE800, %o0
F008E564: 7fff32ee                 call    _ipc_port_release_send
F008E568: d007bfec                 ld      [%fp+var_14], %o0
F008E56C: 3080002d                 ba,a    locret_F008E620
F008E570: 113c0504                 sethi   %hi(paDetachinterrup), %o0! id
F008E574: d20220c4                 ld      [%o0+%lo(paDetachinterrup)], %o1! SEL
F008E578: 40018cbe                 call    _objc_msgSend
F008E57C: 90100018                 mov     %i0, %o0
F008E580: 7fff32e7                 call    _ipc_port_release_send
F008E584: d0062004                 ld      [%i0+4], %o0
F008E588: c0262004                 clr     [%i0+4]
F008E58C: 10800025                 ba      locret_F008E620
F008E590: b0102000                 mov     0, %i0
F008E594: d0022288                 ld      [%o0+0x288], %o0! id
F008E598: b4102000                 mov     0, %i2
F008E59C: d407bfec                 ld      [%fp+var_14], %o2
F008E5A0: 213c0503                 sethi   %hi(paAlloc), %l0
F008E5A4: d20423f0                 ld      [%l0+%lo(paAlloc)], %o1! SEL
F008E5A8: 40018cb2                 call    _objc_msgSend
F008E5AC: d4262004                 st      %o2, [%i0+4]
F008E5B0: 133c0504                 sethi   %hi(paInitcount), %o1
F008E5B4: d20260bc                 ld      [%o1+%lo(paInitcount)], %o1! SEL
F008E5B8: 40018cae                 call    _objc_msgSend
F008E5BC: 94100011                 mov     %l1, %o2
F008E5C0: 80a68011                 cmp     %i2, %l1
F008E5C4: 16800017                 bge     locret_F008E620
F008E5C8: d0262008                 st      %o0, [%i0+8]
F008E5CC: 2b3c0504                 sethi   -0xFEBF000, %l5
F008E5D0: 293c0506                 sethi   %hi(paKerndeviceinte), %l4
F008E5D4: a6100010                 mov     %l0, %l3
F008E5D8: 253c0504                 sethi   -0xFEBF000, %l2
F008E5DC: d0052290                 ld      [%l4+%lo(paKerndeviceinte)], %o0! id
F008E5E0: d204e3f0                 ld      [%l3+0x3F0], %o1! SEL
F008E5E4: 40018ca3                 call    _objc_msgSend
F008E5E8: e0062008                 ld      [%i0+8], %l0
F008E5EC: d204a0c0                 ld      [%l2+0xC0], %o1! SEL
F008E5F0: 40018ca0                 call    _objc_msgSend
F008E5F4: d4062004                 ld      [%i0+4], %o2
F008E5F8: 94100008                 mov     %o0, %o2
F008E5FC: d20560a4                 ld      [%l5+0xA4], %o1! SEL
F008E600: 40018c9c                 call    _objc_msgSend
F008E604: 90100010                 mov     %l0, %o0
F008E608: 80a22000                 cmp     %o0, 0
F008E60C: 02bfffd9                 be      loc_F008E570
F008E610: b406a001                 inc     %i2
F008E614: 80a68011                 cmp     %i2, %l1
F008E618: 06bffff2                 bl      loc_F008E5E0
F008E61C: d0052290                 ld      [%l4+0x290], %o0
F008E620: 81c7e008                 ret
F008E624: 81e80000                 restore
