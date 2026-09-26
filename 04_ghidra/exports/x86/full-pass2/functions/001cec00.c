/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cec00 */

void _objc_msgSendv(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 uStack_8;
  
  puVar5 = &stack0xfffffffc;
  iVar2 = (param_3 >> 2) - 2;
  puVar4 = (undefined1 *)register0x00000010;
  if (iVar2 != 0 && 1 < param_3 >> 2) {
    do {
      iVar3 = iVar2 + -1;
      puVar5 = puVar4 + -8;
      *(undefined4 *)(puVar4 + -8) = *(undefined4 *)(param_4 + 8 + iVar3 * 4);
      bVar1 = 0 < iVar2;
      iVar2 = iVar3;
      puVar4 = puVar4 + -4;
    } while (iVar3 != 0 && bVar1);
  }
  *(undefined4 *)(puVar5 + -4) = param_2;
  *(undefined4 *)(puVar5 + -8) = param_1;
  *(undefined4 *)(puVar5 + -0xc) = 0x1cec29;
  _objc_msgSend();
  return;
}

