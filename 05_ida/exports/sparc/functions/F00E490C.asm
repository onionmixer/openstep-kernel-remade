F00E490C: 9de3bf90                 save    %sp, -0x70, %sp
F00E4910: d4062004                 ld      [%i0+4], %o2
F00E4914: 80a2a018                 cmp     %o2, 0x18
F00E4918: 12800005                 bne     loc_F00E492C
F00E491C: d00e2003                 ldub    [%i0+3], %o0
F00E4920: 80a22001                 cmp     %o0, 1
F00E4924: 22800005                 be,a    loc_F00E4938
F00E4928: d006200c                 ld      [%i0+0xC], %o0
F00E492C: 90103ed0                 mov     -0x130, %o0
F00E4930: 1080001b                 ba      locret_F00E499C
F00E4934: d026601c                 st      %o0, [%i1+0x1C]
F00E4938: 92102100                 mov     0x100, %o1
F00E493C: 7fffe5a1                 call    _audio_port_to_device
F00E4940: d227bff4                 st      %o1, [%fp+var_C]
F00E4944: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E4948: 7fffe9d5                 call    __NXAudioGetDataEncodings
F00E494C: 9407bff4                 add     %fp, var_C, %o2
F00E4950: 80a22000                 cmp     %o0, 0
F00E4954: 12800012                 bne     locret_F00E499C
F00E4958: d026601c                 st      %o0, [%i1+0x1C]
F00E495C: 113c03e6                 sethi   %hi(dword_F00F9B78), %o0
F00E4960: d2022378                 ld      [%o0+%lo(dword_F00F9B78)], %o1
F00E4964: d407bff4                 ld      [%fp+var_C], %o2
F00E4968: d2266020                 st      %o1, [%i1+0x20]
F00E496C: 113fffc09012200f         set     -0xFFF1, %o0
F00E4974: 920a4008                 and     %o1, %o0, %o1
F00E4978: 900aafff                 and     %o2, 0xFFF, %o0
F00E497C: 912a2004                 sll     %o0, 4, %o0
F00E4980: 92124008                 bset    %o0, %o1
F00E4984: d2266020                 st      %o1, [%i1+0x20]
F00E4988: 952aa002                 sll     %o2, 2, %o2
F00E498C: 9402a024                 inc     0x24, %o2 ! '$'
F00E4990: 90102001                 mov     1, %o0
F00E4994: d02e6003                 stb     %o0, [%i1+3]
F00E4998: d4266004                 st      %o2, [%i1+4]
F00E499C: 81c7e008                 ret
F00E49A0: 81e80000                 restore
