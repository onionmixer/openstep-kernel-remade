/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018449c */

undefined4 FUN_0018449c(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  uint local_100;
  undefined4 local_f8;
  int local_f4;
  undefined4 local_ec;
  uint local_e4;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined8 local_d4;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 local_bc;
  uint local_b8;
  undefined4 local_b4;
  byte local_b0;
  byte local_ad;
  undefined1 local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_70;
  undefined1 local_6f;
  undefined4 local_6e;
  undefined4 local_6a;
  undefined4 local_66;
  undefined1 local_62;
  uint local_60;
  undefined4 local_5c;
  byte local_58;
  byte local_55;
  undefined1 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  uint local_c;
  uint local_8;
  
  local_e4 = 0;
  bVar1 = false;
  local_ec = 0;
  if (param_2 == (undefined4 *)0x0) {
    if (param_3 == (undefined4 *)0x0) {
      _IOPanic(s_sg_doiocreq__no_scsi_req_ptr_001e1380);
    }
    else {
      local_100 = param_3[6];
      local_f4 = param_3[4];
      local_f8 = param_3[5];
    }
  }
  else {
    local_100 = param_2[5];
    local_f4 = param_2[3];
    local_f8 = param_2[4];
  }
  uVar2 = _objc_msgSend(param_1,PTR_s_controller_001f939c,PTR_s_maxTransfer_001f9388);
  uVar3 = _objc_msgSend(uVar2);
  if (uVar3 < local_100) {
    return 0x16;
  }
  if (local_100 == 0) {
    local_e0 = local_f8;
  }
  else {
    uVar2 = _objc_msgSend(param_1,PTR_s_controller_001f939c);
    _objc_msgSend(uVar2,PTR_s_getDMAAlignment__001f93a0,local_14);
    if (local_f4 == 1) {
      local_c = local_8;
    }
    bVar1 = true;
    local_ec = _kernel_map;
    if (local_c < 2) {
      local_e4 = local_100;
    }
    else {
      local_e4 = (local_c - 1) + local_100 & -local_c;
    }
    local_e0 = _objc_msgSend(uVar2,PTR_s_allocateBufferOfLength_actualSta_001f93a4,local_100,
                             &local_18,&local_1c);
    if (local_f4 == 1) {
      iVar4 = _copyin(local_f8,local_e0,local_100);
      if (iVar4 != 0) {
        uVar2 = 0xe;
        goto LAB_00184923;
      }
    }
  }
  uVar2 = 0;
  if (param_2 == (undefined4 *)0x0) {
    _bzero(&local_dc,0x6c);
    local_dc = _objc_msgSend(param_1,PTR_s_SCSI3_target_001f93fc);
    local_d4 = _objc_msgSend(param_1,PTR_s_SCSI3_lun_001f9400);
    local_cc = *param_3;
    local_c8 = param_3[1];
    local_c4 = param_3[2];
    local_c0 = param_3[3];
    local_bc = param_3[4] == 0;
    local_b8 = local_e4;
    local_b4 = param_3[7];
    local_b0 = local_b0 & 0xf8 | ~*(byte *)((int)param_3 + 0x4d) & 1 |
               *(byte *)((int)param_3 + 0x4d) & 2 | *(byte *)((int)param_3 + 0x4d) & 4;
    local_ad = local_ad & 0xf | *(char *)(param_3 + 0x13) << 4;
    uVar5 = _objc_msgSend(param_1,PTR_s_executeSCSI3Request_buffer_clien_001f941c,&local_dc,local_e0
                          ,local_ec,0x21);
    param_3[8] = uVar5;
    *(undefined1 *)(param_3 + 9) = local_a8;
    param_3[0x10] = local_a4;
    local_100 = local_a4;
    if ((int)param_3[6] < local_a4) {
      param_3[0x10] = param_3[6];
    }
    param_2 = param_3 + 0x11;
    local_48 = local_a0;
    local_44 = local_9c;
LAB_001848dd:
    _ns_time_to_timeval(local_48,local_44,param_2);
    if ((local_f4 == 0) && (local_100 != 0)) {
      if (!bVar1) {
        return 0;
      }
      uVar2 = _copyout(local_e0,local_f8,local_100);
    }
  }
  else {
    _bzero(&local_70,0x54);
    uVar6 = _objc_msgSend(param_1,PTR_s_SCSI3_target_001f93fc);
    if (((int)((ulonglong)uVar6 >> 0x20) == 0) && ((uint)uVar6 < 0x20)) {
      local_70 = (undefined1)uVar6;
      uVar6 = _objc_msgSend(param_1,PTR_s_SCSI3_lun_001f9400);
      if (((int)((ulonglong)uVar6 >> 0x20) == 0) && ((uint)uVar6 < 8)) {
        local_6f = (undefined1)uVar6;
        local_6e = *param_2;
        local_6a = param_2[1];
        local_66 = param_2[2];
        local_62 = param_2[3] == 0;
        local_60 = local_e4;
        local_5c = param_2[6];
        local_58 = local_58 & 0xf8 | ~*(byte *)((int)param_2 + 0x49) & 1 |
                   *(byte *)((int)param_2 + 0x49) & 2 | *(byte *)((int)param_2 + 0x49) & 4;
        local_55 = local_55 & 0xf | *(char *)(param_2 + 0x12) << 4;
        uVar5 = _objc_msgSend(param_1,PTR_s_executeRequest_buffer_client_sen_001f9418,&local_70,
                              local_e0,local_ec,(int)param_2 + 0x21);
        param_2[7] = uVar5;
        *(undefined1 *)(param_2 + 8) = local_50;
        param_2[0xf] = local_4c;
        local_100 = local_4c;
        if ((int)param_2[5] < local_4c) {
          param_2[0xf] = param_2[5];
        }
        param_2 = param_2 + 0x10;
        goto LAB_001848dd;
      }
    }
    uVar2 = 0x16;
  }
LAB_00184923:
  if (bVar1) {
    _IOFree(local_18,local_1c);
  }
  return uVar2;
}

