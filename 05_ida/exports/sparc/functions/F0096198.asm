F0096198: 8e100011                 mov     %l1, %g7
F009619C: 8c0d200f                 and     %l4, 0xF, %g6
F00961A0: 80a1a001                 cmp     %g6, 1
F00961A4: 02800004                 be      loc_F00961B4
F00961A8: 01000000                 nop
F00961AC: 8e102400                 mov     0x400, %g7
F00961B0: ce81c080                 lda     [%g7]#ASI_NUCLEUS, %g7
F00961B4: 8c102300                 mov     0x300, %g6
F00961B8: 81c3e008                 retl
F00961BC: cc818080                 lda     [%g6]#ASI_NUCLEUS, %g6
