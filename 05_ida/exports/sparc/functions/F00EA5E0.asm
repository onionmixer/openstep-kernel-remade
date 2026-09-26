F00EA5E0: 9de3bf90                 save    %sp, -0x70, %sp
F00EA5E4: 133c0504                 sethi   %hi(paFreekeysValues), %o1
F00EA5E8: 90100018                 mov     %i0, %o0! id
F00EA5EC: d20260f8                 ld      [%o1+%lo(paFreekeysValues)], %o1! SEL
F00EA5F0: 153c03a89412a3c8         set     nullsub_1, %o2
F00EA5F8: 40001c9e                 call    _objc_msgSend
F00EA5FC: 9610000a                 mov     %o2, %o3
F00EA600: 7ffdf740                 call    _free
F00EA604: d0062014                 ld      [%i0+0x14], %o0
F00EA608: f027bff0                 st      %i0, [%fp+var_10]
F00EA60C: 113c0508                 sethi   %hi(stru_F014236C.ext), %o0
F00EA610: d0022398                 ld      [%o0+%lo(stru_F014236C.ext)], %o0
F00EA614: d027bff4                 st      %o0, [%fp+var_C]
F00EA618: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00EA61C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00EA620: 40001cd7                 call    _objc_msgSendSuper
F00EA624: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00EA628: 81c7e008                 ret
F00EA62C: 91e80008                 restore %g0, %o0, %o0
