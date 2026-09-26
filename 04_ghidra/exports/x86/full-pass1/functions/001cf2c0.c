/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf2c0 */

int FUN_001cf2c0(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_001e55fc != 0) {
    do {
      iVar1 = *(int *)(DAT_001e55f8 + uVar2 * 0x18);
      if (*(int *)(iVar1 + 0xc) != 3) {
        return iVar1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_001e55fc);
  }
  return 0;
}

