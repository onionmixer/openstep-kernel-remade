/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b464. */
int __cdecl uname(utsname *a1)
{
  _DWORD *v1; // edi
  int result; // eax
  char v3; // al
  char v4; // dl
  _BYTE v5[4]; // [esp+Ch] [ebp-24h] BYREF
  char v6[32]; // [esp+10h] [ebp-20h] BYREF

  v1 = *(_DWORD **)(dword_1E875C + 36); /*0x10b472*/
  *(_BYTE *)(dword_1E875C + 104) = copyoutstr(aNextstep, *v1, 32, v5); /*0x10b48f*/
  result = dword_1E875C; /*0x10b492*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10b49a*/
  {
    *(_BYTE *)(dword_1E875C + 104) = copyoutstr(&hostname, *v1 + 32, 32, v5); /*0x10b4be*/
    result = dword_1E875C; /*0x10b4c1*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10b4c9*/
    {
      sprintf(v6, "%d", 0); /*0x10b4de*/
      *(_BYTE *)(dword_1E875C + 104) = copyoutstr(v6, *v1 + 64, 32, v5); /*0x10b4f9*/
      result = dword_1E875C; /*0x10b4fc*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10b504*/
      {
        sprintf(v6, "%d", 4); /*0x10b516*/
        *(_BYTE *)(dword_1E875C + 104) = copyoutstr(v6, *v1 + 96, 32, v5); /*0x10b531*/
        result = dword_1E875C; /*0x10b534*/
        if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10b53c*/
        {
          if ( dword_1E8E08 == 5 ) /*0x10b54e*/
          {
            v3 = copyoutstr(a586At, *v1 + 128, 32, v5); /*0x10b5bc*/
          }
          else if ( dword_1E8E08 > 5 ) /*0x10b550*/
          {
            if ( dword_1E8E08 == 132 ) /*0x10b565*/
            {
              v3 = copyoutstr(a486sxAt, *v1 + 128, 32, v5); /*0x10b5a8*/
            }
            else
            {
              if ( dword_1E8E08 != 133 ) /*0x10b56c*/
                goto LABEL_18; /*0x10b56c*/
              v3 = copyoutstr(a586sxAt, *v1 + 128, 32, v5); /*0x10b5d0*/
            }
          }
          else if ( dword_1E8E08 == 3 ) /*0x10b555*/
          {
            v3 = copyoutstr(a386At, *v1 + 128, 32, v5); /*0x10b580*/
          }
          else
          {
            if ( dword_1E8E08 != 4 ) /*0x10b55a*/
            {
LABEL_18:
              v3 = copyoutstr(aUnknownAt, *v1 + 128, 32, v5); /*0x10b5d4*/
              goto LABEL_19; /*0x10b5e7*/
            }
            v3 = copyoutstr(a486At, *v1 + 128, 32, v5); /*0x10b594*/
          }
LABEL_19:
          v4 = v3; /*0x10b5ec*/
          result = dword_1E875C; /*0x10b5ee*/
          *(_BYTE *)(dword_1E875C + 104) = v4; /*0x10b5f3*/
        }
      }
    }
  }
  return result; /*0x10b5f9*/
}
