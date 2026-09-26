F00E46F4: 9de3bf90                 save    %sp, -0x70, %sp
F00E46F8: d4062004                 ld      [%i0+4], %o2
F00E46FC: 80a2a018                 cmp     %o2, 0x18
F00E4700: 12800005                 bne     loc_F00E4714
F00E4704: d00e2003                 ldub    [%i0+3], %o0
F00E4708: 80a22001                 cmp     %o0, 1
F00E470C: 22800005                 be,a    loc_F00E4720
F00E4710: d006200c                 ld      [%i0+0xC], %o0
F00E4714: 90103ed0                 mov     -0x130, %o0
F00E4718: 1080001b                 ba      locret_F00E4784
F00E471C: d026601c                 st      %o0, [%i1+0x1C]
F00E4720: 92102100                 mov     0x100, %o1
F00E4724: 7fffe627                 call    _audio_port_to_device
F00E4728: d227bff4                 st      %o1, [%fp+var_C]
F00E472C: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E4730: 7fffea0d                 call    __NXAudioGetDeviceSupportedParameters
F00E4734: 9407bff4                 add     %fp, var_C, %o2
F00E4738: 80a22000                 cmp     %o0, 0
F00E473C: 12800012                 bne     locret_F00E4784
F00E4740: d026601c                 st      %o0, [%i1+0x1C]
F00E4744: 113c03e6                 sethi   %hi(dword_F00F9B5C), %o0
F00E4748: d202235c                 ld      [%o0+%lo(dword_F00F9B5C)], %o1
F00E474C: d407bff4                 ld      [%fp+var_C], %o2
F00E4750: d2266020                 st      %o1, [%i1+0x20]
F00E4754: 113fffc09012200f         set     -0xFFF1, %o0
F00E475C: 920a4008                 and     %o1, %o0, %o1
F00E4760: 900aafff                 and     %o2, 0xFFF, %o0
F00E4764: 912a2004                 sll     %o0, 4, %o0
F00E4768: 92124008                 bset    %o0, %o1
F00E476C: d2266020                 st      %o1, [%i1+0x20]
F00E4770: 952aa002                 sll     %o2, 2, %o2
F00E4774: 9402a024                 inc     0x24, %o2 ! '$'
F00E4778: 90102001                 mov     1, %o0
F00E477C: d02e6003                 stb     %o0, [%i1+3]
F00E4780: d4266004                 st      %o2, [%i1+4]
F00E4784: 81c7e008                 ret
F00E4788: 81e80000                 restore
