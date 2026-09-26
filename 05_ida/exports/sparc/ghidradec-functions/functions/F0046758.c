
/* WARNING: Removing unreachable block (ram,0xf004687c) */
/* WARNING: Removing unreachable block (ram,0xf004680c) */
/* WARNING: Removing unreachable block (ram,0xf00467c8) */
/* WARNING: Removing unreachable block (ram,0xf00467c0) */
/* WARNING: Removing unreachable block (ram,0xf00467f0) */
/* WARNING: Removing unreachable block (ram,0xf0046854) */
/* WARNING: Removing unreachable block (ram,0xf00468a0) */
/* WARNING: Removing unreachable block (ram,0xf00467a4) */

sqword sub_F0046758(int param_1,uint param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x30);
  if (param_3 < 2) {
    if ((param_2 & 1) == 0) {
      iVar2 = *(int *)(iVar3 + 0x74);
    }
    else {
      sVar1 = *(sword *)(iVar3 + 0x82);
      *(sword *)(iVar3 + 0x82) = sVar1 + -1;
      if (sVar1 == 1) {
        if ((*(word *)(iVar3 + 0x88) & 2) != 0) {
          *(word *)(iVar3 + 0x88) = *(word *)(iVar3 + 0x88) & 0xfffd;
          _wakeup(iVar3 + 0x80);
        }
        if (*(int *)(iVar3 + 0x78) == 0) {
          iVar2 = *(int *)(iVar3 + 0x74);
        }
        else {
          _selwakeup(*(int *)(iVar3 + 0x78),*(word *)(iVar3 + 0x88) & 0x10);
          _thread_deallocate(*(undefined4 *)(iVar3 + 0x78));
          *(undefined4 *)(iVar3 + 0x78) = 0;
          *(word *)(iVar3 + 0x88) = *(word *)(iVar3 + 0x88) & 0xffef;
          iVar2 = *(int *)(iVar3 + 0x74);
        }
      }
      else {
        iVar2 = *(int *)(iVar3 + 0x74);
      }
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x70);
    }
    else {
      _thread_deallocate();
      *(undefined4 *)(iVar3 + 0x74) = 0;
      iVar2 = *(int *)(iVar3 + 0x70);
    }
    if (iVar2 != 0) {
      _thread_deallocate();
      *(undefined4 *)(iVar3 + 0x70) = 0;
    }
    if ((param_2 & 2) == 0) {
      iVar2 = *(int *)(iVar3 + 0x80);
    }
    else {
      sVar1 = *(sword *)(iVar3 + 0x80);
      *(sword *)(iVar3 + 0x80) = sVar1 + -1;
      if (sVar1 == 1) {
        if ((*(word *)(iVar3 + 0x88) & 1) != 0) {
          *(word *)(iVar3 + 0x88) = *(word *)(iVar3 + 0x88) & 0xfffe;
          _wakeup(iVar3 + 0x82);
        }
        iVar2 = *(int *)(iVar3 + 0x80);
      }
      else {
        iVar2 = *(int *)(iVar3 + 0x80);
      }
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x68);
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar3 + 0x7c);
      }
      else {
        do {
          sub_F0047258();
        } while (iVar2 != 0);
        iVar2 = *(int *)(iVar3 + 0x7c);
      }
      if (iVar2 != 0) {
        _smark(iVar3,0x42);
      }
      *(undefined4 *)(iVar3 + 0x68) = 0;
      *(undefined2 *)(iVar3 + 0x86) = 0;
      *(undefined2 *)(iVar3 + 0x84) = 0;
      *(undefined4 *)(iVar3 + 0x7c) = 0;
    }
  }
  return (qword)param_2 << 0x20;
}
