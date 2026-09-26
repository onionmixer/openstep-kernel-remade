F00DC678: 9de3bf90                 save    %sp, -0x70, %sp
F00DC67C: 7ffe7a06                 call    _kern_serv_kernel_task_port
F00DC680: 01000000                 nop
F00DC684: d2068000                 ld      [%i2], %o1
F00DC688: 40005f48                 call    _vm_deallocate_EXTERNAL
F00DC68C: d406a010                 ld      [%i2+0x10], %o2
F00DC690: 80a22000                 cmp     %o0, 0
F00DC694: 02800006                 be      loc_F00DC6AC
F00DC698: 113c03f1                 sethi   %hi(aAudioStreamVmD), %o0! "Audio: stream vm_deallocate error %s\n"
F00DC69C: 90122200                 bset    %lo(aAudioStreamVmD), %o0! "Audio: stream vm_deallocate error %s\n"
F00DC6A0: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DC6A4: 7fffa694                 call    _IOLog
F00DC6A8: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DC6AC: f027bff0                 st      %i0, [%fp+var_10]
F00DC6B0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DC6B4: 133c0508                 sethi   %hi(stru_F01422CC.super_class), %o1
F00DC6B8: d60262d0                 ld      [%o1+%lo(stru_F01422CC.super_class)], %o3
F00DC6BC: 9410001a                 mov     %i2, %o2
F00DC6C0: 133c0505                 sethi   %hi(paFreeregion), %o1
F00DC6C4: d202606c                 ld      [%o1+%lo(paFreeregion)], %o1! SEL
F00DC6C8: 400054ad                 call    _objc_msgSendSuper
F00DC6CC: d627bff4                 st      %o3, [%fp+var_C]
F00DC6D0: 81c7e008                 ret
F00DC6D4: 91e80008                 restore %g0, %o0, %o0
