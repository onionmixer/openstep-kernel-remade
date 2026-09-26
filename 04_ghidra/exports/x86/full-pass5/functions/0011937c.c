/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011937c */

void _cstatfs(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 local_44 [64];
  
  _bzero(local_44,0x40);
  uVar1 = (**(code **)(*(int *)(param_1 + 4) + 0xc))(param_1,local_44);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    uVar1 = _copyout(local_44,param_2,0x40);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  }
  return;
}

