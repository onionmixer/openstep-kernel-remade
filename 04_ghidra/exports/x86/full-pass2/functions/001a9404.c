/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9404 */

int FUN_001a9404(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0x128;
  do {
    puVar1 = (undefined4 *)(iVar3 + param_1);
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    iVar3 = iVar3 + 0x5c;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  return param_1;
}

