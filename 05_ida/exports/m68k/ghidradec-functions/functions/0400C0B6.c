
void _rwuio(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined uVar5;
  int iVar4;
  int iVar6;
  int iStack_c;
  
  if (((**(uint **)(dword_40B57D4 + 0x24) < *(uint *)((int)_active_u + 0x152)) &&
      (iVar1 = *(int *)(*(int *)((int)_active_u + 0x146) + **(uint **)(dword_40B57D4 + 0x24) * 4),
      iVar1 != 0)) && (iVar1 != -0x10000)) {
    if (param_2 == 0) {
      uVar2 = *(uint *)(iVar1 + 8) & 1;
    }
    else {
      uVar2 = *(uint *)(iVar1 + 8) & 2;
    }
    if (uVar2 != 0) {
      *(undefined4 *)((int)param_1 + 0x12) = 0;
      param_1[3] = 0;
      iVar6 = *param_1;
      iStack_c = 0;
      if (0 < param_1[1]) {
        do {
          if ((*(int *)(iVar6 + 4) < 0) ||
             (iVar4 = *(int *)((int)param_1 + 0x12) + *(int *)(iVar6 + 4),
             *(int *)((int)param_1 + 0x12) = iVar4, iVar4 < 0)) {
            *(undefined *)(dword_40B57D4 + 100) = 0x16;
            return;
          }
          iVar6 = iVar6 + 8;
          iStack_c = iStack_c + 1;
        } while (iStack_c < param_1[1]);
      }
      iVar6 = *(int *)((int)param_1 + 0x12);
      while( true ) {
        iVar4 = *(int *)((int)param_1 + 0x12);
        param_1[2] = *(int *)(iVar1 + 0x1a);
        iVar3 = _setjmp(dword_40B57D4 + 0x28);
        if (iVar3 == 0) {
          uVar5 = (*(code *)**(undefined4 **)(iVar1 + 0x12))(iVar1,param_2,param_1);
          *(undefined *)(dword_40B57D4 + 100) = uVar5;
        }
        else if (*(int *)((int)param_1 + 0x12) == iVar6) {
          if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
            *(undefined *)(dword_40B57D4 + 100) = 4;
          }
          else {
            *(undefined *)(dword_40B57D4 + 0x65) = 2;
          }
        }
        *(int *)(dword_40B57D4 + 0x5c) = iVar6 - *(int *)((int)param_1 + 0x12);
        *(int *)(iVar1 + 0x1a) = (iVar4 - *(int *)((int)param_1 + 0x12)) + *(int *)(iVar1 + 0x1a);
        if (*(char *)(dword_40B57D4 + 100) == '\0') break;
        iVar4 = _fspause(*(uint *)(iVar1 + 8) & 0x1000);
        if (iVar4 == 0) {
          return;
        }
      }
      return;
    }
  }
  *(undefined *)(dword_40B57D4 + 100) = 9;
  return;
}
