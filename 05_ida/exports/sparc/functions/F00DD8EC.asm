F00DD8EC: 9de3bf98                 save    %sp, -0x68, %sp
F00DD8F0: 80a66000                 cmp     %i1, 0
F00DD8F4: 02800010                 be      loc_F00DD934
F00DD8F8: 92100018                 mov     %i0, %o1
F00DD8FC: 113c04cc                 sethi   %hi(dword_F01330E0), %o0
F00DD900: d00220e0                 ld      [%o0+%lo(dword_F01330E0)], %o0
F00DD904: 153c03779412a2f8         set     _audioMessages, %o2
F00DD90C: 7ffe73a6                 call    _kern_serv_port_serv
F00DD910: 96100009                 mov     %o1, %o3
F00DD914: b0920000                 orcc    %o0, %g0, %i0
F00DD918: 0280000b                 be      loc_F00DD944
F00DD91C: 113c03f1                 sethi   %hi(aAudioKernServP), %o0! "Audio: kern_serv_port_serv returns %d\n"
F00DD920: 90122340                 bset    %lo(aAudioKernServP), %o0! "Audio: kern_serv_port_serv returns %d\n"
F00DD924: 7fffa1f4                 call    _IOLog
F00DD928: 92100018                 mov     %i0, %o1
F00DD92C: 10800007                 ba      loc_F00DD948
F00DD930: 80a00018                 cmp     %g0, %i0
F00DD934: 113c04cc                 sethi   %hi(dword_F01330E0), %o0
F00DD938: d00220e0                 ld      [%o0+%lo(dword_F01330E0)], %o0
F00DD93C: 7ffe72d7                 call    _kern_serv_port_gone
F00DD940: b0102000                 mov     0, %i0
F00DD944: 80a00018                 cmp     %g0, %i0
F00DD948: b0603fff                 subc    %g0, -1, %i0
F00DD94C: 81c7e008                 ret
F00DD950: 81e80000                 restore
