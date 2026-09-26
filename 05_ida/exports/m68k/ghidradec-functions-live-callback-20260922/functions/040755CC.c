
void _od_drive_start(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = _disksort_first(param_1);
  if (iVar2 != 0) {
    if ((*(word *)(param_1 + 0x36) & 0x2000) == 0) {
      *(word *)(param_1 + 0x36) = *(word *)(param_1 + 0x36) | 0x40;
    }
    if ((*(byte *)(param_1 + 3) & 0x60) == 0) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xbf | 0x20;
    }
    if ((*(byte *)(param_1 + 3) & 0x60) != 0x40) {
      iVar2 = *(int *)(&DAT_40c3e28 + (uint)*(word *)((int)param_1 + 0xd2) * 4);
      puVar1 = *(undefined4 **)(iVar2 + 0x1c);
      *puVar1 = param_1;
      param_1[1] = (int)puVar1;
      *param_1 = iVar2 + 0x18;
      *(int **)(iVar2 + 0x1c) = param_1;
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xdf | 0x40;
    }
  }
  return;
}

