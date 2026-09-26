040817CA: 4856                     pea     (a6)
040817CC: 2c4f                     movea.l sp,a6
040817CE: 61ff0000000e             bsr.l   _dsp_dev_reset_chip
040817D4: 61fffffff8b6             bsr.l   _dsp_dev_reset
040817DA: 4e5e                     unlk    a6
040817DC: 4e75                     rts
