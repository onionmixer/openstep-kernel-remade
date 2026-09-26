04095890: 4e56fffc                 link    a6,#-4
04095894: 2039040b5610             move.l  (dword_40B5610).l,d0
0409589A: 4a80                     tst.l   d0
0409589C: 6726                     beq.s   loc_40958C4
0409589E: 2d79040b5610fffc         move.l  (dword_40B5610).l,var_4(a6)
040958A6: 42b9040b5610             clr.l   (dword_40B5610).l
040958AC: 40c0                     move    sr,d0
040958AE: 46fc2700                 move    #$2700,sr
040958B2: 2f39040b5630             move.l  (dword_40B5630).l,-(sp)
040958B8: 2f2efffc                 move.l  var_4(a6),-(sp)
040958BC: 61ff00000eec             bsr.l   _dbg_longjmp
040958C2: 504f                     addq.w  #8,sp
040958C4: 4879040ac86b             pea     (aDebuggerScrewU).l; "debugger screw-up\n"
040958CA: 61fffffffc5e             bsr.l   _dbg_panic
