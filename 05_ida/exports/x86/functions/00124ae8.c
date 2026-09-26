/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124ae8. */
int __cdecl sub_124AE8(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // eax
  _BYTE *v5; // edx
  int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+18h] [ebp-4h] BYREF

  v8 = 1; /*0x124b09*/
  v7 = 0; /*0x124b10*/
  if ( strlen((const char *)(a3 + 244)) > 0x37 ) /*0x124b34*/
    *(_BYTE *)(a3 + 299) = 0; /*0x124b39*/
  printf("%s", (const char *)(a3 + 244)); /*0x124b46*/
  v3 = kmioctl(0, -2147191792, &v8, 0); /*0x124b5d*/
  if ( !v3 ) /*0x124b64*/
  {
    v4 = *(unsigned __int8 *)(a3 + 242); /*0x124b6d*/
    if ( v4 == 2 ) /*0x124b77*/
    {
      v7 = 1; /*0x124b94*/
    }
    else
    {
      if ( *(unsigned __int8 *)(a3 + 242) > 2u ) /*0x124b79*/
      {
        if ( v4 == 3 ) /*0x124b8b*/
        {
          *(_DWORD *)(a2 + 16) = -1; /*0x124c0b*/
          *(_BYTE *)(a2 + 270) = 0; /*0x124c12*/
          *(_BYTE *)(a2 + 271) = 0; /*0x124c19*/
        }
        return v3; /*0x124c19*/
      }
      if ( v4 != 1 ) /*0x124b7e*/
        return v3; /*0x124b7e*/
    }
    v3 = 0; /*0x124b9b*/
    sub_124D1C(a2 + 272, a2 + 272, v7); /*0x124ba9*/
    if ( v7 ) /*0x124bb3*/
      printf("\n"); /*0x124bba*/
    v5 = (_BYTE *)(a2 + 272); /*0x124bbf*/
    if ( *(_BYTE *)(a2 + 272) ) /*0x124bc4*/
    {
      while ( *v5 != 10 && *v5 != 13 ) /*0x124bd4*/
      {
        if ( !*++v5 ) /*0x124bdd*/
          goto LABEL_18; /*0x124be0*/
      }
      *v5 = 0; /*0x124bd6*/
    }
LABEL_18:
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(a3 + 20); /*0x124be2*/
    *(_BYTE *)(a2 + 270) = *(_BYTE *)(a3 + 242); /*0x124bf7*/
    *(_BYTE *)(a2 + 271) = *(_BYTE *)(a3 + 243); /*0x124c00*/
  }
  return v3; /*0x124c25*/
}
