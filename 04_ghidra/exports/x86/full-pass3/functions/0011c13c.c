/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011c13c */

int _lookuppn(int param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  int local_124;
  int local_11c;
  int local_118;
  undefined1 local_114 [8];
  int local_10c;
  int local_108;
  char local_104 [256];
  
  local_11c = 0;
  local_124 = _active_u[0x58];
  *(short *)(local_124 + 6) = *(short *)(local_124 + 6) + 1;
LAB_0011c171:
  local_104[0] = '\0';
  if (*(int *)(param_1 + 8) != 0) {
    if (**(char **)(param_1 + 4) == '/') {
      _vn_rele(local_124);
      _pn_skipslash(param_1);
      local_124 = _active_u[0x59];
      if (local_124 == 0) {
        local_124 = _rootdir;
      }
      *(short *)(local_124 + 6) = *(short *)(local_124 + 6) + 1;
      goto LAB_0011c1ec;
    }
    if (**(char **)(param_1 + 4) != '\0') goto LAB_0011c1ec;
  }
  if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
    return 2;
  }
LAB_0011c1ec:
  local_118 = 0;
  if (*(int *)(local_124 + 0x28) != 2) {
    iVar3 = 0x14;
    goto LAB_0011c714;
  }
  iVar3 = _pn_getcomponent(param_1,local_104,0);
  if (iVar3 != 0) goto LAB_0011c714;
  if (local_104[0] != '\0') {
    iVar3 = 3;
    bVar6 = true;
    pcVar4 = local_104;
    pcVar5 = &DAT_001db77f;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
LAB_0011c374:
      do {
        local_118 = 0;
        if (*(int *)(local_124 + 0x10) == 0) goto LAB_0011c41a;
        iVar3 = (**(code **)(*(int *)(local_124 + 0x1c) + 0x1c))(local_124,0x40,_active_u[7]);
        if (iVar3 != 0) goto LAB_0011c714;
        uVar2 = *(uint *)(local_124 + 0x10);
        while( true ) {
          if (uVar2 == 0) goto LAB_0011c41a;
          iVar3 = _strncmp((char *)(uVar2 + 0x20),local_104,0xff);
          if (iVar3 == 0) break;
          uVar2 = *(uint *)(uVar2 + 0x120);
        }
        if ((*(uint *)(uVar2 + 0xc) & 2) == 0) {
          iVar3 = (**(code **)(*(int *)(uVar2 + 4) + 8))(uVar2,&local_108);
          if (iVar3 != 0) goto LAB_0011c714;
          local_118 = local_108;
          goto LAB_0011c5d4;
        }
        *(uint *)(uVar2 + 0xc) = *(uint *)(uVar2 + 0xc) | 4;
        _sleep(uVar2);
      } while( true );
    }
    do {
      iVar3 = _active_u[0x59];
      if (((local_124 == iVar3) ||
          (((((local_124 != 0 && (iVar3 != 0)) &&
             (*(int *)(iVar3 + 0x1c) == *(int *)(local_124 + 0x1c))) &&
            (iVar3 = (**(code **)(*(int *)(local_124 + 0x1c) + 0x6c))(local_124,iVar3), iVar3 != 0))
           || (local_124 == _rootdir)))) ||
         (((local_124 != 0 && (_rootdir != 0)) &&
          ((*(int *)(_rootdir + 0x1c) == *(int *)(local_124 + 0x1c) &&
           (iVar3 = (**(code **)(*(int *)(local_124 + 0x1c) + 0x6c))(local_124,_rootdir), iVar3 != 0
           )))))) {
        local_118 = local_124;
        *(short *)(local_124 + 6) = *(short *)(local_124 + 6) + 1;
        goto LAB_0011c5d4;
      }
      if ((*(byte *)(local_124 + 4) & 1) == 0) goto LAB_0011c374;
      local_118 = *(int *)(*(int *)(local_124 + 0x24) + 8);
      *(short *)(local_118 + 6) = *(short *)(local_118 + 6) + 1;
      _vn_rele(local_124);
      local_124 = local_118;
    } while (*(int *)(local_118 + 0xc) != 0);
    *(short *)(local_118 + 6) = *(short *)(local_118 + 6) + 1;
    goto LAB_0011c5d4;
  }
  if (param_3 != (int *)0x0) {
    _vn_rele(local_124);
    return 0x11;
  }
  _pn_set(param_1,&DAT_001db77d);
  goto joined_r0x0011c6bf;
