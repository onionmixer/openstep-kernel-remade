
/* WARNING: Removing unreachable block (ram,0xf009402c) */
/* WARNING: Removing unreachable block (ram,0xf009401c) */
/* WARNING: Removing unreachable block (ram,0xf0093fac) */
/* WARNING: Removing unreachable block (ram,0xf0093fe4) */
/* WARNING: Removing unreachable block (ram,0xf009403c) */
/* WARNING: Removing unreachable block (ram,0xf0093fc0) */
/* WARNING: Removing unreachable block (ram,0xf0093f80) */

void sub_F0093F7C(void)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = 0x2000;
  _kalloc();
  *(undefined4 *)(iVar1 + 4) = 0x2000;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          *(undefined4 *)(iVar1 + 0xc) = dword_F011251C;
          iVar2 = iVar1;
          _msg_receive(iVar1,0,0);
          if (iVar2 == 0) break;
          _printf(DAT_f01127f8,iVar2);
          *(undefined4 *)(iVar1 + 4) = 0x2000;
        }
        if (*(int *)(iVar1 + 0x14) != 0x41) break;
        sub_F00940D4(iVar1);
        *(undefined4 *)(iVar1 + 4) = 0x2000;
      }
      if (*(int *)(iVar1 + 0x14) == 0x357) break;
      _printf(0xf0112820);
      *(undefined4 *)(iVar1 + 4) = 0x2000;
    }
    iVar2 = *(int *)(iVar1 + 0x1c);
    sub_F0094054();
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 4) = 0x2000;
    }
    else {
      if (*(code **)(iVar2 + 0xc) != (code *)0x0) {
        (**(code **)(iVar2 + 0xc))
                  (*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 8),
                   *(undefined4 *)(iVar1 + 0x20));
      }
      _kfree(iVar2,0x14);
      *(undefined4 *)(iVar1 + 4) = 0x2000;
    }
  } while( true );
}

