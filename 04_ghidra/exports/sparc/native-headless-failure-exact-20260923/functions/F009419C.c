
/* WARNING: Removing unreachable block (ram,0xf00941f4) */
/* WARNING: Removing unreachable block (ram,0xf00941c8) */
/* WARNING: Removing unreachable block (ram,0xf009419c) */
/* WARNING: Removing unreachable block (ram,0xf009422c) */
/* WARNING: Removing unreachable block (ram,0xf00941b4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _vol_start_thread(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_c [12];
  
  iVar2 = *(int *)(_kernel_task + 0x88);
  _ipc_port_alloc(iVar2,auStack_c,&DAT_f0112518);
  iVar1 = _kernel_task;
  if (iVar2 == 0) {
    DAT_f011251c = DAT_f0112518[4];
    *DAT_f0112518 = 0;
    _kernel_thread(iVar1,FUN_f0093f7c,0);
    _DAT_f011252c = &PTR_LOOP_f0112528;
    PTR_LOOP_f0112528 = (undefined *)&PTR_LOOP_f0112528;
    DAT_f0112530 = 1;
    if (DAT_f0131251 == '\0') {
      _lock_init(&DAT_f0131254);
      DAT_f0131251 = '\x01';
    }
  }
  else {
    _printf(s_vol_start_thread__port_alloc_ret_f0112850,iVar2);
  }
  return CONCAT44(param_2,param_1);
}

