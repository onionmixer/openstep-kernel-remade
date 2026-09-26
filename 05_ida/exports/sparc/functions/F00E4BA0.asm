F00E4BA0: 9de3bf90                 save    %sp, -0x70, %sp
F00E4BA4: d4062004                 ld      [%i0+4], %o2
F00E4BA8: 80a2a018                 cmp     %o2, 0x18
F00E4BAC: 12800005                 bne     loc_F00E4BC0
F00E4BB0: d00e2003                 ldub    [%i0+3], %o0
F00E4BB4: 80a22001                 cmp     %o0, 1
F00E4BB8: 22800005                 be,a    loc_F00E4BCC
F00E4BBC: d006200c                 ld      [%i0+0xC], %o0
F00E4BC0: 90103ed0                 mov     -0x130, %o0
F00E4BC4: 1080001b                 ba      locret_F00E4C30
F00E4BC8: d026601c                 st      %o0, [%i1+0x1C]
F00E4BCC: 92102100                 mov     0x100, %o1
F00E4BD0: 7fffe50c                 call    _audio_port_to_stream
F00E4BD4: d227bff4                 st      %o1, [%fp+var_C]
F00E4BD8: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E4BDC: 7fffe982                 call    __NXAudioGetStreamSupportedParameters
F00E4BE0: 9407bff4                 add     %fp, var_C, %o2
F00E4BE4: 80a22000                 cmp     %o0, 0
F00E4BE8: 12800012                 bne     locret_F00E4C30
F00E4BEC: d026601c                 st      %o0, [%i1+0x1C]
F00E4BF0: 113c03e6                 sethi   %hi(dword_F00F9B88), %o0
F00E4BF4: d2022388                 ld      [%o0+%lo(dword_F00F9B88)], %o1
F00E4BF8: d407bff4                 ld      [%fp+var_C], %o2
F00E4BFC: d2266020                 st      %o1, [%i1+0x20]
F00E4C00: 113fffc09012200f         set     -0xFFF1, %o0
F00E4C08: 920a4008                 and     %o1, %o0, %o1
F00E4C0C: 900aafff                 and     %o2, 0xFFF, %o0
F00E4C10: 912a2004                 sll     %o0, 4, %o0
F00E4C14: 92124008                 bset    %o0, %o1
F00E4C18: d2266020                 st      %o1, [%i1+0x20]
F00E4C1C: 952aa002                 sll     %o2, 2, %o2
F00E4C20: 9402a024                 inc     0x24, %o2 ! '$'
F00E4C24: 90102001                 mov     1, %o0
F00E4C28: d02e6003                 stb     %o0, [%i1+3]
F00E4C2C: d4266004                 st      %o2, [%i1+4]
F00E4C30: 81c7e008                 ret
F00E4C34: 81e80000                 restore
