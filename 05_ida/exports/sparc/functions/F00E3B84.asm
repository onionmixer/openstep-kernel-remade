F00E3B84: 9de3bf98                 save    %sp, -0x68, %sp
F00E3B88: d2062004                 ld      [%i0+4], %o1
F00E3B8C: 80a26018                 cmp     %o1, 0x18
F00E3B90: 12800005                 bne     loc_F00E3BA4
F00E3B94: d00e2003                 ldub    [%i0+3], %o0
F00E3B98: 80a22001                 cmp     %o0, 1
F00E3B9C: 02800005                 be      loc_F00E3BB0
F00E3BA0: 01000000                 nop
F00E3BA4: 90103ed0                 mov     -0x130, %o0
F00E3BA8: 10800014                 ba      locret_F00E3BF8
F00E3BAC: d026601c                 st      %o0, [%i1+0x1C]
F00E3BB0: 7fffe904                 call    _audio_port_to_device
F00E3BB4: d006200c                 ld      [%i0+0xC], %o0
F00E3BB8: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E3BBC: 7fffeab7                 call    __NXAudioGetSpeaker
F00E3BC0: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F00E3BC4: 80a22000                 cmp     %o0, 0
F00E3BC8: 1280000c                 bne     locret_F00E3BF8
F00E3BCC: d026601c                 st      %o0, [%i1+0x1C]
F00E3BD0: 92102030                 mov     0x30, %o1 ! '0'
F00E3BD4: 90102001                 mov     1, %o0
F00E3BD8: d02e6003                 stb     %o0, [%i1+3]
F00E3BDC: d2266004                 st      %o1, [%i1+4]
F00E3BE0: 113c03e6                 sethi   %hi(dword_F00F9AB4), %o0
F00E3BE4: d20222b4                 ld      [%o0+%lo(dword_F00F9AB4)], %o1
F00E3BE8: 113c03e6                 sethi   %hi(dword_F00F9AB8), %o0
F00E3BEC: d00222b8                 ld      [%o0+%lo(dword_F00F9AB8)], %o0
F00E3BF0: d2266020                 st      %o1, [%i1+0x20]
F00E3BF4: d0266028                 st      %o0, [%i1+0x28]
F00E3BF8: 81c7e008                 ret
F00E3BFC: 81e80000                 restore
