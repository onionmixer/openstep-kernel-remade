/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b75d0 */

void FUN_001b75d0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = 0;
  puVar1 = *(uint **)(param_1 + 0x24);
  uVar3 = puVar1[2];
  puVar2 = (uint *)puVar1[3];
  uVar4 = uVar3;
  if (param_1 + 0x24U != uVar3) {
    uVar4 = uVar3 + 8;
  }
  *(uint **)(uVar4 + 4) = puVar2;
  if ((uint *)(param_1 + 0x24) != puVar2) {
    puVar2 = puVar2 + 2;
  }
  *puVar2 = uVar3;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
  uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_count_001f92d8);
  if (uVar3 != 0) {
    if (*(int *)(param_1 + 0x50) != 0) {
      uVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_dataEncoding_001f9828);
      if (uVar4 == 0x259) {
        uVar5 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_channelCount_001f98b0,puVar1[1],
                              *puVar1,&local_8,&local_c);
        _audio_linear8_peak(uVar5);
      }
      else if (uVar4 < 0x25a) {
        if (uVar4 == 600) {
          uVar5 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_channelCount_001f98b0,puVar1[1],
                                *puVar1 >> 1,&local_8,&local_c);
          _audio_linear16_peak(uVar5);
        }
      }
      else if (uVar4 == 0x25a) {
        uVar5 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_channelCount_001f98b0,puVar1[1],
                              *puVar1,&local_8,&local_c);
        _audio_mulaw8_peak(uVar5);
      }
      _audio_add_peak(*(undefined4 *)(param_1 + 0x58),local_8,param_1 + 0x60,
                      *(undefined4 *)(param_1 + 0x54));
      _audio_add_peak(*(undefined4 *)(param_1 + 0x5c),local_c,param_1 + 0x60,
                      *(undefined4 *)(param_1 + 0x54));
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        uVar5 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_objectAt__001f92e8,uVar4);
        _objc_msgSend(uVar5,PTR_s_dmaCompleteDescriptor_transfered_001f9768,puVar1,*puVar1);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
  _bzero((void *)puVar1[1],*(size_t *)(param_1 + 0x40));
  uVar3 = param_1 + 0x2c;
  if (*(uint *)(param_1 + 0x2c) == uVar3) {
    *(uint **)(param_1 + 0x2c) = puVar1;
    *(uint **)(param_1 + 0x30) = puVar1;
    puVar1[2] = uVar3;
    puVar1[3] = uVar3;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x30);
    puVar1[3] = uVar4;
    puVar1[2] = uVar3;
    *(uint **)(param_1 + 0x30) = puVar1;
    *(uint **)(uVar4 + 8) = puVar1;
  }
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
  return;
}

