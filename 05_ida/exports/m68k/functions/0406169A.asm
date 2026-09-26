0406169A: 4856                     pea     (a6)
0406169C: 2c4f                     movea.l sp,a6
0406169E: 2f0a                     move.l  a2,-(sp)
040616A0: 246e0008                 movea.l 8(a6),a2
040616A4: 302a001c                 move.w  $1C(a2),d0
040616A8: 3200                     move.w  d0,d1
040616AA: 5341                     subq.w  #1,d1
040616AC: 3541001c                 move.w  d1,$1C(a2)
040616B0: 0c400001                 cmpi.w  #1,d0
040616B4: 662c                     bne.s   loc_40616E2
040616B6: 41f9040c2c14             lea     (dword_40C2C14).l,a0
040616BC: 2250                     movea.l (a0),a1
040616BE: 228a                     move.l  a2,(a1)
040616C0: 25490004                 move.l  a1,4(a2)
040616C4: 24bc040c2c10             move.l  #$40C2C10,(a2)
040616CA: 23ca040c2c14             move.l  a2,(dword_40C2C14).l
040616D0: 52b9040c2c08             addq.l  #1,(_vm_page_active_count).l
040616D6: 002a0040001e             ori.b   #$40,$1E(a2) ; '@'
040616DC: 53b9040c32c0             subq.l  #1,(_vm_page_wire_count).l
040616E2: 246efffc                 movea.l -4(a6),a2
040616E6: 4e5e                     unlk    a6
040616E8: 4e75                     rts
