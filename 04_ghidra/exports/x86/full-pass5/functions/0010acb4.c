/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010acb4 */

int _adjtime(timeval *param_1,timeval *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar2 = _suser();
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = _copyin(*puVar1,&local_c,8);
    *(char *)(DAT_001e875c + 0x68) = (char)iVar3;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar3 = _host_adjust_time(DAT_001e97b4,local_c,local_8,&local_14);
      if (puVar1[1] != 0) {
        local_1c = local_14;
        local_18 = local_10;
        iVar3 = _copyout(&local_1c,puVar1[1],8);
      }
    }
  }
  return iVar3;
}

