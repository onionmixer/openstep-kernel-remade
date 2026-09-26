/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b11bc */

int FUN_001b11bc(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 local_8 [4];
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_lock_001f9220);
  puVar2 = *(undefined4 **)(param_1 + 0x174);
  if ((undefined4 *)(param_1 + 0x174) != puVar2) {
    do {
      uVar1 = *puVar2;
      puVar2 = (undefined4 *)puVar2[1];
      _objc_msgSend(uVar1,PTR_s_setIntValues_forParameter_count__001f94bc,local_8,
                    "Evs_ResetKeyboard",1);
    } while ((undefined4 *)(param_1 + 0x174) != puVar2);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_unlock_001f9474);
  return param_1;
}

