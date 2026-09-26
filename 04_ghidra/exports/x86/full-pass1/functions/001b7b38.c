/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7b38 */

undefined4 FUN_001b7b38(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    if ((DAT_001e539c == '\0') || (DAT_001e53a0 == 0)) {
      cVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_isEISAPresent_001f9784);
      if (cVar1 == '\0') {
        iVar3 = _alloc_cnvmem(*(undefined4 *)(param_1 + 0x38),0x10000);
        *(int *)(param_1 + 0x4c) = iVar3;
        if (iVar3 == 0) {
          _IOLog("Audio: no memory for allocating buffers.\n");
          return 0;
        }
      }
      else {
        cVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_isEISAPresent_001f9784);
        if (cVar1 != '\0') {
          iVar3 = _alloc_cnvmem(*(undefined4 *)(param_1 + 0x38),_page_size);
          *(int *)(param_1 + 0x4c) = iVar3;
          if (iVar3 == 0) {
            _IOLog("Audio: no memory for allocating buffers.\n");
            return 0;
          }
        }
      }
      DAT_001e53a0 = *(int *)(param_1 + 0x4c);
      uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 4),
                            PTR_s_createDMABufferFor_length_read_n_001f9774,param_1 + 0x4c,
                            *(undefined4 *)(param_1 + 0x38),(int)*(char *)(param_1 + 0x20),1,0);
      *(undefined4 *)(param_1 + 0x48) = uVar2;
      _objc_msgSend(param_1,PTR_s_initializeFreeQueue_001f9770);
    }
    else {
      *(int *)(param_1 + 0x4c) = DAT_001e53a0;
      uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 4),
                            PTR_s_createDMABufferFor_length_read_n_001f9774,param_1 + 0x4c,
                            *(undefined4 *)(param_1 + 0x38),(int)*(char *)(param_1 + 0x20),1,0);
      *(undefined4 *)(param_1 + 0x48) = uVar2;
      _objc_msgSend(param_1,PTR_s_initializeFreeQueue_001f9770);
    }
  }
  return 1;
}

