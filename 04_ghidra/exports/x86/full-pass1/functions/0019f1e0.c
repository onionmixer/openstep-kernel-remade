/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f1e0 */

undefined * FUN_0019f1e0(undefined *param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined *puStack_1c;
  uint *puStack_18;
  uint local_c;
  uint local_8;
  
  puStack_18 = &local_c;
  puStack_1c = (undefined *)0x19f1f4;
  _IOGetTimestamp();
  puStack_1c = PTR_s_lock_001f9220;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124));
  ppuVar3 = (undefined **)&stack0xffffffec;
  if (param_1[0x154] != '\0') {
    param_1[0x154] = 0;
    param_1[0x14e] = 1;
    if ((((*(uint *)(param_1 + 0x160) != 0) || (*(int *)(param_1 + 0x164) != 0)) &&
        (*(uint *)(param_1 + 0x164) <= local_8)) &&
       ((*(uint *)(param_1 + 0x164) != local_8 || (*(uint *)(param_1 + 0x160) <= local_c)))) {
      *(uint *)(param_1 + 0x158) = local_c;
      *(uint *)(param_1 + 0x15c) = local_8;
      puStack_18 = (uint *)(param_1 + 0x134);
      puStack_1c = (undefined *)0x1;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_doKeyboardEvent_direction_keyBit_001f94ec
                    ,*(undefined4 *)(param_1 + 0x150));
      puVar1 = (uint *)(param_1 + 0x160);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + *(uint *)(param_1 + 0x168);
      *(uint *)(param_1 + 0x164) =
           *(int *)(param_1 + 0x164) + *(int *)(param_1 + 0x16c) +
           (uint)CARRY4(uVar2,*(uint *)(param_1 + 0x168));
    }
    param_1[0x14e] = 0;
    puStack_18 = (uint *)PTR_s_scheduleAutoRepeat_001f94f0;
    ppuVar3 = &puStack_1c;
    puStack_1c = param_1;
    _objc_msgSend();
  }
  *(undefined **)((int)ppuVar3 + -4) = PTR_s_unlock_001f9474;
  *(undefined4 *)((int)ppuVar3 + -8) = *(undefined4 *)(param_1 + 0x124);
  *(undefined4 *)((int)ppuVar3 + -0xc) = 0x19f2c3;
  _objc_msgSend();
  return param_1;
}

