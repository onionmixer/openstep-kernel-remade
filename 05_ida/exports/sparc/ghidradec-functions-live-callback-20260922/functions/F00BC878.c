
/* WARNING: Removing unreachable block (ram,0xf00bc928) */

undefined8 _DoRestore(undefined4 param_1,undefined4 param_2)

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
  iVar3 = 0;
  if (_kmId != 0) {
    (*dword_F0132068)(*(undefined4 *)(_kmId + 0x108),paLock);
    iVar1 = _kmId;
    if (*(int *)(_kmId + 0x114) == 3) {
      if (*(int *)(_kmId + 0x11c) == 0) {
        iVar3 = 0x10;
      }
      else {
        iVar2 = *(int *)(_kmId + 0x11c) + -1;
        *(int *)(_kmId + 0x11c) = iVar2;
        if (iVar2 == 0) {
          *(int *)(iVar1 + 0x114) = *(int *)(iVar1 + 0x118);
          if (*(int *)(iVar1 + 0x118) == 3) {
            _IOLog(aKmdeviceRecurs);
          }
          else {
            iVar3 = *(int *)(iVar1 + 0x110);
            (**(code **)(iVar3 + 8))();
            (*(code *)**(undefined4 **)(_kmId + 0x110))(*(undefined4 **)(_kmId + 0x110));
            *(undefined4 *)(_kmId + 0x110) = 0;
          }
        }
      }
    }
    else {
      iVar3 = 0x16;
    }
    (*dword_F013206C)(*(undefined4 *)(_kmId + 0x108),paUnlock);
  }
  return CONCAT44(param_2,iVar3);
}

