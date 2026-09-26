F00E4C38: 9de3bf90                 save    %sp, -0x70, %sp
F00E4C3C: d4062004                 ld      [%i0+4], %o2
F00E4C40: 80a2a020                 cmp     %o2, 0x20 ! ' '
F00E4C44: 12800005                 bne     loc_F00E4C58
F00E4C48: d00e2003                 ldub    [%i0+3], %o0
F00E4C4C: 80a22001                 cmp     %o0, 1
F00E4C50: 22800005                 be,a    loc_F00E4C64
F00E4C54: d0062018                 ld      [%i0+0x18], %o0
F00E4C58: 90103ed0                 mov     -0x130, %o0
F00E4C5C: 10800023                 ba      locret_F00E4CE8
F00E4C60: d026601c                 st      %o0, [%i1+0x1C]
F00E4C64: 133c03e6                 sethi   %hi(dword_F00F9B8C), %o1
F00E4C68: d202638c                 ld      [%o1+%lo(dword_F00F9B8C)], %o1
F00E4C6C: 80a20009                 cmp     %o0, %o1
F00E4C70: 1280000a                 bne     loc_F00E4C98
F00E4C74: 90103ed0                 mov     -0x130, %o0
F00E4C78: 92102100                 mov     0x100, %o1
F00E4C7C: d006200c                 ld      [%i0+0xC], %o0
F00E4C80: 7fffe4e0                 call    _audio_port_to_stream
F00E4C84: d227bff4                 st      %o1, [%fp+var_C]
F00E4C88: 94066024                 add     %i1, 0x24, %o2 ! '$'
F00E4C8C: d206201c                 ld      [%i0+0x1C], %o1
F00E4C90: 7fffe96b                 call    __NXAudioGetStreamParameterValues
F00E4C94: 9607bff4                 add     %fp, var_C, %o3
F00E4C98: d026601c                 st      %o0, [%i1+0x1C]
F00E4C9C: d006601c                 ld      [%i1+0x1C], %o0
F00E4CA0: 80a22000                 cmp     %o0, 0
F00E4CA4: 12800011                 bne     locret_F00E4CE8
F00E4CA8: 113c03e6                 sethi   %hi(dword_F00F9B90), %o0
F00E4CAC: d2022390                 ld      [%o0+%lo(dword_F00F9B90)], %o1
F00E4CB0: d407bff4                 ld      [%fp+var_C], %o2
F00E4CB4: d2266020                 st      %o1, [%i1+0x20]
F00E4CB8: 113fffc09012200f         set     -0xFFF1, %o0
F00E4CC0: 920a4008                 and     %o1, %o0, %o1
F00E4CC4: 900aafff                 and     %o2, 0xFFF, %o0
F00E4CC8: 912a2004                 sll     %o0, 4, %o0
F00E4CCC: 92124008                 bset    %o0, %o1
F00E4CD0: d2266020                 st      %o1, [%i1+0x20]
F00E4CD4: 952aa002                 sll     %o2, 2, %o2
F00E4CD8: 9402a024                 inc     0x24, %o2 ! '$'
F00E4CDC: 90102001                 mov     1, %o0
F00E4CE0: d02e6003                 stb     %o0, [%i1+3]
F00E4CE4: d4266004                 st      %o2, [%i1+4]
F00E4CE8: 81c7e008                 ret
F00E4CEC: 81e80000                 restore
