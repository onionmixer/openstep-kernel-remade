/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182a0c */

undefined4 _driverServer_server(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  *param_2 = (uint)*(byte *)(param_1 + 1);
  param_2[1] = 0x20;
  param_2[2] = *(uint *)(param_1 + 0xc);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(int *)(param_1 + 0x14) + 100;
  param_2[6] = DAT_001e1264;
  if ((*(int *)(param_1 + 0x14) - 0xa8cU < 0x27) &&
     (*(code **)(s_dropped_msg_accepted__0x_08x__0x_001de779 + *(int *)(param_1 + 0x14) * 4 + 0x1f)
      != (code *)0x0)) {
    (**(code **)(s_dropped_msg_accepted__0x_08x__0x_001de779 + *(int *)(param_1 + 0x14) * 4 + 0x1f))
              (param_1,param_2);
    uVar1 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar1 = 0;
  }
  return uVar1;
}

