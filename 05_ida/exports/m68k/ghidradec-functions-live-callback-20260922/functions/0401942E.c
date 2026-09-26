
int _lookuppn(int param_1,int param_2,int *param_3,int *param_4)

{
  sword *psVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined auStack_114 [8];
  int iStack_10c;
  int iStack_108;
  char acStack_104 [256];
  
  iVar5 = 0;
  iVar4 = *(int *)((int)_active_u + 0x156);
  psVar1 = (sword *)(iVar4 + 6);
  *psVar1 = *psVar1 + 1;
loc_401945A:
  acStack_104[0] = '\0';
  if (*(int *)(param_1 + 8) != 0) {
    if (**(char **)(param_1 + 4) == '/') {
      _vn_rele(iVar4);
      _pn_skipslash(param_1);
      iVar4 = _rootdir;
      if (*(int *)((int)_active_u + 0x15a) != 0) {
        iVar4 = *(int *)((int)_active_u + 0x15a);
      }
      *(sword *)(iVar4 + 6) = *(sword *)(iVar4 + 6) + 1;
      goto loc_40194BA;
    }
    if (**(char **)(param_1 + 4) != '\0') goto loc_40194BA;
  }
  if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
    return 2;
  }
loc_40194BA:
  iVar3 = 0;
  iVar8 = iVar4;
  if (*(int *)(iVar4 + 0x28) != 2) {
    iVar7 = 0x14;
    goto loc_401989A;
  }
  iVar7 = _pn_getcomponent(param_1,acStack_104,0);
  if (iVar7 != 0) goto loc_401989A;
  if (acStack_104[0] != '\0') {
    iVar3 = _strcmp(acStack_104,&asc_40A6712);
    if (iVar3 != 0) {
loc_40195CE:
      do {
        iVar3 = 0;
        if (*(int *)(iVar8 + 0x10) == 0) goto loc_401966A;
        iVar7 = (**(code **)(*(int *)(iVar8 + 0x1c) + 0x1c))
                          (iVar8,0x40,*(undefined4 *)((int)_active_u + 0x1a));
        if (iVar7 != 0) goto loc_401989A;
        iVar4 = *(int *)(iVar8 + 0x10);
        while( true ) {
          if (iVar4 == 0) goto loc_401966A;
          iVar7 = _strncmp(iVar4 + 0x20,acStack_104,0xff);
          if (iVar7 == 0) break;
          iVar4 = *(int *)(iVar4 + 0x120);
        }
        if ((*(uint *)(iVar4 + 0xc) & 2) == 0) {
          iVar7 = (**(code **)(*(int *)(iVar4 + 4) + 8))(iVar4,&iStack_108);
          iVar4 = iStack_108;
          if (iVar7 == 0) goto loc_40197C6;
          goto loc_401989A;
        }
        *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 4;
        _sleep(iVar4,0x1b);
      } while( true );
    }
    do {
      iVar3 = *(int *)((int)_active_u + 0x15a);
      iVar8 = iVar4;
      if (((iVar3 == iVar4) ||
          (((((iVar4 != 0 && (iVar3 != 0)) && (*(int *)(iVar4 + 0x1c) == *(int *)(iVar3 + 0x1c))) &&
            (iVar3 = (**(code **)(*(int *)(iVar4 + 0x1c) + 0x6c))(iVar4,iVar3), iVar3 != 0)) ||
           (_rootdir == iVar4)))) ||
         (((iVar4 != 0 && (_rootdir != 0)) &&
          ((*(int *)(iVar4 + 0x1c) == *(int *)(_rootdir + 0x1c) &&
           (iVar3 = (**(code **)(*(int *)(iVar4 + 0x1c) + 0x6c))(iVar4,_rootdir), iVar3 != 0))))))
      break;
      if ((*(byte *)(iVar4 + 5) & 1) == 0) goto loc_40195CE;
      iVar8 = *(int *)(*(int *)(iVar4 + 0x24) + 8);
      *(sword *)(iVar8 + 6) = *(sword *)(iVar8 + 6) + 1;
      _vn_rele(iVar4);
      iVar4 = iVar8;
    } while (*(int *)(iVar8 + 0xc) != 0);
    *(sword *)(iVar8 + 6) = *(sword *)(iVar8 + 6) + 1;
    iVar4 = iVar8;
    goto loc_40197C6;
  }
  if (param_3 != (int *)0x0) {
    _vn_rele(iVar4);
    return 0x11;
  }
  _pn_set(param_1,&asc_40A6047);
  if (param_4 != (int *)0x0) {
    *param_4 = iVar4;
    return 0;
  }
  goto loc_4019876;
