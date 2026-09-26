F00C9790: 9de3bf78                 save    %sp, -0x88, %sp
F00C9794: d006210c                 ld      [%i0+0x10C], %o0
F00C9798: 80a22000                 cmp     %o0, 0
F00C979C: 02800009                 be      locret_F00C97C0
F00C97A0: 90102018                 mov     0x18, %o0
F00C97A4: d027bfdc                 st      %o0, [%fp+var_24]
F00C97A8: d206210c                 ld      [%i0+0x10C], %o1
F00C97AC: 9007bfd8                 add     %fp, var_28, %o0
F00C97B0: 94102000                 mov     0, %o2
F00C97B4: d227bfe4                 st      %o1, [%fp+var_1C]
F00C97B8: 7ffe71a9                 call    _msg_receive
F00C97BC: 92102000                 mov     0, %o1
F00C97C0: 81c7e008                 ret
F00C97C4: 81e80000                 restore
