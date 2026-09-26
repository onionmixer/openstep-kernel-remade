/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c7048 */

int FUN_001c7048(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *local_c;
  
  if (*(char *)(param_1 + 0x250) != '\0') {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: setting transfer table.\n",uVar1);
  }
  if (((*(int *)(param_1 + 0x23c) == 0) || (uVar3 = *(uint *)(param_1 + 0x240), uVar3 == 0)) ||
     (uVar3 < 9)) {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: Can\'t set transfer table: no vpcode present.\n",uVar1);
  }
  else {
    uVar5 = *(uint *)(*(int *)(param_1 + 0x23c) + 0x20);
    if (uVar5 < uVar3) {
      if (uVar5 == 0) {
        return param_1;
      }
      if (*(char *)(param_1 + 0x250) != '\0') {
        uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar5);
        _IOLog("%s: using transfer table at 0x%08x.\n",uVar1);
      }
      local_c = (uint *)(*(int *)(param_1 + 0x23c) + uVar5 * 4);
      if (*(int *)(param_1 + 0x228) == 0) {
        iVar2 = _objc_msgSend(param_1,PTR_s__setDefaultGammaTable__001f9584,local_c);
        return iVar2;
      }
      uVar6 = 0;
      uVar3 = *(uint *)(param_1 + 0x234);
      if (uVar3 != 0) {
        do {
          uVar3 = (uint)(0x100 / (longlong)(int)uVar3);
          for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + 1) {
            iVar2 = *(int *)(param_1 + 0x238);
            *local_c = ((uint)*(byte *)(uVar6 + *(int *)(param_1 + 0x228)) * iVar2 >> 6) << 0x10 |
                       ((uint)*(byte *)(uVar6 + *(int *)(param_1 + 0x22c)) * iVar2 >> 6) << 8 |
                       (uint)*(byte *)(uVar6 + *(int *)(param_1 + 0x230)) * iVar2 >> 6;
            local_c = local_c + 1;
            uVar3 = (uint)(0x100 / (longlong)*(int *)(param_1 + 0x234));
          }
          uVar6 = uVar6 + 1;
          uVar3 = *(uint *)(param_1 + 0x234);
        } while (uVar6 < uVar3);
      }
      if (*(char *)(param_1 + 0x250) != '\0') {
        local_c = (uint *)(*(int *)(param_1 + 0x23c) + uVar5 * 4);
        uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
        _IOLog("%s: Transfer table:\n",uVar1);
        uVar3 = 0;
        do {
          uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
          _IOLog("%s: ",uVar1);
          uVar5 = 0;
          do {
            uVar1 = *local_c;
            local_c = local_c + 1;
            _IOLog("%08x ",uVar1);
            uVar5 = uVar5 + 1;
          } while (uVar5 < 4);
          _IOLog("\n");
          uVar3 = uVar3 + 1;
        } while (uVar3 < 0x40);
      }
      iVar2 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,7,0);
      if (iVar2 != 0) {
        return param_1;
      }
    }
    else {
      uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar5);
      _IOLog("%s: transfer table address is out of range: 0x%x.\n",uVar1);
    }
  }
  return 0;
}

