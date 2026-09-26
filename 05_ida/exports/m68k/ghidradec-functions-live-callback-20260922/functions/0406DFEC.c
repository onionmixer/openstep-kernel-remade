
int _fd_readid(int param_1,word param_2,undefined4 *param_3)

{
  int iVar1;
  undefined auStack_5e [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  word wStack_54;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  
  _bzero(auStack_5e,0x5a);
  wStack_54 = wStack_54 & 0x8afb | 0xa00 | (word)((*(uint *)(param_1 + 0x182) & 1) << 0xe) |
              (param_2 & 1) << 2;
  auStack_5e[0] = *(undefined *)(param_1 + 0x17d);
  uStack_5c = 10000;
  uStack_58 = 1;
  uStack_44 = 2;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_28 = 7;
  uStack_24 = 0;
  iVar1 = _fd_command(param_1,auStack_5e);
  *param_3 = uStack_38;
  param_3[1] = uStack_34;
  if ((iStack_20 == 0) && (iStack_20 = 4, iVar1 == 0)) {
    iStack_20 = 0;
  }
  return iStack_20;
}

