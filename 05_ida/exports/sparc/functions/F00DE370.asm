F00DE370: 9de3bf98                 save    %sp, -0x68, %sp
F00DE374: 80a62000                 cmp     %i0, 0
F00DE378: 12800004                 bne     loc_F00DE388
F00DE37C: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DE380: 10800015                 ba      locret_F00DE3D4
F00DE384: b01020ca                 mov     0xCA, %i0
F00DE388: d2022224                 ld      [%o0+0x224], %o1! SEL
F00DE38C: 40004d39                 call    _objc_msgSend
F00DE390: 90100018                 mov     %i0, %o0! id
F00DE394: 94102002                 mov     2, %o2
F00DE398: 133c0505                 sethi   %hi(paIntvalueforpar), %o1
F00DE39C: d20260f8                 ld      [%o1+%lo(paIntvalueforpar)], %o1! SEL
F00DE3A0: 40004d34                 call    _objc_msgSend
F00DE3A4: 96100018                 mov     %i0, %o3
F00DE3A8: 80a22000                 cmp     %o0, 0
F00DE3AC: 02800009                 be      loc_F00DE3D0
F00DE3B0: 90100018                 mov     %i0, %o0! id
F00DE3B4: 133c0505                 sethi   %hi(paGetpeakleftRig), %o1
F00DE3B8: d202600c                 ld      [%o1+%lo(paGetpeakleftRig)], %o1! SEL
F00DE3BC: 94100019                 mov     %i1, %o2
F00DE3C0: 40004d2c                 call    _objc_msgSend
F00DE3C4: 9610001a                 mov     %i2, %o3
F00DE3C8: 10800003                 ba      locret_F00DE3D4
F00DE3CC: b0102000                 mov     0, %i0
F00DE3D0: b01020d0                 mov     0xD0, %i0
F00DE3D4: 81c7e008                 ret
F00DE3D8: 81e80000                 restore
