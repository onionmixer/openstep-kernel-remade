
int sub_401C310(undefined4 param_1,undefined4 param_2,sword *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined auStack_1a [4];
  undefined4 uStack_16;
  undefined auStack_12 [12];
  undefined2 uStack_6;
  
  iVar2 = _if_private(param_1);
  uVar1 = *(undefined4 *)(iVar2 + 10);
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,auStack_12,0xe);
  }
  else {
    if (*param_3 != 2) {
      _nb_free(param_2);
      return 0x2f;
    }
    uStack_16 = *(undefined4 *)(param_3 + 2);
    iVar2 = _if_private(param_1,param_2,&uStack_16,auStack_12,auStack_1a);
    uVar3 = _if_private(param_1,*(undefined4 *)(iVar2 + 6));
    iVar2 = _arpresolve(param_1,uVar3);
    if (iVar2 == 0) {
      return 0;
    }
    uStack_6 = 0x800;
  }
  _nb_grow_top(param_2,0xe);
  _nb_write(param_2,0xc,2,&uStack_6);
  iVar2 = _if_output(uVar1,param_2,auStack_12);
  if (iVar2 == 0) {
    iVar4 = _if_opackets(param_1);
    _if_opackets_set(param_1,iVar4 + 1);
  }
  else {
    iVar4 = _if_oerrors(param_1);
    _if_oerrors_set(param_1,iVar4 + 1);
  }
  return iVar2;
}
