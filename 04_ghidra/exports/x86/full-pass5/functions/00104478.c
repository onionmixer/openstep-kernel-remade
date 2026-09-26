/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104478 */

void _fset(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~param_2;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | param_2;
  }
  uVar1 = 0x8004667d;
  if (param_2 == 4) {
    uVar1 = 0x8004667e;
  }
  _fioctl(param_1,uVar1,&param_3);
  return;
}

