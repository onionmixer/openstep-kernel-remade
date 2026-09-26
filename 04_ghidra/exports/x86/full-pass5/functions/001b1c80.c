/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1c80 */

undefined4
FUN_001b1c80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            char param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_3c;
  undefined4 local_38 [7];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 *local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar3 = &DAT_001e5330;
  puVar4 = local_38;
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_38[3] = 0;
  local_1c = param_3;
  if (param_5 == '\0') {
    local_18 = _objc_msgSend(PTR_s_NXConditionLock_001f9d64,PTR_s_alloc_001f9210);
    _objc_msgSend(local_18,PTR_s_initWith__001f9214,1);
    local_14 = &local_3c;
    local_3c = 0xfffffd3e;
  }
  local_10 = *param_4;
  local_c = param_4[1];
  local_8 = param_4[2];
  local_38[4] = _ev_port_list;
  iVar2 = _msg_send_from_kernel(local_38,0,0);
  if (iVar2 == 0) {
    if (param_5 == '\0') {
      _objc_msgSend(local_18,PTR_s_lockWhen__001f9218,2);
    }
    else {
      local_3c = 0;
    }
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar2);
    _IOLog("%s: _threadOpCommon msg_send returned %d\n",uVar1);
    local_3c = 0xfffffd41;
  }
  if (param_5 == '\0') {
    _objc_msgSend(local_18,PTR_s_free_001f921c);
  }
  return local_3c;
}

