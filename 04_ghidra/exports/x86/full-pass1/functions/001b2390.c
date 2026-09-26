/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2390 */

void FUN_001b2390(undefined *param_1)

{
  int iVar1;
  undefined4 **ppuVar2;
  undefined *puStack_2c;
  undefined4 uStack_28;
  undefined *puStack_24;
  undefined *puStack_20;
  undefined *puStack_1c;
  undefined *puStack_18;
  undefined4 *puStack_14;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x188) != 0) {
    puStack_14 = (undefined4 *)PTR_s_lock_001f9220;
    puStack_18 = *(undefined **)(param_1 + 0x110);
    puStack_1c = (undefined *)0x1b23bb;
    _objc_msgSend();
    if (param_1[0x1d2] == '\0') {
      ppuVar2 = &puStack_14;
      puStack_14 = (undefined4 *)PTR_s_unlock_001f9474;
      param_1 = *(undefined **)(param_1 + 0x110);
    }
    else {
      local_8 = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x18);
      puStack_14 = &local_8;
      puStack_18 = PTR_s_pointToScreen__001f9998;
      puStack_1c = param_1;
      puStack_20 = (undefined *)0x1b23f9;
      iVar1 = _objc_msgSend();
      *(int *)(param_1 + 0x18c) = iVar1;
      if (iVar1 < 0) {
        ppuVar2 = &puStack_14;
        puStack_14 = (undefined4 *)PTR_s_unlock_001f9474;
        param_1 = *(undefined **)(param_1 + 0x110);
      }
      else {
        *(undefined4 *)(param_1 + 400) =
             *(undefined4 *)(*(int *)(param_1 + 0x180) + 0xc + iVar1 * 0x14);
        *(undefined4 *)(param_1 + 0x194) =
             *(undefined4 *)(*(int *)(param_1 + 0x180) + 0x10 + iVar1 * 0x14);
        *(short *)(param_1 + 0x192) = *(short *)(param_1 + 0x192) + -1;
        *(short *)(param_1 + 0x196) = *(short *)(param_1 + 0x196) + -1;
        puStack_14 = (undefined4 *)PTR_s_setBrightness_001f9994;
        puStack_18 = param_1;
        puStack_1c = (undefined *)0x1b2453;
        _objc_msgSend();
        puStack_1c = PTR_s_showCursor_001f99fc;
        puStack_20 = param_1;
        puStack_24 = (undefined *)0x1b2460;
        _objc_msgSend();
        puStack_24 = PTR_s_unlock_001f9474;
        uStack_28 = *(undefined4 *)(param_1 + 0x110);
        puStack_2c = (undefined *)0x1b2473;
        _objc_msgSend();
        ppuVar2 = (undefined4 **)&puStack_2c;
        puStack_2c = PTR_s_attachDefaultEventSources_001f9990;
      }
    }
    *(undefined **)((int)ppuVar2 + -4) = param_1;
    *(undefined4 *)((int)ppuVar2 + -8) = 0x1b2480;
    _objc_msgSend();
  }
  return;
}

