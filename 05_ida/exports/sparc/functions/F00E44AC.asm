F00E44AC: 9de3bf90                 save    %sp, -0x70, %sp
F00E44B0: d2062004                 ld      [%i0+4], %o1
F00E44B4: 80a26018                 cmp     %o1, 0x18
F00E44B8: 12800005                 bne     loc_F00E44CC
F00E44BC: d00e2003                 ldub    [%i0+3], %o0
F00E44C0: 80a22001                 cmp     %o0, 1
F00E44C4: 22800005                 be,a    loc_F00E44D8
F00E44C8: d006200c                 ld      [%i0+0xC], %o0
F00E44CC: 90103ed0                 mov     -0x130, %o0
F00E44D0: 1080001c                 ba      locret_F00E4540
F00E44D4: d026601c                 st      %o0, [%i1+0x1C]
F00E44D8: 92102100                 mov     0x100, %o1
F00E44DC: 7fffe6b9                 call    _audio_port_to_device
F00E44E0: d227bff4                 st      %o1, [%fp+var_C]
F00E44E4: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E44E8: 7fffea54                 call    __NXAudioGetDeviceName
F00E44EC: 9407bff4                 add     %fp, var_C, %o2
F00E44F0: 80a22000                 cmp     %o0, 0
F00E44F4: 12800013                 bne     locret_F00E4540
F00E44F8: d026601c                 st      %o0, [%i1+0x1C]
F00E44FC: 113c03e6                 sethi   %hi(dword_F00F9B4C), %o0
F00E4500: d402234c                 ld      [%o0+%lo(dword_F00F9B4C)], %o2
F00E4504: d207bff4                 ld      [%fp+var_C], %o1
F00E4508: d4266020                 st      %o2, [%i1+0x20]
F00E450C: 113fffc09012200f         set     -0xFFF1, %o0
F00E4514: 940a8008                 and     %o2, %o0, %o2
F00E4518: 900a6fff                 and     %o1, 0xFFF, %o0
F00E451C: 912a2004                 sll     %o0, 4, %o0
F00E4520: 94128008                 bset    %o0, %o2
F00E4524: d4266020                 st      %o2, [%i1+0x20]
F00E4528: 92026003                 inc     3, %o1
F00E452C: 920a7ffc                 and     %o1, -4, %o1
F00E4530: 92026024                 inc     0x24, %o1 ! '$'
F00E4534: 90102001                 mov     1, %o0
F00E4538: d02e6003                 stb     %o0, [%i1+3]
F00E453C: d2266004                 st      %o1, [%i1+4]
F00E4540: 81c7e008                 ret
F00E4544: 81e80000                 restore
