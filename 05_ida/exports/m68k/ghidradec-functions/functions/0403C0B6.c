
undefined4 _ipc_entry_get(int param_1,uint *param_2,int *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(iVar3 + 8);
  if (iVar4 == 0) {
    uVar5 = 3;
  }
  else {
    puVar1 = (uint *)(iVar3 + iVar4 * 0x10);
    *(uint *)(iVar3 + 8) = puVar1[2];
    uVar2 = *puVar1;
    *puVar1 = uVar2 + 0x1000000;
    puVar1[2] = 0;
    *param_2 = uVar2 + 0x1000000 >> 0x18 | iVar4 << 8;
    *param_3 = (int)puVar1;
    uVar5 = 0;
  }
  return uVar5;
}
