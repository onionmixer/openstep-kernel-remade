F00EA4E0: 9de3bf90                 save    %sp, -0x70, %sp
F00EA4E4: 213c0506                 sethi   %hi(paInitbare), %l0
F00EA4E8: 7fffff3d                 call    sub_F00EA1DC
F00EA4EC: 9010001c                 mov     %i4, %o0
F00EA4F0: 7fffff44                 call    sub_F00EA200
F00EA4F4: 90022001                 inc     %o0
F00EA4F8: 98100008                 mov     %o0, %o4
F00EA4FC: 90100018                 mov     %i0, %o0! id
F00EA500: d204225c                 ld      [%l0+%lo(paInitbare)], %o1! SEL
F00EA504: 9410001a                 mov     %i2, %o2
F00EA508: 40001cda                 call    _objc_msgSend
F00EA50C: 9610001b                 mov     %i3, %o3
F00EA510: 133c0506                 sethi   %hi(paZone), %o1! SEL
F00EA514: 90100018                 mov     %i0, %o0! id
F00EA518: 40001cd6                 call    _objc_msgSend
F00EA51C: d2026254                 ld      [%o1+%lo(paZone)], %o1
F00EA520: d2062010                 ld      [%i0+0x10], %o1
F00EA524: 40001995                 call    _NXZoneCalloc
F00EA528: 94102008                 mov     8, %o2
F00EA52C: d0262014                 st      %o0, [%i0+0x14]
F00EA530: 81c7e008                 ret
F00EA534: 81e80000                 restore
