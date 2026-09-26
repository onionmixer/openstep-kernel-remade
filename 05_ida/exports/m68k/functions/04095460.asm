04095460: 4e56fffc                 link    a6,#-4
04095464: 61fffff6c118             bsr.l   _get_vbr
0409546A: 2d40fffc                 move.l  d0,var_4(a6)
0409546E: 206efffc                 movea.l var_4(a6),a0
04095472: 43e800bc                 lea     $BC(a0),a1
04095476: 23d1040b5620             move.l  (a1),(dword_40B5620).l
0409547C: 206efffc                 movea.l var_4(a6),a0
04095480: 43e800bc                 lea     $BC(a0),a1
04095484: 22bc04096736             move.l  #$4096736,(a1)
0409548A: 61ff00000026             bsr.l   _dbg_kresume
04095490: 42a7                     clr.l   -(sp)
04095492: 61fffffcf2fe             bsr.l   _adb_watchdog
04095498: 2f39040c977c             move.l  (_dbg_connect_pkt).l,-(sp)
0409549E: 61ff000005c6             bsr.l   _dbg_process
040954A4: 48780001                 pea     (1).w
040954A8: 61fffffcf2e8             bsr.l   _adb_watchdog
040954AE: 4e5e                     unlk    a6
040954B0: 4e75                     rts
