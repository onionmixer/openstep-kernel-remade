/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117448 */

ssize_t _sendto(int param_1,void *param_2,size_t param_3,int param_4,sockaddr *param_5,
               socklen_t param_6)

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
  local_1c = puVar1[4];
  local_18 = puVar1[5];
  local_14 = &local_24;
  local_10 = 1;
  local_24 = puVar1[1];
  local_20 = puVar1[2];
  local_c = 0;
  local_8 = 0;
  sVar2 = _sendit(*puVar1,&local_1c,puVar1[3]);
  return sVar2;
}

