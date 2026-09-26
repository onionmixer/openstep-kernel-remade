/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015beb4 */

undefined4 _host_get_time(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = _mtime;
  if (param_1 == 0) {
    uVar2 = 0x16;
  }
  else {
    do {
      *param_2 = *piVar1;
      param_2[1] = piVar1[1];
    } while (*param_2 != piVar1[2]);
    uVar2 = 0;
  }
  return uVar2;
}

