/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11fddc. */
int __cdecl sub_11FDDC(void *a1, int a2, int a3, _BYTE *a4)
{
  const void *v5; // eax
  __int16 v6; // cx
  NXHashTable *v7; // ebx
  char *v8; // ecx
  int i; // ecx
  void *v10; // eax
  _DWORD *v11; // eax
  void *v12; // eax
  NXHashTable *v13; // ebx
  char *v14; // eax
  int j; // ecx
  void *v16; // eax
  _DWORD *v17; // eax
  void *v18; // eax
  int v19; // [esp-18h] [ebp-78h]
  int v20; // [esp+10h] [ebp-50h]
  _DWORD *v21; // [esp+10h] [ebp-50h]
  int v22; // [esp+10h] [ebp-50h]
  void *v23; // [esp+10h] [ebp-50h]
  void **v24; // [esp+10h] [ebp-50h]
  unsigned int data; // [esp+14h] [ebp-4Ch]
  char v26; // [esp+18h] [ebp-48h]
  int v27; // [esp+1Ch] [ebp-44h]
  char v28; // [esp+20h] [ebp-40h]
  _BYTE *v29; // [esp+24h] [ebp-3Ch]
  char v30[8]; // [esp+28h] [ebp-38h] BYREF
  int v31; // [esp+30h] [ebp-30h]
  __int16 v32; // [esp+34h] [ebp-2Ch]
  _BYTE v33[18]; // [esp+36h] [ebp-2Ah] BYREF
  void *v34; // [esp+48h] [ebp-18h] BYREF
  NXHashState state; // [esp+4Ch] [ebp-14h] BYREF
  int v36; // [esp+54h] [ebp-Ch] BYREF
  __int16 v37; // [esp+58h] [ebp-8h]
  __int16 v38; // [esp+5Eh] [ebp-2h] BYREF

  if ( *(_DWORD *)(if_private(a1) + 20) != a2 ) /*0x11fdfc*/
    return 47; /*0x11fe03*/
  if ( nb_size(a3) <= 8u ) /*0x11fe19*/
    return nullsap_input(a1, a2, a3, a4); /*0x11fe19*/
  if ( (a4[1] & 0xC0) != 0x40 ) /*0x11fe24*/
    return nullsap_input(a1, a2, a3, a4); /*0x11fe24*/
  v5 = (const void *)nb_map(a3); /*0x11fe31*/
  if ( bcmp(v5, &unk_1DB896, 6u) ) /*0x11fe3c*/
    return nullsap_input(a1, a2, a3, a4); /*0x11fe5b*/
  nb_read(a3, 6, 2u, &v38); /*0x11fe6c*/
  nb_shrink_top(a3, 8); /*0x11fe77*/
  v6 = __ROR2__(v38, 8); /*0x11fe83*/
  v38 = v6; /*0x11fe87*/
  if ( (unsigned __int16)(v6 - 4096) <= 0xFu ) /*0x11fe96*/
    return nullsap_input(a1, a2, a3, a4); /*0x11fe96*/
  if ( v6 == 2048 )
  {
    v20 = if_ipackets(a1) + 1; /*0x11fed4*/
    if_ipackets_set(a1, v20); /*0x11fed9*/
    if ( (if_flags(a1) & 0x4000) == 0 && (*(_BYTE *)if_private(a1) & 1) != 0 )
    {
      v7 = *(NXHashTable **)(if_private(a1) + 4); /*0x11ff11*/
      v36 = *((_DWORD *)a4 + 2); /*0x11ff17*/
      v37 = *((_WORD *)a4 + 6); /*0x11ff1e*/
      LOBYTE(v36) = v36 & 0x7F; /*0x11ff22*/
      if ( (char)a4[8] < 0 && (a4[14] & 0x1Fu) > 2 )
      {
        v29 = a4 + 14; /*0x11ff4e*/
        if ( (a4[14] & 0x1Fu) - 2 <= 0x10 && (a4[14] & 1) == 0 )
        {
          v8 = (char *)NXHashGet(v7, &v36); /*0x11ff79*/
          v34 = v8; /*0x11ff7b*/
          if ( v8 )
          {
            bcopy(v29, v8 + 12, a4[14] & 0x1F); /*0x11ff97*/
            *((_BYTE *)v34 + 12) &= 0x1Fu; /*0x11ff9f*/
            *((_BYTE *)v34 + 13) = (~(*((_BYTE *)v34 + 13) >> 7) << 7) | *((_BYTE *)v34 + 13) & 0x7F; /*0x11ffc4*/
          }
          else
          {
            if ( NXCountHashTable(v7) < 0x1F4 ) /*0x11ffde*/
              goto LABEL_36; /*0x11ffde*/
            v28 = 0; /*0x11ffe4*/
            state = NXInitHashState(v7); /*0x11ffee*/
            while ( NXNextHashState(v7, &state, &v34) ) /*0x12000b*/
            {
              v21 = (_DWORD *)((char *)&arptab + 180 * (*((_DWORD *)v34 + 2) % 0x13u)); /*0x120037*/
              for ( i = 0; i <= 8; ++i ) /*0x12003a*/
              {
                if ( *v21 == *((_DWORD *)v34 + 2) && (!a1 || (void *)v21[4] == a1) ) /*0x12004f*/
                  break; /*0x12004f*/
                v21 += 5; /*0x120052*/
              }
              if ( i > 8 ) /*0x12005e*/
                v21 = nullptr; /*0x120060*/
              if ( !v21 || !*((_DWORD *)v34 + 2) ) /*0x120070*/
              {
                v10 = NXHashRemove(v7, v34); /*0x12007b*/
                v34 = v10; /*0x120082*/
                if ( v10 ) /*0x12008a*/
                {
                  kfree((int)v10, 0x20u); /*0x120093*/
                  v28 = 1; /*0x120098*/
                  break; /*0x120098*/
                }
              }
            }
            if ( v28 )
            {
LABEL_36:
              v11 = (_DWORD *)kalloc(0x20u); /*0x1200ba*/
              v34 = v11; /*0x1200c1*/
              *v11 = v36; /*0x1200c7*/
              *((_WORD *)v11 + 2) = v37; /*0x1200cd*/
              v11[2] = 0; /*0x1200d1*/
              bcopy(v29, v11 + 3, *v29 & 0x1F); /*0x1200ec*/
              *((_BYTE *)v34 + 12) &= 0x1Fu; /*0x1200f4*/
              *((_BYTE *)v34 + 13) = (~(*((_BYTE *)v34 + 13) >> 7) << 7) | *((_BYTE *)v34 + 13) & 0x7F; /*0x120119*/
              v12 = NXHashInsert(v7, v34); /*0x120121*/
              v34 = v12; /*0x120128*/
              if ( v12 ) /*0x120130*/
                kfree((int)v12, 0x20u); /*0x120135*/
            }
            else
            {
              printf("add_sr: source route table overflow\n");
            }
          }
        }
      }
    }
    inet_queue(a1, a3); /*0x120145*/
  }
  else
  {
    if ( v6 != 2054 ) /*0x11febc*/
      return nullsap_input(a1, a2, a3, a4); /*0x11fea9*/
    v22 = if_ipackets(a1) + 1; /*0x12015c*/
    if_ipackets_set(a1, v22); /*0x120161*/
    if ( (if_flags(a1) & 0x4000) != 0 )
    {
      nb_free(a3); /*0x120430*/
    }
    else
    {
      if ( (*(_BYTE *)if_private(a1) & 1) != 0 ) /*0x120188*/
      {
        bcopy(a4, v30, 0x20u); /*0x120191*/
        v27 = *(_DWORD *)(nb_map(a3) + 14); /*0x1201a4*/
      }
      nb_write(a3, 0, 2u, &unk_1DB89E); /*0x1201b7*/
      v19 = *(_DWORD *)(if_private(a1) + 16); /*0x1201ce*/
      v23 = (void *)(if_private(a1) + 8); /*0x1201e0*/
      arpinput(a1, v23, v19, a3); /*0x1201e8*/
      if ( (*(_BYTE *)if_private(a1) & 1) != 0 )
      {
        v13 = *(NXHashTable **)(if_private(a1) + 4); /*0x12020f*/
        v36 = v31; /*0x120215*/
        v37 = v32; /*0x12021c*/
        LOBYTE(v36) = v31 & 0x7F; /*0x120220*/
        if ( (v31 & 0x80u) != 0 && (v33[0] & 0x1Fu) > 2 && (v33[0] & 0x1Fu) - 2 <= 0x10 && (v33[0] & 1) == 0 )
        {
          v14 = (char *)NXHashGet(v13, &v36); /*0x120269*/
          v34 = v14; /*0x120270*/
          if ( v14 )
          {
            bcopy(v33, v14 + 12, v33[0] & 0x1F); /*0x120286*/
            *((_BYTE *)v34 + 12) &= 0x1Fu; /*0x12028e*/
            *((_BYTE *)v34 + 13) = (~(*((_BYTE *)v34 + 13) >> 7) << 7) | *((_BYTE *)v34 + 13) & 0x7F; /*0x1202ad*/
          }
          else
          {
            if ( NXCountHashTable(v13) < 0x1F4 ) /*0x1202c6*/
              goto LABEL_65; /*0x1202c6*/
            v26 = 0; /*0x1202cc*/
            state = NXInitHashState(v13); /*0x1202d6*/
            while ( NXNextHashState(v13, &state, &v34) ) /*0x1202f3*/
            {
              data = *((_DWORD *)v34 + 2); /*0x1202ff*/
              v24 = (void **)((char *)&arptab + 180 * (data % 0x13)); /*0x120323*/
              for ( j = 0; j <= 8; ++j ) /*0x120326*/
              {
                if ( *v24 == (void *)data && (!a1 || v24[4] == a1) ) /*0x120346*/
                  break; /*0x120346*/
                v24 += 5; /*0x120349*/
              }
              if ( j > 8 ) /*0x120355*/
                v24 = nullptr; /*0x120357*/
              if ( !v24 || !*((_DWORD *)v34 + 2) ) /*0x120367*/
              {
                v16 = NXHashRemove(v13, v34); /*0x120376*/
                v34 = v16; /*0x12037d*/
                if ( v16 ) /*0x120385*/
                {
                  kfree((int)v16, 0x20u); /*0x12038e*/
                  v26 = 1; /*0x120393*/
                  break; /*0x120393*/
                }
              }
            }
            if ( v26 )
            {
LABEL_65:
              v17 = (_DWORD *)kalloc(0x20u); /*0x1203b2*/
              v34 = v17; /*0x1203b9*/
              *v17 = v36; /*0x1203bf*/
              *((_WORD *)v17 + 2) = v37; /*0x1203c5*/
              v17[2] = v27; /*0x1203cc*/
              bcopy(v33, v17 + 3, v33[0] & 0x1F); /*0x1203dd*/
              *((_BYTE *)v34 + 12) &= 0x1Fu; /*0x1203e5*/
              *((_BYTE *)v34 + 13) = (~(*((_BYTE *)v34 + 13) >> 7) << 7) | *((_BYTE *)v34 + 13) & 0x7F; /*0x120407*/
              v18 = NXHashInsert(v13, v34); /*0x12040f*/
              v34 = v18; /*0x120416*/
              if ( v18 ) /*0x12041e*/
                kfree((int)v18, 0x20u); /*0x120423*/
            }
            else
            {
              printf("add_sr: source route table overflow\n");
            }
          }
        }
      }
    }
  }
  return 0; /*0x120451*/
}
