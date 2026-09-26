/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001835d8 */

int _sdread(ushort param_1,uio *param_2)

{
  uint *puVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  uint uVar8;
  int local_34;
  void *local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14 [2];
  uint local_c;
  
  iVar4 = FUN_001840ec((int)(short)param_1);
  local_18 = 0;
  pvVar7 = (void *)0x0;
  local_1c = 0;
  local_2c = (void *)0x0;
  bVar2 = false;
  uVar8 = 0;
  local_34 = 0;
  uVar5 = FUN_0018414c((int)(short)param_1);
  if (iVar4 == 0) {
    iVar4 = 6;
  }
  else {
    cVar3 = _objc_msgSend(iVar4,PTR_s_isFormatted_001f9398);
    if (cVar3 == '\0') {
      iVar4 = 0x16;
    }
    else {
      puVar1 = *(uint **)param_2;
      uVar6 = _objc_msgSend(uVar5,PTR_s_controller_001f939c,PTR_s_getDMAAlignment__001f93a0,local_14
                           );
      _objc_msgSend(uVar6);
      if (_forceSdPageAlign != 0) {
        local_14[0] = _page_size;
      }
      if (((1 < local_14[0]) && ((*puVar1 & local_14[0] - 1) != 0)) ||
         ((1 < local_c && ((puVar1[1] & local_c - 1) != 0)))) {
        bVar2 = true;
        uVar5 = _objc_msgSend(uVar5,PTR_s_controller_001f939c,
                              PTR_s_allocateBufferOfLength_actualSta_001f93a4,puVar1[1],&local_18,
                              &local_1c);
        pvVar7 = (void *)_objc_msgSend(uVar5);
        local_2c = (void *)*puVar1;
        *puVar1 = (uint)pvVar7;
        uVar8 = puVar1[1];
        local_34 = *(int *)(param_2 + 0xc);
        *(undefined4 *)(param_2 + 0xc) = 1;
      }
      iVar4 = _objc_msgSend(iVar4,PTR_s_blockSize_001f93a8);
      iVar4 = _physio(_sdstrategy,(buf_t)(&DAT_001e1268)[(param_1 & 0xf8) >> 3],(int)(short)param_1,
                      1,(u_int *)FUN_001840d0,param_2,iVar4);
      if (bVar2) {
        if (local_34 == 1) {
          _bcopy(pvVar7,local_2c,uVar8);
        }
        else {
          _copyout(pvVar7,local_2c,uVar8);
        }
        _IOFree(local_18,local_1c);
      }
    }
  }
  return iVar4;
}

