F0099C30: 9de3bf98                 save    %sp, -0x68, %sp
F0099C34: 113c0442                 sethi   %hi(_kernel_task), %o0
F0099C38: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0
F0099C3C: 80a22000                 cmp     %o0, 0
F0099C40: 02800008                 be      loc_F0099C60
F0099C44: 113c04f7                 sethi   %hi(_reboot_how), %o0
F0099C48: f02221f0                 st      %i0, [%o0+%lo(_reboot_how)]
F0099C4C: 113c02679012200c         set     _halt_thread, %o0
F0099C54: 7fff734c                 call    _calloutDispatch
F0099C58: 92102000                 mov     0, %o1
F0099C5C: 30800006                 ba,a    locret_F0099C74
F0099C60: 90102001                 mov     1, %o0
F0099C64: 92162004                 or      %i0, 4, %o1
F0099C68: 153c045c                 sethi   %hi(unk_F01170B0), %o2
F0099C6C: 7ffdda06                 call    _boot
F0099C70: 9412a0b0                 bset    %lo(unk_F01170B0), %o2
F0099C74: 81c7e008                 ret
F0099C78: 81e80000                 restore
