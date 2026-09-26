/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae600 */

undefined4 FUN_001ae600(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [8];
  uint local_60;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  byte local_55;
  undefined1 local_52;
  undefined1 local_4a;
  uint local_48;
  undefined4 local_44;
  byte local_40;
  
  puVar1 = (undefined4 *)
           _objc_msgSend(*(undefined4 *)(param_1 + 0x184),
                         PTR_s_allocateBufferOfLength_actualSta_001f93a4,0x1a,&local_6c,&local_70);
  _bzero(&local_58,0x54);
  local_56 = 3;
  local_55 = local_55 & 0x1f | *(char *)(param_1 + 0x189) << 5;
  local_52 = 0x1a;
  local_58 = *(undefined1 *)(param_1 + 0x188);
  local_57 = *(undefined1 *)(param_1 + 0x189);
  local_4a = 1;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x184),PTR_s_getDMAAlignment__001f93a0,local_68);
  if (local_60 < 2) {
    local_48 = 0x1a;
  }
  else {
    local_48 = local_60 + 0x19 & -local_60;
  }
  local_44 = 0x14;
  local_40 = local_40 | 1;
  uVar2 = _IOVmTaskSelf();
  uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x184),
                        PTR_s_executeRequest_buffer_client__001f9a9c,&local_58,puVar1,uVar2);
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_3 = *puVar1;
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
  }
  *(undefined2 *)param_3 = *(undefined2 *)puVar1;
  _IOFree(local_6c,local_70);
  return uVar2;
}

