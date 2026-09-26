F008858C: 9de3bf98                 save    %sp, -0x68, %sp
F0088590: 80a62000                 cmp     %i0, 0
F0088594: 02800031                 be      locret_F0088658
F0088598: a0062010                 add     %i0, 0x10, %l0
F008859C: d0040000                 ld      [%l0], %o0
F00885A0: 80a22000                 cmp     %o0, 0
F00885A4: 12bffffe                 bne     loc_F008859C
F00885A8: 01000000                 nop
F00885AC: 40003a3f                 call    _simple_lock_try
F00885B0: 90100010                 mov     %l0, %o0
F00885B4: 80a22000                 cmp     %o0, 0
F00885B8: 02bffff9                 be      loc_F008859C
F00885BC: 01000000                 nop
F00885C0: e0060000                 ld      [%i0], %l0
F00885C4: 80a60010                 cmp     %i0, %l0
F00885C8: 22800012                 be,a    loc_F0088610
F00885CC: d0062014                 ld      [%i0+0x14], %o0
F00885D0: d0042018                 ld      [%l0+0x18], %o0
F00885D4: 80a20019                 cmp     %o0, %i1
F00885D8: 2a80000a                 bcs,a   loc_F0088600
F00885DC: e0042008                 ld      [%l0+8], %l0
F00885E0: 80a2001a                 cmp     %o0, %i2
F00885E4: 3a800007                 bcc,a   loc_F0088600
F00885E8: e0042008                 ld      [%l0+8], %l0
F00885EC: 90100018                 mov     %i0, %o0
F00885F0: 92100010                 mov     %l0, %o1
F00885F4: 7fffffa0                 call    _vm_policy_apply
F00885F8: 9410001b                 mov     %i3, %o2
F00885FC: e0042008                 ld      [%l0+8], %l0
F0088600: 80a60010                 cmp     %i0, %l0
F0088604: 32bffff4                 bne,a   loc_F00885D4
F0088608: d0042018                 ld      [%l0+0x18], %o0
F008860C: d0062014                 ld      [%i0+0x14], %o0
F0088610: 80a22000                 cmp     %o0, 0
F0088614: 02800005                 be      loc_F0088628
F0088618: b4268019                 sub     %i2, %i1, %i2
F008861C: 80a68008                 cmp     %i2, %o0
F0088620: 38800002                 bgu,a   loc_F0088628
F0088624: b4100008                 mov     %o0, %i2
F0088628: d2062024                 ld      [%i0+0x24], %o1
F008862C: 9610001b                 mov     %i3, %o3
F0088630: d0062020                 ld      [%i0+0x20], %o0
F0088634: b2064009                 add     %i1, %o1, %i1
F0088638: 92100019                 mov     %i1, %o1
F008863C: 7fffffd4                 call    sub_F008858C
F0088640: 9402401a                 add     %o1, %i2, %o2
F0088644: c0262010                 clr     [%i0+0x10]
F0088648: 90100018                 mov     %i0, %o0
F008864C: 92102000                 mov     0, %o1
F0088650: 7fffa26b                 call    _thread_wakeup_prim
F0088654: 94102000                 mov     0, %o2
F0088658: 81c7e008                 ret
F008865C: 81e80000                 restore
