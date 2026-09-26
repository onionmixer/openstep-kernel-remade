
undefined4 _ipc_hash_local_lookup(int param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (param_2 >> 6) % *(uint *)(param_1 + 0x10);
  while( true ) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0xc + uVar3 * 0x10);
    if (iVar2 == 0) {
      return 0;
    }
    puVar1 = (undefined *)(*(int *)(param_1 + 0xc) + iVar2 * 0x10);
    if (param_2 == *(uint *)(puVar1 + 4)) break;
    uVar3 = uVar3 + 1;
    if (*(uint *)(param_1 + 0x10) == uVar3) {
      uVar3 = 0;
    }
  }
  *param_3 = CONCAT31((int3)iVar2,*puVar1);
  *param_4 = (int)puVar1;
  return 1;
}
