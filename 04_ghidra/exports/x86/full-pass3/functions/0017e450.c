/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e450 */

undefined4 __io_convert_port_in(undefined4 param_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = _object_copyin(*(undefined4 *)(_active_threads + 0xc),param_1,6,0,&local_8);
  if (iVar1 != 0) {
    return local_8;
  }
  return 0;
}

