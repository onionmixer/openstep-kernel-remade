/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016c8d4 */

void _kern_serv_port_gone(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x4b0) == param_2) {
      *(undefined4 *)(iVar1 + 0x4b0) = 0;
    }
    iVar2 = 0;
    iVar3 = 0;
    do {
      if (*(int *)(iVar3 + 0x18c + iVar1) == param_2) {
        *(undefined4 *)(iVar3 + 0x18c + iVar1) = 0;
        *(undefined4 *)(iVar3 + 400 + iVar1) = 0;
        return;
      }
      iVar3 = iVar3 + 0x10;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x32);
  }
  return;
}

