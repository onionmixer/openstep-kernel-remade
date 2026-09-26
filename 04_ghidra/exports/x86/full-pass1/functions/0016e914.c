/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e914 */

void FUN_0016e914(int *param_1,int param_2)

{
  host_t host;
  kern_return_t kVar1;
  char *kernel_version;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    kernel_version = (char *)(param_2 + 0x2c);
    host = _convert_port_to_host(param_1[2]);
    kVar1 = _host_kernel_version(host,kernel_version);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    if (kVar1 == 0) {
      *(undefined4 *)(param_2 + 4) = 0x22c;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e015c;
      *(undefined4 *)(param_2 + 0x24) = DAT_001e0160;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e0164;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

