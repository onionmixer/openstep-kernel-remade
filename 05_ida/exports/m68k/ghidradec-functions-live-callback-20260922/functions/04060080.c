
void _vm_object_enter(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    param_2 = param_2 & 0x7f;
    puVar1 = &_vm_object_hashtable + param_2 * 2;
    puVar3 = (undefined4 *)_zalloc(_object_hash_zone);
    puVar3[2] = param_1;
    *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) | 0x10;
    puVar2 = (undefined4 *)(&dword_40C2DB0)[param_2 * 2];
    if (puVar2 == puVar1) {
      *puVar1 = puVar3;
    }
    else {
      *puVar2 = puVar3;
    }
    puVar3[1] = puVar2;
    *puVar3 = puVar1;
    (&dword_40C2DB0)[param_2 * 2] = puVar3;
  }
  return;
}

