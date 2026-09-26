/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab9e0 */

undefined4 FUN_001ab9e0(int param_1,undefined4 param_2,char *param_3,void *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = _strcmp(param_3,"setflags");
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = _strcmp(param_3,"getaddr");
    if (iVar1 == 0) {
      _bcopy((void *)(param_1 + 0x13c),param_4,6);
    }
    else {
      uVar2 = 0x16;
    }
  }
  return uVar2;
}

