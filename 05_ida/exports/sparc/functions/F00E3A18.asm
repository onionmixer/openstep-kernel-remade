F00E3A18: 9de3bf98                 save    %sp, -0x68, %sp
F00E3A1C: d2062004                 ld      [%i0+4], %o1
F00E3A20: 80a26018                 cmp     %o1, 0x18
F00E3A24: 12800005                 bne     loc_F00E3A38
F00E3A28: d00e2003                 ldub    [%i0+3], %o0
F00E3A2C: 80a22001                 cmp     %o0, 1
F00E3A30: 02800005                 be      loc_F00E3A44
F00E3A34: 01000000                 nop
F00E3A38: 90103ed0                 mov     -0x130, %o0
F00E3A3C: 10800010                 ba      locret_F00E3A7C
F00E3A40: d026601c                 st      %o0, [%i1+0x1C]
F00E3A44: 7fffe95f                 call    _audio_port_to_device
F00E3A48: d006200c                 ld      [%i0+0xC], %o0
F00E3A4C: 7fffea64                 call    __NXAudioGetClipCount
F00E3A50: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E3A54: 80a22000                 cmp     %o0, 0
F00E3A58: 12800009                 bne     locret_F00E3A7C
F00E3A5C: d026601c                 st      %o0, [%i1+0x1C]
F00E3A60: 92102028                 mov     0x28, %o1 ! '('
F00E3A64: 90102001                 mov     1, %o0
F00E3A68: d02e6003                 stb     %o0, [%i1+3]
F00E3A6C: 113c03e6                 sethi   %hi(dword_F00F9AA4), %o0
F00E3A70: d00222a4                 ld      [%o0+%lo(dword_F00F9AA4)], %o0
F00E3A74: d2266004                 st      %o1, [%i1+4]
F00E3A78: d0266020                 st      %o0, [%i1+0x20]
F00E3A7C: 81c7e008                 ret
F00E3A80: 81e80000                 restore
