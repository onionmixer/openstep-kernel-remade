
void _v2d_map(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined7 *puVar8;
  undefined4 auStack_c [2];
  
  iVar5 = 0;
  puVar7 = unk_40C39C6;
  piVar4 = &unk_40C39C2;
  do {
    for (piVar1 = (int *)*piVar4; piVar1 != piVar4; piVar1 = *(int **)((int)piVar1 + 0x12a)) {
      if (piVar1[4] == *(int *)(param_1 + 0x10)) {
        piVar1 = *(int **)puVar7;
        if (piVar1 == piVar4) {
          *piVar4 = param_1;
        }
        else {
          *(int *)((int)piVar1 + 0x12a) = param_1;
        }
        *(int **)(param_1 + 0x12e) = piVar1;
        *(int **)(param_1 + 0x12a) = piVar4;
        *(int *)puVar7 = param_1;
        return;
      }
    }
    puVar7 = (undefined *)((int)puVar7 + 0x262);
    piVar4 = (int *)((int)piVar4 + 0x262);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 1);
  puVar8 = &_fd_drive;
  iVar5 = 0;
  do {
    if ((*(byte *)((int)puVar8 + 0x23) & 1) == 0) break;
    if ((*(int *)((int)puVar8 + 0xc) == 0) && (*(int *)(puVar8 + 2) == 0)) goto loc_406E49E;
    iVar5 = iVar5 + 1;
    puVar8 = puVar8 + 5;
  } while (iVar5 < 1);
  auStack_c[0] = unk_40C3714._0_4_;
  auStack_c[1] = unk_40C3714._4_4_;
  iVar5 = 0;
  puVar8 = &_fd_drive;
  iVar6 = 0;
  do {
    if ((*(byte *)((int)puVar8 + 0x23) & 1) == 0) break;
    iVar2 = _ts_greater(auStack_c,puVar8 + 3);
    if (iVar2 != 0) {
      auStack_c[0] = *(undefined4 *)(puVar8 + 3);
      auStack_c[1] = *(undefined4 *)((int)puVar8 + 0x1c);
      iVar5 = iVar6;
    }
    iVar6 = iVar6 + 1;
    puVar8 = puVar8 + 5;
  } while (iVar6 < 1);
  puVar8 = &_fd_drive + iVar5 * 5;
loc_406E49E:
  puVar3 = (undefined4 *)_kalloc(0x10);
  puVar3[2] = *(undefined4 *)((int)puVar8 + 0xc);
  puVar3[3] = param_1;
  *dword_40C3764 = puVar3;
  puVar3[1] = dword_40C3764;
  *puVar3 = &_disk_eject_q;
  piVar4 = *(int **)(*(int *)(puVar8 + 1) + 0x25a);
  dword_40C3764 = puVar3;
  if (piVar4 == (int *)(*(int *)(puVar8 + 1) + 0x256)) {
    *piVar4 = param_1;
  }
  else {
    *(int *)((int)piVar4 + 0x12a) = param_1;
  }
  *(int **)(param_1 + 0x12e) = piVar4;
  *(int *)(param_1 + 0x12a) = *(int *)(puVar8 + 1) + 0x256;
  *(int *)(*(int *)(puVar8 + 1) + 0x25a) = param_1;
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | 8;
  *(int *)(param_1 + 8) = ((int)puVar8 + -0x40c36fc) * -0x33333333 >> 3;
  return;
}
