/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179764 */

void _vm_object_remove(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar5 = param_1 & 0x7f;
  puVar1 = &_vm_object_hashtable + uVar5 * 2;
  puVar2 = (undefined4 *)(&_vm_object_hashtable)[uVar5 * 2];
  while( true ) {
    if (puVar1 == puVar2) {
      return;
    }
    if (*(uint *)(puVar2[2] + 0x28) == param_1) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  puVar3 = (undefined4 *)*puVar2;
  puVar4 = (undefined4 *)puVar2[1];
  if (puVar1 == puVar3) {
    (&DAT_001f6f54)[uVar5 * 2] = puVar4;
  }
  else {
    puVar3[1] = puVar4;
  }
  if (puVar1 == puVar4) {
    *puVar1 = puVar3;
  }
  else {
    *puVar4 = puVar3;
  }
  _zfree(_object_hash_zone,puVar2);
  return;
}

