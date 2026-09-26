
int _breadDirect(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  undefined auStack_48 [3];
  byte bStack_45;
  sword sStack_2c;
  int iStack_20;
  undefined4 uStack_8;
  
  uStack_8 = 0;
  iVar1 = _incore(param_1,param_3);
  if (iVar1 == 0) {
    sub_40177C6(param_1,param_2,param_3,param_4,auStack_48);
    _vnReadAhead(param_1,param_6,param_7);
    _biowait(auStack_48);
    if ((bStack_45 & 4) == 0) {
      sub_401787A(auStack_48);
      *param_8 = 0;
      param_4 = param_4 - iStack_20;
    }
    else {
      *param_8 = (int)sStack_2c;
      param_4 = param_4 - iStack_20;
      sub_401787A(auStack_48);
    }
  }
  else {
    iVar1 = _breada(param_1,param_3,param_4,param_6,param_7);
    if ((*(byte *)(iVar1 + 3) & 4) == 0) {
      _copy_to_phys(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(param_2 + 0x22),param_5);
      *param_8 = 0;
      _brelse(iVar1);
      param_4 = param_4 - *(int *)(iVar1 + 0x28);
    }
    else {
      _brelse(iVar1);
      *param_8 = (int)*(sword *)(iVar1 + 0x1c);
      param_4 = 0;
    }
  }
  return param_4;
}

