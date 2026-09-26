/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6794 */

int FUN_001a6794(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_8;
  
  bVar1 = false;
  uVar3 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58);
  uVar4 = _objc_msgSend(param_1,PTR_s_physicalBlockSize_001f9c54);
  uVar5 = _objc_msgSend(param_1,PTR_s_name_001f9228);
  iVar6 = _objc_msgSend(uVar3,PTR_s_isDiskReady__001f9384,1);
  if (iVar6 == -0x44e) {
    iVar6 = -0x44e;
  }
  else if (iVar6 == 0) {
    cVar2 = _objc_msgSend(uVar3,PTR_s_isFormatted_001f9398);
    if ((uVar4 == 0) || (cVar2 == '\0')) {
      iVar6 = -0x44d;
    }
    else {
      iVar6 = _objc_msgSend(param_1,PTR_s_NeXTpartitionOffset_001f9c50);
      if (-1 < iVar6) {
        uVar7 = (uVar4 + 0x1c47) / uVar4;
        iVar10 = uVar4 * uVar7;
        uVar4 = iVar10 + _page_mask & ~_page_mask;
        uVar5 = _IOMalloc(uVar4);
        iVar12 = 0;
        iVar11 = iVar6;
        do {
          uVar8 = _IOVmTaskSelf();
          iVar6 = _objc_msgSend(uVar3,PTR_s_readAt_length_buffer_actualLengt_001f9cb4,iVar11,iVar10,
                                uVar5,&local_8,uVar8);
          if (((iVar6 == 0) && (local_8 == iVar10)) &&
             (iVar9 = _check_label(uVar5,iVar11), iVar9 == 0)) {
            bVar1 = true;
            break;
          }
          if (iVar6 == -0x44e) break;
          iVar11 = iVar11 + uVar7;
          iVar12 = iVar12 + 1;
        } while (iVar12 < 4);
        if (bVar1) {
          *(undefined1 *)(param_1 + 0x1a8) = 1;
          _get_disk_label(uVar5,param_3);
          iVar6 = 0;
        }
        else if (iVar6 != -0x44e) {
          iVar6 = -0x44c;
        }
        _IOFree(uVar5,uVar4);
      }
    }
  }
  else {
    uVar3 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar6);
    _IOLog("%s readLabel: bogus return from isDiskReady (%s)\n",uVar5,uVar3);
  }
  return iVar6;
}

