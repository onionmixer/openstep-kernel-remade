0406D152: 4e56ffa4                 link    a6,#-$5C
0406D156: 2f0a                     move.l  a2,-(sp)
0406D158: 2f02                     move.l  d2,-(sp)
0406D15A: 242e0008                 move.l  arg_0(a6),d2
0406D15E: 4878005a                 pea     ($5A).w
0406D162: 45eeffa6                 lea     var_5A(a6),a2
0406D166: 2f0a                     move.l  a2,-(sp)
0406D168: 61ff00025ca8             bsr.l   _bzero
0406D16E: 1d7c0013ffb0             move.b  #$13,var_50(a6)
0406D174: 422effb1                 clr.b   var_4F(a6)
0406D178: 1039040b14a9             move.b  (byte_40B14A9).l,d0
0406D17E: 00000050                 ori.b   #$50,d0 ; 'P'
0406D182: 8039040b14ad             or.b    (byte_40B14AD).l,d0
0406D188: 1d40ffb2                 move.b  d0,var_4E(a6)
0406D18C: 422effb3                 clr.b   var_4D(a6)
0406D190: 2d7c00002710ffa8         move.l  #$2710,var_58(a6)
0406D198: 7201                     moveq   #1,d1
0406D19A: 2d41ffac                 move.l  d1,var_54(a6)
0406D19E: 7204                     moveq   #4,d1
0406D1A0: 2d41ffc0                 move.l  d1,var_40(a6)
0406D1A4: 2f0a                     move.l  a2,-(sp)
0406D1A6: 2f02                     move.l  d2,-(sp)
0406D1A8: 61ffffffdc12             bsr.l   _fc_send_cmd
0406D1AE: 242eff9c                 move.l  var_64(a6),d2
0406D1B2: 246effa0                 movea.l var_60(a6),a2
0406D1B6: 4e5e                     unlk    a6
0406D1B8: 4e75                     rts
