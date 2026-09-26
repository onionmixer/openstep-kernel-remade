
byte _od_request_vol(void)

{
  int iVar1;
  undefined *puVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  bool bVar9;
  byte bVar10;
  bool bVar11;
  
  cVar3 = (_od_spl & 0x10) != 0;
  if (_od_empty < 1) {
    puVar2 = _od_specific;
    if (_od_specific == (undefined *)0x0) {
      puVar2 = _od_vol;
      do {
        if ((puVar2[0xd9] & 0x40) != 0) break;
        puVar2 = puVar2 + 0xda;
      } while (puVar2 < (undefined *)0x40c592e);
      cVar3 = puVar2 < (undefined *)0x40c592e;
      bVar9 = SBORROW4((int)puVar2,0x40c592e);
      bVar5 = (int)(puVar2 + -0x40c592e) < 0;
      bVar7 = true;
      bVar11 = (bool)cVar3;
      if (puVar2 == (undefined *)0x40c592e) goto loc_407A954;
    }
    iVar1 = _od_make_empty();
    bVar9 = false;
    bVar5 = iVar1 < 0;
    bVar7 = iVar1 == 0;
    bVar11 = false;
    if (iVar1 < 1) goto loc_407A954;
    _od_specific = puVar2;
    if (((_rootdev >> 8 != _od_blk_major) ||
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) != 0)) &&
       (_panel_req_port != 0)) {
      cVar3 = 0xfffffff3 < *(uint *)(puVar2 + 0xae);
      _vol_panel_disk_label
                (_od_panel_abort,*(uint *)(puVar2 + 0xae) + 0xc,1,0,puVar2,0,&_od_vol_tag);
      _od_alert_present = 1;
      bVar5 = false;
      bVar7 = false;
      bVar9 = false;
      bVar11 = false;
      goto loc_407A954;
    }
    cVar3 = 0xfffffff3 < *(uint *)(puVar2 + 0xae);
    iVar1 = *(uint *)(puVar2 + 0xae) + 0xc;
    cVar4 = iVar1 < 0;
    cVar6 = iVar1 == 0;
    cVar8 = '\0';
    bVar10 = 0;
    _od_alert(aInsertDisk,aPleaseInsertDi,iVar1,(int)(puVar2 + -0x40c3ec8) * -0x2593f69b >> 1,0,0,0,
              0,0,0);
    bVar10 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar8 << 1 | bVar10;
  }
  else {
    if (((_rootdev >> 8 == _od_blk_major) &&
        ((unk_40C3FA0[(sword)(word)(((uint)_rootdev << 0x18) >> 0x1b) * 0xda] & 0x20) == 0)) ||
       (_panel_req_port == 0)) {
      cVar3 = _od_empty == 0;
      iVar1 = _od_empty + -1;
      cVar4 = iVar1 < 0;
      cVar6 = iVar1 == 0;
      cVar8 = '\0';
      bVar10 = 0;
      _od_alert(aInsertDisk,aPleaseInsertNe,iVar1,0,0,0,0,0,0,0);
    }
    else {
      cVar3 = 0xfbf3c211 < (uint)(_od_empty * 0xda);
      _vol_panel_disk_num(_od_panel_abort,_od_empty + -1,1,0,DAT_40c3dee + _od_empty * 0xda,0,
                          &_od_vol_tag);
      _od_alert_present = 1;
      cVar4 = '\0';
      cVar6 = '\0';
      cVar8 = '\0';
      bVar10 = 0;
    }
    bVar10 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar8 << 1 | bVar10;
  }
  cVar3 = (_od_spl & 0x10) != 0;
  bVar5 = false;
  bVar7 = bVar10 == 0;
  bVar9 = false;
  bVar11 = false;
loc_407A954:
  return cVar3 << 4 | bVar5 << 3 | bVar7 << 2 | bVar9 << 1 | bVar11;
}

