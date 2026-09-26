040557D8: 4856                     pea     (a6)
040557DA: 2c4f                     movea.l sp,a6
040557DC: 2f0a                     move.l  a2,-(sp)
040557DE: 42b9040c2bc0             clr.l   (_first_zone).l
040557E4: 23fc040c2bc0040c2bc4     move.l  #$40C2BC0,(_last_zone).l
040557EE: 42b9040c2bc8             clr.l   (_num_zones).l
040557F4: 41f9040c2ba8             lea     (unk_40C2BA8).l,a0
040557FA: 20bc040c2bb0             move.l  #$40C2BB0,(a0)
04055800: 7201                     moveq   #1,d1
04055802: 23c1040c2bac             move.l  d1,(dword_40C2BAC).l
04055808: d0fcffec                 adda.w  #$FFEC,a0
0405580C: 23c8040c2bd0             move.l  a0,(_zone_free_space).l
04055812: 23c1040c2bf0             move.l  d1,(_zone_free_space_count).l
04055818: 42b9040c2bfc             clr.l   (_zone_zone).l
0405581E: 4879040a9102             pea     (aZones).l; "zones"
04055824: 42a7                     clr.l   -(sp)
04055826: 4878003a                 pea     ($3A).w
0405582A: 48781d00                 pea     ($1D00).w
0405582E: 4878003a                 pea     ($3A).w
04055832: 61fffffff7ae             bsr.l   _zinit
04055838: 23c0040c2bfc             move.l  d0,(_zone_zone).l
0405583E: 48780060                 pea     ($60).w
04055842: 48780010                 pea     ($10).w
04055846: 45f9040556d0             lea     (sub_40556D0).l,a2
0405584C: 4e92                     jsr     (a2)
0405584E: 48780300                 pea     ($300).w
04055852: 48780080                 pea     ($80).w
04055856: 4e92                     jsr     (a2)
04055858: defc0020                 adda.w  #$20,sp ; ' '
0405585C: 2eb9040b06d0             move.l  (_page_size).l,(sp)
04055862: 48780400                 pea     ($400).w
04055866: 4e92                     jsr     (a2)
04055868: 246efffc                 movea.l -4(a6),a2
0405586C: 4e5e                     unlk    a6
0405586E: 4e75                     rts
