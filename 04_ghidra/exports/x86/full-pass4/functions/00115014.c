/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115014 */

undefined4 _sodisconnect(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = _splnet();
  if ((*(ushort *)(param_1 + 6) & 2) == 0) {
    uVar2 = 0x39;
  }
  else if ((*(ushort *)(param_1 + 6) & 8) == 0) {
    uVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,6,0,0,0);
  }
  else {
    uVar2 = 0x25;
  }
  _splx(uVar1);
  return uVar2;
}

