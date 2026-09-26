/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aaac8 */

void FUN_001aaac8(int param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  byte **ppbVar4;
  byte *pbStack_1c;
  undefined *puStack_18;
  undefined1 *puStack_14;
  
  if ((*param_3 & 1) != 0) {
    puStack_14 = PTR_s_lock_001f9220;
    puStack_18 = *(undefined **)(param_1 + 0x138);
    pbStack_1c = (byte *)0x1aaaf0;
    _objc_msgSend();
    pbStack_1c = param_3;
    iVar2 = _objc_msgSend(param_1,PTR_s_searchMulti__001f9b48);
    if (iVar2 == 0) {
      puStack_14 = (undefined1 *)0x14;
      puStack_18 = (undefined *)0x1aab3b;
      puVar3 = (undefined4 *)_IOMalloc();
      *puVar3 = *(undefined4 *)param_3;
      *(undefined2 *)(puVar3 + 1) = *(undefined2 *)(param_3 + 4);
      puVar3[4] = 1;
      iVar2 = param_1 + 0x144;
      if (*(int *)(param_1 + 0x144) == iVar2) {
        *(undefined4 **)(param_1 + 0x144) = puVar3;
        *(undefined4 **)(param_1 + 0x148) = puVar3;
        puVar3[2] = iVar2;
        puVar3[3] = iVar2;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x148);
        puVar3[3] = iVar1;
        puVar3[2] = iVar2;
        *(undefined4 **)(param_1 + 0x148) = puVar3;
        *(undefined4 **)(iVar1 + 8) = puVar3;
      }
      *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)param_3;
      *(undefined2 *)(param_1 + 0x140) = *(undefined2 *)(param_3 + 4);
      puStack_14 = &DAT_00000007;
      puStack_18 = PTR_s_send__001f9b4c;
      pbStack_1c = *(byte **)(param_1 + 300);
      ppbVar4 = &pbStack_1c;
      _objc_msgSend();
    }
    else {
      iVar1 = *(int *)(iVar2 + 0x10);
      *(int *)(iVar2 + 0x10) = iVar1 + 1;
      ppbVar4 = (byte **)&stack0xfffffff0;
      if (iVar1 + 1 < 0) {
        *(int *)(iVar2 + 0x10) = iVar1;
        ppbVar4 = (byte **)&stack0xfffffff0;
      }
    }
    *(undefined **)((int)ppbVar4 + -4) = PTR_s_unlock_001f9474;
    *(undefined4 *)((int)ppbVar4 + -8) = *(undefined4 *)(param_1 + 0x138);
    *(undefined4 *)((int)ppbVar4 + -0xc) = 0x1aabb1;
    _objc_msgSend();
  }
  return;
}

