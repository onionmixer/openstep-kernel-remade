
/* WARNING: Removing unreachable block (ram,0xf00939d8) */
/* WARNING: Removing unreachable block (ram,0xf0093a68) */
/* WARNING: Removing unreachable block (ram,0xf009392c) */
/* WARNING: Removing unreachable block (ram,0xf0093960) */
/* WARNING: Removing unreachable block (ram,0xf00939ac) */
/* WARNING: Removing unreachable block (ram,0xf00938e4) */
/* WARNING: Removing unreachable block (ram,0xf009396c) */
/* WARNING: Removing unreachable block (ram,0xf0093954) */
/* WARNING: Removing unreachable block (ram,0xf0093a78) */
/* WARNING: Removing unreachable block (ram,0xf0093a08) */
/* WARNING: Removing unreachable block (ram,0xf00939c4) */
/* WARNING: Removing unreachable block (ram,0xf0093908) */

undefined8
FUN_f00938e4(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,char *param_6,char *param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  if (DAT_f0131251 == '\0') {
    _lock_init(&DAT_f0131254,1);
    DAT_f0131251 = '\x01';
  }
  if (DAT_f0112510 == 0) {
    puVar2 = (undefined4 *)0x64;
    _kalloc();
    puVar2[2] = param_1;
    *(short *)(puVar2 + 3) = (short)param_2;
    *(undefined2 *)((int)puVar2 + 0xe) = param_3;
    puVar2[4] = param_4;
    puVar2[5] = param_5;
    puVar2[0x18] = param_8;
    _strcpy((char *)(puVar2 + 6),param_6);
    _strcpy((char *)(puVar2 + 0x16),param_7);
    _lock_write(&DAT_f0131254);
    puVar1 = puVar2;
    if ((undefined **)PTR_LOOP_f0112524 != &PTR_LOOP_f0112520) {
      *(undefined4 **)PTR_LOOP_f0112524 = puVar2;
      puVar1 = (undefined4 *)PTR_LOOP_f0112520;
    }
    PTR_LOOP_f0112520 = (undefined *)puVar1;
    puVar2[1] = PTR_LOOP_f0112524;
    *puVar2 = &PTR_LOOP_f0112520;
    PTR_LOOP_f0112524 = (undefined *)puVar2;
    _lock_done(&DAT_f0131254);
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)0x4;
    if (param_1 == 0) {
      pvVar3 = (void *)0x84;
      _kalloc();
      _memcpy(pvVar3,&DAT_f0112534,0x70);
      *(undefined1 *)((int)pvVar3 + 3) = 1;
      *(undefined4 *)((int)pvVar3 + 4) = 0x84;
      *(undefined4 *)((int)pvVar3 + 0x1c) = param_5;
      *(undefined4 *)((int)pvVar3 + 0x20) = 0;
      *(undefined4 *)((int)pvVar3 + 0x28) = param_8;
      *(int *)((int)pvVar3 + 0x10) = DAT_f0112510;
      _strcpy((char *)((int)pvVar3 + 0x30),param_6);
      *(undefined1 *)((int)pvVar3 + 0x70) = 2;
      *(undefined1 *)((int)pvVar3 + 0x71) = 0x20;
      *(short *)((int)pvVar3 + 0x74) = (short)param_2;
      *(undefined2 *)((int)pvVar3 + 0x76) = param_3;
      *(undefined1 *)((int)pvVar3 + 0x78) = 8;
      *(undefined1 *)((int)pvVar3 + 0x79) = 8;
      *(uint *)((int)pvVar3 + 0x70) = *(uint *)((int)pvVar3 + 0x70) & 0xffff0009 | 0x28;
      *(uint *)((int)pvVar3 + 0x78) = *(uint *)((int)pvVar3 + 0x78) & 0xffff0009 | 0x68;
      _strcpy((char *)((int)pvVar3 + 0x7c),param_7);
      _msg_send_from_kernel(pvVar3,1,0);
    }
  }
  return CONCAT44(param_2,pvVar3);
}

