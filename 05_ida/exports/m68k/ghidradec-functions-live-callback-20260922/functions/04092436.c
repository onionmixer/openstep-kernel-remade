
void _cnopen(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  word wVar3;
  sword sVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = _ttynty(_cons_tp);
  wVar3 = *(word *)(_cons_tp + 0x38);
  iVar1 = *_active_u;
  iVar6 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  if ((*(byte *)(iVar1 + 0x16) & 0x40) == 0) {
    if ((*(byte *)(iVar1 + 0x28) & 0x40) != 0) goto loc_409257E;
    *(int *)((int)_active_u + 0x15e) = _cons_tp;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar6 + 0xe) + 8) + 8) = _cons_tp;
    sVar4 = *(sword *)(_cons_tp + 0x42);
    if (sVar4 == 0) {
      _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),0);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0xe);
      *(undefined2 *)(_cons_tp + 0x42) = *(undefined2 *)(*(int *)(iVar6 + 0xe) + 0xe);
    }
    else if (sVar4 != *(sword *)(iVar1 + 0x2e)) {
      _enterpgrp(iVar1,(int)sVar4,0);
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar6 + 0xe) + 8);
    if ((((iVar1 != *(int *)(iVar2 + 4)) || (*(int *)(iVar2 + 8) != 0)) ||
        (*(int *)(iVar5 + 8) != 0)) || ((*(byte *)(iVar6 + 0x16) & 0x40) != 0)) goto loc_409257E;
    *(int *)((int)_active_u + 0x15e) = _cons_tp;
    *(undefined2 *)((int)_active_u + 0x162) = param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0xe) + 8);
    *(int *)(*(int *)(*(int *)(iVar6 + 0xe) + 8) + 8) = _cons_tp;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0xe);
    *(undefined2 *)(_cons_tp + 0x42) = *(undefined2 *)(*(int *)(iVar6 + 0xe) + 0xe);
  }
  *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 0x40;
loc_409257E:
  (**(code **)(_cdevsw + (uint)(wVar3 >> 8) * 0x2c))((int)(sword)wVar3,param_2);
  return;
}

