F00E3C00: 9de3bf98                 save    %sp, -0x68, %sp
F00E3C04: d2062004                 ld      [%i0+4], %o1
F00E3C08: 80a26030                 cmp     %o1, 0x30 ! '0'
F00E3C0C: 12800005                 bne     loc_F00E3C20
F00E3C10: d00e2003                 ldub    [%i0+3], %o0
F00E3C14: 80a22000                 cmp     %o0, 0
F00E3C18: 22800005                 be,a    loc_F00E3C2C
F00E3C1C: d0062018                 ld      [%i0+0x18], %o0
F00E3C20: 90103ed0                 mov     -0x130, %o0
F00E3C24: 10800021                 ba      locret_F00E3CA8
F00E3C28: d026601c                 st      %o0, [%i1+0x1C]
F00E3C2C: 133c03e6                 sethi   %hi(dword_F00F9ABC), %o1
F00E3C30: d20262bc                 ld      [%o1+%lo(dword_F00F9ABC)], %o1
F00E3C34: 80a20009                 cmp     %o0, %o1
F00E3C38: 12800014                 bne     loc_F00E3C88
F00E3C3C: 90103ed0                 mov     -0x130, %o0
F00E3C40: d0062020                 ld      [%i0+0x20], %o0
F00E3C44: 133c03e6                 sethi   %hi(dword_F00F9AC0), %o1
F00E3C48: d20262c0                 ld      [%o1+%lo(dword_F00F9AC0)], %o1
F00E3C4C: 80a20009                 cmp     %o0, %o1
F00E3C50: 1280000e                 bne     loc_F00E3C88
F00E3C54: 90103ed0                 mov     -0x130, %o0
F00E3C58: d0062028                 ld      [%i0+0x28], %o0
F00E3C5C: 133c03e6                 sethi   %hi(dword_F00F9AC4), %o1
F00E3C60: d20262c4                 ld      [%o1+%lo(dword_F00F9AC4)], %o1
F00E3C64: 80a20009                 cmp     %o0, %o1
F00E3C68: 12800008                 bne     loc_F00E3C88
F00E3C6C: 90103ed0                 mov     -0x130, %o0
F00E3C70: 7fffe8d4                 call    _audio_port_to_device
F00E3C74: d006200c                 ld      [%i0+0xC], %o0
F00E3C78: d206201c                 ld      [%i0+0x1C], %o1
F00E3C7C: d4062024                 ld      [%i0+0x24], %o2
F00E3C80: 7fffeaa2                 call    __NXAudioSetSpeaker
F00E3C84: d606202c                 ld      [%i0+0x2C], %o3
F00E3C88: d026601c                 st      %o0, [%i1+0x1C]
F00E3C8C: d006601c                 ld      [%i1+0x1C], %o0
F00E3C90: 80a22000                 cmp     %o0, 0
F00E3C94: 12800005                 bne     locret_F00E3CA8
F00E3C98: 92102020                 mov     0x20, %o1 ! ' '
F00E3C9C: 90102001                 mov     1, %o0
F00E3CA0: d02e6003                 stb     %o0, [%i1+3]
F00E3CA4: d2266004                 st      %o1, [%i1+4]
F00E3CA8: 81c7e008                 ret
F00E3CAC: 81e80000                 restore
