04001B16: 2e6f0004                 movea.l 4(sp),sp
04001B1A: 206f003c                 movea.l arg_38(sp),a0
04001B1E: 4e7b8800                 movec   a0,usp
04001B22: 4cd77fff                 movem.l (sp),d0-d7/a0-a6
04001B26: defc0040                 adda.w  #$40,sp ; '@'
04001B2A: 4e73                     rte
