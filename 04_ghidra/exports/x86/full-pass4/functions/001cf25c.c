/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf25c */

int FUN_001cf25c(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  while( true ) {
    if (DAT_001e55fc <= uVar5) {
      return 0;
    }
    iVar1 = uVar5 * 0x18;
    iVar2 = *(int *)(DAT_001e55f8 + 0x10 + iVar1);
    iVar3 = FUN_001cf6b0(*(undefined4 *)(DAT_001e55f8 + iVar1));
    uVar4 = iVar2 + *(int *)(iVar3 + 0x18);
    if ((uVar4 <= param_1) && (param_1 < uVar4 + *(int *)(iVar3 + 0x1c))) break;
    uVar5 = uVar5 + 1;
  }
  return iVar1 + DAT_001e55f8;
}

