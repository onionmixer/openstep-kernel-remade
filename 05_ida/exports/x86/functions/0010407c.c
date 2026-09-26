/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10407c. */
int fcntl(int a1, int a2, ...)
{
  int v2; // edi
  int result; // eax
  int v4; // eax
  char v5; // bl
  int v6; // ebx
  unsigned int v7; // ebx
  char v8; // al
  char v9; // dl
  char v10; // dl
  char v11; // dl
  char v12; // dl
  unsigned int v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+Ch] [ebp-28h]
  _BYTE *v15; // [esp+14h] [ebp-20h]
  _DWORD *v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-18h] BYREF
  __int16 v18; // [esp+20h] [ebp-14h] BYREF
  int v19; // [esp+24h] [ebp-10h]
  int v20; // [esp+28h] [ebp-Ch]

  v16 = *(_DWORD **)(dword_1E875C + 36); /*0x10408e*/
  if ( *(_DWORD *)(active_u + 348) > *v16 ) /*0x1040a2*/
  {
    v2 = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *v16); /*0x1040ae*/
    if ( v2 ) /*0x1040b3*/
    {
      if ( v2 != -65536 ) /*0x1040bf*/
      {
        v15 = (_BYTE *)(*(_DWORD *)(active_u + 340) + *v16); /*0x1040ce*/
        result = v16[1]; /*0x1040d4*/
        switch ( result ) /*0x1040e0*/
        {
          case 0: /*0x1040e0*/
            v13 = v16[2]; /*0x104116*/
            if ( v13 > 0xFF ) /*0x10411f*/
              goto LABEL_44; /*0x10411f*/
            result = ufalloc(v13); /*0x104129*/
            v14 = result; /*0x10412e*/
            if ( result >= 0 ) /*0x104136*/
            {
              v4 = *(_DWORD *)(active_u + 336); /*0x104146*/
              if ( *(_DWORD *)(v4 + 4 * *v16) != v2 ) /*0x10414f*/
              {
                *(_DWORD *)(v4 + 4 * v14) = 0; /*0x104154*/
                break; /*0x10415b*/
              }
              v5 = *v15 & 0xFE; /*0x104167*/
              expand_fdlist(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 56), v14); /*0x10417a*/
              *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v14) = v2; /*0x10418a*/
              *(_BYTE *)(v14 + *(_DWORD *)(active_u + 340)) = v5 & 0xFE; /*0x10419c*/
              ++*(_WORD *)(v2 + 14); /*0x10419f*/
              result = active_u; /*0x1041a3*/
              if ( *(_DWORD *)(active_u + 344) < v14 ) /*0x1041ae*/
                *(_DWORD *)(active_u + 344) = v14; /*0x1041b4*/
            }
            return result; /*0x1041ba*/
          case 1: /*0x1040e0*/
            result = dword_1E875C; /*0x1041c0*/
            *(_DWORD *)(dword_1E875C + 96) = *v15 & 1; /*0x1041cd*/
            return result; /*0x1041d0*/
          case 2: /*0x1040e0*/
            LOBYTE(result) = v16[2] & 1; /*0x1041e6*/
            *v15 = result | *v15 & 0xFE; /*0x1041ea*/
            return result; /*0x1041ec*/
          case 3: /*0x1040e0*/
            result = dword_1E875C; /*0x1041f4*/
            *(_DWORD *)(dword_1E875C + 96) = *(_DWORD *)(v2 + 8) - 1; /*0x1041fd*/
            return result; /*0x104200*/
          case 4: /*0x1040e0*/
            if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x104216*/
              v6 = *(_DWORD *)(v2 + 8) & 0x400031B3; /*0x104218*/
            else
              v6 = *(_DWORD *)(v2 + 8) & 0x21B3; /*0x104220*/
            v7 = (v16[2] + 1) & 0xFFFFDE4C | v6; /*0x104232*/
            v17 = (v7 >> 2) & 1; /*0x10423c*/
            *(_BYTE *)(dword_1E875C + 104) = fioctl(v2, -2147195266, &v17); /*0x104258*/
            result = dword_1E875C; /*0x10425b*/
            if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x104263*/
            {
              v17 = (v7 >> 6) & 1; /*0x104275*/
              *(_BYTE *)(dword_1E875C + 104) = fioctl(v2, -2147195267, &v17); /*0x10428e*/
              result = dword_1E875C; /*0x104291*/
              if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x104299*/
              {
                v17 = (*(_DWORD *)(v2 + 8) >> 2) & 1; /*0x1042a8*/
                return fioctl(v2, -2147195266, &v17); /*0x1042b2*/
              }
              else
              {
                *(_DWORD *)(v2 + 8) = v7; /*0x1042bc*/
              }
            }
            return result; /*0x1042b7*/
          case 5: /*0x1040e0*/
            v8 = fgetown(v2, dword_1E875C + 96); /*0x1042ce*/
            goto LABEL_23; /*0x1042d3*/
          case 6: /*0x1040e0*/
            v8 = fsetown(v2, v16[2]); /*0x1042e0*/
LABEL_23:
            v9 = v8; /*0x1042e5*/
            result = dword_1E875C; /*0x1042e7*/
            *(_BYTE *)(dword_1E875C + 104) = v9; /*0x1042ec*/
            return result; /*0x1042ef*/
          case 7: /*0x1040e0*/
          case 8: /*0x1040e0*/
          case 9: /*0x1040e0*/
            if ( *(_WORD *)(v2 + 12) != 1 ) /*0x1042f9*/
              break; /*0x1042f9*/
            if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) == 0 || *(_DWORD *)(*(_DWORD *)(v2 + 24) + 40) != 1 ) /*0x104317*/
              goto LABEL_44; /*0x104317*/
            v10 = copyin(v16[2], &v18, 20); /*0x10432f*/
            result = dword_1E875C; /*0x104331*/
            *(_BYTE *)(dword_1E875C + 104) = v10; /*0x104336*/
            if ( v10 ) /*0x10433e*/
              return result; /*0x10433e*/
            if ( v18 == 2 ) /*0x10434c*/
            {
              if ( v16[1] != 7 && (*(_BYTE *)(v2 + 8) & 2) == 0 ) /*0x104381*/
                break; /*0x104381*/
            }
            else if ( v18 > 2 ) /*0x10434e*/
            {
              if ( v18 != 3 ) /*0x10435c*/
                goto LABEL_44; /*0x10435c*/
            }
            else
            {
              if ( v18 != 1 ) /*0x104354*/
              {
LABEL_44:
                result = dword_1E875C; /*0x1043ca*/
                *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1043cf*/
                return result; /*0x1043d3*/
              }
              if ( v16[1] != 7 && (*(_BYTE *)(v2 + 8) & 1) == 0 ) /*0x10436d*/
                break; /*0x10436d*/
            }
            v11 = rewhence(&v18, v2, 0); /*0x1043a0*/
            result = dword_1E875C; /*0x1043a2*/
            *(_BYTE *)(dword_1E875C + 104) = v11; /*0x1043a7*/
            if ( v11 ) /*0x1043af*/
              return result; /*0x1043af*/
            if ( v20 < 0 ) /*0x1043ba*/
            {
              v19 += v20; /*0x1043bc*/
              v20 = -v20; /*0x1043c1*/
            }
            if ( v19 < 0 ) /*0x1043c8*/
              goto LABEL_44; /*0x1043c8*/
            if ( v16[1] != 7 && v18 != 3 ) /*0x1043e6*/
            {
              *v15 |= 4u; /*0x1043eb*/
              *(_DWORD *)(*(_DWORD *)active_u + 40) |= 0x20000000u; /*0x1043f5*/
            }
            v12 = (*(int (__cdecl **)(_DWORD, __int16 *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(*(_DWORD *)(v2 + 24) + 28) /*0x104423*/
                                                                                + 96))(
                    *(_DWORD *)(v2 + 24),
                    &v18,
                    v16[1],
                    *(_DWORD *)(v2 + 32),
                    *(__int16 *)(*(_DWORD *)active_u + 48));
            result = dword_1E875C; /*0x104425*/
            *(_BYTE *)(dword_1E875C + 104) = v12; /*0x10442a*/
            if ( !v12 && v16[1] == 7 ) /*0x10443b*/
            {
              if ( v18 == 3 ) /*0x104442*/
                result = copyout(&v18, v16[2], 2); /*0x10444a*/
              else
                result = copyout(&v18, v16[2], 20); /*0x104456*/
              *(_BYTE *)(dword_1E875C + 104) = result; /*0x104461*/
            }
            return result; /*0x104464*/
          default:
            *(_BYTE *)(dword_1E875C + 104) = 22; /*0x104468*/
            return result; /*0x104468*/
        }
      }
    }
  }
  result = dword_1E875C; /*0x104383*/
  *(_BYTE *)(dword_1E875C + 104) = 9; /*0x104388*/
  return result; /*0x10446f*/
}
