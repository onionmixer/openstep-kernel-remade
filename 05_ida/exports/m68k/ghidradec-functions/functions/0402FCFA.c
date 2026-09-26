
undefined4 _svckudp_dup(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  _dupchecks = _dupchecks + 1;
  uVar1 = *(uint *)(*(int *)(param_1[7] + 0x2e) + 4);
  puVar3 = *(uint **)(_drhashtbl + (uVar1 & 0x1f) * 4);
  while( true ) {
    if (puVar3 == (uint *)0x0) {
      return 0;
    }
    if ((((uVar1 == *puVar3) && (puVar3[7] == *param_1)) && (puVar3[6] == param_1[1])) &&
       ((puVar3[5] == param_1[2] && (iVar2 = _bcmp(puVar3 + 1,param_1[7] + 0xe,0x10), iVar2 == 0))))
    break;
    puVar3 = (uint *)puVar3[9];
  }
  _dupreqs = _dupreqs + 1;
  return 1;
}
