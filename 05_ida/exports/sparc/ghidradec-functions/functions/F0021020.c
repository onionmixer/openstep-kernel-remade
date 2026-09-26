
/* WARNING: Removing unreachable block (ram,0xf0021264) */
/* WARNING: Removing unreachable block (ram,0xf002124c) */
/* WARNING: Removing unreachable block (ram,0xf0021208) */
/* WARNING: Removing unreachable block (ram,0xf00211a4) */
/* WARNING: Removing unreachable block (ram,0xf0021118) */
/* WARNING: Removing unreachable block (ram,0xf002108c) */
/* WARNING: Removing unreachable block (ram,0xf002106c) */
/* WARNING: Removing unreachable block (ram,0xf00210a0) */
/* WARNING: Removing unreachable block (ram,0xf0021164) */
/* WARNING: Removing unreachable block (ram,0xf00211bc) */
/* WARNING: Removing unreachable block (ram,0xf0021218) */
/* WARNING: Removing unreachable block (ram,0xf002125c) */
/* WARNING: Removing unreachable block (ram,0xf0021270) */
/* WARNING: Removing unreachable block (ram,0xf0021044) */

undefined8 _accept(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  sword sVar3;
  undefined *puVar2;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int *piVar5;
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
  bool bVar6;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  if (piVar5[1] != 0) {
    iVar1 = piVar5[2];
    _copyin(iVar1,(undefined *)((int)register0x00000038 + -0xc),4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0021278;
    iVar1 = piVar5[1];
    _useracc(iVar1,*(undefined4 *)((int)register0x00000038 + -0xc),0);
    if (iVar1 == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
      goto locret_F0021278;
    }
  }
  iVar1 = *piVar5;
  _getsock();
  if (iVar1 != 0) {
    _splnet();
    iVar1 = *(int *)(iVar1 + 0x18);
    if ((*(word *)(iVar1 + 2) & 2) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    }
    else {
      sVar3 = *(sword *)(iVar1 + 0x20);
      if ((*(word *)(iVar1 + 6) & 0x100) == 0) goto loc_F0021124;
      bVar6 = sVar3 == 0;
      if (bVar6) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x23;
      }
      else {
        while (bVar6) {
          if (*(sword *)(iVar1 + 0x56) != 0) {
loc_F0021140:
            sVar3 = *(sword *)(iVar1 + 0x56);
            goto loc_F0021144;
          }
          if ((*(word *)(iVar1 + 6) & 0x20) != 0) {
            *(undefined2 *)(iVar1 + 0x56) = 0x35;
            goto loc_F0021140;
          }
          _sleep(iVar1 + 0x54,0x1a);
          sVar3 = *(sword *)(iVar1 + 0x20);
loc_F0021124:
          bVar6 = sVar3 == 0;
        }
        sVar3 = *(sword *)(iVar1 + 0x56);
loc_F0021144:
        puVar2 = DAT_f0133c00;
        if (sVar3 == 0) {
          _falloc();
          if (puVar2 == (undefined *)0x0) {
            *(undefined4 *)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) = 0;
          }
          else {
            iVar4 = *(int *)(iVar1 + 0x1c);
            iVar1 = iVar4;
            _soqremque(iVar4,1);
            if (iVar1 == 0) {
              _panic(&aAccept);
            }
            *(undefined2 *)(puVar2 + 0xc) = 2;
            *(undefined4 *)(puVar2 + 8) = 3;
            *(undefined **)(puVar2 + 0x14) = _socketops;
            *(int *)(puVar2 + 0x18) = iVar4;
            iVar1 = 1;
            *(undefined **)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) =
                 puVar2;
            _m_get(1,8);
            _soaccept(iVar4,iVar1);
            if (piVar5[1] != 0) {
              if ((int)*(sword *)(iVar1 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
                *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar1 + 8);
              }
              _copyout(iVar1 + *(int *)(iVar1 + 4),piVar5[1],
                       *(undefined4 *)((int)register0x00000038 + -0xc));
              _copyout((undefined *)((int)register0x00000038 + -0xc),piVar5[2],4);
            }
            _m_freem(iVar1);
          }
        }
        else {
          *(char *)(dword_F0133DDC + 0x38) = (char)sVar3;
          *(undefined2 *)(iVar1 + 0x56) = 0;
        }
      }
    }
    _splx();
  }
locret_F0021278:
  return CONCAT44(param_2,param_1);
}
