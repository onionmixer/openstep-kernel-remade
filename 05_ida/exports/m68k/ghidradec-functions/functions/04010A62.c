
undefined4 _ptcselect(byte param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = *(int **)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  puVar2 = *(uint **)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  if ((*(uint *)((int)piVar1 + 0x3e) & 0x10) == 0) {
    return 1;
  }
  if (param_2 == 1) {
    if ((((*(uint *)((int)piVar1 + 0x3e) & 4) != 0) && (piVar1[6] != 0)) &&
       ((*(uint *)((int)piVar1 + 0x3e) & 0x100) == 0)) {
      return 1;
    }
  }
  else {
    if (1 < param_2) {
      if (param_2 != 2) {
        return 0;
      }
      if ((*(uint *)((int)piVar1 + 0x3e) & 4) != 0) {
        if ((*puVar2 & 0x20) == 0) {
          if (piVar1[3] + *piVar1 < 0x3fe) {
            return 1;
          }
          if (piVar1[3] != 0) goto loc_4010B3A;
          uVar4 = *(uint *)((int)piVar1 + 0x3a) & 0x22;
        }
        else {
          uVar4 = piVar1[3];
        }
        if (uVar4 == 0) {
          return 1;
        }
      }
loc_4010B3A:
      iVar3 = _selthreadcache(puVar2 + 2);
      if (iVar3 == 0) {
        return 0;
      }
      uVar4 = 2;
      goto loc_4010B4A;
    }
    if (param_2 != 0) {
      return 0;
    }
  }
  if (((*(byte *)((int)piVar1 + 0x41) & 4) != 0) &&
     ((((*puVar2 & 8) != 0 && (*(char *)(puVar2 + 3) != '\0')) ||
      (((char)*puVar2 < '\0' && (*(char *)((int)puVar2 + 0xd) != '\0')))))) {
    return 1;
  }
  iVar3 = _selthreadcache(puVar2 + 1);
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = 1;
loc_4010B4A:
  *puVar2 = uVar4 | *puVar2;
  return 0;
}
