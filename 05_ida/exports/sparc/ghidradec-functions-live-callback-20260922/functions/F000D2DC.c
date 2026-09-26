
/* WARNING: Removing unreachable block (ram,0xf000d594) */
/* WARNING: Removing unreachable block (ram,0xf000d574) */
/* WARNING: Removing unreachable block (ram,0xf000d5f8) */
/* WARNING: Removing unreachable block (ram,0xf000d50c) */
/* WARNING: Removing unreachable block (ram,0xf000d3b0) */
/* WARNING: Removing unreachable block (ram,0xf000d398) */
/* WARNING: Removing unreachable block (ram,0xf000d3a4) */
/* WARNING: Removing unreachable block (ram,0xf000d3b8) */
/* WARNING: Removing unreachable block (ram,0xf000d360) */

sqword _waitpgrp(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 unaff_l0;
  int iVar8;
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
  uVar1 = *(undefined4 *)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = uVar1;
  do {
    iVar5 = *_active_u;
    iVar8 = *(int *)(iVar5 + 0x48);
    iVar7 = *(int *)((int)register0x00000038 + -0x14);
    if (iVar8 != 0) {
      piVar6 = *(int **)((int)register0x00000038 + -0x10);
      do {
        if (*piVar6 == (int)*(sword *)(iVar8 + 0x2e)) {
          iVar7 = *(int *)(iVar8 + 0x68);
          *(int *)((int)register0x00000038 + -0x14) = *(int *)((int)register0x00000038 + -0x14) + 1;
          if (iVar7 == 0) {
            iVar5 = iVar8 + 0x34;
            *(int *)(dword_F0133DDC + 0x30) = (int)*(sword *)(iVar8 + 0x30);
            _copyout(iVar5,piVar6[1],4);
            *(char *)(dword_F0133DDC + 0x38) = (char)iVar5;
            if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
              *(undefined2 *)(iVar8 + 0x34) = 0;
              if (*(int *)(iVar8 + 0x38) != 0) {
                _ruadd(_active_u + 0x6d);
                _kfree(*(undefined4 *)(iVar8 + 0x38),0x48);
                *(undefined4 *)(iVar8 + 0x38) = 0;
              }
              _leavepgrp(iVar8);
              _delete_posix_proc(iVar8);
              *(undefined *)(iVar8 + 0x13) = 0;
              *(undefined2 *)(iVar8 + 0x30) = 0;
              iVar5 = *(int *)(iVar8 + 8);
              *(undefined2 *)(iVar8 + 0x32) = 0;
              **(int **)(iVar8 + 0xc) = iVar5;
              if (iVar5 != 0) {
                *(undefined4 *)(*(int *)(iVar8 + 8) + 0xc) = *(undefined4 *)(iVar8 + 0xc);
              }
              *(int *)(iVar8 + 8) = _freeproc;
              _freeproc = iVar8;
              if (*(int *)(iVar8 + 0x50) != 0) {
                *(undefined4 *)(*(int *)(iVar8 + 0x50) + 0x4c) = *(undefined4 *)(iVar8 + 0x4c);
              }
              if (*(int *)(iVar8 + 0x4c) == 0) {
                iVar5 = *(int *)(iVar8 + 0x44);
              }
              else {
                *(undefined4 *)(*(int *)(iVar8 + 0x4c) + 0x50) = *(undefined4 *)(iVar8 + 0x50);
                iVar5 = *(int *)(iVar8 + 0x44);
              }
              if (*(int *)(iVar5 + 0x48) == iVar8) {
                *(undefined4 *)(iVar5 + 0x48) = *(undefined4 *)(iVar8 + 0x4c);
                *(undefined4 *)(iVar8 + 0x44) = 0;
              }
              else {
                *(undefined4 *)(iVar8 + 0x44) = 0;
              }
              *(undefined4 *)(iVar8 + 0x50) = 0;
              *(undefined4 *)(iVar8 + 0x4c) = 0;
              *(undefined4 *)(iVar8 + 0x48) = 0;
              *(undefined4 *)(iVar8 + 0x18) = 0;
              *(undefined4 *)(iVar8 + 0x24) = 0;
              *(undefined4 *)(iVar8 + 0x20) = 0;
              *(undefined4 *)(iVar8 + 0x1c) = 0;
              *(undefined4 *)(iVar8 + 0x28) = 0;
              *(undefined *)(iVar8 + 0x17) = 0;
            }
            goto locret_F000D60C;
          }
          if (*(int *)(iVar7 + 0x44) < 1) {
            iVar8 = *(int *)(iVar8 + 0x4c);
          }
          else if (*(char *)(iVar8 + 0x13) == '\x06') {
            uVar4 = *(uint *)(iVar8 + 0x28);
            if ((uVar4 & 0x20) == 0) {
              if ((uVar4 & 0x10) == 0) {
                if ((piVar6[2] & 2U) == 0) {
                  iVar8 = *(int *)(iVar8 + 0x4c);
                  goto loc_F000D51C;
                }
                iVar7 = *(int *)(iVar8 + 0x7c);
              }
              else {
                iVar7 = *(int *)(iVar8 + 0x7c);
              }
              if ((iVar7 == 0) || (iVar7 == iVar5)) {
                *(uint *)(iVar8 + 0x28) = uVar4 | 0x20;
                *(int *)(dword_F0133DDC + 0x30) = (int)*(sword *)(iVar8 + 0x30);
                iVar5 = (int)*(char *)(iVar8 + 0x17);
                if (iVar5 == 0) {
                  iVar5 = *(int *)(iVar8 + 0x3c);
                }
                *(uint *)((int)register0x00000038 + -0xc) = iVar5 << 8 | 0x7f;
                puVar2 = (undefined *)((int)register0x00000038 + -0xc);
                _copyout(puVar2,*(undefined4 *)(*(int *)((int)register0x00000038 + -0x10) + 4),4);
                uVar3 = SUB41(puVar2,0);
                goto loc_F000D580;
              }
              iVar8 = *(int *)(iVar8 + 0x4c);
            }
            else {
              iVar8 = *(int *)(iVar8 + 0x4c);
            }
          }
          else {
            iVar8 = *(int *)(iVar8 + 0x4c);
          }
        }
        else {
          iVar8 = *(int *)(iVar8 + 0x4c);
        }
loc_F000D51C:
        piVar6 = *(int **)((int)register0x00000038 + -0x10);
      } while (iVar8 != 0);
      iVar7 = *(int *)((int)register0x00000038 + -0x14);
    }
    iVar5 = *(int *)((int)register0x00000038 + -0x10);
    if (iVar7 == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 10;
      goto locret_F000D60C;
    }
    if ((*(uint *)(iVar5 + 8) & 1) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
      puVar2 = (undefined *)((int)register0x00000038 + -0xc);
      _copyout(puVar2,*(undefined4 *)(iVar5 + 4),4);
      uVar3 = SUB41(puVar2,0);
loc_F000D580:
      *(undefined *)(dword_F0133DDC + 0x38) = uVar3;
      goto locret_F000D60C;
    }
    iVar5 = dword_F0133DDC + 0x28;
    _setjmp();
    if (iVar5 != 0) {
      if ((_active_u[0x4f] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) == 0) {
        *(undefined *)(dword_F0133DDC + 0x39) = 2;
      }
      else {
        *(undefined *)(dword_F0133DDC + 0x38) = 4;
      }
locret_F000D60C:
      return (qword)param_2 << 0x20;
    }
    _sleep(*_active_u,0x1e);
  } while( true );
}

