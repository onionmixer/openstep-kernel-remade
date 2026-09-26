/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bc4e8 */

void FUN_001bc4e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = 0x194;
  local_14 = 0x193;
  local_10 = 0x191;
  local_c = 400;
  local_8 = 0x192;
  local_2c = param_6;
  local_28 = param_7;
  local_24 = param_3;
  if (param_4 == 2) {
    local_20 = 0x259;
  }
  else if ((param_4 < 3) || (param_4 != 4)) {
    local_20 = 0x25a;
  }
  else {
    local_20 = 600;
  }
  local_1c = param_5;
  __NXAudioSetStreamParameters(param_2,&local_18,5,&local_2c);
  return;
}

