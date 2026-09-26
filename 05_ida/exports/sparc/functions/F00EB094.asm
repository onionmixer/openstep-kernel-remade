F00EB094: 9de3bf90                 save    %sp, -0x70, %sp
F00EB098: 233c0506                 sethi   -0xFEBE800, %l1
F00EB09C: 213c0503                 sethi   -0xFEBF400, %l0
F00EB0A0: 90100018                 mov     %i0, %o0! id
F00EB0A4: 400019f3                 call    _objc_msgSend
F00EB0A8: d2046238                 ld      [%l1+0x238], %o1! SEL
F00EB0AC: 80a22000                 cmp     %o0, 0
F00EB0B0: 02800006                 be      locret_F00EB0C8
F00EB0B4: 01000000                 nop
F00EB0B8: 400019ee                 call    _objc_msgSend
F00EB0BC: d20423fc                 ld      [%l0+0x3FC], %o1
F00EB0C0: 10bffff9                 ba      loc_F00EB0A4
F00EB0C4: 90100018                 mov     %i0, %o0
F00EB0C8: 81c7e008                 ret
F00EB0CC: 81e80000                 restore
