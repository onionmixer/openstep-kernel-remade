/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001973c4 */

undefined4
_alert(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,undefined4 param_5,
      undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
      undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  char local_cc [200];
  
  _sprintf(local_cc,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12);
  _DoAlert(param_3,local_cc);
  return 0;
}

