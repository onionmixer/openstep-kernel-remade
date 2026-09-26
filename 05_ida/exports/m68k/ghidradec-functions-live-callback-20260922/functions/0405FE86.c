
void _vm_object_copy(int *param_1,uint param_2,int param_3,int *param_4,uint *param_5,
                    undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    *param_4 = 0;
    *param_5 = 0;
  }
  else {
    if ((param_1[9] == 0) || ((*(byte *)((int)param_1 + 0x42) & 8) != 0)) {
      *(sword *)(param_1 + 5) = *(sword *)(param_1 + 5) + 1;
      piVar4 = (int *)*param_1;
      if (piVar4 != param_1) {
        do {
          if ((param_2 <= (uint)piVar4[6]) && ((uint)piVar4[6] < param_3 + param_2)) {
            *(byte *)((int)piVar4 + 0x21) = *(byte *)((int)piVar4 + 0x21) | 0x20;
          }
          piVar4 = (int *)piVar4[2];
        } while (piVar4 != param_1);
      }
      *param_4 = (int)param_1;
      *param_5 = param_2;
      *param_6 = 1;
      return;
    }
    _vm_object_collapse(param_1);
    iVar1 = param_1[6];
    if (((iVar1 == 0) || (*(sword *)(iVar1 + 0x16) != 0)) || (*(int *)(iVar1 + 0x24) != 0)) {
      iVar3 = _vm_object_allocate(param_1[4]);
      iVar1 = param_1[6];
      if (iVar1 != 0) {
        if ((param_1 != *(int **)(iVar1 + 0x1c)) || (*(int *)(iVar1 + 0x20) != 0)) {
                    /* WARNING: Subroutine does not return */
          _panic(aVmObjectCopyCo);
        }
        *(sword *)(param_1 + 5) = *(sword *)(param_1 + 5) + -1;
        *(int *)(iVar1 + 0x1c) = iVar3;
        *(sword *)(iVar3 + 0x14) = *(sword *)(iVar3 + 0x14) + 1;
      }
      uVar2 = *(uint *)(iVar3 + 0x10);
      *(int **)(iVar3 + 0x1c) = param_1;
      *(undefined4 *)(iVar3 + 0x20) = 0;
      *(sword *)(param_1 + 5) = *(sword *)(param_1 + 5) + 1;
      param_1[6] = iVar3;
      for (piVar4 = (int *)*param_1; piVar4 != param_1; piVar4 = (int *)piVar4[2]) {
        if ((uint)piVar4[6] < uVar2) {
          *(byte *)((int)piVar4 + 0x21) = *(byte *)((int)piVar4 + 0x21) | 0x20;
        }
      }
      *param_4 = iVar3;
    }
    else {
      *(sword *)(iVar1 + 0x14) = *(sword *)(iVar1 + 0x14) + 1;
      *param_4 = iVar1;
    }
    *param_5 = param_2;
  }
  *param_6 = 0;
  return;
}

