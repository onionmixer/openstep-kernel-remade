
int _zsopen(word param_1,byte param_2)

{
  undefined *puVar1;
  word *pwVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  
  bVar9 = (byte)param_1;
  uVar3 = bVar9 & 0x1f;
  if (dword_40B51A4 == 0) {
    dword_40B51A4 = 1;
    dword_40B51B8 = sub_408BC84();
    sub_408D042();
  }
  if (uVar3 < 2) {
    iVar5 = uVar3 * 0x86;
    puVar1 = unk_40B51BC + iVar5;
    iVar6 = _ttynty(puVar1);
    iVar7 = uVar3 * 0x164;
    if ((param_1 & 0x1f) == 0) {
      *(int *)(DAT_40b52d0 + iVar7 + 0xc) = _slot_id_bmap + 0x2018001;
    }
    else {
      *(int *)(DAT_40b52d0 + iVar7 + 0xc) = _slot_id_bmap + 0x2018000;
    }
    if (((-1 < (char)unk_40B51BC[iVar5 + 0x41]) || (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0)
        ) && ((-1 < (char)bVar9 || ((*(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 8) == 0)))) {
      if ((param_1 & 0x40) == 0) {
        bVar4 = *(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 4;
      }
      else {
        bVar4 = *(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 2;
      }
      if (bVar4 == 0) {
        iVar8 = _zsacquire(uVar3,1,unk_40B2422);
        if (iVar8 != 0) {
          return iVar8;
        }
        if ((char)bVar9 < '\0') goto loc_408B402;
        *(int *)(DAT_40b5423 + iVar7 + 5) = *(int *)(DAT_40b5423 + iVar7 + 5) + 1;
loc_408B3FE:
        do {
          if (-1 < (char)bVar9) goto loc_408B40A;
loc_408B402:
          (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 0x10;
          do {
            if ((param_1 & 0x40) == 0) {
              (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 2;
            }
            else {
              (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 4;
            }
            if (((param_1 & 0x20) != 0) && (dword_40B51B8 == 2)) {
              (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 0x40;
            }
            if ((unk_40B51BC[iVar5 + 0x41] & 4) == 0) {
              *(word *)(unk_40B51BC + iVar5 + 0x38) = param_1;
              *(code **)(unk_40B51BC + iVar5 + 0x24) = sub_408CA1E;
              _ttychars(puVar1);
              if (unk_40B51BC[iVar5 + 0x47] == '\0') {
                unk_40B51BC[iVar5 + 0x47] = 0xd;
                unk_40B51BC[iVar5 + 0x48] = 0xd;
                *(undefined4 *)(unk_40B51BC + iVar5 + 0x3a) = 0xd8;
              }
              if ((char)bVar9 < '\0') {
                unk_40B51BC[iVar5 + 0x3a] = unk_40B51BC[iVar5 + 0x3a] | 1;
              }
              else {
                unk_40B51BC[iVar5 + 0x3a] = unk_40B51BC[iVar5 + 0x3a] & 0xfe;
              }
              if ((*(byte *)((int)&DAT_40b5400 + iVar7 + 2) & 1) == 0) {
                *(uint *)(unk_40B51BC + iVar5 + 0x3e) =
                     *(uint *)(unk_40B51BC + iVar5 + 0x3e) & 0xffffffef;
                sub_408BCB6(uVar3);
                pwVar2 = (word *)((int)&DAT_40b5400 + iVar7 + 2);
                *pwVar2 = *pwVar2 | 0x100;
              }
              sub_408BE8E(uVar3,0);
            }
            if ((DAT_40b5423[iVar7] & 4) != 0) {
loc_408B54A:
              sub_408CF32(uVar3,5,0);
              sub_408CD86(uVar3);
              if (((bVar9 & 0xc0) == 0x40) && ((*(uint *)(unk_40B51BC + iVar5 + 0x3e) & 0x10) == 0))
              {
                if (((param_2 & 4) == 0) && (-1 < *(sword *)(iVar6 + 0x12))) {
                  *(uint *)(unk_40B51BC + iVar5 + 0x3e) = *(uint *)(unk_40B51BC + iVar5 + 0x3e) | 2;
                  iVar8 = _sleep(DAT_40b52d0 + iVar7,0x11c);
                  if (iVar8 != 0) {
                    iVar5 = *(int *)(DAT_40b5423 + iVar7 + 5);
                    *(int *)(DAT_40b5423 + iVar7 + 5) = iVar5 + -1;
                    if (iVar5 != 1) {
                      return 4;
                    }
                    if (((&DAT_40b5400)[uVar3 * 0x59] & 0x18) != 0) {
                      return 4;
                    }
                    _zsclose((int)(sword)param_1,0);
                    return 4;
                  }
                  goto loc_408B3FE;
                }
              }
              else {
                *(uint *)(unk_40B51BC + iVar5 + 0x3e) = *(uint *)(unk_40B51BC + iVar5 + 0x3e) | 0x10
                ;
              }
              if (-1 < (char)bVar9) {
                (&DAT_40b5400)[uVar3 * 0x59] = (&DAT_40b5400)[uVar3 * 0x59] | 8;
                *(int *)(DAT_40b5423 + iVar7 + 5) = *(int *)(DAT_40b5423 + iVar7 + 5) + -1;
              }
              iVar5 = (*(code *)(&_linesw)[(char)unk_40B51BC[iVar5 + 0x45] * 0xc])
                                ((int)(sword)param_1,puVar1);
              return iVar5;
            }
            _ns_sleep(0,2000000000);
            sub_408CF32(uVar3,5,0);
            if ((bVar9 & 0xc0) == 0x40) {
              _ns_sleep(0,2000000000);
            }
            if ((char)bVar9 < '\0') goto loc_408B54A;
loc_408B40A:
          } while ((*(byte *)((int)&DAT_40b5400 + iVar7 + 3) & 0x10) == 0);
          iVar8 = _sleep(DAT_40b52d0 + iVar7,0x11c);
          if (iVar8 != 0) {
            iVar5 = *(int *)(DAT_40b5423 + iVar7 + 5);
            *(int *)(DAT_40b5423 + iVar7 + 5) = iVar5 + -1;
            if ((iVar5 == 1) && (((&DAT_40b5400)[uVar3 * 0x59] & 0x18) == 0)) {
              (&DAT_40b5400)[uVar3 * 0x59] = 0;
              _zsrelease(uVar3);
            }
            return 4;
          }
        } while( true );
      }
    }
    iVar5 = 0x10;
  }
  else {
    iVar5 = 6;
  }
  return iVar5;
}

