
/* WARNING: Removing unreachable block (ram,0xf00a3a44) */
/* WARNING: Removing unreachable block (ram,0xf00a3a3c) */
/* WARNING: Removing unreachable block (ram,0xf00a39fc) */
/* WARNING: Removing unreachable block (ram,0xf00a3990) */
/* WARNING: Removing unreachable block (ram,0xf00a3878) */
/* WARNING: Removing unreachable block (ram,0xf00a38c8) */
/* WARNING: Removing unreachable block (ram,0xf00a39a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3a10) */
/* WARNING: Removing unreachable block (ram,0xf00a3858) */
/* WARNING: Removing unreachable block (ram,0xf00a3a90) */
/* WARNING: Removing unreachable block (ram,0xf00a3ab0) */
/* WARNING: Removing unreachable block (ram,0xf00a3a74) */

undefined8 _getargs(char *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  undefined4 unaff_l0;
  byte *pbVar6;
  char *pcVar7;
  undefined4 unaff_l1;
  undefined5 **ppuVar8;
  undefined *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar10;
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
  _strncpy(_boot_file,aMachKernel,0x40);
  if (*param_1 == '\0') {
    uVar10 = 1;
  }
  else {
    while( true ) {
      iVar4 = (int)*param_1;
      _isargsep();
      if (iVar4 == 0) break;
      param_1 = param_1 + 1;
    }
    cVar2 = *param_1;
    if (*param_1 != '\0') {
loc_F00A38B0:
      pcVar7 = param_1;
      if (cVar2 == '-') {
        pbVar6 = (byte *)&_init_args;
        _argstrcpy(param_1,&_init_args);
        bVar3 = _init_args._0_1_;
        while( true ) {
          switch((int)((bVar3 - 0x61) * 0x1000000) >> 0x18) {
          case :
            _boothowto = _boothowto | 1;
            break;
          case :
            _boothowto = _boothowto | 4;
            break;
          case :
            _boothowto = _boothowto | 0x200000;
            break;
          case :
            _boothowto = _boothowto | 8;
            break;
          case :
            _boothowto = _boothowto | 2;
          }
          iVar4 = (int)(char)*pbVar6;
          if (iVar4 == 0) break;
          pbVar6 = pbVar6 + 1;
          _isargsep();
          if (iVar4 != 0) break;
          bVar3 = *pbVar6;
        }
      }
      else {
        while( true ) {
          iVar4 = (int)*pcVar7;
          _isargsep();
          if ((iVar4 != 0) || (*pcVar7 == '=')) break;
          pcVar7 = pcVar7 + 1;
        }
        if ((*pcVar7 == '=') && (ppuVar8 = &_kernargs, _kernargs != (undefined5 *)0x0)) {
          puVar9 = DAT_f011926c;
          do {
            pcVar5 = param_1;
            _strncmp(param_1,*ppuVar8,(int)pcVar7 - (int)param_1);
            if (pcVar5 == (char *)0x0) goto loc_F00A3A10;
            ppuVar8 = ppuVar8 + 2;
            puVar9 = (undefined *)((int)puVar9 + 8);
          } while (*ppuVar8 != (undefined5 *)0x0);
        }
      }
      goto loc_F00A3A90;
    }
loc_F00A3AE8:
    uVar10 = 0;
  }
  return CONCAT44(param_2,uVar10);
loc_F00A3A10:
  while( true ) {
    iVar4 = (int)*pcVar7;
    _isargsep();
    if (iVar4 == 0) break;
    pcVar7 = pcVar7 + 1;
  }
  pcVar5 = pcVar7;
  _getval(pcVar7,(undefined *)((int)register0x00000038 + -0xc));
  if (pcVar5 == (char *)0x0) {
    **(undefined4 **)puVar9 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else if (pcVar5 == (char *)0x1) {
    _argstrcpy(pcVar7 + 1,*(undefined4 *)puVar9);
  }
loc_F00A3A90:
  while( true ) {
    iVar4 = (int)*param_1;
    _isargsep();
    if (iVar4 != 0) break;
    param_1 = param_1 + 1;
  }
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    iVar4 = (int)*param_1;
    _isargsep();
    if (iVar4 == 0) {
      cVar1 = *param_1;
      goto loc_F00A3ADC;
    }
    param_1 = param_1 + 1;
    cVar2 = *param_1;
  }
  cVar1 = *param_1;
loc_F00A3ADC:
  cVar2 = *param_1;
  if (cVar1 == '\0') goto loc_F00A3AE8;
  goto loc_F00A38B0;
}
