/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114ccc */

int _solisten(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _splnet();
  iVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,3,0,0,0);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      *(int *)(param_1 + 0x1c) = param_1;
      *(int *)(param_1 + 0x14) = param_1;
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 2;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (0x80 < param_2) {
      param_2 = 0x80;
    }
    *(short *)(param_1 + 0x22) = (short)param_2;
    _splx(uVar1);
    iVar2 = 0;
  }
  else {
    _splx(uVar1);
  }
  return iVar2;
}

