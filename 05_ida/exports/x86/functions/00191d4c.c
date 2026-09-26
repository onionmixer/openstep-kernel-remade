/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191d4c. */
int initrootnet()
{
  int v0; // ebx
  int v2; // esi
  int v3; // eax
  char *v4; // eax
  char *v5; // [esp+8h] [ebp-24h] BYREF
  _DWORD v6[4]; // [esp+Ch] [ebp-20h] BYREF
  __int16 v7; // [esp+1Ch] [ebp-10h]
  in_addr v8; // [esp+20h] [ebp-Ch] BYREF

  v5 = nullptr; /*0x191d54*/
  v0 = 0; /*0x191d5b*/
  if ( in_ifaddr && (*(_BYTE *)(*(_DWORD *)(in_ifaddr + 32) + 12) & 8) == 0 ) /*0x191d6d*/
    return 0; /*0x191d6f*/
  LOWORD(v6[0]) = **(_WORD **)dword_1E7740; /*0x191d82*/
  HIWORD(v6[0]) = 48; /*0x191d8d*/
  v2 = socreate(2, &v5, 2, 0); /*0x191da4*/
  if ( v2 )
  {
    printf("initrootnet: socreate failed\n");
  }
  else
  {
    v7 = 2; /*0x191db4*/
    while ( 1 )
    {
      v3 = ifioctl((int)v5, -1071617759, v6); /*0x191dc9*/
      v2 = v3; /*0x191dce*/
      if ( !v3 ) /*0x191dd5*/
        break; /*0x191dd5*/
      if ( v3 != 60 )
      {
        printf("initrootnet: autoaddr failed\n");
        goto LABEL_16; /*0x191df9*/
      }
      if ( !v0 )
      {
        printf("initrootnet: BOOTP timed out, still trying...\n");
        v0 = 1; /*0x191dea*/
      }
    }
    if ( v0 )
      printf("initrootnet: BOOTP [OK].\n");
    v4 = inet_ntoa((in_addr)&v8); /*0x191e1c*/
    printf("primary network interface: %s [%s]\n", (const char *)v6, v4);
  }
LABEL_16:
  if ( v5 ) /*0x191e35*/
    soclose((int)v5); /*0x191e38*/
  return v2; /*0x191e42*/
}
