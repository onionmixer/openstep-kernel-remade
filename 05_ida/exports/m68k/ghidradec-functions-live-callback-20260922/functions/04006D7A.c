
void _enterpgrp(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  puVar1 = (undefined4 *)_pgfind(param_2);
  iVar2 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_kalloc(0x14);
    if (param_3 == 0) {
      puVar1[2] = *(undefined4 *)(*(int *)(iVar2 + 0xe) + 8);
      *(int *)puVar1[2] = *(int *)puVar1[2] + 1;
    }
    else {
      puVar3 = (undefined4 *)_kalloc(0xe);
      puVar3[1] = param_1;
      *puVar3 = 1;
      puVar3[2] = 0;
      *(undefined2 *)(puVar3 + 3) = 0;
      *(byte *)(param_1 + 0x28) = *(byte *)(param_1 + 0x28) & 0xbf;
      puVar1[2] = puVar3;
    }
    puVar1[3] = param_2;
    *puVar1 = (&_pgrphash)[param_2 & 0x3f];
    (&_pgrphash)[param_2 & 0x3f] = puVar1;
    puVar1[4] = 0;
    puVar1[1] = 0;
  }
  else if (puVar1[3] == *(int *)(*(int *)(iVar2 + 0xe) + 0xc)) {
    return;
  }
  if ((*(byte *)(param_1 + 0x16) & 0x40) != 0) {
    _fixjobc(param_1,puVar1,1);
    _fixjobc(param_1,*(undefined4 *)(iVar2 + 0xe),0);
  }
  piVar5 = (int *)(*(int *)(iVar2 + 0xe) + 4);
  while( true ) {
    if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aEnterpgrpCanTF);
    }
    if (param_1 == *piVar5) break;
    iVar4 = _get_posix_proc((int)*(sword *)(*piVar5 + 0x30));
    piVar5 = (int *)(iVar4 + 10);
  }
  *piVar5 = *(int *)(iVar2 + 10);
  if (*(int *)(*(int *)(iVar2 + 0xe) + 4) == 0) {
    _pgdelete(*(int *)(iVar2 + 0xe));
  }
  *(undefined4 **)(iVar2 + 0xe) = puVar1;
  *(undefined4 *)(iVar2 + 10) = puVar1[1];
  puVar1[1] = param_1;
  *(undefined2 *)(param_1 + 0x2e) = *(undefined2 *)(*(int *)(iVar2 + 0xe) + 0xe);
  return;
}

