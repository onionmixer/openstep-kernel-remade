
/* WARNING: Removing unreachable block (ram,0xf0081028) */
/* WARNING: Removing unreachable block (ram,0xf0080ff8) */
/* WARNING: Removing unreachable block (ram,0xf0080fac) */
/* WARNING: Removing unreachable block (ram,0xf0080f88) */
/* WARNING: Removing unreachable block (ram,0xf0080f50) */
/* WARNING: Removing unreachable block (ram,0xf0080f2c) */
/* WARNING: Removing unreachable block (ram,0xf0080f0c) */
/* WARNING: Removing unreachable block (ram,0xf0080ee0) */
/* WARNING: Removing unreachable block (ram,0xf0080ef8) */
/* WARNING: Removing unreachable block (ram,0xf0080f18) */
/* WARNING: Removing unreachable block (ram,0xf0080f3c) */
/* WARNING: Removing unreachable block (ram,0xf0080f70) */
/* WARNING: Removing unreachable block (ram,0xf0080f98) */
/* WARNING: Removing unreachable block (ram,0xf0080fdc) */
/* WARNING: Removing unreachable block (ram,0xf0081010) */
/* WARNING: Removing unreachable block (ram,0xf0081040) */
/* WARNING: Removing unreachable block (ram,0xf0080eb8) */

void sub_F0080EA4(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar4 = *(int *)(_active_threads + 0xc);
  iVar1 = 1;
  *(undefined4 *)(iVar4 + 0x50) = 1;
  _task_self();
  dword_F0130F60 = iVar1;
  do {
    do {
    } while (dword_F0130F5C != 0);
    puVar2 = &dword_F0130F5C;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  iVar1 = dword_F0130F60;
  _port_set_allocate_EXTERNAL(dword_F0130F60,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 != 0) {
    _panic(aUxHandlerPortS);
  }
  iVar1 = dword_F0130F60;
  _port_allocate_EXTERNAL(dword_F0130F60,(undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 != 0) {
    _panic(aUxHandlerPortA);
  }
  iVar1 = dword_F0130F60;
  _port_set_add_EXTERNAL
            (dword_F0130F60,*(undefined4 *)((int)register0x00000038 + -0xc),
             *(undefined4 *)((int)register0x00000038 + -0x10));
  if (iVar1 != 0) {
    _panic(aUxHandlerPortS_0);
  }
  _object_copyin(iVar4,*(undefined4 *)((int)register0x00000038 + -0x10),6,0,&_ux_exception_port);
  if (iVar4 == 0) {
    _panic(aUxHandlerObjec);
  }
  _thread_wakeup_prim(&_ux_exception_port,0,0);
  dword_F0130F5C = 0;
  _task_name(aUxExcept);
  puVar5 = (undefined *)((int)register0x00000038 + -0x90);
  *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
  do {
    while( true ) {
      *(undefined4 *)((int)register0x00000038 + -0x84) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      puVar3 = puVar5;
      _msg_receive(puVar5,0,0);
      if (puVar3 == (undefined *)0x0) break;
      if (puVar3 == (undefined *)0xffffff34) {
        *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
      }
      else {
        _panic(aExceptionHandl_0);
        *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
      }
    }
    iVar1 = *(int *)((int)register0x00000038 + -0x80);
    puVar3 = puVar5;
    _exc_server(puVar5,(undefined *)((int)register0x00000038 + -0x38));
    if (puVar3 != (undefined *)0x0) {
      _msg_send((undefined *)((int)register0x00000038 + -0x38),0,0);
    }
    if (iVar1 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
    }
    else {
      _port_deallocate_EXTERNAL(dword_F0130F60,iVar1);
      *(undefined4 *)((int)register0x00000038 + -0x8c) = 0x58;
    }
  } while( true );
}
