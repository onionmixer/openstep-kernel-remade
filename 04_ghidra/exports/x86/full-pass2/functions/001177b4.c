/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001177b4 */

ssize_t _recv(int param_1,void *param_2,size_t param_3,int param_4)

{
  undefined4 *puVar1;
  ssize_t sVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 *local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  local_1c = 0;
  local_18 = 0;
  local_14 = &local_24;
  local_10 = 1;
  local_24 = puVar1[1];
  local_20 = puVar1[2];
  local_c = 0;
  local_8 = 0;
  sVar2 = _recvit(*puVar1,&local_1c,puVar1[3],0,0);
  return sVar2;
}

