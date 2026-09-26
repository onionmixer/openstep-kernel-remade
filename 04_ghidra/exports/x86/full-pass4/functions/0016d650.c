/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d650 */

undefined4 _kern_serv_handler(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_24 [3];
  undefined1 local_21;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_21 = 1;
  local_20 = 0x20;
  local_1c = *(undefined4 *)(param_1 + 8);
  local_18 = 0;
  local_14 = *(undefined4 *)(param_1 + 0x10);
  local_10 = *(int *)(param_1 + 0x14) + 100;
  local_c = 0x10012002;
  local_8 = -0x12f;
  if ((*(int *)(param_1 + 0x14) - 100U < 0xd) &&
     (*(code **)(&DAT_001d1180 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(&DAT_001d1180 + *(int *)(param_1 + 0x14) * 4))(param_1,local_24,param_2);
    if (local_8 == -0x131) {
      uVar1 = 0;
    }
    else {
      uVar1 = _msg_send(local_24,~*(uint *)(param_2 + 4) >> 0x1f,*(uint *)(param_2 + 4));
    }
  }
  else {
    uVar1 = 0xfffffed1;
  }
  return uVar1;
}

