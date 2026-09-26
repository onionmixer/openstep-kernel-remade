
undefined4 sub_401C67E(undefined4 param_1,int param_2,undefined4 param_3)

{
  sword sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  sword sStack_a;
  sword sStack_8;
  sword sStack_6;
  
  iVar2 = _if_private(param_1);
  if (param_2 != *(int *)(iVar2 + 10)) {
    return 0x2f;
  }
  _nb_read(param_3,0xc,2,&sStack_6);
  if ((word)(sStack_6 - 0x1000U) < 0x10) {
    sVar1 = sStack_6 << 9;
    if (sVar1 == 0) {
      return 0x2f;
    }
    uVar3 = _nb_size(param_3);
    if (uVar3 <= (int)sVar1 + 0x12U) {
      return 0x2f;
    }
    _nb_read(param_3,(int)sVar1 | 0xe,4,&sStack_a);
    sStack_6 = sStack_a;
    if ((sStack_a != 0x800) && (sStack_a != 0x806)) {
      return 0x2f;
    }
    uVar3 = _nb_size(param_3);
    if (uVar3 < (uint)(sVar1 + 0xe + (int)sStack_8)) {
      return 0x2f;
    }
    sub_401C58A(param_3,(int)sVar1,(int)(sword)(sStack_8 + -4));
  }
  if (sStack_6 == 0x800) {
    _nb_shrink_top(param_3,0xe);
    iVar2 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar2 + 1);
    _inet_queue(param_1,param_3);
  }
  else {
    if (sStack_6 != 0x806) {
      return 0x2f;
    }
    iVar2 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar2 + 1);
    uVar3 = _if_flags(param_1);
    if ((uVar3 & 0x4000) == 0) {
      _nb_shrink_top(param_3,0xe);
      iVar2 = _if_private(param_1,param_3);
      uVar4 = _if_private(param_1,*(undefined4 *)(iVar2 + 6));
      _arpinput(param_1,uVar4);
    }
    else {
      _nb_free(param_3);
    }
  }
  return 0;
}
