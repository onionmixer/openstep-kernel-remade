F00DE0A4: 9de3bf98                 save    %sp, -0x68, %sp
F00DE0A8: 80a62000                 cmp     %i0, 0
F00DE0AC: 02800017                 be      loc_F00DE108
F00DE0B0: 113c0505                 sethi   %hi(paAudiodevice), %o0
F00DE0B4: e2022224                 ld      [%o0+%lo(paAudiodevice)], %l1
F00DE0B8: 90100018                 mov     %i0, %o0! id
F00DE0BC: 40004ded                 call    _objc_msgSend
F00DE0C0: 92100011                 mov     %l1, %o1
F00DE0C4: 94102000                 mov     0, %o2
F00DE0C8: 133c0505                 sethi   %hi(paIntvalueforpar), %o1! SEL
F00DE0CC: e00260f8                 ld      [%o1+%lo(paIntvalueforpar)], %l0
F00DE0D0: 96100018                 mov     %i0, %o3
F00DE0D4: 40004de7                 call    _objc_msgSend
F00DE0D8: 92100010                 mov     %l0, %o1! SEL
F00DE0DC: d0264000                 st      %o0, [%i1]
F00DE0E0: 90100018                 mov     %i0, %o0! id
F00DE0E4: 40004de3                 call    _objc_msgSend
F00DE0E8: 92100011                 mov     %l1, %o1
F00DE0EC: 92100010                 mov     %l0, %o1! SEL
F00DE0F0: 94102001                 mov     1, %o2
F00DE0F4: 40004ddf                 call    _objc_msgSend
F00DE0F8: 96100018                 mov     %i0, %o3
F00DE0FC: d0268000                 st      %o0, [%i2]
F00DE100: 10800003                 ba      locret_F00DE10C
F00DE104: b0102000                 mov     0, %i0
F00DE108: b01020ca                 mov     0xCA, %i0
F00DE10C: 81c7e008                 ret
F00DE110: 81e80000                 restore
