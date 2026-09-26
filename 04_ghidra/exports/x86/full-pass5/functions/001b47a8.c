/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b47a8 */

void FUN_001b47a8(int param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  undefined *puVar6;
  bool bVar7;
  uint local_14;
  uint local_c;
  
  uVar3 = 1 << ((char)param_3 + 0x10U & 0x1f);
  local_c = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_deviceFlags_001f993c);
  local_c = local_c & ~uVar3;
  pbVar4 = *(byte **)(param_1 + 0x8c + param_3 * 4);
  if (pbVar4 != (byte *)0x0) {
    iVar5 = 0;
    if (*(short *)(param_1 + 4) == 0) {
      local_14 = (uint)*pbVar4;
      pbVar4 = pbVar4 + 1;
    }
    else {
      local_14 = (uint)*(short *)pbVar4;
      pbVar4 = pbVar4 + 2;
    }
    if (0 < (int)local_14) {
      do {
        if (*(short *)(param_1 + 4) == 0) {
          uVar2 = (uint)*pbVar4;
          pbVar4 = pbVar4 + 1;
        }
        else {
          uVar2 = (uint)*(short *)pbVar4;
          pbVar4 = pbVar4 + 2;
        }
        if ((*(uint *)(param_4 + (uVar2 >> 5) * 4) & 1 << ((byte)uVar2 & 0x1f)) != 0) {
          local_c = local_c | uVar3;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)local_14);
    }
  }
  if (param_3 != 1) {
    if (param_3 == 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_setAlphaLock__001f992c,
                    local_c >> 0x10 & 1);
    }
    goto LAB_001b496d;
  }
  if ((((local_c & 0x100000) != 0) && (*(int *)(param_1 + 0x8c) == 0)) &&
     (*(short *)(param_1 + 0x4e0) == -1)) {
    if ((local_c & 0x20000) == 0) {
      cVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_charKeyActive_001f9934);
      if (cVar1 != '\0') goto LAB_001b48fe;
      cVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_alphaLock_001f9930);
      bVar7 = cVar1 == '\0';
      puVar6 = PTR_s_setAlphaLock__001f992c;
    }
    else {
      bVar7 = false;
      puVar6 = PTR_s_setCharKeyActive__001f9938;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),puVar6,bVar7);
  }
LAB_001b48fe:
  cVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_alphaLock_001f9930);
  if (cVar1 == '\x01') {
    local_c = local_c & 0xfffeffff | 0x10000;
  }
  else {
    local_c = local_c & 0xfffeffff | (local_c & 0x20000) >> 1;
  }
LAB_001b496d:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_setDeviceFlags__001f9928,local_c);
  return;
}

