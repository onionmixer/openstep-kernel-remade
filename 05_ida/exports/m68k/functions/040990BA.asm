040990BA: 4856                     pea     (a6)
040990BC: 2c4f                     movea.l sp,a6
040990BE: 42a7                     clr.l   -(sp)
040990C0: 61fffffcb6d0             bsr.l   _adb_watchdog
040990C6: 4e5e                     unlk    a6
040990C8: 4e75                     rts
