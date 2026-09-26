F00E478C: 9de3bf90                 save    %sp, -0x70, %sp
F00E4790: d4062004                 ld      [%i0+4], %o2
F00E4794: 80a2a020                 cmp     %o2, 0x20 ! ' '
F00E4798: 12800005                 bne     loc_F00E47AC
F00E479C: d00e2003                 ldub    [%i0+3], %o0
F00E47A0: 80a22001                 cmp     %o0, 1
F00E47A4: 22800005                 be,a    loc_F00E47B8
F00E47A8: d0062018                 ld      [%i0+0x18], %o0
F00E47AC: 90103ed0                 mov     -0x130, %o0
F00E47B0: 10800023                 ba      locret_F00E483C
F00E47B4: d026601c                 st      %o0, [%i1+0x1C]
F00E47B8: 133c03e6                 sethi   %hi(dword_F00F9B60), %o1
F00E47BC: d2026360                 ld      [%o1+%lo(dword_F00F9B60)], %o1
F00E47C0: 80a20009                 cmp     %o0, %o1
F00E47C4: 1280000a                 bne     loc_F00E47EC
F00E47C8: 90103ed0                 mov     -0x130, %o0
F00E47CC: 92102100                 mov     0x100, %o1
F00E47D0: d006200c                 ld      [%i0+0xC], %o0
F00E47D4: 7fffe5fb                 call    _audio_port_to_device
F00E47D8: d227bff4                 st      %o1, [%fp+var_C]
F00E47DC: 94066024                 add     %i1, 0x24, %o2 ! '$'
F00E47E0: d206201c                 ld      [%i0+0x1C], %o1
F00E47E4: 7fffe9f3                 call    __NXAudioGetDeviceParameterValues
F00E47E8: 9607bff4                 add     %fp, var_C, %o3
F00E47EC: d026601c                 st      %o0, [%i1+0x1C]
F00E47F0: d006601c                 ld      [%i1+0x1C], %o0
F00E47F4: 80a22000                 cmp     %o0, 0
F00E47F8: 12800011                 bne     locret_F00E483C
F00E47FC: 113c03e6                 sethi   %hi(dword_F00F9B64), %o0
F00E4800: d2022364                 ld      [%o0+%lo(dword_F00F9B64)], %o1
F00E4804: d407bff4                 ld      [%fp+var_C], %o2
F00E4808: d2266020                 st      %o1, [%i1+0x20]
F00E480C: 113fffc09012200f         set     -0xFFF1, %o0
F00E4814: 920a4008                 and     %o1, %o0, %o1
F00E4818: 900aafff                 and     %o2, 0xFFF, %o0
F00E481C: 912a2004                 sll     %o0, 4, %o0
F00E4820: 92124008                 bset    %o0, %o1
F00E4824: d2266020                 st      %o1, [%i1+0x20]
F00E4828: 952aa002                 sll     %o2, 2, %o2
F00E482C: 9402a024                 inc     0x24, %o2 ! '$'
F00E4830: 90102001                 mov     1, %o0
F00E4834: d02e6003                 stb     %o0, [%i1+3]
F00E4838: d4266004                 st      %o2, [%i1+4]
F00E483C: 81c7e008                 ret
F00E4840: 81e80000                 restore
