040897AA: 4856                     pea     (a6)
040897AC: 2c4f                     movea.l sp,a6
040897AE: 2f39040b5184             move.l  (dword_40B5184).l,-(sp)
040897B4: 61fffffe0d6c             bsr.l   _ev_unregister_screen
040897BA: 42b9040b5184             clr.l   (dword_40B5184).l
040897C0: 4e5e                     unlk    a6
040897C2: 4e75                     rts
