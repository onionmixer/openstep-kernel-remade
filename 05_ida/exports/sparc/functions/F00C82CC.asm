F00C82CC: 9de3bf98                 save    %sp, -0x68, %sp
F00C82D0: 113c0506                 sethi   %hi(paNxspinlock), %o0
F00C82D4: d00222f0                 ld      [%o0+%lo(paNxspinlock)], %o0! id
F00C82D8: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00C82DC: 4000a565                 call    _objc_msgSend
F00C82E0: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00C82E4: 133c04cc                 sethi   %hi(dword_F01330B0), %o1
F00C82E8: d02260b0                 st      %o0, [%o1+%lo(dword_F01330B0)]
F00C82EC: 133c04cc901260a0         set     dword_F01330A0, %o0
F00C82F4: d0222004                 st      %o0, [%o0+4]
F00C82F8: d02260a0                 st      %o0, [%o1+%lo(dword_F01330A0)]
F00C82FC: 133c04cc901260a8         set     dword_F01330A8, %o0
F00C8304: d0222004                 st      %o0, [%o0+4]
F00C8308: d02260a8                 st      %o0, [%o1+%lo(dword_F01330A8)]
F00C830C: 113c0321901220b4         set     sub_F00C84B4, %o0
F00C8314: 4000076b                 call    _IOForkThread
F00C8318: 92102000                 mov     0, %o1
F00C831C: 81c7e008                 ret
F00C8320: 81e80000                 restore
