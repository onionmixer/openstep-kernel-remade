
void _vm_object_remove(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = &_vm_object_hashtable + (param_1 & 0x7f) * 2;
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return;
    }
    if (param_1 == *(uint *)(puVar2[2] + 0x24)) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  puVar3 = (undefined4 *)*puVar2;
  puVar4 = (undefined4 *)puVar2[1];
  if (puVar3 == puVar1) {
    (&dword_40C2DB0)[(param_1 & 0x7f) * 2] = puVar4;
  }
  else {
    puVar3[1] = puVar4;
  }
  if (puVar4 == puVar1) {
    *puVar1 = puVar3;
  }
  else {
    *puVar4 = puVar3;
  }
  _zfree(_object_hash_zone,puVar2);
  return;
}

