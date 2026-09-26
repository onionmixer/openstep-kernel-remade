0408EC2E: 4856                     pea     (a6)
0408EC30: 2c4f                     movea.l sp,a6
0408EC32: 48e72030                 movem.l d2/a2-a3,-(sp)
0408EC36: 246e0008                 movea.l 8(a6),a2
0408EC3A: 266a01fe                 movea.l $1FE(a2),a3
0408EC3E: 2279040c32d4             movea.l (_slot_id).l,a1
0408EC44: 207c02000110             movea.l #$2000110,a0
0408EC4A: 20309800                 move.l  (a0,a1.l),d0
0408EC4E: 1013                     move.b  (a3),d0
0408EC50: 40c0                     move    sr,d0
0408EC52: 46fc2300                 move    #$2300,sr
0408EC56: 48c0                     ext.l   d0
0408EC58: 7440                     moveq   #$40,d2 ; '@'
0408EC5A: 85aa0202                 or.l    d2,$202(a2)
0408EC5E: 40c1                     move    sr,d1
0408EC60: 46c0                     move    d0,sr
0408EC62: 200a                     move.l  a2,d0
0408EC64: 0480040c8f34             subi.l  #$40C8F34,d0
0408EC6A: 4c3c0800bfce8063         muls.l  #$BFCE8063,d0
0408EC72: e480                     asr.l   #2,d0
0408EC74: 2f00                     move.l  d0,-(sp)
0408EC76: 48790408ed0a             pea     (_en_tx_dmaintr).l
0408EC7C: 48780001                 pea     (1).w
0408EC80: 61ff000051fe             bsr.l   _callout_dispatch
0408EC86: 4cee0c04fff4             movem.l -$C(a6),d2/a2-a3
0408EC8C: 4e5e                     unlk    a6
0408EC8E: 4e75                     rts
