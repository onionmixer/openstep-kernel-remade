
void _nattr_to_vattr(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined uVar3;
  
  iVar1 = *(int *)((int)param_1 + 0x2e);
  *param_3 = *param_2;
  *(undefined2 *)(param_3 + 1) = *(undefined2 *)((int)param_2 + 6);
  *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)((int)param_2 + 0xe);
  *(undefined2 *)(param_3 + 2) = *(undefined2 *)((int)param_2 + 0x12);
  uVar3 = _vfs_fixedmajor(param_1[9]);
  *(uint *)((int)param_3 + 10) =
       (uint)CONCAT11(uVar3,*(undefined *)(*(int *)(param_1[9] + 0x126) + 0x29));
  *(int *)((int)param_3 + 0xe) = param_2[10];
  *(undefined2 *)((int)param_3 + 0x12) = *(undefined2 *)((int)param_2 + 10);
  uVar2 = *(uint *)(*param_1 + 0x14);
  if (((uint)param_2[5] < uVar2) &&
     (((*(byte *)(*param_1 + 0x34) & 0x40) != 0 || ((*(byte *)(iVar1 + 0x5f) & 0x10) != 0)))) {
    param_3[5] = uVar2;
  }
  else {
    param_3[5] = param_2[5];
  }
  if ((*(uint *)(iVar1 + 0x90) < (uint)param_3[5]) || ((*(byte *)(iVar1 + 0x5f) & 0x10) == 0)) {
    *(int *)(iVar1 + 0x90) = param_3[5];
  }
  param_3[7] = param_2[0xb];
  param_3[8] = param_2[0xc];
  param_3[9] = param_2[0xd];
  param_3[10] = param_2[0xe];
  param_3[0xb] = param_2[0xf];
  param_3[0xc] = param_2[0x10];
  *(undefined2 *)(param_3 + 0xd) = *(undefined2 *)((int)param_2 + 0x1e);
  *(int *)((int)param_3 + 0x36) = param_2[8];
  if (*param_2 == 3) {
    param_3[6] = 0x800;
  }
  else if (*param_2 == 4) {
    param_3[6] = 0x2000;
  }
  else {
    param_3[6] = param_2[6];
  }
  if ((*param_2 == 4) && (param_2[7] == -1)) {
    *param_3 = 8;
    *(word *)(param_3 + 1) = *(word *)(param_3 + 1) & 0xfff | 0x1000;
    *(undefined2 *)(param_3 + 0xd) = 0;
    param_3[6] = param_2[6];
  }
  return;
}
