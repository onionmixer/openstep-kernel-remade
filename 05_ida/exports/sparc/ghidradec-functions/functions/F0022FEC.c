
/* WARNING: Removing unreachable block (ram,0xf0023130) */
/* WARNING: Removing unreachable block (ram,0xf00231a8) */
/* WARNING: Removing unreachable block (ram,0xf002311c) */

undefined8 _unp_gc(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
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
  if (_unp_gcing == 0) {
    _unp_gcing = 1;
loc_F002300C:
    _unp_defer = 0;
    if ((undefined4 **)_file_list != &_file_list) {
      uVar2 = _file_list[2];
      puVar4 = _file_list;
      while( true ) {
        puVar4[2] = uVar2 & 0xffffffcf;
        puVar4 = (undefined4 *)*puVar4;
        if ((undefined4 **)puVar4 == &_file_list) break;
        uVar2 = puVar4[2];
      }
    }
    do {
      if ((undefined4 **)_file_list != &_file_list) {
        sVar1 = *(sword *)((int)_file_list + 0xe);
        puVar4 = _file_list;
        do {
          if (sVar1 == 0) {
            puVar4 = (undefined4 *)*puVar4;
          }
          else {
            uVar2 = puVar4[2];
            if ((uVar2 & 0x20) == 0) {
              if ((uVar2 & 0x10) == 0) {
                if (sVar1 != *(sword *)(puVar4 + 4)) {
                  puVar4[2] = uVar2 | 0x10;
                  goto loc_F00230C8;
                }
                puVar4 = (undefined4 *)*puVar4;
              }
              else {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
            else {
              puVar4[2] = uVar2 & 0xffffffdf;
              _unp_defer = _unp_defer + -1;
loc_F00230C8:
              if (*(sword *)(puVar4 + 3) == 2) {
                iVar3 = puVar4[6];
                if (iVar3 == 0) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                else if (*(undefined **)(*(int *)(iVar3 + 0xc) + 4) == _unixdomain) {
                  if ((*(word *)(*(int *)(iVar3 + 0xc) + 10) & 0x10) == 0) {
                    puVar4 = (undefined4 *)*puVar4;
                  }
                  else {
                    if ((*(word *)(iVar3 + 0x38) & 1) != 0) {
                      _sbwait(iVar3 + 0x24);
                      goto loc_F002300C;
                    }
                    _unp_scan(*(undefined4 *)(iVar3 + 0x30),_unp_mark);
                    puVar4 = (undefined4 *)*puVar4;
                  }
                }
                else {
                  puVar4 = (undefined4 *)*puVar4;
                }
              }
              else {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
          }
          if ((undefined4 **)puVar4 == &_file_list) break;
          sVar1 = *(sword *)((int)puVar4 + 0xe);
        } while( true );
      }
    } while (_unp_defer != 0);
    if ((undefined4 **)_file_list != &_file_list) {
      sVar1 = *(sword *)((int)_file_list + 0xe);
      puVar4 = _file_list;
      while( true ) {
        if (sVar1 == *(sword *)(puVar4 + 4)) {
          if ((puVar4[2] & 0x10) == 0) {
            while (sVar1 != 0) {
              _unp_discard(puVar4);
              sVar1 = *(sword *)(puVar4 + 4);
            }
            puVar4 = (undefined4 *)*_file_list;
          }
          else {
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
        if ((undefined4 **)puVar4 == &_file_list) break;
        sVar1 = *(sword *)((int)puVar4 + 0xe);
      }
    }
    _unp_gcing = 0;
  }
  return CONCAT44(param_2,param_1);
}
