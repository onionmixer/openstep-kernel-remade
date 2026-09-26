F00C3C88: 9de3bf90                 save    %sp, -0x70, %sp
F00C3C8C: f027bff0                 st      %i0, [%fp+var_10]
F00C3C90: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C3C94: 9410001a                 mov     %i2, %o2
F00C3C98: 133c0507                 sethi   %hi(stru_F0141E1C.ext), %o1
F00C3C9C: 992f2018                 sll     %i4, 24, %o4
F00C3CA0: d6026248                 ld      [%o1+%lo(stru_F0141E1C.ext)], %o3
F00C3CA4: 993b2018                 sra     %o4, 24, %o4
F00C3CA8: 133c0504                 sethi   %hi(paInitforresourc_0), %o1
F00C3CAC: d627bff4                 st      %o3, [%fp+var_C]
F00C3CB0: d2026034                 ld      [%o1+%lo(paInitforresourc_0)], %o1! SEL
F00C3CB4: 4000b732                 call    _objc_msgSendSuper
F00C3CB8: 9610001b                 mov     %i3, %o3
F00C3CBC: 113c0506                 sethi   %hi(paKernlock), %o0
F00C3CC0: d002228c                 ld      [%o0+%lo(paKernlock)], %o0! id
F00C3CC4: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C3CC8: 4000b6ea                 call    _objc_msgSend
F00C3CCC: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C3CD0: 133c0504                 sethi   %hi(paInitwithlevel), %o1
F00C3CD4: d2026028                 ld      [%o1+%lo(paInitwithlevel)], %o1! SEL
F00C3CD8: 4000b6e6                 call    _objc_msgSend
F00C3CDC: 9410200a                 mov     0xA, %o2
F00C3CE0: d026202c                 st      %o0, [%i0+0x2C]
F00C3CE4: 90102009                 mov     9, %o0
F00C3CE8: d0262030                 st      %o0, [%i0+0x30]
F00C3CEC: 81c7e008                 ret
F00C3CF0: 81e80000                 restore
