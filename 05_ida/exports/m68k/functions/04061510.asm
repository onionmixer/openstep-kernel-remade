04061510: 4856                     pea     (a6)
04061512: 2c4f                     movea.l sp,a6
04061514: 2f0a                     move.l  a2,-(sp)
04061516: 246e0008                 movea.l 8(a6),a2
0406151A: 2f0a                     move.l  a2,-(sp)
0406151C: 61fffffffcbc             bsr.l   _vm_page_remove
04061522: 584f                     addq.w  #4,sp
04061524: 082a0004001e             btst    #4,$1E(a2)
0406152A: 6608                     bne.s   loc_4061534
0406152C: 2f0a                     move.l  a2,-(sp)
0406152E: 61ff0000000c             bsr.l   _vm_page_addfree
04061534: 246efffc                 movea.l -4(a6),a2
04061538: 4e5e                     unlk    a6
0406153A: 4e75                     rts
