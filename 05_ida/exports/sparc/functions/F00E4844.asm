F00E4844: 9de3bf90                 save    %sp, -0x70, %sp
F00E4848: d2062004                 ld      [%i0+4], %o1
F00E484C: 80a26018                 cmp     %o1, 0x18
F00E4850: 12800005                 bne     loc_F00E4864
F00E4854: d00e2003                 ldub    [%i0+3], %o0
F00E4858: 80a22001                 cmp     %o0, 1
F00E485C: 22800005                 be,a    loc_F00E4870
F00E4860: d006200c                 ld      [%i0+0xC], %o0
F00E4864: 90103ed0                 mov     -0x130, %o0
F00E4868: 10800027                 ba      locret_F00E4904
F00E486C: d026601c                 st      %o0, [%i1+0x1C]
F00E4870: 92102100                 mov     0x100, %o1
F00E4874: 7fffe5d3                 call    _audio_port_to_device
F00E4878: d227bff4                 st      %o1, [%fp+var_C]
F00E487C: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E4880: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F00E4884: 96066034                 add     %i1, 0x34, %o3 ! '4'
F00E4888: 9806603c                 add     %i1, 0x3C, %o4 ! '<'
F00E488C: 7fffe9e0                 call    __NXAudioGetSamplingRates
F00E4890: 9a07bff4                 add     %fp, var_C, %o5
F00E4894: 80a22000                 cmp     %o0, 0
F00E4898: 1280001b                 bne     locret_F00E4904
F00E489C: d026601c                 st      %o0, [%i1+0x1C]
F00E48A0: 113c03e6                 sethi   %hi(dword_F00F9B68), %o0
F00E48A4: d2022368                 ld      [%o0+%lo(dword_F00F9B68)], %o1
F00E48A8: 113c03e6                 sethi   %hi(dword_F00F9B6C), %o0
F00E48AC: d002236c                 ld      [%o0+%lo(dword_F00F9B6C)], %o0
F00E48B0: d2266020                 st      %o1, [%i1+0x20]
F00E48B4: d0266028                 st      %o0, [%i1+0x28]
F00E48B8: 113c03e6                 sethi   %hi(dword_F00F9B70), %o0
F00E48BC: d2022370                 ld      [%o0+%lo(dword_F00F9B70)], %o1
F00E48C0: 113c03e6                 sethi   %hi(dword_F00F9B74), %o0
F00E48C4: d4022374                 ld      [%o0+%lo(dword_F00F9B74)], %o2
F00E48C8: d2266030                 st      %o1, [%i1+0x30]
F00E48CC: d207bff4                 ld      [%fp+var_C], %o1
F00E48D0: d4266038                 st      %o2, [%i1+0x38]
F00E48D4: 113fffc09012200f         set     -0xFFF1, %o0
F00E48DC: 940a8008                 and     %o2, %o0, %o2
F00E48E0: 900a6fff                 and     %o1, 0xFFF, %o0
F00E48E4: 912a2004                 sll     %o0, 4, %o0
F00E48E8: 94128008                 bset    %o0, %o2
F00E48EC: d4266038                 st      %o2, [%i1+0x38]
F00E48F0: 932a6002                 sll     %o1, 2, %o1
F00E48F4: 9202603c                 inc     0x3C, %o1 ! '<'
F00E48F8: 90102001                 mov     1, %o0
F00E48FC: d02e6003                 stb     %o0, [%i1+3]
F00E4900: d2266004                 st      %o1, [%i1+4]
F00E4904: 81c7e008                 ret
F00E4908: 81e80000                 restore
