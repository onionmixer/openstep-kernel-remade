/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00183790 */

int _sdwrite(ushort param_1,uio *param_2)

{
  uint *puVar1;
  void *pvVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *pvVar8;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  uint local_10;
  uint local_8;
  
  iVar5 = FUN_001840ec((int)(short)param_1);
  local_18 = 0;
  local_1c = 0;
  bVar3 = false;
  uVar6 = FUN_0018414c((int)(short)param_1);
  if (iVar5 == 0) {
    iVar5 = 6;
  }
  else {
    cVar4 = _objc_msgSend(iVar5,PTR_s_isFormatted_001f9398);
    if (cVar4 == '\0') {
      iVar5 = 0x16;
    }
    else {
      puVar1 = *(uint **)param_2;
      uVar7 = _objc_msgSend(uVar6,PTR_s_controller_001f939c,PTR_s_getDMAAlignment__001f93a0,local_14
                           );
      _objc_msgSend(uVar7);
      if (_forceSdPageAlign != 0) {
        local_10 = _page_size;
      }
      if (((1 < local_10) && ((*puVar1 & local_10 - 1) != 0)) ||
         ((1 < local_8 && ((puVar1[1] & local_8 - 1) != 0)))) {
        bVar3 = true;
        uVar6 = _objc_msgSend(uVar6,PTR_s_controller_001f939c,
                              PTR_s_allocateBufferOfLength_actualSta_001f93a4,puVar1[1],&local_18,
                              &local_1c);
        pvVar8 = (void *)_objc_msgSend(uVar6);
        pvVar2 = (void *)*puVar1;
        *puVar1 = (uint)pvVar8;
        if (*(int *)(param_2 + 0xc) == 1) {
          _bcopy(pvVar2,pvVar8,puVar1[1]);
        }
        else {
          _copyin(pvVar2,pvVar8,puVar1[1]);
          *(undefined4 *)(param_2 + 0xc) = 1;
        }
      }
      iVar5 = _objc_msgSend(iVar5,PTR_s_blockSize_001f93a8);
      iVar5 = _physio(_sdstrategy,(buf_t)(&DAT_001e1268)[(param_1 & 0xf8) >> 3],(int)(short)param_1,
                      0,(u_int *)FUN_001840d0,param_2,iVar5);
      if (bVar3) {
        _IOFree(local_18,local_1c);
      }
    }
  }
  return iVar5;
}

