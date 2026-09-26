/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ffd8 */

undefined4 * FUN_0017ffd8(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)_kalloc(0x58);
  puVar4 = &DAT_001d1390;
  puVar5 = puVar1;
  for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar2 = _objc_msgSend(PTR_s_KernLock_001f9d84,PTR_s_alloc_001f9210,PTR_s_initWithLevel__001f9248,6
                       );
  uVar2 = _objc_msgSend(uVar2);
  puVar1[0xc] = uVar2;
  _ipc_object_reference(param_1);
  puVar1[0xb] = param_1;
  puVar1[0xf] = FUN_001802e8;
  puVar1[0x11] = puVar1;
  puVar1[0x14] = 0;
  puVar1[2] = 0xfffffffe;
  puVar1[3] = 0;
  puVar1[4] = 0;
  _ipc_object_reference(puVar1[0xb]);
  return puVar1;
}

