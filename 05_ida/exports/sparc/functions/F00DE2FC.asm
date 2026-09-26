F00DE2FC: 9de3bf98                 save    %sp, -0x68, %sp
F00DE300: 80a62000                 cmp     %i0, 0
F00DE304: 12800004                 bne     loc_F00DE314
F00DE308: 94100019                 mov     %i1, %o2
F00DE30C: 10800017                 ba      locret_F00DE368
F00DE310: b01020ca                 mov     0xCA, %i0
F00DE314: 133c0505                 sethi   %hi(paCheckowner), %o1
F00DE318: d2026018                 ld      [%o1+%lo(paCheckowner)], %o1! SEL
F00DE31C: 40004d55                 call    _objc_msgSend
F00DE320: 90100018                 mov     %i0, %o0
F00DE324: 912a2018                 sll     %o0, 24, %o0
F00DE328: 80a22000                 cmp     %o0, 0
F00DE32C: 0280000e                 be      loc_F00DE364
F00DE330: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DE334: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DE338: 40004d4e                 call    _objc_msgSend
F00DE33C: 90100018                 mov     %i0, %o0! id
F00DE340: 94102002                 mov     2, %o2
F00DE344: 80a0001a                 cmp     %g0, %i2
F00DE348: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE34C: 96402000                 addc    %g0, 0, %o3
F00DE350: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1! SEL
F00DE354: 40004d47                 call    _objc_msgSend
F00DE358: 98100018                 mov     %i0, %o4
F00DE35C: 10800003                 ba      locret_F00DE368
F00DE360: b0102000                 mov     0, %i0
F00DE364: b01020c8                 mov     0xC8, %i0
F00DE368: 81c7e008                 ret
F00DE36C: 81e80000                 restore
