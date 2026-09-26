
void _ptrace(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar2 < 1) {
    *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x10;
    *(undefined4 *)(*_active_u + 0x7a) = *(undefined4 *)(*_active_u + 0x42);
    *(int *)(*(int *)(*_active_u + 0x42) + 0x7e) = *_active_u;
    return;
  }
  iVar5 = _pfind(piVar2[1]);
  if (iVar5 == 0) {
loc_400ADF2:
    *(undefined *)(dword_40B57D4 + 100) = 3;
    return;
  }
  iVar3 = *(int *)(iVar5 + 0x66);
  iVar1 = *piVar2;
  if (iVar1 == 10) {
    iVar1 = *_active_u;
    if (((*(sword *)(iVar1 + 0x2c) == 0) || (*(sword *)(iVar1 + 0x2c) == *(sword *)(iVar5 + 0x2c)))
       && (((*(uint *)(iVar5 + 0x28) & 0x10) == 0 && (*(int *)(iVar1 + 0x7e) == 0)))) {
      *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 0x10;
      *(int *)(iVar5 + 0x7a) = *_active_u;
      *(int *)(iVar1 + 0x7e) = iVar5;
      _psignal(iVar5,0x11);
      return;
    }
    goto loc_400ADF2;
  }
  if ((((*(int *)(iVar3 + 0x3c) == 0) || (*(char *)(iVar5 + 0x13) != '\x06')) ||
      (iVar4 = *(int *)(iVar5 + 0x7a), iVar4 != *_active_u)) ||
     ((*(byte *)(iVar5 + 0x2b) & 0x10) == 0)) goto loc_400ADF2;
  if (iVar1 == 8) {
    *(char *)(iVar5 + 0x17) = *(char *)(iVar5 + 0x17) + ' ';
  }
  else {
    if (iVar1 < 9) {
      if (iVar1 != 7) goto loc_400AF76;
    }
    else if (iVar1 != 9) {
      if (iVar1 == 0xb) {
        iVar1 = *(int *)(iVar4 + 0x7e);
        if (iVar1 == 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return;
        }
        *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xffffffef;
        *(undefined4 *)(iVar1 + 0x7a) = 0;
        *(undefined4 *)(iVar4 + 0x7e) = 0;
        goto loc_400AF46;
      }
      goto loc_400AF76;
    }
    iVar4 = *(int *)(iVar3 + 0x18);
    iVar1 = **(int **)(iVar4 + 0x80);
    if (piVar2[2] != 1) {
      *(uint *)(iVar1 + 0x40) = (int)(sword)((uint)piVar2[2] >> 0x10) | *(uint *)(iVar1 + 0x40);
      *(uint *)(iVar1 + 0x44) = (uint)*(word *)((int)piVar2 + 10) << 0x10 | *(uint *)(iVar1 + 0x44);
    }
    if (0x20 < (uint)piVar2[3]) {
loc_400AF76:
      *(undefined *)(dword_40B57D4 + 100) = 5;
      return;
    }
    if (0x1ef8 << 0x20 - *(char *)(iVar5 + 0x17) < 0) {
      *(undefined *)(*(int *)(iVar4 + 0x80) + 0x70) = 0;
    }
    *(undefined *)(iVar5 + 0x17) = *(undefined *)((int)piVar2 + 0xf);
    if (0x1ef8 << 0x20 - piVar2[3] < 0) {
      *(char *)(*(int *)(iVar4 + 0x80) + 0x70) = (char)piVar2[3];
    }
    if (*piVar2 == 9) {
      *(byte *)(iVar1 + 0x40) = *(byte *)(iVar1 + 0x40) | 0x80;
    }
  }
loc_400AF46:
  *(undefined *)(iVar5 + 0x13) = 3;
  if ((*(int *)(iVar5 + 0x6a) != 0) && (*(char *)(iVar5 + 0x17) != '\0')) {
    _clear_wait(*(int *)(iVar5 + 0x6a),2,1);
  }
  _task_resume(iVar3);
  return;
}

