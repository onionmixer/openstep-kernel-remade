/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3f6c */

void FUN_001b3f6c(int param_1,undefined4 param_2,uint param_3,char param_4)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  ushort uVar14;
  undefined4 uVar15;
  uint local_28;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_c;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_setCharKeyActive__001f9938,1);
  local_c = 0xb;
  if (param_4 == '\x01') {
    local_c = 10;
  }
  uVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_eventFlags_001f9920);
  uVar5 = uVar4 >> 0x10;
  sVar2 = *(short *)(param_1 + 4);
  puVar10 = *(ushort **)(param_1 + 0xd0 + param_3 * 4);
  local_20 = uVar4;
  if (puVar10 == (ushort *)0x0) goto LAB_001b4307;
  if (sVar2 == 0) {
    uVar14 = (ushort)(byte)*puVar10;
    puVar10 = (ushort *)((int)puVar10 + 1);
  }
  else {
    uVar14 = *puVar10;
    puVar10 = puVar10 + 1;
  }
  if ((uVar14 != 0) && (uVar5 != 0)) {
    iVar8 = 2;
    if (sVar2 != 0) {
      iVar8 = 4;
    }
    iVar13 = 0;
    if (*(uint *)(param_1 + 0x88) < 0x80000000) {
      do {
        if ((uVar14 & 1) != 0) {
          if ((uVar5 & 1) != 0) {
            puVar10 = (ushort *)((int)puVar10 + iVar8);
          }
          iVar8 = iVar8 * 2;
        }
        uVar14 = (short)uVar14 >> 1;
        uVar5 = (int)uVar5 >> 1;
        iVar13 = iVar13 + 1;
      } while (iVar13 <= (int)*(uint *)(param_1 + 0x88));
    }
  }
  if (sVar2 == 0) {
    uVar5 = (uint)(byte)*puVar10;
    uVar11 = (uint)*(byte *)((int)puVar10 + 1);
  }
  else {
    uVar5 = (uint)(short)*puVar10;
    uVar11 = (uint)(short)puVar10[1];
  }
  puVar10 = *(ushort **)(param_1 + 0xd0 + param_3 * 4);
  uVar6 = (uVar4 & 0x30000) >> 0x10;
  if (sVar2 == 0) {
    uVar14 = (ushort)(byte)*puVar10;
    puVar10 = (ushort *)((int)puVar10 + 1);
  }
  else {
    uVar14 = *puVar10;
    puVar10 = puVar10 + 1;
  }
  if ((uVar14 != 0) && (uVar6 != 0)) {
    iVar8 = 2;
    if (sVar2 != 0) {
      iVar8 = 4;
    }
    iVar13 = 0;
    if (*(uint *)(param_1 + 0x88) < 0x80000000) {
      do {
        if ((uVar14 & 1) != 0) {
          if ((uVar6 & 1) != 0) {
            puVar10 = (ushort *)((int)puVar10 + iVar8);
          }
          iVar8 = iVar8 * 2;
        }
        uVar14 = (short)uVar14 >> 1;
        uVar6 = (int)uVar6 >> 1;
        iVar13 = iVar13 + 1;
      } while (iVar13 <= (int)*(uint *)(param_1 + 0x88));
    }
  }
  if (sVar2 == 0) {
    uVar9 = (uint)(byte)*puVar10;
    uVar6 = (uint)*(byte *)((int)puVar10 + 1);
    if (uVar5 == 0xff) goto LAB_001b4141;
  }
  else {
    uVar9 = (uint)(short)*puVar10;
    uVar6 = (uint)(short)puVar10[1];
    if (uVar5 == 0xffff) {
LAB_001b4141:
      pbVar12 = *(byte **)(param_1 + 0x2d4 + uVar11 * 4);
      iVar8 = 0;
      if (sVar2 == 0) {
        local_28 = (uint)*pbVar12;
        pbVar12 = pbVar12 + 1;
      }
      else {
        local_28 = (uint)*(short *)pbVar12;
        pbVar12 = pbVar12 + 2;
      }
      for (; iVar8 < (int)local_28; iVar8 = iVar8 + 1) {
        if (iVar8 % 10 == 9) {
          _thread_block();
        }
        if (sVar2 == 0) {
          local_18 = (uint)*pbVar12;
          pbVar12 = pbVar12 + 1;
        }
        else {
          local_18 = (uint)*(short *)pbVar12;
          pbVar12 = pbVar12 + 2;
        }
        uVar5 = param_3;
        if (local_18 == 0xff) {
          if (param_4 == '\x01') {
            if (sVar2 == 0) {
              bVar1 = *pbVar12;
              pbVar12 = pbVar12 + 1;
            }
            else {
              bVar1 = (byte)*(undefined2 *)pbVar12;
              pbVar12 = pbVar12 + 2;
            }
            local_20 = local_20 | 1 << (bVar1 + 0x10 & 0x1f);
            uVar9 = 0;
            uVar6 = 0;
            local_18 = 0;
            local_1c = 0;
            uVar11 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_deviceFlags_001f993c,
                                   param_3,0,0,0,0);
            uVar7 = *(undefined4 *)(param_1 + 0x4f8);
            uVar15 = 0xc;
            goto LAB_001b4276;
          }
          if (sVar2 == 0) {
            pbVar12 = pbVar12 + 1;
          }
          else {
            pbVar12 = pbVar12 + 2;
          }
        }
        else {
          if (sVar2 == 0) {
            local_1c = (uint)*pbVar12;
            pbVar12 = pbVar12 + 1;
          }
          else {
            local_1c = (uint)*(short *)pbVar12;
            pbVar12 = pbVar12 + 2;
          }
          uVar7 = *(undefined4 *)(param_1 + 0x4f8);
          uVar15 = local_c;
          uVar11 = local_20;
          uVar6 = local_1c;
          uVar9 = local_18;
LAB_001b4276:
          _objc_msgSend(uVar7,PTR_s_keyboardEvent_flags_keyCode_char_001f991c,uVar15,uVar11,uVar5,
                        local_1c,local_18,uVar6,uVar9);
        }
      }
      if (local_20 != uVar4) {
        uVar7 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_deviceFlags_001f993c,param_3,0,
                              0,0,0);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),
                      PTR_s_keyboardEvent_flags_keyCode_char_001f991c,0xc,uVar7);
        local_20 = uVar4;
      }
      goto LAB_001b4307;
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_keyboardEvent_flags_keyCode_char_001f991c,
                local_c,uVar4,param_3,uVar11,uVar5,uVar6,uVar9);
LAB_001b4307:
  if ((*(byte *)(param_3 + 6 + param_1) & 0x40) != 0) {
    iVar8 = 0;
    do {
      if (param_3 == *(ushort *)(param_1 + 0x4d8 + iVar8 * 2)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),
                      PTR_s_keyboardSpecialEvent_flags_keyCo_001f9918,local_c,local_20,param_3,iVar8
                     );
        if (iVar8 != 4) {
          return;
        }
        if (*(int *)(param_1 + 0x8c) != 0) {
          return;
        }
        if (param_4 != '\x01') {
          return;
        }
        uVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_deviceFlags_001f993c);
        cVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_alphaLock_001f9930);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_setAlphaLock__001f992c,cVar3 == '\0');
        if (cVar3 == '\0') {
          uVar4 = uVar4 | 0x10000;
        }
        else {
          uVar4 = uVar4 & 0xfffeffff;
        }
        _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),PTR_s_setDeviceFlags__001f9928,uVar4);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),
                      PTR_s_keyboardEvent_flags_keyCode_char_001f991c,0xc,uVar4,param_3,0,0,0,0);
        return;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 7);
  }
  return;
}

