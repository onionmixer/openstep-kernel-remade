/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114f6c */

undefined4 _soconnect(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(byte *)(param_1 + 2) & 2) == 0) {
    uVar1 = _splnet();
    if (((*(byte *)(param_1 + 6) & 6) == 0) ||
       (((*(byte *)(*(int *)(param_1 + 0xc) + 10) & 4) == 0 &&
        (iVar2 = _sodisconnect(param_1), iVar2 == 0)))) {
      uVar3 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,4,0,param_2,0);
    }
    else {
      uVar3 = 0x38;
    }
    _splx(uVar1);
    return uVar3;
  }
  return 0x2d;
}

