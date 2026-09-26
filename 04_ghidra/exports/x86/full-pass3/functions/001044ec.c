/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001044ec */

undefined4 _fsetown(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0xc) == 2) {
    *(undefined2 *)(*(int *)(param_1 + 0x18) + 0x5a) = (undefined2)param_2;
    uVar1 = 0;
  }
  else {
    if (param_2 < 1) {
      param_2 = -param_2;
    }
    else {
      iVar2 = _pfind(param_2);
      if (iVar2 == 0) {
        return 3;
      }
      param_2 = (int)*(short *)(iVar2 + 0x2e);
    }
    uVar1 = _fioctl(param_1,0x80047476,&param_2);
  }
  return uVar1;
}