LAB_0011c41a:
  iVar3 = (**(code **)(*(int *)(local_124 + 0x1c) + 0x20))
                    (local_124,local_104,&local_108,_active_u[7],param_1,0);
  local_118 = local_108;
  if (iVar3 != 0) {
    local_118 = 0;
    if (((*(int *)(param_1 + 8) == 0) && (param_3 != (int *)0x0)) && (iVar3 != 0xd)) {
      _pn_set(param_1,local_104);
      *param_3 = local_124;
      if (param_4 == (int *)0x0) {
        return 0;
      }
      *param_4 = 0;
      return 0;
    }
    goto LAB_0011c714;
  }
  while (uVar2 = *(uint *)(local_118 + 0xc), uVar2 != 0) {
    if ((*(uint *)(uVar2 + 0xc) & 2) == 0) {
      iVar3 = (**(code **)(*(int *)(*(int *)(local_118 + 0xc) + 4) + 8))
                        (*(int *)(local_118 + 0xc),&local_108);
      if (iVar3 != 0) goto LAB_0011c714;
      _vn_rele(local_118);
      local_118 = local_108;
    }
    else {
      *(uint *)(uVar2 + 0xc) = *(uint *)(uVar2 + 0xc) | 4;
      _sleep(uVar2);
    }
  }
  if (*(int *)(local_118 + 0x28) == 5) goto code_r0x0011c520;
LAB_0011c5d4:
  if (*(int *)(param_1 + 8) == 0) goto LAB_0011c628;
  if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
    pcVar4 = *(char **)(param_1 + 4);
    cVar1 = *pcVar4;
    while (cVar1 == '/') {
      pcVar4 = pcVar4 + 1;
      cVar1 = *pcVar4;
    }
    if ((*pcVar4 == '\0') && (*(int *)(local_118 + 0x28) == 2)) {
      **(undefined1 **)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
    }
  }
  if (*(int *)(param_1 + 8) == 0) goto LAB_0011c628;
  _pn_skipslash(param_1);
  _vn_rele(local_124);
  local_124 = local_118;
  goto LAB_0011c1ec;
code_r0x0011c520:
  if ((param_2 != 1) && (*(int *)(param_1 + 8) == 0)) {
LAB_0011c628:
    _pn_set(param_1,local_104);
    if (param_3 == (int *)0x0) {
      _vn_rele(local_124);
      local_124 = local_118;
    }
    else {
      if ((local_124 == local_118) ||
         ((((local_124 != 0 && (local_118 != 0)) &&
           (*(int *)(local_118 + 0x1c) == *(int *)(local_124 + 0x1c))) &&
          (iVar3 = (**(code **)(*(int *)(local_124 + 0x1c) + 0x6c))(local_124,local_118), iVar3 != 0
          )))) {
        _vn_rele(local_124);
        _vn_rele(local_118);
        return 0x11;
      }
      *param_3 = local_124;
      local_124 = local_118;
    }
joined_r0x0011c6bf:
    if (param_4 == (int *)0x0) {
      _vn_rele(local_124);
    }
    else {
      *param_4 = local_124;
    }
    return 0;
  }
  local_11c = local_11c + 1;
  if (0x14 < local_11c) {
    iVar3 = 0x3e;
LAB_0011c714:
    if (local_118 != 0) {
      _vn_rele(local_118);
    }
    _vn_rele(local_124);
    return iVar3;
  }
  iVar3 = FUN_0011c760(local_118,local_104,local_124,local_114);
  if (iVar3 != 0) goto LAB_0011c714;
  if (local_10c == 0) {
    _pn_set(local_114,&DAT_001db782);
  }
  iVar3 = _pn_combine(param_1,local_114);
  _pn_free(local_114);
  if (iVar3 != 0) goto LAB_0011c714;
  _vn_rele(local_118);
  goto LAB_0011c171;
}

