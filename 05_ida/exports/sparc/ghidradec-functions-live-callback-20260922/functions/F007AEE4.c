
/* WARNING: Removing unreachable block (ram,0xf007b0a0) */
/* WARNING: Removing unreachable block (ram,0xf007b084) */
/* WARNING: Removing unreachable block (ram,0xf007b00c) */
/* WARNING: Removing unreachable block (ram,0xf007aff0) */
/* WARNING: Removing unreachable block (ram,0xf007afcc) */
/* WARNING: Removing unreachable block (ram,0xf007afa8) */
/* WARNING: Removing unreachable block (ram,0xf007af84) */
/* WARNING: Removing unreachable block (ram,0xf007af5c) */
/* WARNING: Removing unreachable block (ram,0xf007af38) */
/* WARNING: Removing unreachable block (ram,0xf007af24) */
/* WARNING: Removing unreachable block (ram,0xf007af48) */
/* WARNING: Removing unreachable block (ram,0xf007af6c) */
/* WARNING: Removing unreachable block (ram,0xf007af98) */
/* WARNING: Removing unreachable block (ram,0xf007afbc) */
/* WARNING: Removing unreachable block (ram,0xf007afe0) */
/* WARNING: Removing unreachable block (ram,0xf007b004) */
/* WARNING: Removing unreachable block (ram,0xf007b050) */
/* WARNING: Removing unreachable block (ram,0xf007b0b0) */
/* WARNING: Removing unreachable block (ram,0xf007b064) */
/* WARNING: Removing unreachable block (ram,0xf007af0c) */

void _notify_server_loop(void)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x50) = 1;
  iVar2 = *(int *)(_active_threads + 0xc);
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_allocate(iVar1,&unk_F0130F48);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  _get_kern_port(iVar2,unk_F0130F48,&dword_F0130F4C);
  iVar1 = iVar2;
  _task_set_special_port(iVar2,2,dword_F0130F4C);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_allocate(iVar1,&_pn_register_port);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  _get_kern_port(iVar2,_pn_register_port,&_pn_register_port_k);
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_set_allocate(iVar1,&unk_F0130F50);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_set_add(iVar1,unk_F0130F50,unk_F0130F48);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = *(int *)(iVar2 + 0x88);
  _port_set_add(iVar1,unk_F0130F50,_pn_register_port);
  if (iVar1 != 0) {
    sub_F007B0C8();
  }
  iVar1 = 0x2000;
  _kalloc();
  dword_F0130F58 = &dword_F0130F54;
  dword_F0130F54 = &dword_F0130F54;
  *(undefined4 *)(iVar1 + 4) = 0x2000;
  do {
    while( true ) {
      while( true ) {
        *(undefined4 *)(iVar1 + 0xc) = unk_F0130F50;
        iVar2 = iVar1;
        _msg_receive(iVar1,0,0);
        if (iVar2 == 0) break;
        _printf(aNotifyServerLo,iVar2);
        *(undefined4 *)(iVar1 + 4) = 0x2000;
      }
      if (*(int *)(iVar1 + 0xc) == _pn_register_port) break;
      if (*(int *)(iVar1 + 0xc) == unk_F0130F48) {
        sub_F007B17C(iVar1);
        *(undefined4 *)(iVar1 + 4) = 0x2000;
      }
      else {
        _printf(aNotifyServerLo_0);
        *(undefined4 *)(iVar1 + 4) = 0x2000;
      }
    }
    sub_F007B0F4(iVar1);
    *(undefined4 *)(iVar1 + 4) = 0x2000;
  } while( true );
}

