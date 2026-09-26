
void sub_4038728(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  if ((int)param_1[2] < 1) {
    puVar1 = (uint *)(_lf_svnode_hash + (*param_1 & 0x3f) * 4);
    uVar2 = *puVar1;
    while( true ) {
      if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aLfFreeSvnodeCa);
      }
      puVar3 = (uint *)*puVar1;
      if (param_1 == puVar3) break;
      puVar1 = puVar3 + 3;
      uVar2 = *puVar1;
    }
    _vn_rele(*puVar3);
    *puVar1 = puVar3[3];
    _kfree(puVar3,0x10);
  }
  return;
}
