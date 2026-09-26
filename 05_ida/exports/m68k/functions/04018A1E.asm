04018A1E: 4856                     pea     (a6)
04018A20: 2c4f                     movea.l sp,a6
04018A22: 2f0a                     move.l  a2,-(sp)
04018A24: 52b9040b6d90             addq.l  #1,(dword_40B6D90).l
04018A2A: 41f9040b6b60             lea     (_nc_hash).l,a0
04018A30: b1fc040b6d60             cmpa.l  #$40B6D60,a0
04018A36: 6436                     bcc.s   loc_4018A6E
04018A38: 2450                     movea.l (a0),a2
04018A3A: b1ca                     cmpa.l  a2,a0
04018A3C: 6726                     beq.s   loc_4018A64
04018A3E: 4aaa0014                 tst.l   $14(a2)
04018A42: 6706                     beq.s   loc_4018A4A
04018A44: 4aaa0010                 tst.l   $10(a2)
04018A48: 660e                     bne.s   loc_4018A58
04018A4A: 4879040a66ba             pea     (aDnlcPurgeZeroV).l; "dnlc_purge: zero vp"
04018A50: 61ffffff3214             bsr.l   _panic
04018A56: 584f                     addq.w  #4,sp
04018A58: 2f0a                     move.l  a2,-(sp)
04018A5A: 61ff000000a2             bsr.l   sub_4018AFE
04018A60: 584f                     addq.w  #4,sp
04018A62: 60c6                     bra.s   loc_4018A2A
04018A64: 5048                     addq.w  #8,a0
04018A66: b1fc040b6d60             cmpa.l  #$40B6D60,a0
04018A6C: 65ca                     bcs.s   loc_4018A38
04018A6E: 246efffc                 movea.l -4(a6),a2
04018A72: 4e5e                     unlk    a6
04018A74: 4e75                     rts
