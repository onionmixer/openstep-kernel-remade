/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cec30 */

char * _getsectdatafromheaderinfo(undefined4 *param_1,char *param_2,char *param_3,uint32_t *param_4)

{
  char *pcVar1;
  
  pcVar1 = _getsectdatafromheader((mach_header *)*param_1,param_2,param_3,param_4);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = pcVar1 + param_1[4];
  }
  return pcVar1;
}

