F00EB49C: 9de3bf90                 save    %sp, -0x70, %sp
F00EB4A0: d2062004                 ld      [%i0+4], %o1
F00EB4A4: d0062008                 ld      [%i0+8], %o0
F00EB4A8: 912a2002                 sll     %o0, 2, %o0
F00EB4AC: 94020009                 add     %o0, %o1, %o2
F00EB4B0: 80a2400a                 cmp     %o1, %o2
F00EB4B4: 3a800013                 bcc,a   locret_F00EB500
F00EB4B8: b0102000                 mov     0, %i0
F00EB4BC: 173c0506                 sethi   -0xFEBE800, %o3
F00EB4C0: d0024000                 ld      [%o1], %o0
F00EB4C4: 80a2001a                 cmp     %o0, %i2
F00EB4C8: 3280000a                 bne,a   loc_F00EB4F0
F00EB4CC: 92026004                 inc     4, %o1
F00EB4D0: d4062004                 ld      [%i0+4], %o2
F00EB4D4: 9422400a                 sub     %o1, %o2, %o2
F00EB4D8: 90100018                 mov     %i0, %o0! id
F00EB4DC: d202e230                 ld      [%o3+0x230], %o1! SEL
F00EB4E0: 400018e4                 call    _objc_msgSend
F00EB4E4: 953aa002                 sra     %o2, 2, %o2
F00EB4E8: 10800006                 ba      locret_F00EB500
F00EB4EC: b0100008                 mov     %o0, %i0
F00EB4F0: 80a2400a                 cmp     %o1, %o2
F00EB4F4: 2abffff4                 bcs,a   loc_F00EB4C4
F00EB4F8: d0024000                 ld      [%o1], %o0
F00EB4FC: b0102000                 mov     0, %i0
F00EB500: 81c7e008                 ret
F00EB504: 81e80000                 restore
