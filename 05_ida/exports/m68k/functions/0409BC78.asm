0409BC78: 082e0007ff34             btst    #7,-$CC(a6)
0409BC7E: 67ff00000012             beq.l   loc_409BC92
0409BC84: f23948000409b7c8         fmove.x (tbyte_409B7C8).l,fp0
0409BC8C: 60ff0000000c             bra.l   loc_409BC9A
0409BC92: f23948000409b7bc         fmove.x (tbyte_409B7BC).l,fp0
0409BC9A: f239d0400409b7a4         fmovem.x (tbyte_409B7A4).l,fp1
0409BCA2: 60ff000074aa             bra.l   sto_cos
