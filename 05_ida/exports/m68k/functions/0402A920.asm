0402A920: 4856                     pea     (a6)
0402A922: 2c4f                     movea.l sp,a6
0402A924: 4879040a707b             pea     (aNfsBadop).l; "nfs_badop"
0402A92A: 61fffffe133a             bsr.l   _panic
