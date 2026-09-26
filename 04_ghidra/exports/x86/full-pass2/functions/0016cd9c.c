/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016cd9c */

undefined4 _kern_serv_get_log(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_c [4];
  undefined4 local_8;
  
  piVar1 = (int *)*param_1;
  if (piVar1[0xc] == 0) {
    _port_deallocate_EXTERNAL(piVar1[2],param_2);
    uVar3 = 0x65;
  }
  else {
    iVar2 = piVar1[9];
    if (piVar1[10] == iVar2) {
      piVar1[6] = param_2;
      uVar3 = 0;
    }
    else {
      uVar4 = (piVar1[10] - iVar2) + _page_mask & ~_page_mask;
      _vm_read_EXTERNAL(piVar1[0x133],iVar2,uVar4,&local_8,local_c);
      _kern_serv_log_data(param_2,local_8,piVar1[10] - piVar1[9] >> 5);
      _port_deallocate_EXTERNAL(piVar1[2],param_2);
      _vm_deallocate_EXTERNAL(piVar1[2],local_8,uVar4);
      uVar3 = _splhigh();
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      piVar1[10] = piVar1[9];
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      _splx(uVar3);
      uVar3 = 0;
    }
  }
  return uVar3;
}

