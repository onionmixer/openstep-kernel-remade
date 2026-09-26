/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011771c */

ssize_t _recvfrom(int param_1,void *param_2,size_t param_3,int param_4,sockaddr *param_5,
                 socklen_t *param_6)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 *local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  if (puVar1[5] != 0) {
    uVar2 = _copyin(puVar1[5],&local_20,4);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  }
  iVar3 = DAT_001e875c;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    local_1c = puVar1[4];
    local_18 = local_20;
    local_14 = &local_28;
    local_10 = 1;
    local_28 = puVar1[1];
    local_24 = puVar1[2];
    local_c = 0;
    local_8 = 0;
    iVar3 = _recvit(*puVar1,&local_1c,puVar1[3],puVar1[5],0);
  }
  return iVar3;
}

