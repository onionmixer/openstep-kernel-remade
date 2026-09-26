/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b3aa4 */

/* WARNING: Removing unreachable block (ram,0x001b3b24) */

undefined4
FUN_001b3aa4(undefined4 param_1,undefined4 param_2,ushort *param_3,int param_4,ushort *param_5)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  int local_24;
  uint local_20;
  uint local_18;
  uint local_14;
  ushort *local_10;
  
  local_18 = 0xffffffff;
  _bzero(param_5,0x4f0);
  param_5[0x42] = 0xffff;
  param_5[0x43] = 0xffff;
  param_5[100] = 0xffff;
  param_5[0x65] = 0xffff;
  param_5[0x166] = 0xffff;
  param_5[0x167] = 0xffff;
  puVar9 = (ushort *)((int)param_3 + param_4);
  local_10 = param_3;
  *(ushort **)(param_5 + 0x274) = param_3;
  *(int *)(param_5 + 0x276) = param_4;
  if (param_3 < puVar9) {
    uVar3 = *param_3;
    local_10 = param_3 + 1;
  }
  else {
    uVar3 = 0;
  }
  *param_5 = uVar3;
  if (local_10 < puVar9) {
    if (uVar3 == 0) {
      local_20 = (uint)(byte)*local_10;
      local_10 = (ushort *)((int)local_10 + 1);
    }
    else {
      local_20 = (uint)*local_10;
      local_10 = local_10 + 1;
    }
  }
  else {
    local_20 = 0;
  }
  iVar8 = 0;
  if (local_20 != 0) {
    do {
      if (local_10 < puVar9) {
        if (uVar3 == 0) {
          uVar6 = (uint)(byte)*local_10;
          local_10 = (ushort *)((int)local_10 + 1);
        }
        else {
          uVar6 = (uint)*local_10;
          local_10 = local_10 + 1;
        }
      }
      else {
        uVar6 = 0;
      }
      if (0xf < uVar6) {
        return 0;
      }
      if (*(int *)(param_5 + 0x42) < (int)uVar6) {
        *(uint *)(param_5 + 0x42) = uVar6;
      }
      *(ushort **)(param_5 + uVar6 * 2 + 0x44) = local_10;
      local_24 = 0;
      if (local_10 < puVar9) {
        if (uVar3 == 0) {
          local_14 = (uint)(byte)*local_10;
          local_10 = (ushort *)((int)local_10 + 1);
        }
        else {
          local_14 = (uint)*local_10;
          local_10 = local_10 + 1;
        }
      }
      else {
        local_14 = 0;
      }
      if (local_14 != 0) {
        do {
          if (local_10 < puVar9) {
            if (uVar3 == 0) {
              uVar5 = (uint)(byte)*local_10;
              local_10 = (ushort *)((int)local_10 + 1);
            }
            else {
              uVar5 = (uint)*local_10;
              local_10 = local_10 + 1;
            }
          }
          else {
            uVar5 = 0;
          }
          if (0x7f < uVar5) {
            return 0;
          }
          bVar2 = *(byte *)(uVar5 + 2 + (int)param_5);
          if ((bVar2 & 0x10) != 0) {
            return 0;
          }
          *(byte *)(uVar5 + 2 + (int)param_5) = bVar2 | (byte)uVar6 & 0xf | 0x10;
          local_24 = local_24 + 1;
        } while (local_24 < (int)local_14);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)local_20);
  }
  if (local_10 < puVar9) {
    if (uVar3 == 0) {
      uVar6 = (uint)(byte)*local_10;
      local_10 = (ushort *)((int)local_10 + 1);
    }
    else {
      uVar6 = (uint)*local_10;
      local_10 = local_10 + 1;
    }
  }
  else {
    uVar6 = 0;
  }
  *(uint *)(param_5 + 100) = uVar6;
  iVar8 = 0;
  do {
    if (iVar8 < (int)uVar6) {
      *(ushort **)(param_5 + iVar8 * 2 + 0x66) = local_10;
      if (local_10 < puVar9) {
        if (uVar3 == 0) {
          uVar5 = (uint)(byte)*local_10;
          local_10 = (ushort *)((int)local_10 + 1);
        }
        else {
          uVar5 = (uint)*local_10;
          local_10 = local_10 + 1;
        }
      }
      else {
        uVar5 = 0;
      }
      if (uVar3 == 0) {
        if (uVar5 != 0xff) goto LAB_001b3cd7;
      }
      else if (uVar5 != 0xffff) {
LAB_001b3cd7:
        pbVar1 = (byte *)(iVar8 + 2 + (int)param_5);
        *pbVar1 = *pbVar1 | 0x20;
        iVar7 = 0;
        local_24 = 1;
        if (*(uint *)(param_5 + 0x42) < 0x80000000) {
          do {
            if ((uVar5 & 1) != 0) {
              local_24 = local_24 * 2;
            }
            iVar7 = iVar7 + 1;
            uVar5 = (int)uVar5 >> 1;
          } while (iVar7 <= (int)*(uint *)(param_5 + 0x42));
        }
        iVar7 = 0;
        if (0 < local_24) {
          do {
            if (local_10 < puVar9) {
              if (uVar3 == 0) {
                uVar4 = (ushort)(byte)*local_10;
                local_10 = (ushort *)((int)local_10 + 1);
              }
              else {
                uVar4 = *local_10;
                local_10 = local_10 + 1;
              }
            }
            else {
              uVar4 = 0;
            }
            if (local_10 < puVar9) {
              if (uVar3 == 0) {
                uVar5 = (uint)(byte)*local_10;
                local_10 = (ushort *)((int)local_10 + 1);
              }
              else {
                uVar5 = (uint)*local_10;
                local_10 = local_10 + 1;
              }
            }
            else {
              uVar5 = 0;
            }
            if (uVar3 == 0) {
              if (uVar4 == 0xff) goto LAB_001b3d80;
            }
            else if (uVar4 == 0xffff) {
LAB_001b3d80:
              if ((int)local_18 < (int)uVar5) {
                local_18 = uVar5;
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < local_24);
        }
        goto LAB_001b3dae;
      }
      (param_5 + iVar8 * 2 + 0x66)[0] = 0;
      (param_5 + iVar8 * 2 + 0x66)[1] = 0;
    }
    else {
      (param_5 + iVar8 * 2 + 0x66)[0] = 0;
      (param_5 + iVar8 * 2 + 0x66)[1] = 0;
    }
LAB_001b3dae:
    iVar8 = iVar8 + 1;
    if (0x7f < iVar8) {
      if (local_10 < puVar9) {
        if (uVar3 == 0) {
          uVar6 = (uint)(byte)*local_10;
          local_10 = (ushort *)((int)local_10 + 1);
        }
        else {
          uVar6 = (uint)*local_10;
          local_10 = local_10 + 1;
        }
      }
      else {
        uVar6 = 0;
      }
      *(uint *)(param_5 + 0x166) = uVar6;
      if ((int)local_18 < (int)uVar6) {
        iVar8 = 0;
        if (uVar6 != 0) {
          do {
            *(ushort **)(param_5 + iVar8 * 2 + 0x168) = local_10;
            iVar7 = 0;
            if (local_10 < puVar9) {
              if (uVar3 == 0) {
                uVar6 = (uint)(byte)*local_10;
                local_10 = (ushort *)((int)local_10 + 1);
              }
              else {
                uVar6 = (uint)*local_10;
                local_10 = local_10 + 1;
              }
            }
            else {
              uVar6 = 0;
            }
            if (uVar6 != 0) {
              do {
                if (local_10 < puVar9) {
                  if (uVar3 == 0) {
                    local_10 = (ushort *)((int)local_10 + 1);
                  }
                  else {
                    local_10 = local_10 + 1;
                  }
                  if (local_10 < puVar9) {
                    if (uVar3 == 0) {
                      local_10 = (ushort *)((int)local_10 + 1);
                    }
                    else {
                      local_10 = local_10 + 1;
                    }
                  }
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 < (int)uVar6);
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < *(int *)(param_5 + 0x166));
        }
        if (local_10 < puVar9) {
          if (uVar3 == 0) {
            local_20 = (uint)(byte)*local_10;
            local_10 = (ushort *)((int)local_10 + 1);
          }
          else {
            local_20 = (uint)*local_10;
            local_10 = local_10 + 1;
          }
        }
        else {
          local_20 = 0;
        }
        if ((local_20 < 10) && (local_20 != 0)) {
          iVar8 = 8;
          do {
            param_5[iVar8 + 0x26a] = 0xffff;
            iVar8 = iVar8 + -1;
          } while (-1 < iVar8);
          iVar8 = 0;
          if (local_20 != 0) {
            do {
              if (local_10 < puVar9) {
                if (uVar3 == 0) {
                  uVar6 = (uint)(byte)*local_10;
                  local_10 = (ushort *)((int)local_10 + 1);
                }
                else {
                  uVar6 = (uint)*local_10;
                  local_10 = local_10 + 1;
                }
              }
              else {
                uVar6 = 0;
              }
              if (local_10 < puVar9) {
                if (uVar3 == 0) {
                  uVar4 = (ushort)(byte)*local_10;
                  local_10 = (ushort *)((int)local_10 + 1);
                }
                else {
                  uVar4 = *local_10;
                  local_10 = local_10 + 1;
                }
              }
              else {
                uVar4 = 0;
              }
              if (8 < uVar6) {
                return 0;
              }
              param_5[uVar6 + 0x26a] = uVar4;
              iVar8 = iVar8 + 1;
            } while (iVar8 < (int)local_20);
          }
          iVar8 = 0;
          do {
            if (param_5[iVar8 + 0x26a] != 0xffff) {
              pbVar1 = (byte *)(param_5[iVar8 + 0x26a] + 2 + (int)param_5);
              *pbVar1 = *pbVar1 | 0x60;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < 7);
          return param_1;
        }
      }
      return 0;
    }
  } while( true );
}

