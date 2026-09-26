/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113a68 */

void _pfctlinput(int param_1,sockaddr *param_2)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x14) != (code *)0x0) {
          (**(code **)(uVar2 + 0x14))(param_1,param_2,0);
        }
        uVar2 = uVar2 + 0x30;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  return;
}

