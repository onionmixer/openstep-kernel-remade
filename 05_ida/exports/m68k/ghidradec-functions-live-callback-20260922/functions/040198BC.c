
int sub_40198BC(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  char cStack_12e;
  undefined auStack_12d [255];
  undefined4 auStack_2e [3];
  int aiStack_22 [2];
  int *piStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  iVar2 = 0;
  _pn_alloc(param_4);
  iVar1 = _dnlc_lookupSymLink(param_2,param_3);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 0x42) == '\0')) {
    aiStack_22[0] = *param_4;
    aiStack_22[1] = 0x400;
    piStack_1a = aiStack_22;
    uStack_16 = 1;
    uStack_12 = 0;
    uStack_e = 1;
    iStack_8 = 0x400;
    iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x44))
                      (param_1,&piStack_1a,*(undefined4 *)(_active_u + 0x1a));
    param_4[2] = 0x400 - iStack_8;
    if (iVar2 != 0) goto loc_4019A9E;
    _dnlc_enterSymLink(param_2,param_3,param_4);
  }
  else {
    _bcopy(*(undefined4 *)(iVar1 + 0x3e),*param_4,(int)*(sword *)(iVar1 + 0x44));
    param_4[2] = (int)*(sword *)(iVar1 + 0x44);
  }
  *(undefined *)(param_4[2] + *param_4) = 0;
  iVar1 = *param_4;
  while (iVar1 = _index(iVar1,0x24), iVar1 != 0) {
    if ((iVar1 == *param_4) || (*(char *)(iVar1 + -1) == '/')) {
      if (iVar1 != 0) {
        _pn_alloc(auStack_2e);
        if (param_4[2] == 0) goto loc_4019A7A;
        goto loc_40199D2;
      }
      break;
    }
    iVar1 = iVar1 + 1;
  }
  goto loc_4019A9A;
loc_40199D2:
  do {
    if (*(char *)param_4[1] == '/') {
      iVar2 = _pn_append(auStack_2e,&asc_40A6715);
      if (iVar2 != 0) goto loc_4019A8E;
      _pn_skipslash(param_4);
    }
    iVar2 = _pn_getcomponent(param_4,&cStack_12e);
    if (iVar2 != 0) goto loc_4019A8E;
    pcVar4 = &cStack_12e;
    if (cStack_12e == '$') {
      puVar3 = _metalinks;
      if (_metalinks._0_4_ != 0) {
        do {
          iVar1 = _strcmp(auStack_12d,*(int *)puVar3);
          if (iVar1 == 0) break;
          puVar3 = (undefined *)((int)puVar3 + 0xc);
        } while (*(int *)puVar3 != 0);
        if ((*(int *)puVar3 != 0) &&
           ((pcVar4 = *(char **)((int)puVar3 + 4), *pcVar4 != '\0' ||
            (pcVar4 = *(char **)((int)puVar3 + 8), pcVar4 != (char *)0x0)))) goto loc_4019A60;
      }
      iVar2 = 2;
      goto loc_4019A8E;
    }
loc_4019A60:
    iVar2 = _pn_append(auStack_2e,pcVar4);
    if (iVar2 != 0) goto loc_4019A8E;
  } while (param_4[2] != 0);
loc_4019A7A:
  if (iVar2 == 0) {
    iVar2 = _pn_set(param_4,auStack_2e[0]);
  }
loc_4019A8E:
  _pn_free(auStack_2e);
loc_4019A9A:
  if (iVar2 == 0) {
    return 0;
  }
loc_4019A9E:
  _pn_free(param_4);
  return iVar2;
}

