F00D7600: 9de3bf90                 save    %sp, -0x70, %sp
F00D7604: a0102000                 mov     0, %l0
F00D7608: 233c04bb                 sethi   %hi(dword_F012EF0C), %l1
F00D760C: 293c0504                 sethi   -0xFEBF000, %l4
F00D7610: 273c0504                 sethi   -0xFEBF000, %l3
F00D7614: 253c0505                 sethi   -0xFEBEC00, %l2
F00D7618: d004630c                 ld      [%l1+%lo(dword_F012EF0C)], %o0! id
F00D761C: 40006895                 call    _objc_msgSend
F00D7620: d20520b8                 ld      [%l4+0xB8], %o1
F00D7624: 80a40008                 cmp     %l0, %o0
F00D7628: 1a80000d                 bcc     loc_F00D765C
F00D762C: d004630c                 ld      [%l1+0x30C], %o0! id
F00D7630: d204e0c8                 ld      [%l3+0xC8], %o1! SEL
F00D7634: 4000688f                 call    _objc_msgSend
F00D7638: 94100010                 mov     %l0, %o2
F00D763C: b0100008                 mov     %o0, %i0
F00D7640: 4000688c                 call    _objc_msgSend
F00D7644: d204a228                 ld      [%l2+0x228], %o1
F00D7648: 80a2001a                 cmp     %o0, %i2
F00D764C: 02800005                 be      locret_F00D7660
F00D7650: a0042001                 inc     %l0
F00D7654: 10bffff2                 ba      loc_F00D761C
F00D7658: d004630c                 ld      [%l1+0x30C], %o0
F00D765C: b0102000                 mov     0, %i0
F00D7660: 81c7e008                 ret
F00D7664: 81e80000                 restore
