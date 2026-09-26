
/* WARNING: Type propagation algorithm not settling */

undefined4 sub_408067A(int param_1)

{
  undefined4 uVar1;
  undefined4 ******ppppppuVar2;
  uint uVar3;
  int iVar4;
  word wVar5;
  undefined4 *******pppppppuVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 ******ppppppuVar11;
  undefined4 ******ppppppuVar12;
  int iVar13;
  uint uVar14;
  undefined uVar15;
  undefined4 *******unaff_A3;
  int iVar16;
  uint uStack_1c;
  undefined uStack_d;
  undefined4 *******pppppppuStack_c;
  undefined4 *******pppppppuStack_8;
  
  iVar13 = *(int *)(param_1 + 4) + -0x24;
  uVar10 = *(undefined4 *)(param_1 + 0x1c);
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  ppppppuVar2 = *(undefined4 *******)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x14) == 200) {
    if ((dword_40C6E84 & 0x20000) == 0) {
      iVar9 = param_1 + 0x24;
      pppppppuStack_c = &pppppppuStack_c;
      pppppppuStack_8 = &pppppppuStack_c;
      while (0 < iVar13) {
        uVar15 = (undefined)uVar1;
        uStack_d = (undefined)uVar10;
        switch(*(undefined4 *)(iVar9 + 4)) {
        case :
          uStack_1c = (uint)*(word *)(iVar9 + 0xe);
          ppppppuVar11 = (undefined4 ******)(*(int *)(iVar9 + 0x10) * uStack_1c >> 3);
          if ((*(byte *)(iVar9 + 0xb) & 8) == 0) {
            uVar8 = ~_page_mask;
            uVar3 = *(uint *)(iVar9 + 0x14);
            uVar14 = uVar3 % _page_size;
            uVar7 = (int)ppppppuVar11 + _page_mask + uVar14 & uVar8;
            unaff_A3 = (undefined4 *******)_kalloc(0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 0;
            pppppppuVar6 = unaff_A3 + 1;
            iVar16 = _vm_allocate(_kernel_map,pppppppuVar6,uVar7,1);
            if (iVar16 != 0) {
              return 0x68;
            }
            iVar16 = _vm_map_copy(_kernel_map,dword_40C6EBC,*pppppppuVar6,uVar7,uVar8 & uVar3,0,1);
            if (iVar16 != 0) {
              _vm_deallocate(_kernel_map,*pppppppuVar6,uVar7);
              return 0x68;
            }
            _vm_map_pageable(_kernel_map,*pppppppuVar6,(int)*pppppppuVar6 + uVar7,0);
            *pppppppuVar6 = (undefined4 ******)(uVar14 + (int)*pppppppuVar6);
            iVar13 = iVar13 + -0x18;
            iVar16 = iVar9 + 0x18;
          }
          else {
            unaff_A3 = (undefined4 *******)_kalloc((int)ppppppuVar11 + 0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 1;
            _bcopy(iVar9 + 0x14,(undefined4 ******)((int)unaff_A3 + 0x26),ppppppuVar11);
            unaff_A3[1] = (undefined4 ******)((int)unaff_A3 + 0x26);
            iVar13 = (iVar13 + -0x14) - (int)ppppppuVar11;
            iVar16 = iVar9 + 0x14 + (int)ppppppuVar11;
          }
          wVar5 = *(word *)(iVar9 + 0xe);
          if (wVar5 == 0x10) {
            ppppppuVar12 = (undefined4 ******)0x2;
loc_408089C:
            *unaff_A3 = ppppppuVar12;
          }
          else {
            if (0x10 < wVar5) {
              if (wVar5 == 0x18) {
                ppppppuVar12 = (undefined4 ******)0x3;
              }
              else {
                if (wVar5 != 0x20) goto loc_408089E;
                ppppppuVar12 = (undefined4 ******)0x4;
              }
              goto loc_408089C;
            }
            if (wVar5 == 8) {
              ppppppuVar12 = (undefined4 ******)0x1;
              goto loc_408089C;
            }
          }
loc_408089E:
          unaff_A3[2] = ppppppuVar11;
          unaff_A3[3] = unaff_A3[1];
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 0x10;
          iVar13 = iVar13 + -0x10;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x7;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          break;
        case :
          iVar16 = iVar9 + 0x14;
          iVar13 = iVar13 + -0x14;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x8;
          unaff_A3[1] = (undefined4 ******)(*(uint *)(iVar9 + 0xc) & 0xf89f0000);
          unaff_A3[2] = (undefined4 ******)(*(uint *)(iVar9 + 0x10) & 0xf89f0000);
          break;
        case :
          iVar4 = *(int *)(iVar9 + 0x20);
          if ((*(byte *)(iVar9 + 0x13) & 8) == 0) {
            unaff_A3 = (undefined4 *******)_kalloc(0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 0;
          }
          else {
            unaff_A3 = (undefined4 *******)_kalloc(iVar4 + 0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 1;
            _bcopy(iVar9 + 0x1c,(undefined4 ******)((int)unaff_A3 + 0x26),iVar4);
            unaff_A3[1] = (undefined4 ******)((int)unaff_A3 + 0x26);
          }
          *unaff_A3 = (undefined4 ******)0x9;
          if (*(undefined4 ******)(iVar9 + 0xc) == (undefined4 *****)0x0) {
            unaff_A3[1][4] = _snd_var;
          }
          else {
            unaff_A3[1][4] = *(undefined4 ******)(iVar9 + 0xc);
          }
          iVar16 = iVar4 + 0x1c + iVar9;
          iVar13 = (iVar13 + -0x1c) - iVar4;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 8;
          iVar13 = iVar13 + -8;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0xa;
          break;
        case :
          iVar16 = iVar9 + 8;
          iVar13 = iVar13 + -8;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0xb;
          break;
        case :
          iVar16 = iVar9 + 0x1c;
          iVar13 = iVar13 + -0x1c;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x0;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          unaff_A3[2] = *(undefined4 *******)(iVar9 + 0x10);
          unaff_A3[3] = *(undefined4 *******)(iVar9 + 0x18);
          break;
        case :
          ppppppuVar11 = *(undefined4 *******)(iVar9 + 0x14);
          if ((undefined4 ******)0x1fd0 < ppppppuVar11) {
            return 0x68;
          }
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          ppppppuVar12 = (undefined4 ******)_kalloc(ppppppuVar11);
          unaff_A3[1] = ppppppuVar12;
          *(undefined *)((int)unaff_A3 + 0x23) = 0;
          unaff_A3[4] = ppppppuVar2;
          wVar5 = *(word *)(iVar9 + 0xe);
          if (wVar5 == 0x10) {
            ppppppuVar12 = (undefined4 ******)0xe;
loc_4080922:
            *unaff_A3 = ppppppuVar12;
          }
          else {
            if (0x10 < wVar5) {
              if (wVar5 == 0x18) {
                ppppppuVar12 = (undefined4 ******)0xf;
              }
              else {
                if (wVar5 != 0x20) goto loc_4080924;
                ppppppuVar12 = (undefined4 ******)0x10;
              }
              goto loc_4080922;
            }
            if (wVar5 == 8) {
              ppppppuVar12 = (undefined4 ******)0xd;
              goto loc_4080922;
            }
          }
loc_4080924:
          unaff_A3[2] = ppppppuVar11;
          unaff_A3[3] = unaff_A3[1];
          iVar16 = iVar9 + 0x18;
          iVar13 = iVar13 + -0x18;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 0x10;
          iVar13 = iVar13 + -0x10;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x11;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          *(undefined *)((int)unaff_A3 + 0x23) = 0;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        :
          goto loc_40806AA;
        }
        *(undefined *)((int)unaff_A3 + 0x23) = 0;
        *(undefined *)(unaff_A3 + 8) = uStack_d;
        *(undefined *)((int)unaff_A3 + 0x21) = 3;
        *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
        *(undefined *)(unaff_A3 + 9) = 0;
        pppppppuVar6 = pppppppuStack_c;
joined_r0x04080ab2:
        pppppppuStack_c = unaff_A3;
        if ((undefined4 ********)pppppppuStack_8 != &pppppppuStack_c) {
          pppppppuStack_8[6] = unaff_A3;
          pppppppuStack_c = pppppppuVar6;
        }
        unaff_A3[7] = pppppppuStack_8;
        unaff_A3[6] = &pppppppuStack_c;
        iVar9 = iVar16;
        pppppppuStack_8 = unaff_A3;
      }
      if ((undefined4 ********)pppppppuStack_c == &pppppppuStack_c) {
        _dspq_execute();
      }
      else {
        if (pppppppuStack_8 == pppppppuStack_c) {
          *(undefined *)((int)unaff_A3 + 0x21) = 0;
        }
        else {
          *(undefined *)((int)pppppppuStack_8 + 0x21) = 2;
          *(undefined *)((int)pppppppuStack_c + 0x21) = 1;
        }
        _dspq_enqueue(&pppppppuStack_c);
      }
      uVar10 = 100;
    }
    else {
      uVar10 = 0x6d;
    }
  }
  else {
loc_40806AA:
    uVar10 = 0x66;
  }
  return uVar10;
}

