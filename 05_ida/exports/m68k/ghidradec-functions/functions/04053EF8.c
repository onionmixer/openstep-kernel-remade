
void _calloutInitialize(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  if (dword_40AFF2C == 0) {
    dword_40B4DC4 = &dword_40B4DC0;
    dword_40B4DC0 = &dword_40B4DC0;
    dword_40B4DCC = &dword_40B4DC8;
    dword_40B4DC8 = &dword_40B4DC8;
    dword_40B4DBC = &dword_40B4DB8;
    dword_40B4DB8 = &dword_40B4DB8;
    puVar3 = unk_40B45B8;
    puVar1 = &unk_40B45B4;
    do {
      puVar2 = puVar1;
      *puVar2 = &dword_40B4DB8;
      *(undefined4 **)puVar3 = dword_40B4DBC;
      **(undefined4 **)puVar3 = puVar2;
      puVar3 = (undefined *)((int)puVar3 + 0x20);
      puVar1 = puVar2 + 8;
      dword_40B4DBC = puVar2;
    } while (puVar2 + 8 < unk_40B45B8 + 0x7fc);
    _kernel_thread(_kernel_task,&loc_4054964,0);
    _set_timer_expire_func(0,sub_405497E);
    dword_40AFF2C = 1;
  }
  return;
}
