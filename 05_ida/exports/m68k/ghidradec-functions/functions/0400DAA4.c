
undefined4 _ttyopen(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  sword sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = _ttynty(param_2);
  iVar1 = *_active_u;
  iVar7 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  if ((*(byte *)(iVar1 + 0x16) & 0x40) == 0) {
    if ((*(byte *)(iVar1 + 0x28) & 0x40) != 0) goto loc_400DBBE;
    *(int *)((int)_active_u + 0x15e) = param_2;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(*(int *)(iVar7 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar7 + 0xe) + 8) + 8) = param_2;
    sVar4 = *(sword *)(param_2 + 0x42);
    if (sVar4 == 0) {
      _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),1);
      *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar7 + 0xe);
      *(undefined2 *)(param_2 + 0x42) = *(undefined2 *)(*(int *)(iVar7 + 0xe) + 0xe);
    }
    else if (sVar4 != *(sword *)(iVar1 + 0x2e)) {
      _enterpgrp(iVar1,(int)sVar4,0);
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar7 + 0xe) + 8);
    if ((((iVar1 != *(int *)(iVar2 + 4)) || (*(int *)(iVar2 + 8) != 0)) ||
        (*(int *)(iVar6 + 8) != 0)) || ((*(byte *)(iVar7 + 0x16) & 0x40) != 0)) goto loc_400DBBE;
    *(int *)((int)_active_u + 0x15e) = param_2;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(*(int *)(iVar7 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar7 + 0xe) + 8) + 8) = param_2;
    *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar7 + 0xe);
    *(undefined2 *)(param_2 + 0x42) = *(undefined2 *)(*(int *)(iVar7 + 0xe) + 0xe);
  }
  *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 0x40;
loc_400DBBE:
  *(undefined2 *)(param_2 + 0x38) = param_1;
  uVar3 = *(uint *)(param_2 + 0x3e);
  uVar5 = uVar3 & 0xfffffffd;
  *(uint *)(param_2 + 0x3e) = uVar5;
  if ((uVar3 & 4) == 0) {
    *(uint *)(param_2 + 0x3e) = uVar5 | 4;
    *(undefined4 *)(iVar6 + 0x10) = 0x1c251a1c;
    *(undefined *)(iVar6 + 0x14) = 0x5c;
    *(undefined *)(iVar6 + 0x15) = 1;
    *(undefined *)(iVar6 + 0x16) = 0;
    _bzero(param_2 + 0x5a,8);
    if (*(char *)(param_2 + 0x45) != '\x02') {
      _ttywflush(param_2);
    }
  }
  _ttysetspec(iVar6);
  return 0;
}
