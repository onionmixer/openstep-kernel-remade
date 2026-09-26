/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca65c */

int _object_setInstanceVariable(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    iVar1 = _class_getInstanceVariable(*param_1,param_2);
    if (iVar1 != 0) {
      *(undefined4 *)((int)param_1 + *(int *)(iVar1 + 8)) = param_3;
    }
  }
  return iVar1;
}

