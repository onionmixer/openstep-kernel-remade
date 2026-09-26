/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116614 */

void _sbappend(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != 0) {
    piVar2 = *(int **)(param_1 + 0xc);
    if (piVar2 != (int *)0x0) {
      iVar1 = piVar2[0x1f];
      while (iVar1 != 0) {
        piVar2 = (int *)piVar2[0x1f];
        iVar1 = piVar2[0x1f];
      }
      for (; *piVar2 != 0; piVar2 = (int *)*piVar2) {
      }
    }
    _sbcompress(param_1,param_2,piVar2);
  }
  return;
}

