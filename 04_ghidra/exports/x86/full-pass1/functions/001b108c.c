/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b108c */

int FUN_001b108c(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 local_8 [4];
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    *(undefined4 *)(param_1 + 0x1bc) = 0x1e;
    *(undefined2 *)(param_1 + 0x1b2) = 3;
    *(undefined2 *)(param_1 + 0x1b0) = 3;
    *(undefined4 *)(param_1 + 0x1b8) = 0xffffffe2;
    *(undefined2 *)(param_1 + 0x1ae) = 0xfffd;
    *(undefined2 *)(param_1 + 0x1ac) = 0xfffd;
    *(undefined4 *)(param_1 + 0x1b4) = 1;
    *(int *)(param_1 + 0x1a4) = *(int *)(*(int *)(param_1 + 0x168) + 0x10) + 0x48a8;
    *(undefined4 *)(param_1 + 0x1a0) = 0x48a8;
    *(undefined4 *)(param_1 + 0x1c8) = 0x10;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),PTR_s_lock_001f9220);
    puVar2 = *(undefined4 **)(param_1 + 0x174);
    if ((undefined4 *)(param_1 + 0x174) != puVar2) {
      do {
        uVar1 = *puVar2;
        puVar2 = (undefined4 *)puVar2[1];
        _objc_msgSend(uVar1,PTR_s_setIntValues_forParameter_count__001f94bc,local_8,"Evs_ResetMouse"
                      ,1);
      } while ((undefined4 *)(param_1 + 0x174) != puVar2);
    }
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  _objc_msgSend(uVar1,PTR_s_unlock_001f9474);
  return param_1;
}

