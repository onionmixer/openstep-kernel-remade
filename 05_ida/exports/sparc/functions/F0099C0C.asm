F0099C0C: 9de3bf98                 save    %sp, -0x68, %sp
F0099C10: 90102001                 mov     1, %o0
F0099C14: 133c04f7                 sethi   %hi(_reboot_how), %o1
F0099C18: 153c045c                 sethi   %hi(unk_F01170A8), %o2
F0099C1C: d20261f0                 ld      [%o1+%lo(_reboot_how)], %o1
F0099C20: 7ffdda19                 call    _boot
F0099C24: 9412a0a8                 bset    %lo(unk_F01170A8), %o2
F0099C28: 81c7e008                 ret
F0099C2C: 81e80000                 restore
