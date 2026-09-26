/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e4b4 */

undefined4 __io_host_priv_self(void)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  uVar1 = DAT_001e97b4;
  _port_reference(DAT_001e97b4);
  _object_copyout(*(undefined4 *)(_active_threads + 0xc),uVar1,6,&local_8);
  return local_8;
}

