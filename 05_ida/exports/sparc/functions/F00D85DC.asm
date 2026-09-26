F00D85DC: 9de3bf90                 save    %sp, -0x70, %sp
F00D85E0: 90100018                 mov     %i0, %o0! id
F00D85E4: 9410201e                 mov     0x1E, %o2
F00D85E8: 133c0505                 sethi   %hi(paSetinputforTo), %o1! SEL
F00D85EC: e0026154                 ld      [%o1+%lo(paSetinputforTo)], %l0
F00D85F0: 96102000                 mov     0, %o3
F00D85F4: 4000649f                 call    _objc_msgSend
F00D85F8: 92100010                 mov     %l0, %o1
F00D85FC: 90100018                 mov     %i0, %o0! id
F00D8600: 92100010                 mov     %l0, %o1! SEL
F00D8604: 9410201f                 mov     0x1F, %o2
F00D8608: 4000649a                 call    _objc_msgSend
F00D860C: 96102000                 mov     0, %o3
F00D8610: 90100018                 mov     %i0, %o0! id
F00D8614: 92100010                 mov     %l0, %o1! SEL
F00D8618: 94102020                 mov     0x20, %o2 ! ' '
F00D861C: 40006495                 call    _objc_msgSend
F00D8620: 96102000                 mov     0, %o3
F00D8624: 90100018                 mov     %i0, %o0! id
F00D8628: 92100010                 mov     %l0, %o1! SEL
F00D862C: 94102021                 mov     0x21, %o2 ! '!'
F00D8630: 40006490                 call    _objc_msgSend
F00D8634: 96102000                 mov     0, %o3
F00D8638: 90100018                 mov     %i0, %o0! id
F00D863C: 92100010                 mov     %l0, %o1! SEL
F00D8640: 94102022                 mov     0x22, %o2 ! '"'
F00D8644: 4000648b                 call    _objc_msgSend
F00D8648: 96102000                 mov     0, %o3
F00D864C: 90100018                 mov     %i0, %o0! id
F00D8650: 92100010                 mov     %l0, %o1! SEL
F00D8654: 9410001a                 mov     %i2, %o2
F00D8658: 40006486                 call    _objc_msgSend
F00D865C: 96102001                 mov     1, %o3
F00D8660: 81c7e008                 ret
F00D8664: 81e80000                 restore
