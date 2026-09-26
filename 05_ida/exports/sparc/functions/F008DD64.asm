F008DD64: 9de3bf88                 save    %sp, -0x78, %sp
F008DD68: 9007bfe8                 add     %fp, var_18, %o0
F008DD6C: d023a040                 st      %o0, [%sp+0x78+var_38]
F008DD70: 113c0504                 sethi   %hi(paMappedrange_0), %o0
F008DD74: d2022090                 ld      [%o0+%lo(paMappedrange_0)], %o1! SEL
F008DD78: 90100018                 mov     %i0, %o0! id
F008DD7C: 40018ebd                 call    _objc_msgSend
F008DD80: 01000000                 nop
F008DD84: 00000008                 illtrap
F008DD88: d0062010                 ld      [%i0+0x10], %o0
F008DD8C: 80a22000                 cmp     %o0, 0
F008DD90: 22800007                 be,a    loc_F008DDAC
F008DD94: f027bff0                 st      %i0, [%fp+var_10]
F008DD98: d002200c                 ld      [%o0+0xC], %o0! target_task
F008DD9C: d2062014                 ld      [%i0+0x14], %o1! address
F008DDA0: 7ffff2c0                 call    _vm_deallocate
F008DDA4: d407bfec                 ld      [%fp+var_14], %o2
F008DDA8: f027bff0                 st      %i0, [%fp+var_10]
F008DDAC: 133c0507                 sethi   %hi(stru_F0141BEC.ext), %o1
F008DDB0: d4026018                 ld      [%o1+%lo(stru_F0141BEC.ext)], %o2
F008DDB4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008DDB8: 133c0503                 sethi   %hi(paFree), %o1
F008DDBC: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008DDC0: 40018eef                 call    _objc_msgSendSuper
F008DDC4: d427bff4                 st      %o2, [%fp+var_C]
F008DDC8: 81c7e008                 ret
F008DDCC: 91e80008                 restore %g0, %o0, %o0
