
void sub_405577E(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = unk_40C2BD4;
  if ((*(int *)(param_1 + 0x10) == 0) && (iVar3 = 1, 1 < _zone_free_space_count)) {
    do {
      iVar1 = **(int **)puVar4;
      uVar2 = -iVar1 & iVar1 + *(int *)(param_1 + 0x18) + -1;
      if (uVar2 <= (uint)(*(int **)puVar4)[1]) {
        *(uint *)(param_1 + 0x18) = uVar2;
        *(int *)(param_1 + 0x32) = *(int *)puVar4;
        return;
      }
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < _zone_free_space_count);
  }
  return;
}
