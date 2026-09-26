/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011325c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _b_to_q(void *param_1,uint param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  if ((int)param_2 < 1) {
    return 0;
  }
  uVar2 = _spltty();
  puVar1 = _cfreelist;
  puVar5 = (undefined4 *)param_3[2];
  uVar6 = param_2;
  if ((puVar5 == (undefined4 *)0x0) || (*param_3 < 0)) {
    if (_cfreelist == (undefined4 *)0x0) goto LAB_0011333b;
    __cfreecount = __cfreecount + -0x34;
    puVar5 = _cfreelist + 1;
    _cfreelist = (undefined4 *)*_cfreelist;
    _bzero(puVar5,8);
    *puVar1 = 0;
    puVar5 = puVar1 + 3;
    param_3[1] = (int)puVar5;
  }
  for (; puVar1 = _cfreelist, uVar6 != 0; uVar6 = uVar6 - uVar4) {
    if (((uint)puVar5 & 0x3f) == 0) {
      puVar5[-0x10] = _cfreelist;
      if (puVar1 == (undefined4 *)0x0) break;
      _cfreelist = (undefined4 *)*puVar1;
      __cfreecount = __cfreecount + -0x34;
      _bzero(puVar1 + 1,8);
      *puVar1 = 0;
      puVar5 = puVar1 + 3;
    }
    uVar3 = 0x40 - ((uint)puVar5 & 0x3f);
    uVar4 = uVar6;
    if (uVar3 <= uVar6) {
      uVar4 = uVar3;
    }
    _bcopy(param_1,puVar5,uVar4);
    param_1 = (void *)((int)param_1 + uVar4);
    puVar5 = (undefined4 *)((int)puVar5 + uVar4);
  }
LAB_0011333b:
  param_3[2] = (int)puVar5;
  *param_3 = *param_3 + (param_2 - uVar6);
  _splx(uVar2);
  return uVar6;
}

