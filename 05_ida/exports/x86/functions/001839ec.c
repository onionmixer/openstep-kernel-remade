/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1839ec. */
int __cdecl sdioctl(unsigned __int16 a1, int a2, char *a3)
{
  int v3; // esi
  id *v4; // ecx
  int v5; // ebx
  id v6; // edx
  int v7; // ebx
  const char *v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // ebx
  int v11; // edx
  int v12; // ecx
  id v13; // eax
  unsigned int v14; // edx
  int v15; // esi
  id v16; // eax
  id v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // edx
  id v21; // ebx
  id v22; // eax
  id v24; // [esp+10h] [ebp-B0h]
  id v25; // [esp+14h] [ebp-ACh]
  id v26; // [esp+18h] [ebp-A8h]
  int v27; // [esp+1Ch] [ebp-A4h]
  id v28; // [esp+20h] [ebp-A0h]
  int v29; // [esp+24h] [ebp-9Ch] BYREF
  int v30; // [esp+28h] [ebp-98h] BYREF
  char v31[8]; // [esp+2Ch] [ebp-94h] BYREF
  unsigned int v32; // [esp+34h] [ebp-8Ch]
  unsigned int v33; // [esp+38h] [ebp-88h]
  _DWORD __dst[12]; // [esp+3Ch] [ebp-84h] BYREF
  _BYTE v35[2]; // [esp+6Ch] [ebp-54h] BYREF
  int v36; // [esp+6Eh] [ebp-52h]
  int v37; // [esp+72h] [ebp-4Eh]
  int v38; // [esp+76h] [ebp-4Ah]
  bool v39; // [esp+7Ah] [ebp-46h]
  int v40; // [esp+7Ch] [ebp-44h]
  int v41; // [esp+80h] [ebp-40h]
  char v42; // [esp+84h] [ebp-3Ch]
  char v43; // [esp+87h] [ebp-39h]
  int v44; // [esp+88h] [ebp-38h]
  char v45; // [esp+8Ch] [ebp-34h]
  int v46; // [esp+90h] [ebp-30h]
  _BYTE v47[24]; // [esp+A4h] [ebp-1Ch] BYREF
  __int16 v48; // [esp+BCh] [ebp-4h]

  v27 = 0; /*0x183a0c*/
  v26 = nullptr; /*0x183a16*/
  v3 = *(_DWORD *)a3; /*0x183a20*/
  if ( (unsigned __int8)((unsigned __int8)a1 >> 3) > 0x10u || dword_1E7568 != HIBYTE(a1) ) /*0x183a38*/
    return 6; /*0x183a38*/
  v4 = (id *)&dword_1E7324[9 * ((unsigned __int8)a1 >> 3)]; /*0x183a41*/
  if ( a2 == 536896533 ) /*0x183a4e*/
    goto LABEL_19; /*0x183a4e*/
  if ( a2 <= 536896533 ) /*0x183a50*/
  {
    if ( a2 != -1068207359 ) /*0x183a58*/
    {
      if ( a2 > -1068207359 ) /*0x183a5a*/
      {
        if ( a2 > 536896513 || a2 < 536896512 ) /*0x183a7e*/
          return 22; /*0x183a7e*/
      }
      else if ( a2 != -2147195881 ) /*0x183a62*/
      {
        return 22; /*0x184055*/
      }
      goto LABEL_19; /*0x183a62*/
    }
    goto LABEL_22; /*0x183a58*/
  }
  if ( a2 > 1074029593 ) /*0x183a8e*/
  {
    if ( a2 != 1074295557 && a2 != 1076913157 ) /*0x183ab6*/
      return 22; /*0x183ab6*/
    goto LABEL_22; /*0x183ab6*/
  }
  if ( a2 >= 1074029592 ) /*0x183a96*/
  {
LABEL_22:
    v28 = *v4; /*0x183ad8*/
    goto LABEL_23; /*0x183ada*/
  }
  if ( a2 != 1074029591 ) /*0x183a9e*/
    return 22; /*0x183a9e*/
LABEL_19:
  v5 = a1 & 7; /*0x183ac0*/
  if ( v5 == 7 ) /*0x183ac6*/
    v5 = 0; /*0x183ac8*/
  v28 = v4[v5 + 1]; /*0x183ace*/
LABEL_23:
  if ( v28 ) /*0x183ae7*/
  {
    if ( a2 == 536896533 ) /*0x183af3*/
    {
      if ( (unsigned __int8)objc_msgSend(v28, sel_isRemovable) ) /*0x183cf6*/
        v26 = objc_msgSend(v28, sel_eject); /*0x183d15*/
    }
    else
    {
      if ( a2 <= 536896533 ) /*0x183af9*/
      {
        if ( a2 != -1068207359 ) /*0x183b01*/
        {
          if ( a2 > -1068207359 ) /*0x183b07*/
          {
            if ( a2 == 536896512 ) /*0x183b1e*/
            {
              v7 = IOMalloc(7260); /*0x183bd2*/
              v26 = objc_msgSend(v28, sel_readLabel_, v7); /*0x183be7*/
              if ( !v26 ) /*0x183bf2*/
                v27 = copyout(v7, v3, 7260); /*0x183c00*/
            }
            else
            {
              v7 = IOMalloc(7260); /*0x183c1e*/
              v27 = copyin(v3, v7, 7260); /*0x183c2c*/
              if ( !v27 ) /*0x183c37*/
                v26 = objc_msgSend(v28, sel_writeLabel_, v7); /*0x183c4c*/
            }
            IOFree(v7, 7260); /*0x183c0f*/
          }
          else
          {
            v26 = objc_msgSend(v28, sel_setFormatted_, *a3); /*0x183b9c*/
          }
          goto LABEL_82; /*0x183ba5*/
        }
        if ( *((_DWORD *)a3 + 5) ) /*0x183d4e*/
        {
          v24 = objc_msgSend(*v4, sel_controller); /*0x183d66*/
          objc_msgSend(v24, sel_getDMAAlignment_, v31); /*0x183d80*/
          if ( *((_DWORD *)a3 + 3) == 1 ) /*0x183d8c*/
            v14 = v33; /*0x183d8e*/
          else
            v14 = v32; /*0x183d98*/
          if ( v14 <= 1 ) /*0x183da1*/
          {
            v15 = *((_DWORD *)a3 + 5); /*0x183db4*/
            v16 = objc_msgSend(v24, sel_allocateBufferOfLength_actualStart_actualLength_, v15, &v30, &v29); /*0x183dd3*/
          }
          else
          {
            v15 = -v14 & (v14 + *((_DWORD *)a3 + 5) - 1); /*0x183dad*/
            v16 = objc_msgSend(v24, sel_allocateBufferOfLength_actualStart_actualLength_, v15, &v30, &v29); /*0x183daf*/
          }
          v25 = v16; /*0x183dd8*/
          if ( *((_DWORD *)a3 + 3) == 1 ) /*0x183de5*/
          {
            v27 = copyin(*((_DWORD *)a3 + 4), v16, *((_DWORD *)a3 + 5)); /*0x183dfb*/
            if ( v27 ) /*0x183e06*/
            {
              *((_DWORD *)a3 + 7) = 9; /*0x183e08*/
LABEL_77:
              if ( *((_DWORD *)a3 + 5) ) /*0x183f88*/
                IOFree(v30, v29); /*0x183fa0*/
              goto LABEL_82; /*0x183fa8*/
            }
          }
        }
        else
        {
          v15 = 0; /*0x183e14*/
          v25 = nullptr; /*0x183e16*/
        }
        bzero(v35, 0x54u); /*0x183e26*/
        v35[0] = (unsigned __int8)objc_msgSend(v28, sel_target); /*0x183e3f*/
        v35[1] = (unsigned __int8)objc_msgSend(v28, sel_lun); /*0x183e56*/
        v36 = *(_DWORD *)a3; /*0x183e5b*/
        v37 = *((_DWORD *)a3 + 1); /*0x183e61*/
        v38 = *((_DWORD *)a3 + 2); /*0x183e67*/
        v39 = *((_DWORD *)a3 + 3) == 0; /*0x183e74*/
        v40 = v15; /*0x183e77*/
        v41 = *((_DWORD *)a3 + 6); /*0x183e7d*/
        v42 = ((a3[73] & 1) == 0) | v42 & 0xFE; /*0x183e9b*/
        v42 = a3[73] & 2 | v42 & 0xFD; /*0x183ea8*/
        v42 = v42 & 0xFB | a3[73] & 4; /*0x183eb5*/
        v43 = v43 & 0xF | (16 * a3[72]); /*0x183ec5*/
        if ( *((_DWORD *)a3 + 3) == 1 ) /*0x183ecc*/
          v17 = objc_msgSend(v28, sel_sdCdbWrite_buffer_client_, v35, v25, kernel_map); /*0x183ee1*/
        else
          v17 = objc_msgSend(v28, sel_sdCdbRead_buffer_client_, v35, v25, kernel_map); /*0x183eff*/
        v26 = v17; /*0x183f04*/
        v18 = v44; /*0x183f0d*/
        *((_DWORD *)a3 + 7) = v44; /*0x183f10*/
        if ( v18 == 13 && v45 == 2 ) /*0x183f1c*/
          *((_DWORD *)a3 + 7) = 3; /*0x183f1e*/
        a3[32] = v45; /*0x183f28*/
        v19 = v46; /*0x183f2b*/
        *((_DWORD *)a3 + 15) = v46; /*0x183f2e*/
        v20 = *((_DWORD *)a3 + 5); /*0x183f31*/
        if ( v19 > v20 ) /*0x183f36*/
          *((_DWORD *)a3 + 15) = v20; /*0x183f38*/
        *((_DWORD *)a3 + 17) = 0; /*0x183f3b*/
        *((_DWORD *)a3 + 16) = 0; /*0x183f42*/
        if ( !*((_DWORD *)a3 + 3) && v46 ) /*0x183f53*/
          v27 = copyout(v25, *((_DWORD *)a3 + 4), *((_DWORD *)a3 + 15)); /*0x183f69*/
        if ( *((_DWORD *)a3 + 7) == 2 ) /*0x183f76*/
        {
          qmemcpy(a3 + 33, v47, 0x18u); /*0x183f84*/
          *(_WORD *)(a3 + 57) = v48; /*0x183f86*/
        }
        goto LABEL_77; /*0x183f86*/
      }
      if ( a2 == 1074029593 ) /*0x183b3e*/
      {
        v13 = objc_msgSend(v28, sel_diskSize); /*0x183d39*/
        goto LABEL_51; /*0x183d39*/
      }
      if ( a2 <= 1074029593 ) /*0x183b44*/
      {
        if ( a2 == 1074029591 ) /*0x183b4c*/
        {
          v6 = (id)(char)objc_msgSend(v28, sel_isFormatted); /*0x183bc0*/
LABEL_52:
          *(_DWORD *)a3 = v6; /*0x183d40*/
          goto LABEL_82; /*0x183d45*/
        }
        v13 = objc_msgSend(v28, sel_blockSize); /*0x183d29*/
LABEL_51:
        v6 = v13; /*0x183d3e*/
        goto LABEL_52; /*0x183d3e*/
      }
      if ( a2 == 1074295557 ) /*0x183b66*/
      {
        v26 = objc_msgSend(v28, sel_updatePhysicalParameters); /*0x183fc2*/
        if ( v26 ) /*0x183fcd*/
          return (int)objc_msgSend(v28, sel_errnoFromReturn_, v26); /*0x183fcd*/
        v21 = objc_msgSend(v28, sel_blockSize); /*0x183fe5*/
        v22 = objc_msgSend(v28, sel_diskSize); /*0x183ff4*/
        a3[4] = HIBYTE(v21); /*0x184010*/
        a3[5] = BYTE2(v21); /*0x184018*/
        a3[6] = BYTE1(v21); /*0x184020*/
        a3[7] = (char)v21; /*0x184023*/
        *a3 = ((unsigned int)v22 - 1) >> 24; /*0x184037*/
        a3[1] = ((unsigned int)v22 - 1) >> 16; /*0x18403e*/
        a3[2] = (unsigned __int16)((_WORD)v22 - 1) >> 8; /*0x184046*/
        a3[3] = (_BYTE)v22 - 1; /*0x184049*/
      }
      else
      {
        bzero(__dst, 0x30u); /*0x183c69*/
        v8 = (const char *)objc_msgSend(v28, sel_driveName); /*0x183c7b*/
        strcpy((char *)__dst, v8); /*0x183c84*/
        v9 = (unsigned int)objc_msgSend(v28, sel_blockSize); /*0x183c9b*/
        __dst[10] = v9; /*0x183c9d*/
        __dst[11] = dword_1E756C; /*0x183ca5*/
        if ( v9 ) /*0x183cad*/
        {
          v10 = (v9 + 7259) / v9; /*0x183cbb*/
          v11 = 3; /*0x183cbd*/
          v12 = 3 * v10; /*0x183cc2*/
          do /*0x183ccf*/
          {
            __dst[v11 + 6] = v12; /*0x183cc8*/
            v12 -= v10; /*0x183ccc*/
            --v11; /*0x183cce*/
          }
          while ( v11 >= 0 ); /*0x183ccf*/
        }
        qmemcpy(a3, __dst, 0x30u); /*0x183cdd*/
      }
    }
LABEL_82:
    if ( !v26 ) /*0x18405f*/
      return v27; /*0x184086*/
    return (int)objc_msgSend(v28, sel_errnoFromReturn_, v26); /*0x18407a*/
  }
  return 6; /*0x184093*/
}
