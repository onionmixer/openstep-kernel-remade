
/* WARNING: Removing unreachable block (ram,0xf001bc44) */
/* WARNING: Removing unreachable block (ram,0xf001bc20) */
/* WARNING: Removing unreachable block (ram,0xf001bba8) */
/* WARNING: Removing unreachable block (ram,0xf001bad0) */
/* WARNING: Removing unreachable block (ram,0xf001ba6c) */
/* WARNING: Removing unreachable block (ram,0xf001ba5c) */
/* WARNING: Removing unreachable block (ram,0xf001baa0) */
/* WARNING: Removing unreachable block (ram,0xf001bb6c) */
/* WARNING: Removing unreachable block (ram,0xf001bbc0) */
/* WARNING: Removing unreachable block (ram,0xf001bc3c) */
/* WARNING: Removing unreachable block (ram,0xf001bb50) */
/* WARNING: Removing unreachable block (ram,0xf001ba08) */

undefined8 _ptcread(uint param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  uint *puVar7;
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
  iVar6 = (param_1 & 0xff) * 0x10;
  iVar5 = *(int *)(DAT_f012f20c + iVar6);
  puVar7 = *(uint **)(DAT_f012f20c + iVar6 + 4);
  uVar1 = *(uint *)(iVar5 + 0x40);
  while( true ) {
    if ((uVar1 & 4) != 0) {
      uVar1 = *puVar7;
      if ((uVar1 & 8) != 0) {
        puVar2 = (undefined *)(uint)*(byte *)(puVar7 + 3);
        if (puVar2 != (undefined *)0x0) {
          _ureadc(puVar2,param_2);
          if (puVar2 == (undefined *)0x0) {
            if ((puVar7[3] & 0x40000000) == 0) {
              *(undefined *)(puVar7 + 3) = 0;
            }
            else {
              *(undefined *)((int)register0x00000038 + -0x90) = *(undefined *)(iVar5 + 0x49);
              *(undefined *)((int)register0x00000038 + -0x8f) = *(undefined *)(iVar5 + 0x4a);
              *(undefined *)((int)register0x00000038 + -0x8e) = *(undefined *)(iVar5 + 0x4d);
              *(undefined *)((int)register0x00000038 + -0x8d) = *(undefined *)(iVar5 + 0x4e);
              *(sword *)((int)register0x00000038 + -0x8c) = (sword)*(undefined4 *)(iVar5 + 0x3c);
              _bcopy(iVar5 + 0x4f,(undefined *)((int)register0x00000038 + -0x8a),6);
              _bcopy(iVar5 + 0x55,(undefined *)((int)register0x00000038 + -0x84),6);
              *(undefined4 *)((int)register0x00000038 + -0x7c) = *(undefined4 *)(iVar5 + 0x40);
              *(uint *)((int)register0x00000038 + -0x78) = (uint)*(word *)(iVar5 + 0x3c);
              uVar1 = 0x1c;
              if (*(uint *)(param_2 + 0x14) < 0x1c) {
                uVar1 = *(uint *)(param_2 + 0x14);
              }
              _uiomove((undefined *)((int)register0x00000038 + -0x90),uVar1,0,param_2);
              *(undefined *)(puVar7 + 3) = 0;
            }
            puVar2 = (undefined *)0x0;
          }
          goto locret_F001BC64;
        }
        uVar1 = *puVar7;
      }
      if ((uVar1 & 0x80) == 0) {
        iVar6 = *(int *)(iVar5 + 0x18);
      }
      else {
        puVar2 = (undefined *)(uint)*(byte *)((int)puVar7 + 0xd);
        if (puVar2 != (undefined *)0x0) {
          _ureadc(puVar2,param_2);
          if (puVar2 == (undefined *)0x0) {
            *(undefined *)((int)puVar7 + 0xd) = 0;
            puVar2 = (undefined *)0x0;
          }
          goto locret_F001BC64;
        }
        iVar6 = *(int *)(iVar5 + 0x18);
      }
      uVar1 = *(uint *)(iVar5 + 0x40);
      if ((iVar6 != 0) && ((uVar1 & 0x100) == 0)) {
        puVar3 = (undefined *)0x0;
        puVar2 = (undefined *)0x0;
        if ((*puVar7 & 0x88) != 0) {
          _ureadc(0,param_2);
          puVar2 = puVar3;
        }
        iVar6 = *(int *)(param_2 + 0x14);
        if ((iVar6 < 1) || (puVar2 != (undefined *)0x0)) goto loc_F001BBE8;
        puVar3 = (undefined *)((int)register0x00000038 + -0x70);
        goto loc_F001BB9C;
      }
    }
    if ((uVar1 & 0x10) == 0) {
      puVar2 = (undefined *)0x5;
      goto locret_F001BC64;
    }
    if ((*puVar7 & 4) != 0) break;
    _sleep(iVar5 + 0x1c,0x1c);
    uVar1 = *(uint *)(iVar5 + 0x40);
  }
  puVar2 = (undefined *)0x23;
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
    puVar2 = (undefined *)0xb;
  }
locret_F001BC64:
  return CONCAT44(param_2,puVar2);
loc_F001BB9C:
  if (100 < iVar6) {
    iVar6 = 100;
  }
  iVar4 = iVar5 + 0x18;
  _q_to_b(iVar5 + 0x18,puVar3,iVar6);
  if (iVar4 < 1) goto loc_F001BBE8;
  puVar2 = puVar3;
  _uiomove(puVar3,iVar4,0,param_2);
  iVar6 = *(int *)(param_2 + 0x14);
  if ((iVar6 < 1) || (puVar2 != (undefined *)0x0)) goto loc_F001BBE8;
  goto loc_F001BB9C;
loc_F001BBE8:
  if (*(int *)(iVar5 + 0x18) <= (int)*(sword *)(_ttlowat + (*(byte *)(iVar5 + 0x4a) & 0x1f) * 2)) {
    if ((*(uint *)(iVar5 + 0x40) & 0x40) != 0) {
      *(uint *)(iVar5 + 0x40) = *(uint *)(iVar5 + 0x40) & 0xffffffbf;
      _wakeup(iVar5 + 0x18);
    }
    if (*(int *)(iVar5 + 0x2c) != 0) {
      _selwakeup(*(int *)(iVar5 + 0x2c),*(uint *)(iVar5 + 0x40) & 0x1000);
      _thread_deallocate(*(undefined4 *)(iVar5 + 0x2c));
      *(undefined4 *)(iVar5 + 0x2c) = 0;
      *(uint *)(iVar5 + 0x40) = *(uint *)(iVar5 + 0x40) & 0xffffefff;
    }
  }
  goto locret_F001BC64;
}
