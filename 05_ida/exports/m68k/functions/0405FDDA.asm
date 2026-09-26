0405FDDA: 4856                     pea     (a6)
0405FDDC: 2c4f                     movea.l sp,a6
0405FDDE: 61ff0000036c             bsr.l   _vm_object_cache_clear
0405FDE4: 4e5e                     unlk    a6
0405FDE6: 4e75                     rts
