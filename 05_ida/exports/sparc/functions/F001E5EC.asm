F001E5EC: 9de3bf98                 save    %sp, -0x68, %sp
F001E5F0: 80a6e000                 cmp     %i3, 0
F001E5F4: 02800007                 be      loc_F001E610
F001E5F8: 90100018                 mov     %i0, %o0
F001E5FC: 9210001b                 mov     %i3, %o1
F001E600: 7ffffb88                 call    _pffindproto
F001E604: 9410001a                 mov     %i2, %o2
F001E608: 10800005                 ba      loc_F001E61C
F001E60C: b0100008                 mov     %o0, %i0
F001E610: 7ffffb62                 call    _pffindtype
F001E614: 9210001a                 mov     %i2, %o1
F001E618: b0100008                 mov     %o0, %i0
F001E61C: 80a62000                 cmp     %i0, 0
F001E620: 32800004                 bne,a   loc_F001E630
F001E624: d0560000                 ldsh    [%i0], %o0
F001E628: 1080002a                 ba      locret_F001E6D0
F001E62C: b010202b                 mov     0x2B, %i0 ! '+'
F001E630: 80a2001a                 cmp     %o0, %i2
F001E634: 02800004                 be      loc_F001E644
F001E638: 90102001                 mov     1, %o0
F001E63C: 10800025                 ba      locret_F001E6D0
F001E640: b0102029                 mov     0x29, %i0 ! ')'
F001E644: 7ffffced                 call    _m_getclr
F001E648: 92102003                 mov     3, %o1
F001E64C: d4022004                 ld      [%o0+4], %o2
F001E650: 92102020                 mov     0x20, %o1 ! ' '
F001E654: a002000a                 add     %o0, %o2, %l0
F001E658: d2342002                 sth     %o1, [%l0+2]
F001E65C: c0342006                 clrh    [%l0+6]
F001E660: f432000a                 sth     %i2, [%o0+%o2]
F001E664: 113c04cf                 sethi   %hi(_active_u), %o0
F001E668: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001E66C: d002201c                 ld      [%o0+0x1C], %o0
F001E670: d0522002                 ldsh    [%o0+2], %o0
F001E674: 80a22000                 cmp     %o0, 0
F001E678: 32800005                 bne,a   loc_F001E68C
F001E67C: f024200c                 st      %i0, [%l0+0xC]
F001E680: 90102080                 mov     0x80, %o0
F001E684: d0342006                 sth     %o0, [%l0+6]
F001E688: f024200c                 st      %i0, [%l0+0xC]
F001E68C: 90100010                 mov     %l0, %o0
F001E690: 92102000                 mov     0, %o1
F001E694: 94102000                 mov     0, %o2
F001E698: da06201c                 ld      [%i0+0x1C], %o5
F001E69C: 9610001b                 mov     %i3, %o3
F001E6A0: 9fc34000                 call    %o5
F001E6A4: 98102000                 mov     0, %o4
F001E6A8: b0920000                 orcc    %o0, %g0, %i0
F001E6AC: 32800005                 bne,a   loc_F001E6C0
F001E6B0: d2142006                 lduh    [%l0+6], %o1
F001E6B4: e0264000                 st      %l0, [%i1]
F001E6B8: 10800006                 ba      locret_F001E6D0
F001E6BC: b0102000                 mov     0, %i0
F001E6C0: 90100010                 mov     %l0, %o0
F001E6C4: 92126001                 bset    1, %o1
F001E6C8: 4000003b                 call    _sofree
F001E6CC: d2322006                 sth     %o1, [%o0+6]
F001E6D0: 81c7e008                 ret
F001E6D4: 81e80000                 restore
