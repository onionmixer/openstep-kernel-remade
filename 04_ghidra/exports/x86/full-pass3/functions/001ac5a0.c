/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac5a0 */

undefined4 FUN_001ac5a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  byte local_48;
  byte local_47;
  byte local_46;
  undefined1 local_45;
  byte local_44;
  byte local_43;
  byte local_42;
  undefined1 local_41;
  undefined1 local_40 [2];
  char local_3e;
  
  local_54 = 0;
  iVar1 = _objc_msgSend(param_1,PTR_s_updateReadyState_001f9cbc);
  if (iVar1 != 0) {
    return 0xfffffd28;
  }
  iVar1 = _objc_msgSend(param_1,PTR_s_sdReadCapacity__001f9ab0,&local_48);
  if (iVar1 != 0) {
    return 0xfffffd36;
  }
  _objc_msgSend(param_1,PTR_s_setDiskSize__001f9c60,
                CONCAT31((uint3)(((uint)(ushort)((ushort)(((uint)local_48 << 0x18) >> 0x10) |
                                                (ushort)local_47) << 0x10) >> 8) | (uint3)local_46,
                         local_45) + 1);
  _objc_msgSend(param_1,PTR_s_setBlockSize__001f9c64,
                CONCAT31((uint3)(((uint)(ushort)((ushort)(((uint)local_44 << 0x18) >> 0x10) |
                                                (ushort)local_43) << 0x10) >> 8) | (uint3)local_42,
                         local_41));
  uVar2 = _objc_msgSend(param_1,PTR_s_blockSize_001f93a8);
  uVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x184),
                        PTR_s_allocateBufferOfLength_actualSta_001f93a4,uVar2,&local_4c,&local_50);
  iVar4 = 10;
  iVar1 = 0;
  do {
    iVar3 = _objc_msgSend(param_1,PTR_s_sdRawRead_blockCnt_buffer__001f9aac,iVar4,1,uVar2);
    if (iVar3 == 0) {
      uVar2 = 1;
      goto LAB_001ac6ef;
    }
    iVar4 = iVar4 + 10;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  uVar2 = 0;
LAB_001ac6ef:
  _objc_msgSend(param_1,PTR_s_setFormattedInternal__001f9ca0,uVar2);
  _IOFree(local_4c,local_50);
  if (*(char *)(param_1 + 0x1bc) != '\x05') {
    _bzero(local_40,0x3c);
    _objc_msgSend(param_1,PTR_s_sdModeSense__001f9aa8,local_40);
    if (-1 < local_3e) goto LAB_001ac747;
  }
  local_54 = 1;
LAB_001ac747:
  _objc_msgSend(param_1,PTR_s_setWriteProtected__001f9c9c,local_54);
  return 0;
}

