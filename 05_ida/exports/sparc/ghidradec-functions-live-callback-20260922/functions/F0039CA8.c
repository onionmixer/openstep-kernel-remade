
/* WARNING: Removing unreachable block (ram,0xf0039d50) */
/* WARNING: Removing unreachable block (ram,0xf0039eb4) */
/* WARNING: Removing unreachable block (ram,0xf0039e68) */
/* WARNING: Removing unreachable block (ram,0xf0039de4) */
/* WARNING: Removing unreachable block (ram,0xf0039d70) */
/* WARNING: Removing unreachable block (ram,0xf0039ce4) */
/* WARNING: Removing unreachable block (ram,0xf0039d24) */
/* WARNING: Removing unreachable block (ram,0xf0039d9c) */
/* WARNING: Removing unreachable block (ram,0xf0039e18) */
/* WARNING: Removing unreachable block (ram,0xf0039e9c) */
/* WARNING: Removing unreachable block (ram,0xf0039eec) */
/* WARNING: Removing unreachable block (ram,0xf0039efc) */
/* WARNING: Removing unreachable block (ram,0xf0039cb4) */

undefined8 _exportfs(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cVar8;
  uint *puVar3;
  uint uVar4;
  word *pwVar5;
  int iVar6;
  sword *psVar7;
  undefined4 unaff_l0;
  int *piVar9;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar10;
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
  puVar10 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar2 = dword_F0133DDC;
  _suser();
  if (iVar2 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 1;
    goto locret_F0039F04;
  }
  uVar1 = *puVar10;
  _lookupname(uVar1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0039F04;
  (**(code **)(*(int *)(iVar2 + 0x1c) + 100))(iVar2,(undefined *)((int)register0x00000038 + -0x10));
  *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
  iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x24);
  _vn_rele();
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0039F04;
  if (puVar10[1] == 0) {
    cVar8 = (char)iVar2 + '\x14';
    _unexport();
    *(char *)(dword_F0133DDC + 0x38) = cVar8;
    puVar3 = *(uint **)((int)register0x00000038 + -0x10);
    iVar2 = *(word *)puVar3 + 2;
  }
  else {
    puVar3 = (uint *)0x30;
    _kalloc(0x30,*(undefined4 *)((int)register0x00000038 + -0x10));
    uVar4 = *(uint *)((int)register0x00000038 + -0x10);
    puVar3[8] = *(uint *)(iVar2 + 0x14);
    puVar3[9] = *(uint *)(iVar2 + 0x18);
    puVar3[10] = uVar4;
    uVar1 = puVar10[1];
    _copyin(uVar1,puVar3,0x20);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      if ((*puVar3 & 0xfffffffc) == 0) {
        if ((*puVar3 & 2) == 0) {
          uVar4 = puVar3[2];
        }
        else {
          cVar8 = (char)puVar3 + '\x18';
          _loadaddrs();
          *(char *)(dword_F0133DDC + 0x38) = cVar8;
          if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
            pwVar5 = (word *)puVar3[10];
            goto loc_F0039EE8;
          }
          uVar4 = puVar3[2];
        }
        if (uVar4 == 1) {
          cVar8 = (char)puVar3 + '\f';
          _loadaddrs();
        }
        else {
          cVar8 = '\x16';
        }
        *(char *)(dword_F0133DDC + 0x38) = cVar8;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          piVar9 = &_exported;
          iVar2 = _exported;
joined_r0xf0039e54:
          do {
            if (iVar2 == 0) goto loc_F0039ED8;
            iVar2 = *piVar9 + 0x20;
            _bcmp(iVar2,puVar3 + 8,8);
            iVar6 = *piVar9;
            if (iVar2 == 0) {
              if (**(sword **)(iVar6 + 0x28) == *(sword *)puVar3[10]) {
                psVar7 = *(sword **)(iVar6 + 0x28) + 1;
                _bcmp(psVar7,(sword *)puVar3[10] + 1);
                iVar6 = *piVar9;
                if (psVar7 == (sword *)0x0) {
                  *piVar9 = *(int *)(iVar6 + 0x2c);
                  _exportfree();
                  iVar2 = *piVar9;
                  goto joined_r0xf0039e54;
                }
              }
              else {
                iVar6 = *piVar9;
              }
            }
            piVar9 = (int *)(iVar6 + 0x2c);
            iVar2 = *piVar9;
          } while( true );
        }
        pwVar5 = (word *)puVar3[10];
      }
      else {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        pwVar5 = (word *)puVar3[10];
      }
    }
    else {
      pwVar5 = (word *)puVar3[10];
    }
loc_F0039EE8:
    _kfree(pwVar5,*pwVar5 + 2);
    iVar2 = 0x30;
  }
  _kfree(puVar3,iVar2);
locret_F0039F04:
  return CONCAT44(param_2,param_1);
loc_F0039ED8:
  puVar3[0xb] = 0;
  *piVar9 = (int)puVar3;
  goto locret_F0039F04;
}

