/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134f94 */

undefined4 * _authkern_create(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x28);
  _bzero(puVar1,0x28);
  puVar1[8] = &PTR__authkern_nextverf_001dcd88;
  *puVar1 = 1;
  puVar1[3] = __null_auth;
  puVar1[4] = DAT_001ef1b4;
  puVar1[5] = DAT_001ef1b8;
  return puVar1;
}

