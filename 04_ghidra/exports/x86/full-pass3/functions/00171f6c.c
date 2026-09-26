/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171f6c */

void FUN_00171f6c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = _machine_exception(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    switch(param_1) {
    case 1:
      if (param_2 == 1) {
        *param_4 = 0xb;
      }
      else {
        *param_4 = 10;
      }
      break;
    case 2:
      *param_4 = 4;
      break;
    case 3:
      *param_4 = 8;
      break;
    case 4:
      *param_4 = 7;
      break;
    case 5:
      if (param_2 == 0x10001) {
        *param_4 = 0xd;
      }
      else if (param_2 < 0x10002) {
        if (param_2 == 0x10000) {
          *param_4 = 0xc;
        }
      }
      else if (param_2 == 0x10002) {
        *param_4 = 6;
      }
      break;
    case 6:
      *param_4 = 5;
    }
  }
  return;
}

