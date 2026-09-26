/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125f54. */
int ip_init()
{
  __int16 *v0; // eax
  int v1; // eax
  int v2; // ecx
  _BYTE *v3; // edx
  char *v4; // ebx
  _WORD *v5; // esi
  __int16 v6; // ax
  int result; // eax
  int v8; // [esp+Ch] [ebp-8h] BYREF

  v0 = pffindproto(2, 255, 3); /*0x125f66*/
  if ( !v0 ) /*0x125f72*/
    panic(aIpInit); /*0x125f79*/
  v1 = (-1431655765 * ((char *)v0 - (char *)&inetsw)) >> 4; /*0x125fa2*/
  v2 = 255; /*0x125fa5*/
  v3 = &unk_1EACEF; /*0x125faa*/
  do /*0x125fb4*/
  {
    *v3-- = v1; /*0x125fb0*/
    --v2; /*0x125fb3*/
  }
  while ( v2 >= 0 ); /*0x125fb4*/
  v4 = (char *)off_1DBCC8; /*0x125fb6*/
  if ( off_1DBCCC > off_1DBCC8 ) /*0x125fc2*/
  {
    v5 = (_WORD *)((char *)off_1DBCC8 + 8); /*0x125fc4*/
    do /*0x126017*/
    {
      if ( **((_DWORD **)v5 - 1) == 2 ) /*0x125fce*/
      {
        v6 = *v5; /*0x125fd0*/
        if ( *v5 ) /*0x125fd0*/
        {
          if ( v6 != 255 ) /*0x125fdc*/
            ip_protox[v6] = (-1431655765 * (v4 - (char *)&inetsw)) >> 4; /*0x126005*/
        }
      }
      v5 += 24; /*0x12600b*/
      v4 += 48; /*0x12600e*/
    }
    while ( off_1DBCCC > (_UNKNOWN *)v4 ); /*0x126017*/
  }
  dword_1EAA94 = (int)&ipq; /*0x126019*/
  ipq = (int)&ipq; /*0x126023*/
  result = getthetime(&v8); /*0x126031*/
  ip_id = v8; /*0x12603a*/
  dword_1EAA7C = ipqmaxlen; /*0x126047*/
  return result; /*0x126050*/
}
