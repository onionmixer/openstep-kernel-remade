F00E42FC: 9de3bf98                 save    %sp, -0x68, %sp
F00E4300: d2062004                 ld      [%i0+4], %o1
F00E4304: 80a26040                 cmp     %o1, 0x40 ! '@'
F00E4308: 12800005                 bne     loc_F00E431C
F00E430C: d00e2003                 ldub    [%i0+3], %o0
F00E4310: 80a22000                 cmp     %o0, 0
F00E4314: 22800005                 be,a    loc_F00E4328
F00E4318: d0062018                 ld      [%i0+0x18], %o0
F00E431C: 90103ed0                 mov     -0x130, %o0
F00E4320: 1080002e                 ba      locret_F00E43D8
F00E4324: d026601c                 st      %o0, [%i1+0x1C]
F00E4328: 900a200c                 and     %o0, 0xC, %o0
F00E432C: 80a22004                 cmp     %o0, 4
F00E4330: 12800022                 bne     loc_F00E43B8
F00E4334: 90103ed0                 mov     -0x130, %o0
F00E4338: d206201c                 ld      [%i0+0x1C], %o1
F00E433C: 1100024090122008         set     0x90008, %o0
F00E4344: 80a24008                 cmp     %o1, %o0
F00E4348: 1280001c                 bne     loc_F00E43B8
F00E434C: 90103ed0                 mov     -0x130, %o0
F00E4350: d0062028                 ld      [%i0+0x28], %o0
F00E4354: 133c03e6                 sethi   %hi(dword_F00F9B30), %o1
F00E4358: d2026330                 ld      [%o1+%lo(dword_F00F9B30)], %o1
F00E435C: 80a20009                 cmp     %o0, %o1
F00E4360: 12800016                 bne     loc_F00E43B8
F00E4364: 90103ed0                 mov     -0x130, %o0
F00E4368: d0062030                 ld      [%i0+0x30], %o0
F00E436C: 133c03e6                 sethi   %hi(dword_F00F9B34), %o1
F00E4370: d2026334                 ld      [%o1+%lo(dword_F00F9B34)], %o1
F00E4374: 80a20009                 cmp     %o0, %o1
F00E4378: 12800010                 bne     loc_F00E43B8
F00E437C: 90103ed0                 mov     -0x130, %o0
F00E4380: d0062038                 ld      [%i0+0x38], %o0
F00E4384: 133c03e6                 sethi   %hi(dword_F00F9B38), %o1
F00E4388: d2026338                 ld      [%o1+%lo(dword_F00F9B38)], %o1
F00E438C: 80a20009                 cmp     %o0, %o1
F00E4390: 1280000a                 bne     loc_F00E43B8
F00E4394: 90103ed0                 mov     -0x130, %o0
F00E4398: 7fffe71a                 call    _audio_port_to_stream
F00E439C: d006200c                 ld      [%i0+0xC], %o0
F00E43A0: d2062024                 ld      [%i0+0x24], %o1
F00E43A4: d4062020                 ld      [%i0+0x20], %o2
F00E43A8: d606202c                 ld      [%i0+0x2C], %o3
F00E43AC: d8062034                 ld      [%i0+0x34], %o4
F00E43B0: 7fffea7b                 call    __NXAudioPlayStreamData
F00E43B4: da06203c                 ld      [%i0+0x3C], %o5
F00E43B8: d026601c                 st      %o0, [%i1+0x1C]
F00E43BC: d006601c                 ld      [%i1+0x1C], %o0
F00E43C0: 80a22000                 cmp     %o0, 0
F00E43C4: 12800005                 bne     locret_F00E43D8
F00E43C8: 92102020                 mov     0x20, %o1 ! ' '
F00E43CC: 90102001                 mov     1, %o0
F00E43D0: d02e6003                 stb     %o0, [%i1+3]
F00E43D4: d2266004                 st      %o1, [%i1+4]
F00E43D8: 81c7e008                 ret
F00E43DC: 81e80000                 restore
