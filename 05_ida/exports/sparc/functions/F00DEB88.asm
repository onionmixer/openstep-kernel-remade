F00DEB88: 9de3bf98                 save    %sp, -0x68, %sp
F00DEB8C: 80a62000                 cmp     %i0, 0
F00DEB90: 12800004                 bne     loc_F00DEBA0
F00DEB94: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DEB98: 10800018                 ba      locret_F00DEBF8
F00DEB9C: b01020ca                 mov     0xCA, %i0
F00DEBA0: d2022058                 ld      [%o0+0x58], %o1! SEL
F00DEBA4: 40004b33                 call    _objc_msgSend
F00DEBA8: 90100018                 mov     %i0, %o0! id
F00DEBAC: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DEBB0: 40004b30                 call    _objc_msgSend
F00DEBB4: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DEBB8: 94102197                 mov     0x197, %o2
F00DEBBC: 133c0505                 sethi   %hi(paIntvalueforpar), %o1
F00DEBC0: d20260f8                 ld      [%o1+%lo(paIntvalueforpar)], %o1! SEL
F00DEBC4: 40004b2b                 call    _objc_msgSend
F00DEBC8: 96100018                 mov     %i0, %o3
F00DEBCC: 80a22000                 cmp     %o0, 0
F00DEBD0: 02800009                 be      loc_F00DEBF4
F00DEBD4: 90100018                 mov     %i0, %o0! id
F00DEBD8: 133c0505                 sethi   %hi(paGetpeakleftRig), %o1
F00DEBDC: d202600c                 ld      [%o1+%lo(paGetpeakleftRig)], %o1! SEL
F00DEBE0: 94100019                 mov     %i1, %o2
F00DEBE4: 40004b23                 call    _objc_msgSend
F00DEBE8: 9610001a                 mov     %i2, %o3
F00DEBEC: 10800003                 ba      locret_F00DEBF8
F00DEBF0: b0102000                 mov     0, %i0
F00DEBF4: b01020d0                 mov     0xD0, %i0
F00DEBF8: 81c7e008                 ret
F00DEBFC: 81e80000                 restore
