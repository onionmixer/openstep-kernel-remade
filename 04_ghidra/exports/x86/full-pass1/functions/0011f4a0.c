/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011f4a0 */

undefined4 _locontrol(undefined4 param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = _strcmp(param_2,"setaddr");
  if (iVar1 == 0) {
    uVar2 = _if_flags(param_1);
    _if_flags_set(param_1,uVar2 | 0x41);
  }
  else {
    iVar1 = _strcmp(param_2,"add-multicast");
    if ((iVar1 != 0) && (iVar1 = _strcmp(param_2,"add-multicast"), iVar1 != 0)) {
      return 0x16;
    }
    if (*(short *)(param_3 + 0x10) != 2) {
      uVar3 = 0x2f;
    }
  }
  return uVar3;
}

