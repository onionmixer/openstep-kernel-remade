
uint _b_to_q(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar2 = _cfreelist;
  if ((int)param_2 < 1) {
    return 0;
  }
  puVar5 = (undefined4 *)param_3[2];
  uVar4 = param_2;
  if ((puVar5 == (undefined4 *)0x0) || (*param_3 < 0)) {
    if (_cfreelist == (undefined4 *)0x0) goto loc_401170E;
    puVar5 = _cfreelist + 1;
    _cfreelist = (undefined4 *)*_cfreelist;
    _cfreecount = _cfreecount + -0x34;
    _bzero(puVar5,8);
    *puVar2 = 0;
    puVar5 = puVar2 + 3;
    param_3[1] = (int)puVar5;
  }
  for (; puVar2 = _cfreelist, uVar4 != 0; uVar4 = uVar4 - uVar3) {
    if (((uint)puVar5 & 0x3f) == 0) {
      puVar5[-0x10] = _cfreelist;
      if (puVar2 == (undefined4 *)0x0) break;
      _cfreelist = (undefined4 *)*puVar2;
      _cfreecount = _cfreecount + -0x34;
      _bzero(puVar2 + 1,8);
      *puVar2 = 0;
      puVar5 = puVar2 + 3;
    }
    uVar1 = 0x40 - ((uint)puVar5 & 0x3f);
    uVar3 = uVar4;
    if (uVar1 <= uVar4) {
      uVar3 = uVar1;
    }
    _bcopy(param_1,puVar5,uVar3);
    param_1 = uVar3 + param_1;
    puVar5 = (undefined4 *)(uVar3 + (int)puVar5);
  }
loc_401170E:
  param_3[2] = (int)puVar5;
  *param_3 = (param_2 - uVar4) + *param_3;
  return uVar4;
}

