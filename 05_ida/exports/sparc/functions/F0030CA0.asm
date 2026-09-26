F0030CA0: 9de3bf98                 save    %sp, -0x68, %sp
F0030CA4: d006201c                 ld      [%i0+0x1C], %o0
F0030CA8: 7fffb6c3                 call    _sofree
F0030CAC: c0222008                 clr     [%o0+8]
F0030CB0: d0062038                 ld      [%i0+0x38], %o0
F0030CB4: 80a22000                 cmp     %o0, 0
F0030CB8: 22800005                 be,a    loc_F0030CCC
F0030CBC: d0062024                 ld      [%i0+0x24], %o0
F0030CC0: 7fffb37d                 call    _m_free
F0030CC4: 01000000                 nop
F0030CC8: d0062024                 ld      [%i0+0x24], %o0
F0030CCC: 80a22000                 cmp     %o0, 0
F0030CD0: 02800004                 be      loc_F0030CE0
F0030CD4: 01000000                 nop
F0030CD8: 7ffff053                 call    _rtfree
F0030CDC: 01000000                 nop
F0030CE0: 40000eaa                 call    _ip_freemoptions
F0030CE4: d006203c                 ld      [%i0+0x3C], %o0
F0030CE8: d2060000                 ld      [%i0], %o1
F0030CEC: d0062004                 ld      [%i0+4], %o0
F0030CF0: d0226004                 st      %o0, [%o1+4]
F0030CF4: d4062004                 ld      [%i0+4], %o2
F0030CF8: d2060000                 ld      [%i0], %o1
F0030CFC: 90100018                 mov     %i0, %o0
F0030D00: d2228000                 st      %o1, [%o2]
F0030D04: 4000dd27                 call    _kfree
F0030D08: 92102040                 mov     0x40, %o1 ! '@'
F0030D0C: 81c7e008                 ret
F0030D10: 81e80000                 restore
