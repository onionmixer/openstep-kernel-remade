F00E3514: 9de3bf98                 save    %sp, -0x68, %sp
F00E3518: d2062004                 ld      [%i0+4], %o1
F00E351C: 80a26018                 cmp     %o1, 0x18
F00E3520: 12800005                 bne     loc_F00E3534
F00E3524: d00e2003                 ldub    [%i0+3], %o0
F00E3528: 80a22001                 cmp     %o0, 1
F00E352C: 02800005                 be      loc_F00E3540
F00E3530: 01000000                 nop
F00E3534: 90103ed0                 mov     -0x130, %o0
F00E3538: 1080000f                 ba      locret_F00E3574
F00E353C: d026601c                 st      %o0, [%i1+0x1C]
F00E3540: 7fffeaa0                 call    _audio_port_to_device
F00E3544: d006200c                 ld      [%i0+0xC], %o0
F00E3548: 7fffeabe                 call    __NXAudioGetExclusiveUser
F00E354C: 92066024                 add     %i1, 0x24, %o1 ! '$'
F00E3550: 80a22000                 cmp     %o0, 0
F00E3554: 12800008                 bne     locret_F00E3574
F00E3558: d026601c                 st      %o0, [%i1+0x1C]
F00E355C: 92102028                 mov     0x28, %o1 ! '('
F00E3560: c02e6003                 clrb    [%i1+3]
F00E3564: 113c03e6                 sethi   %hi(dword_F00F9A54), %o0
F00E3568: d0022254                 ld      [%o0+%lo(dword_F00F9A54)], %o0
F00E356C: d2266004                 st      %o1, [%i1+4]
F00E3570: d0266020                 st      %o0, [%i1+0x20]
F00E3574: 81c7e008                 ret
F00E3578: 81e80000                 restore
