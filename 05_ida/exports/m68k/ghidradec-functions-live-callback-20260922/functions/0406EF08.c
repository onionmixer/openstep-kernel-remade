
void sub_406EF08(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = _disk_eject_q;
  if (((undefined4 **)_disk_eject_q != &_disk_eject_q) &&
     (iVar2 = *(int *)(_disk_eject_q[3] + 8), (&DAT_40c370c)[iVar2 * 10] == 0)) {
    puVar1 = (undefined4 *)*_disk_eject_q;
    puVar3 = (undefined4 *)_disk_eject_q[1];
    puVar6 = puVar3;
    if ((undefined4 **)puVar1 != &_disk_eject_q) {
      puVar1[1] = puVar3;
      puVar6 = dword_40C3764;
    }
    dword_40C3764 = puVar6;
    *puVar3 = puVar1;
    iVar4 = (&dword_40C3708)[iVar2 * 10];
    if ((iVar4 != 0) && (*(int *)(iVar4 + 4) == 0)) {
      if (*(sword *)(iVar4 + 0x128) != 0) {
        _update(*(int *)(iVar4 + 0x10) << 3 | _fd_blk_major << 8,0xfffffff8);
      }
      _fd_basic_cmd(iVar4,2);
      if ((*(sword *)(iVar4 + 0x128) == 0) && ((*(byte *)(iVar4 + 0x127) & 4) == 0)) {
        _fd_free_fv(iVar4);
      }
    }
    (&DAT_40c370c)[iVar2 * 10] = puVar5[3];
    sub_406EFD6(puVar5[3],0);
    _kfree(puVar5,0x10);
  }
  return;
}

