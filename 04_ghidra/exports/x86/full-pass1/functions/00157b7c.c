/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157b7c */

kern_return_t _host_kernel_version(host_t host,char *kernel_version)

{
  if (host != 0) {
    _strncpy(kernel_version,_version,0x200);
    return 0;
  }
  return 4;
}

