
void sub_408CBAC(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x164;
  pbVar1 = (byte *)(&DAT_40b52dc)[param_1 * 0x59];
  _delay(1);
  while( true ) {
    if ((*pbVar1 & 4) == 0) {
      return;
    }
    if (*(uint *)(DAT_40b5308 + iVar3 + 0xd8) <= *(uint *)(DAT_40b5308 + iVar3)) break;
    _delay(1);
    pbVar2 = *(byte **)(DAT_40b5308 + iVar3);
    *(byte **)(DAT_40b5308 + iVar3) = pbVar2 + 1;
    pbVar1[2] = DAT_40b5308[iVar3 + 0xf7] & *pbVar2;
    _delay(1);
    *(int *)(DAT_40b5408 + iVar3) = (_hz / _hz) * 3;
  }
  *(undefined4 *)(DAT_40b5408 + iVar3) = 0;
  _delay(1);
  *pbVar1 = 0x28;
  if (*(int *)(DAT_40b5408 + iVar3 + 4) != 0) {
    return;
  }
  *(int *)(DAT_40b5408 + iVar3 + 4) = (_hz / _hz) * 3;
  _callout_dispatch(0,sub_408CC8C,param_1);
  return;
}

