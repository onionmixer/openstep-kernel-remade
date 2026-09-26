/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016cf28 */

void FUN_0016cf28(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 local_c [4];
  undefined4 local_8;
  
  uVar3 = (param_1[10] - param_1[9]) + _page_mask & ~_page_mask;
  uVar2 = _splhigh();
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  iVar1 = param_1[6];
  param_1[6] = 0;
  LOCK();
  *param_1 = 0;
  UNLOCK();
  _splx(uVar2);
  if (iVar1 != 0) {
    _vm_read_EXTERNAL(param_1[0x133],param_1[9],uVar3,&local_8,local_c);
    _kern_serv_log_data(iVar1,local_8,param_1[10] - param_1[9] >> 5);
    _port_deallocate_EXTERNAL(param_1[2],iVar1);
    _vm_deallocate_EXTERNAL(param_1[2],local_8,uVar3);
    uVar2 = _splhigh();
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_1[10] = param_1[9];
    LOCK();
    *param_1 = 0;
    UNLOCK();
    _splx(uVar2);
  }
  return;
}

