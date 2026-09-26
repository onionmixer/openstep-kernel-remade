/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111f90 */

undefined4 _ptswrite(byte param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(&DAT_001e56d0 + (uint)param_1 * 0x10);
  if (*(int *)(iVar1 + 0x24) != 0) {
    uVar2 = (*(code *)(&PTR__ttwrite_001daff4)[*(char *)(iVar1 + 0x47) * 0xc])(iVar1,param_2);
    return uVar2;
  }
  return 5;
}

