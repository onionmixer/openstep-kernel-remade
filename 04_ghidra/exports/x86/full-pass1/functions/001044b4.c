/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001044b4 */

undefined4 _fgetown(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0xc) == 2) {
    *param_2 = (int)*(short *)(*(int *)(param_1 + 0x18) + 0x5a);
    uVar1 = 0;
  }
  else {
    uVar1 = _fioctl(param_1,0x40047477,param_2);
    *param_2 = -*param_2;
  }
  return uVar1;
}

