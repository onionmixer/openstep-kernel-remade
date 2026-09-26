
undefined4 _looutput(undefined4 param_1,undefined4 param_2,sword *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_3 == 2) {
    _inet_queue(param_1,param_2);
    iVar2 = _if_opackets(param_1);
    _if_opackets_set(param_1,iVar2 + 1);
    iVar2 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar2 + 1);
    uVar1 = 0;
  }
  else {
    _nb_free(param_2);
    uVar1 = 0x2f;
  }
  return uVar1;
}

