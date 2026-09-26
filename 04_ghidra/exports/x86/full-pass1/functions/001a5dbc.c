/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5dbc */

void __regparm2
FUN_001a5dbc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  if (param_5 == 1) {
    param_2 = 0;
  }
  else if (param_5 == 0) {
    param_2 = 2;
  }
  else if (param_5 == 2) {
    param_2 = 0xffffffff;
  }
  _volCheckRequest(param_3,param_2);
  return;
}

