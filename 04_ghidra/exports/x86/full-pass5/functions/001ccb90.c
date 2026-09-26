/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccb90 */

int * __internal_class_createInstanceFromZone(int param_1,int param_2,int param_3)

{
  int *piVar1;
  size_t sVar2;
  
  if (param_1 == 0) {
    ___objc_error(0,"allocating nil object",0);
  }
  sVar2 = param_2 + *(int *)(param_1 + 0x14);
  piVar1 = (int *)(**(code **)(param_3 + 4))(param_3,sVar2);
  if (piVar1 == (int *)0x0) {
    ___objc_error(param_1,"failed -- out of memory(%s, %u)",*(undefined4 *)(param_1 + 8),param_2);
    piVar1 = (int *)0x0;
  }
  else {
    _bzero(piVar1,sVar2);
    *piVar1 = param_1;
  }
  return piVar1;
}