loc_401966A:
  iVar7 = (**(code **)(*(int *)(iVar8 + 0x1c) + 0x20))
                    (iVar8,acStack_104,&iStack_108,*(undefined4 *)((int)_active_u + 0x1a),param_1,0)
  ;
  iVar3 = iStack_108;
  if (iVar7 != 0) {
    iVar3 = 0;
    if (((*(int *)(param_1 + 8) == 0) && (param_3 != (int *)0x0)) && (iVar7 != 0xd)) {
      _pn_set(param_1,acStack_104);
      *param_3 = iVar8;
      if (param_4 == (int *)0x0) {
        return 0;
      }
      *param_4 = 0;
      return 0;
    }
    goto loc_401989A;
  }
  while (iVar4 = *(int *)(iVar3 + 0xc), iVar4 != 0) {
    if ((*(uint *)(iVar4 + 0xc) & 2) == 0) {
      iVar7 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xc) + 4) + 8))
                        (*(int *)(iVar3 + 0xc),&iStack_108);
      if (iVar7 != 0) goto loc_401989A;
      _vn_rele(iVar3);
      iVar3 = iStack_108;
    }
    else {
      *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 4;
      _sleep(iVar4,0x1b);
    }
  }
  iVar4 = iVar3;
  if (*(int *)(iVar3 + 0x28) == 5) goto loc_401973a;
loc_40197C6:
  iVar3 = iVar4;
  if (*(int *)(param_1 + 8) == 0) goto loc_4019810;
  if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
    pcVar6 = *(char **)(param_1 + 4);
    cVar2 = *pcVar6;
    while (cVar2 == '/') {
      pcVar6 = pcVar6 + 1;
      cVar2 = *pcVar6;
    }
    if ((*pcVar6 == '\0') && (*(int *)(iVar4 + 0x28) == 2)) {
      **(undefined **)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
    }
  }
  if (*(int *)(param_1 + 8) == 0) goto loc_4019810;
  _pn_skipslash(param_1);
  _vn_rele(iVar8);
  goto loc_40194BA;
loc_401973a:
  if ((param_2 != 1) && (*(int *)(param_1 + 8) == 0)) {
loc_4019810:
    _pn_set(param_1,acStack_104);
    if (param_3 == (int *)0x0) {
      _vn_rele(iVar8);
    }
    else {
      if ((iVar3 == iVar8) ||
         ((((iVar8 != 0 && (iVar3 != 0)) && (*(int *)(iVar8 + 0x1c) == *(int *)(iVar3 + 0x1c))) &&
          (iVar4 = (**(code **)(*(int *)(iVar8 + 0x1c) + 0x6c))(iVar8,iVar3), iVar4 != 0)))) {
        _vn_rele(iVar8);
        _vn_rele(iVar3);
        return 0x11;
      }
      *param_3 = iVar8;
    }
    iVar4 = iVar3;
    if (param_4 == (int *)0x0) {
loc_4019876:
      _vn_rele(iVar4);
    }
    else {
      *param_4 = iVar3;
    }
    return 0;
  }
  iVar5 = iVar5 + 1;
  if (0x14 < iVar5) {
    iVar7 = 0x3e;
loc_401989A:
    if (iVar3 != 0) {
      _vn_rele(iVar3);
    }
    _vn_rele(iVar8);
    return iVar7;
  }
  iVar7 = sub_40198BC(iVar3,acStack_104,iVar8,auStack_114);
  if (iVar7 != 0) goto loc_401989A;
  if (iStack_10c == 0) {
    _pn_set(auStack_114,&asc_40A6047);
  }
  iVar7 = _pn_combine(param_1,auStack_114);
  _pn_free(auStack_114);
  if (iVar7 != 0) goto loc_401989A;
  _vn_rele(iVar3);
  iVar4 = iVar8;
  goto loc_401945A;
}

