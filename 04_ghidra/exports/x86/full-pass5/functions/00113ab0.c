/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113ab0 */

void _pfslowtimo(void)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x28) != (code *)0x0) {
          (**(code **)(uVar2 + 0x28))();
        }
        uVar2 = uVar2 + 0x30;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  _timeout(0x113ab0);
  return;
}

