/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d21c */

undefined4 FUN_0015d21c(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = param_2[1];
    param_3 = param_3 - (iVar1 * 4 + 8);
    iVar2 = _thread_setstatus(param_1,*param_2,param_2 + 2,iVar1);
    if (iVar2 != 0) break;
    param_2 = param_2 + 2 + iVar1;
  }
  return 4;
}

