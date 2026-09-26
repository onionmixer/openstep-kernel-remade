/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114fdc */

undefined4 _soconnect2(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = _splnet();
  uVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,0x11,0,param_2,0);
  _splx(uVar1);
  return uVar2;
}

