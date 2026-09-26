/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11c760. */
int __cdecl sub_11C760(int a1, char *a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  const char *i; // eax
  char *v8; // eax
  char **v9; // ebx
  int v10; // eax
  char v12; // [esp+14h] [ebp-12Ch] BYREF
  char v13[255]; // [esp+15h] [ebp-12Bh] BYREF
  int v14[3]; // [esp+114h] [ebp-2Ch] BYREF
  _DWORD v15[2]; // [esp+120h] [ebp-20h] BYREF
  _DWORD v16[5]; // [esp+128h] [ebp-18h] BYREF
  int v17; // [esp+13Ch] [ebp-4h]

  v4 = 0; /*0x11c76f*/
  pn_alloc(a4); /*0x11c772*/
  v5 = dnlc_lookupSymLink(a2, a3); /*0x11c77f*/
  v6 = v5; /*0x11c784*/
  if ( v5 && *(_BYTE *)(v5 + 68) ) /*0x11c78d*/
  {
    bcopy(*(const void **)(v5 + 64), *(void **)a4, *(__int16 *)(v5 + 70)); /*0x11c79f*/
    *(_DWORD *)(a4 + 8) = *(__int16 *)(v6 + 70); /*0x11c7a8*/
  }
  else
  {
    v15[0] = *(_DWORD *)a4; /*0x11c7b2*/
    v15[1] = 1024; /*0x11c7b5*/
    v16[0] = v15; /*0x11c7bf*/
    v16[1] = 1; /*0x11c7c2*/
    v16[2] = 0; /*0x11c7c9*/
    v16[3] = 1; /*0x11c7d0*/
    v17 = 1024; /*0x11c7d7*/
    v4 = (*(int (__cdecl **)(int, _DWORD *, _DWORD))(*(_DWORD *)(a1 + 28) + 68))(a1, v16, *(_DWORD *)(active_u + 28)); /*0x11c7f7*/
    *(_DWORD *)(a4 + 8) = 1024 - v17; /*0x11c801*/
    if ( v4 ) /*0x11c809*/
    {
LABEL_32:
      pn_free(a4); /*0x11c967*/
      return v4; /*0x11c968*/
    }
    dnlc_enterSymLink(a2, a3, a4); /*0x11c818*/
  }
  *(_BYTE *)(*(_DWORD *)(a4 + 8) + *(_DWORD *)a4) = 0; /*0x11c825*/
  for ( i = *(const char **)a4; ; i = v8 + 1 ) /*0x11c829*/
  {
    v8 = index(i, 36); /*0x11c82f*/
    if ( !v8 ) /*0x11c839*/
      break; /*0x11c839*/
    if ( *(char **)a4 == v8 || *(v8 - 1) == 47 ) /*0x11c847*/
    {
      pn_alloc(v14); /*0x11c858*/
      if ( *(_DWORD *)(a4 + 8) ) /*0x11c860*/
      {
        while ( 1 ) /*0x11c884*/
        {
          if ( **(_BYTE **)(a4 + 4) == 47 ) /*0x11c88a*/
          {
            v4 = pn_append((int)v14, asc_1DB784); /*0x11c897*/
            if ( v4 ) /*0x11c89e*/
              break; /*0x11c89e*/
            pn_skipslash(a4); /*0x11c8a5*/
          }
          v4 = pn_getcomponent(a4, &v12); /*0x11c8ba*/
          if ( v4 ) /*0x11c8c1*/
            break; /*0x11c8c1*/
          if ( v12 == 36 ) /*0x11c8ce*/
          {
            v9 = &metalinks; /*0x11c8d0*/
            if ( !metalinks ) /*0x11c8dc*/
              goto LABEL_24; /*0x11c8dc*/
            do /*0x11c8f9*/
            {
              if ( !strcmp(v13, *v9) ) /*0x11c8ea*/
                break; /*0x11c8f4*/
              v9 += 3; /*0x11c8f6*/
            }
            while ( *v9 ); /*0x11c8f9*/
            if ( !*v9 ) /*0x11c8fe*/
            {
LABEL_24:
              v4 = 2; /*0x11c918*/
              break; /*0x11c91d*/
            }
            if ( *v9[1] ) /*0x11c906*/
            {
              v10 = pn_append((int)v14, v9[1]); /*0x11c921*/
            }
            else
            {
              if ( !v9[2] ) /*0x11c910*/
                goto LABEL_24; /*0x11c910*/
              v10 = pn_append((int)v14, v9[2]); /*0x11c913*/
            }
          }
          else
          {
            v10 = pn_append((int)v14, &v12); /*0x11c92c*/
          }
          v4 = v10; /*0x11c931*/
          if ( v10 ) /*0x11c938*/
            break; /*0x11c938*/
          if ( !*(_DWORD *)(a4 + 8) ) /*0x11c93a*/
            goto LABEL_29; /*0x11c93e*/
        }
      }
      else
      {
LABEL_29:
        v4 = pn_set(a4, v14[0]); /*0x11c948*/
      }
      pn_free(v14); /*0x11c957*/
      break; /*0x11c95b*/
    }
  }
  if ( v4 ) /*0x11c965*/
    goto LABEL_32; /*0x11c965*/
  return v4; /*0x11c975*/
}
