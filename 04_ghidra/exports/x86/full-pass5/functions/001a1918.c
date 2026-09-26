/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1918 */

undefined4 _PCbopFC(undefined4 param_1,int param_2,ushort *param_3)

{
  undefined4 uVar1;
  
  if ((param_3[1] & 4) == 0) {
    uVar1 = 0;
  }
  else {
    *(uint *)(param_2 + 0x38) = (uint)*param_3;
    *(ushort *)(param_2 + 0x3c) = param_3[1];
    *(uint *)(param_2 + 0x40) = param_3[2] & 0xfd7 | 0x202;
    *(uint *)(param_2 + 0x44) = (uint)param_3[3];
    *(ushort *)(param_2 + 0x48) = param_3[4];
    uVar1 = _thread_exception_return();
  }
  return uVar1;
}

