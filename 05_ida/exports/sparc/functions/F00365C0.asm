F00365C0: 9de3bf90                 save    %sp, -0x70, %sp
F00365C4: d0066004                 ld      [%i1+4], %o0
F00365C8: e4566008                 ldsh    [%i1+8], %l2
F00365CC: 80a4a000                 cmp     %l2, 0
F00365D0: 04800022                 ble     loc_F0036658
F00365D4: a2064008                 add     %i1, %o0, %l1
F00365D8: d00c4000                 ldub    [%l1], %o0
F00365DC: 80a22000                 cmp     %o0, 0
F00365E0: 0280001e                 be      loc_F0036658
F00365E4: 80a22001                 cmp     %o0, 1
F00365E8: 32800004                 bne,a   loc_F00365F8
F00365EC: e00c6001                 ldub    [%l1+1], %l0
F00365F0: 10800005                 ba      loc_F0036604
F00365F4: a0102001                 mov     1, %l0
F00365F8: 80a42000                 cmp     %l0, 0
F00365FC: 04800017                 ble     loc_F0036658
F0036600: 01000000                 nop
F0036604: 80a22002                 cmp     %o0, 2
F0036608: 32800011                 bne,a   loc_F003664C
F003660C: a4248010                 sub     %l2, %l0, %l2
F0036610: 80a42004                 cmp     %l0, 4
F0036614: 3280000e                 bne,a   loc_F003664C
F0036618: a4248010                 sub     %l2, %l0, %l2
F003661C: d00ea021                 ldub    [%i2+0x21], %o0
F0036620: 808a2002                 btst    2, %o0
F0036624: 2280000a                 be,a    loc_F003664C
F0036628: a4248010                 sub     %l2, %l0, %l2
F003662C: 90046002                 add     %l1, 2, %o0! void *
F0036630: 9207bff6                 add     %fp, var_A, %o1! void *
F0036634: 40017937                 call    _bcopy
F0036638: 94102002                 mov     2, %o2
F003663C: d217bff6                 lduh    [%fp+var_A], %o1
F0036640: 40000072                 call    _tcp_mss
F0036644: 90100018                 mov     %i0, %o0
F0036648: a4248010                 sub     %l2, %l0, %l2
F003664C: 80a4a000                 cmp     %l2, 0
F0036650: 14bfffe2                 bg      loc_F00365D8
F0036654: a2044010                 add     %l1, %l0, %l1
F0036658: 7fff9d17                 call    _m_free
F003665C: 90100019                 mov     %i1, %o0
F0036660: 81c7e008                 ret
F0036664: 81e80000                 restore
