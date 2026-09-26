F00C9634: 9de3bf90                 save    %sp, -0x70, %sp
F00C9638: a0100018                 mov     %i0, %l0
F00C963C: 9410001a                 mov     %i2, %o2
F00C9640: d0042110                 ld      [%l0+0x110], %o0! id
F00C9644: 80a22000                 cmp     %o0, 0
F00C9648: 1280000c                 bne     locret_F00C9678
F00C964C: b0102000                 mov     0, %i0
F00C9650: 133c0506                 sethi   %hi(paStartiothreadw_0), %o1
F00C9654: d20260e4                 ld      [%o1+%lo(paStartiothreadw_0)], %o1! SEL
F00C9658: 4000a086                 call    _objc_msgSend
F00C965C: 90100010                 mov     %l0, %o0
F00C9660: b0920000                 orcc    %o0, %g0, %i0
F00C9664: 12800005                 bne     locret_F00C9678
F00C9668: 01000000                 nop
F00C966C: d0042110                 ld      [%l0+0x110], %o0
F00C9670: 400002ce                 call    _IOSetThreadPolicy
F00C9674: 92102002                 mov     2, %o1
F00C9678: 81c7e008                 ret
F00C967C: 81e80000                 restore
