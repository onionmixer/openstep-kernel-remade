/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c217c */

uint FUN_001c217c(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(param_1 + 0x24);
  if (puVar1[1] == 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s__delegate_001f9c08,PTR_s_resourcesForKey__001f9344,
                          "PCMCIA_TUPLE_LIST");
    iVar3 = _objc_msgSend(uVar2);
    if (iVar3 != 0) {
      uVar4 = _objc_msgSend(iVar3,PTR_s_count_001f92d8);
      *puVar1 = uVar4;
      uVar4 = _IOMalloc(uVar4 << 2);
      puVar1[1] = uVar4;
      uVar4 = 0;
      if (*puVar1 != 0) {
        do {
          uVar2 = _objc_msgSend(iVar3,PTR_s_objectAt__001f92e8,uVar4);
          uVar2 = _objc_msgSend(PTR_s_IOPCMCIATuple_001f9db0,PTR_s_alloc_001f9210,
                                PTR_s_initWithKernTuple__001f962c,uVar2);
          uVar2 = _objc_msgSend(uVar2);
          *(undefined4 *)(puVar1[1] + uVar4 * 4) = uVar2;
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar1);
      }
    }
  }
  return puVar1[1];
}

