F00DD5C8: 9de3bf90                 save    %sp, -0x70, %sp
F00DD5CC: 7ffe7632                 call    _kern_serv_kernel_task_port
F00DD5D0: 01000000                 nop
F00DD5D4: d2068000                 ld      [%i2], %o1
F00DD5D8: 40005b74                 call    _vm_deallocate_EXTERNAL
F00DD5DC: d406a010                 ld      [%i2+0x10], %o2
F00DD5E0: 92920000                 orcc    %o0, %g0, %o1
F00DD5E4: 02800004                 be      loc_F00DD5F4
F00DD5E8: 113c03f1                 sethi   %hi(aAudioStreamVmD_0), %o0! "Audio: stream vm_deallocate error %d\n"
F00DD5EC: 7fffa2c2                 call    _IOLog
F00DD5F0: 901222f0                 bset    %lo(aAudioStreamVmD_0), %o0! "Audio: stream vm_deallocate error %d\n"
F00DD5F4: f027bff0                 st      %i0, [%fp+var_10]
F00DD5F8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DD5FC: 133c0508                 sethi   %hi(stru_F01422CC.ext), %o1
F00DD600: d60262f8                 ld      [%o1+%lo(stru_F01422CC.ext)], %o3
F00DD604: 9410001a                 mov     %i2, %o2
F00DD608: 133c0505                 sethi   %hi(paFreeregion), %o1
F00DD60C: d202606c                 ld      [%o1+%lo(paFreeregion)], %o1! SEL
F00DD610: 400050db                 call    _objc_msgSendSuper
F00DD614: d627bff4                 st      %o3, [%fp+var_C]
F00DD618: 81c7e008                 ret
F00DD61C: 91e80008                 restore %g0, %o0, %o0
