040967AA: 206f0004                 movea.l arg_0(sp),a0
040967AE: 20af0008                 move.l  arg_4(sp),(a0)
040967B2: 216800400020             move.l  $40(a0),$20(a0)
040967B8: 4cd0ffff                 movem.l (a0),d0-d7/a0-a7
040967BC: 4ed0                     jmp     (a0)
