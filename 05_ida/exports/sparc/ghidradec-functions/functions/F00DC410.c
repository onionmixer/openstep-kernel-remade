
/* WARNING: Removing unreachable block (ram,0xf00dc4fc) */
/* WARNING: Removing unreachable block (ram,0xf00dc614) */
/* WARNING: Removing unreachable block (ram,0xf00dc57c) */
/* WARNING: Removing unreachable block (ram,0xf00dc54c) */
/* WARNING: Removing unreachable block (ram,0xf00dc4d8) */
/* WARNING: Removing unreachable block (ram,0xf00dc498) */
/* WARNING: Removing unreachable block (ram,0xf00dc42c) */
/* WARNING: Removing unreachable block (ram,0xf00dc4a8) */
/* WARNING: Removing unreachable block (ram,0xf00dc53c) */
/* WARNING: Removing unreachable block (ram,0xf00dc568) */
/* WARNING: Removing unreachable block (ram,0xf00dc590) */
/* WARNING: Removing unreachable block (ram,0xf00dc4f0) */
/* WARNING: Removing unreachable block (ram,0xf00dc50c) */
/* WARNING: Removing unreachable block (ram,0xf00dc414) */

undefined8 -[InputStream returnRecordedData](int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  uint *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar10;
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
  iVar5 = param_1;
  _kern_serv_kernel_task_port();
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
  puVar6 = *(uint **)(param_1 + 0x2c);
  puVar8 = (uint *)0x0;
  bVar1 = false;
  if ((uint *)(param_1 + 0x2c) != puVar6) {
    uVar7 = puVar6[3];
    do {
      if (*puVar6 < uVar7) {
        if (uVar7 < puVar6[1]) {
          bVar1 = true;
          puVar8 = puVar6;
          break;
        }
        puVar6 = (uint *)puVar6[0xf];
      }
      else {
        puVar6 = (uint *)puVar6[0xf];
      }
      puVar8 = puVar6;
      bVar1 = false;
      if ((uint *)(param_1 + 0x2c) == puVar6) break;
      uVar7 = puVar6[3];
    } while( true );
  }
  if (bVar1) {
    piVar3 = (int *)0x44;
    _IOMalloc();
    _memcpy();
    iVar9 = puVar8[3] - *puVar8;
    uVar7 = puVar8[4] - iVar9;
    iVar10 = puVar8[2] - puVar8[3];
    iVar4 = iVar5;
    _vm_allocate_EXTERNAL(iVar5,piVar3,iVar9,1);
    if (iVar4 == 0) {
      puVar8[8] = 0;
      puVar8[10] = 0;
      _bcopy(*puVar8,*piVar3,iVar9);
      iVar4 = iVar5;
      _vm_deallocate_EXTERNAL(iVar5,*puVar8,puVar8[4]);
      if (iVar4 != 0) {
        _IOLog(aAudioVmDealloc,aMachErr);
      }
      _vm_allocate_EXTERNAL(iVar5,puVar8,uVar7,1);
      if (iVar5 != 0) {
        _IOLog(aAudioCannotAll);
        iVar10 = 0;
        uVar7 = 0;
      }
      puVar8[4] = uVar7;
      puVar8[1] = *puVar8 + uVar7;
      puVar8[3] = *puVar8;
      puVar8[2] = *puVar8 + iVar10;
      piVar3[4] = iVar9;
      piVar3[0xc] = 1;
      piVar3[0xb] = 1;
      iVar9 = *piVar3 + iVar9;
      piVar3[1] = iVar9;
      piVar3[2] = iVar9;
      piVar3[3] = iVar9;
      iVar5 = *(int *)(param_1 + 0x2c);
      if (param_1 + 0x2c == iVar5) {
        *(int **)(param_1 + 0x2c) = piVar3;
        *(int **)(param_1 + 0x30) = piVar3;
        piVar3[0xf] = iVar5;
        piVar3[0x10] = iVar5;
      }
      else {
        piVar3[0x10] = param_1 + 0x2c;
        piVar3[0xf] = iVar5;
        *(int **)(param_1 + 0x2c) = piVar3;
        *(int **)(iVar5 + 0x40) = piVar3;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paUnlock);
      *(undefined *)(param_1 + 0x78) = 0;
      goto locret_F00DC620;
    }
    _IOLog(aAudioCannotAll);
    _IOFree(piVar3,0x44);
    uVar2 = *(undefined4 *)(param_1 + 0x28);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x28);
  }
  _objc_msgSend(uVar2,paUnlock);
  *(undefined *)(param_1 + 0x78) = 1;
locret_F00DC620:
  return CONCAT44(param_2,param_1);
}
