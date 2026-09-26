F00EBCFC: 9de3bf90                 save    %sp, -0x70, %sp
F00EBD00: 80a62000                 cmp     %i0, 0
F00EBD04: 12800004                 bne     loc_F00EBD14
F00EBD08: 133c0506                 sethi   -0xFEBE800, %o1
F00EBD0C: 10800013                 ba      locret_F00EBD58
F00EBD10: b0102000                 mov     0, %i0
F00EBD14: 90100018                 mov     %i0, %o0! id
F00EBD18: d2026220                 ld      [%o1+0x220], %o1! SEL
F00EBD1C: 400016d5                 call    _objc_msgSend
F00EBD20: 9410001a                 mov     %i2, %o2
F00EBD24: 94920000                 orcc    %o0, %g0, %o2! arg_size
F00EBD28: 02800007                 be      loc_F00EBD44
F00EBD2C: 90100018                 mov     %i0, %o0! self
F00EBD30: 9210001a                 mov     %i2, %o1! op
F00EBD34: 40001778                 call    _objc_msgSendv
F00EBD38: 9610001b                 mov     %i3, %o3
F00EBD3C: 10800007                 ba      locret_F00EBD58
F00EBD40: b0100008                 mov     %o0, %i0
F00EBD44: 133c0506                 sethi   %hi(paDoesnotrecogni), %o1
F00EBD48: d2026224                 ld      [%o1+%lo(paDoesnotrecogni)], %o1! SEL
F00EBD4C: 400016c9                 call    _objc_msgSend
F00EBD50: 9410001a                 mov     %i2, %o2
F00EBD54: b0100008                 mov     %o0, %i0
F00EBD58: 81c7e008                 ret
F00EBD5C: 81e80000                 restore
