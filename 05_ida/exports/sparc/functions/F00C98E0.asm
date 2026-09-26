F00C98E0: 9de3bf90                 save    %sp, -0x70, %sp
F00C98E4: 113c0506                 sethi   %hi(paAttachinterrup_0), %o0! id
F00C98E8: d20220e8                 ld      [%o0+%lo(paAttachinterrup_0)], %o1! SEL
F00C98EC: 40009fe1                 call    _objc_msgSend
F00C98F0: 90100018                 mov     %i0, %o0
F00C98F4: 80a22000                 cmp     %o0, 0
F00C98F8: 32800009                 bne,a   locret_F00C991C
F00C98FC: b0103d27                 mov     -0x2D9, %i0
F00C9900: 90100018                 mov     %i0, %o0! id
F00C9904: 133c0506                 sethi   %hi(paChangeinterrup), %o1
F00C9908: d20260cc                 ld      [%o1+%lo(paChangeinterrup)], %o1! SEL
F00C990C: 9410001a                 mov     %i2, %o2
F00C9910: 40009fd8                 call    _objc_msgSend
F00C9914: 96102001                 mov     1, %o3
F00C9918: b0100008                 mov     %o0, %i0
F00C991C: 81c7e008                 ret
F00C9920: 81e80000                 restore
