/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001840ec */

undefined4 FUN_001840ec(ushort param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = (param_1 & 0xf8) >> 3;
  uVar4 = param_1 & 7;
  if ((uVar2 < 0x10) && (uVar4 < 8)) {
    iVar1 = uVar2 * 0x24;
    if (uVar4 == 7) {
      if (DAT_001e7564 == (short)(param_1 >> 8)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(&DAT_001e7324 + iVar1);
      }
    }
    else {
      uVar3 = *(undefined4 *)(&DAT_001e7328 + uVar4 * 4 + iVar1);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

