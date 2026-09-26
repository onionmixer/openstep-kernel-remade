/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6c4c */

undefined4 FUN_001a6c4c(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 local_8 [4];
  
  uVar7 = 0;
  uVar2 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58);
  iVar3 = _IOMalloc(_page_size);
  bVar1 = false;
  iVar4 = _objc_msgSend(param_1,PTR_s_physicalBlockSize_001f9c54);
  if (iVar4 == 0x200) {
    uVar5 = _IOVmTaskSelf();
    iVar4 = _objc_msgSend(uVar2,PTR_s_readAt_length_buffer_actualLengt_001f9cb4,0,0x200,iVar3,
                          local_8,uVar5);
    if (iVar4 == 0) {
      if (*(short *)(iVar3 + 0x1fe) == -0x55ab) {
        iVar4 = iVar3 + 0x1be;
        iVar6 = 0;
        do {
          if (*(char *)(iVar4 + 4) != '\0') {
            if (*(char *)(iVar4 + 4) == -0x59) {
              uVar7 = *(undefined4 *)(iVar4 + 8);
              goto LAB_001a6d0b;
            }
            bVar1 = true;
          }
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + 0x10;
        } while (iVar6 < 4);
        if (bVar1) {
          uVar7 = 0xfffffbb0;
        }
      }
    }
    else {
      uVar7 = 0xfffffbb1;
    }
  }
LAB_001a6d0b:
  _IOFree(iVar3,_page_size);
  return uVar7;
}

